#include <stdio.h>
#include<locale.h>

int main() {
	
	setlocale(LC_ALL,"");
   
    float celsius, fahrenheit;

    printf("Precisa converter celsius para fahrenheit? Vamos lá!\n");
    printf("Quantos graus celsius está ai?\n");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9/5) + 32;

    printf("%.2f Celsius é equivalent à %.2f Fahrenheit\n", celsius, fahrenheit);

    return 0;
}
