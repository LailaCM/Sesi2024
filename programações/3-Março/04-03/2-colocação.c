#include<stdio.h> 
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"");
	
	int i;
	for(i=1; i<=10; i+=2){
	printf("%d� colocado\n",i);
	}


	return 0;
}
