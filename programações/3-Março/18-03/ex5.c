#include <stdio.h>
#include<locale.h>

int main(void) {
	
	setlocale(LC_ALL,"");
	
	// 
	
	int min, max, i, j, primo;
	scanf("%i %i", &min, &max);
	
	for (i = min; i <= max; i++) {
		if (i == 0 || i == 1) {
			//n�meros zero e 1 n�o s�o primos
			primo = 0;
		} else {
			primo = 1; //considero inicialmente que o n�mero � primo
			for(j = 2; j < i; j++) { //tento provar que ele n�o � primo
				if (i % j == 0) {
					primo = 0; //consigo provar que ele n�o � primo
				}
			}
		}
		if (primo == 1) {
			printf("%i ", i);
		}
	}
	
	return 0;
}
