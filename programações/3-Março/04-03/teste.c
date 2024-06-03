#include<stdio.h> 
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"");
	
	int i;
	for(i=1; i<=10; i*=10){
	printf("%dº colocado\n",i);
	}


	return 0;
}
