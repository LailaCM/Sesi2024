#include <stdio.h>
#include<locale.h>

int main() {
	
	setlocale(LC_ALL,"");
	
	//Exerc�cio 4 Escreva um programa que come�a pedindo um n�mero N ao usu�rio e depois pede N n�meros. O programa dever� mostrar na tela todos esses n�meros ordenados do menor para o maior.
   
   double num;
   
   //Precis�o desejada
   double epsilson = 0.00001; 
   
   printf("\n");
   printf("Digite um n�mero para encontrar a raiz aproximada");
   scanf("%f", &num);
   
   double guess = num / 2;
   
   double erro = num -(guess*guess);
   while (erro>epsilon || erro < -epsilon)
   	guess = (


    return 0;
}
