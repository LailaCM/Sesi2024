#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

char* tipo_triangulo(int a, int b, int c) {
    if (a == b && b == c)
        return "Equilátero";
    else if (a == b || a == c || b == c)
        return "Isósceles";
    else
        return "Escaleno";
}

void ler_arquivo(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int a, b, c;
        sscanf(linha, "%d;%d;%d", &a, &b, &c);
        if (a + b > c && a + c > b && b + c > a) {
            char *tipo = tipo_triangulo(a, b, c);
            printf("%d, %d, %d - %s\n", a, b, c, tipo);
        } else {
            printf("%d, %d, %d - Não é um triângulo\n", a, b, c);
        }
    }

    fclose(arquivo);
}

int main() {
	setlocale(LC_ALL,"");
    const char *arquivo = "triangulos.csv";
    ler_arquivo(arquivo);
    return 0;
}

