#include<stdio.h> 
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"");
	
	int i;
	
	printf("Vamos jogar um jogo?  Adivinhe o número que estou pensando!\n");
	printf("Digite um número:\n");
	scanf("%d", &i);
	
	while(i!=4){
		printf ("Não, tenta mais uma vez!\n");
		scanf("%d", &i);
	}
	printf("Isso! Você acertou!\n");

	return 0;
}
