#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_TIMES 100
#define MAX_NOME 50

struct Time {
    char nome[MAX_NOME];
    int jogos;
    int vitorias;
    int empates;
    int derrotas;
    int saldo;
    int pontos;
};

void ler_arquivo(const char *nome_arquivo, struct Time times[], int *num_times) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char linha[100];
    *num_times = 0;

    // Ignora a primeira linha
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome[MAX_NOME];
        int jogos, vitorias, empates, derrotas, saldo;

        sscanf(linha, "%49[^;];%d;%d;%d;%d;%d", nome, &jogos, &vitorias, &empates, &derrotas, &saldo);

        strcpy(times[*num_times].nome, nome);
        times[*num_times].jogos = jogos;
        times[*num_times].vitorias = vitorias;
        times[*num_times].empates = empates;
        times[*num_times].derrotas = derrotas;
        times[*num_times].saldo = saldo;

        (*num_times)++;
    }

    fclose(arquivo);
}


void calcular_pontos(struct Time times[], int num_times) {
	int i;
    for (i = 0; i < num_times; i++) {
        times[i].pontos = times[i].vitorias * 3 + times[i].empates;
    }
}

void calcular_saldo(struct Time times[], int num_times) {
	int i;
    for (i = 0; i < num_times; i++) {
        times[i].saldo = times[i].vitorias - times[i].derrotas;
    }
}

void ordenar_times(struct Time times[], int num_times) {
	int i, j;
    for (i = 0; i < num_times - 1; i++) {
        for ( j = i + 1; j < num_times; j++) {
            if (times[i].pontos < times[j].pontos ||
                (times[i].pontos == times[j].pontos && times[i].saldo < times[j].saldo)) {
                struct Time temp = times[i];
                times[i] = times[j];
                times[j] = temp;
            }
        }
    }
}

void exibir_classificacao(struct Time times[], int num_times) {
	int i;
    printf("Classificação:\n");
    printf("%-15s%-7s%-7s%-7s%-7s%-7s%-7s\n", "Time", "Jogos", "Vitórias", "Empates", "Derrotas", "Saldo", "Pontos");
    for (i = 0; i < num_times; i++) {
        printf("%-15s%-7d%-7d%-7d%-7d%-7d%-7d\n", times[i].nome, times[i].jogos, times[i].vitorias, times[i].empates, times[i].derrotas, times[i].saldo, times[i].pontos);
    }
}

int main() {
    setlocale(LC_ALL,"");

    const char *arquivo = "times.csv";
    struct Time times[MAX_TIMES];
    int num_times;

    ler_arquivo(arquivo, times, &num_times);
    calcular_pontos(times, num_times);
    calcular_saldo(times, num_times);
    ordenar_times(times, num_times);
    exibir_classificacao(times, num_times);

    return 0;
}






