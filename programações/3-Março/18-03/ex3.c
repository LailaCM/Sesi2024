#include <stdio.h>

int main() {
    
    char ch;
    int isFirstChar = 1;
    
    //Exercício 4 Escreva um programa que começa pedindo um número N ao usuário e depois pede N números. O programa deverá mostrar na tela todos esses números ordenados do menor para o maior.

    printf("Escreva diversos caracteres e digite X para ver o que digitou: ");

    while ((ch = getchar()) != 'x') {
        if (ch != '\n') {
            if (isFirstChar) {
                isFirstChar = 0;
            } else {
                printf(" - ");
            }

            // Print the character
            printf("%c", ch);
        }
    }

    return 0;
}
