#include <stdio.h>

int main() {
    
    char ch;
    int isFirstChar = 1;
    
    //Exerc�cio 4 Escreva um programa que come�a pedindo um n�mero N ao usu�rio e depois pede N n�meros. O programa dever� mostrar na tela todos esses n�meros ordenados do menor para o maior.

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
