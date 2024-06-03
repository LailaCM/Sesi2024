#include<stdio.h>
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"");
    	
    int x, y, z, n;
    
    printf("Precisa encontrar a média de três números? Vem comigo!\n");
    printf("Digite os três números interios separadamente:\n");
    scanf("%d %d %d",&x, &y, &z);
    
    n= x + y + z;
    n= n/3;
    
    printf("A média dos numeros que voce informou é %d", n);
    
    return 0;
}
