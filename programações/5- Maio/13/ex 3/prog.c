#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_CANDIDATOS 100
#define MAX_NOME 50

struct Candidato {
    char nome[MAX_NOME];
    int votos;
    float percentual_votos;
};

void ler_arquivo(const char *nome_arquivo, struct Candidato candidatos[], int *num_candidatos, int *total_votos) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char linha[100];
    *total_votos = 0;
    *num_candidatos = 0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome[MAX_NOME];
        int votos;
        sscanf(linha, "%49[^,],%d", nome, &votos);
        strcpy(candidatos[*num_candidatos].nome, nome);
        candidatos[*num_candidatos].votos = votos;
        *total_votos += votos;
        (*num_candidatos)++;
    }

    fclose(arquivo);
}

void calcular_percentual(struct Candidato candidatos[], int num_candidatos, int total_votos) {
	int i;
    for (i = 0; i < num_candidatos; i++) {
        candidatos[i].percentual_votos = ((float)candidatos[i].votos / total_votos) * 100;
    }
}

void ordenar_candidatos(struct Candidato candidatos[], int num_candidatos) {
	int i, j;
    for (i = 0; i < num_candidatos - 1; i++) {
        for ( j = i + 1; j < num_candidatos; j++) {
            if (candidatos[i].votos < candidatos[j].votos) {
                struct Candidato temp = candidatos[i];
                candidatos[i] = candidatos[j];
                candidatos[j] = temp;
            }
        }
    }
}

void exibir_resultado(struct Candidato candidatos[], int num_candidatos, struct Candidato primeiro_colocado, struct Candidato segundo_colocado) {
	int i;
    printf("Resultado das Eleições:\n");
    for (i = 0; i < num_candidatos; i++) {
        printf("%s: %.2f%% dos votos\n", candidatos[i].nome, candidatos[i].percentual_votos);
    }

    if (primeiro_colocado.percentual_votos > 50) {
        printf("\n%s ganhou em primeiro turno com %.2f%% dos votos.\n", primeiro_colocado.nome, primeiro_colocado.percentual_votos);
    } else {
        printf("\nHaverá segundo turno entre %s e %s.\n", primeiro_colocado.nome, segundo_colocado.nome);
    }
}

int main() {
    const char *arquivo = "votos.csv";
    struct Candidato candidatos[MAX_CANDIDATOS];
    int num_candidatos, total_votos;
    
    setlocale(LC_ALL,"");

    ler_arquivo(arquivo, candidatos, &num_candidatos, &total_votos);
    calcular_percentual(candidatos, num_candidatos, total_votos);
    ordenar_candidatos(candidatos, num_candidatos);

    struct Candidato primeiro_colocado = candidatos[0];
    struct Candidato segundo_colocado = candidatos[1];

    exibir_resultado(candidatos, num_candidatos, primeiro_colocado, segundo_colocado);

    return 0;
}





