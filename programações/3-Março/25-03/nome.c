#include <stdio.h>
#include<locale.h>

int main() {
	
	setlocale(LC_ALL,"");
	
	char nome[10];
	
	printf("Qual o nome seu nome?\n");
    scanf("%s",&nome);
    printf("Olá %s!",nome);
    
    return 0;
}
