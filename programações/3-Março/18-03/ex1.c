#include<stdio.h>
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"");
    	
    int x, y, z, n;
    
    printf("Precisa encontrar a m�dia de tr�s n�meros? Vem comigo!\n");
    printf("Digite os tr�s n�meros interios separadamente:\n");
    scanf("%d %d %d",&x, &y, &z);
    
    n= x + y + z;
    n= n/3;
    
    printf("A m�dia dos numeros que voce informou � %d", n);
    
    return 0;
}
