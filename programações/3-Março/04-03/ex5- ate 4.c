#include<stdio.h> 
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"");
	
	int i;
	
	printf("Vamos jogar um jogo?  Adivinhe o n�mero que estou pensando!\n");
	printf("Digite um n�mero:\n");
	scanf("%d", &i);
	
	while(i!=4){
		printf ("N�o, tenta mais uma vez!\n");
		scanf("%d", &i);
	}
	printf("Isso! Voc� acertou!\n");

	return 0;
}
