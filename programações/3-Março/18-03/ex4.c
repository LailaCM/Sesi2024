#include <stdio.h>
#include<locale.h>

int main() {
	
	setlocale(LC_ALL,"");
	
	//Exercício 4 Escreva um programa que começa pedindo um número N ao usuário e depois pede N números. O programa deverá mostrar na tela todos esses números ordenados do menor para o maior.
   
   double num;
   
   //Precisão desejada
   double epsilson = 0.00001; 
   
   printf("\n");
   printf("Digite um número para encontrar a raiz aproximada");
   scanf("%f", &num);
   
   double guess = num / 2;
   
   double erro = num -(guess*guess);
   while (erro>epsilon || erro < -epsilon)
   	guess = (


    return 0;
}
