#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
	int cpm =5;
	int vetor[cpm];
	int i;
	for (i = 0; i <= cpm; i++) {
		vetor[i] = rand() % 101;
	}
    for (i = 0; i <= cpm; i++) {
    	printf("%d\n", vetor[i]);
	}
	return 0;

}
