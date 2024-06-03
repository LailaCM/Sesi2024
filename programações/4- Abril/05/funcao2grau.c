#include<stdio.h>
#include<locale.h>
#include<math.h>

//Declarando as 3 fun��es que retornam o Delta, x' e x''
float delta(int a, int b, int c){
    return (b * b) - (4.0 * a * c);
}

float xLinha(float delta, int a, int b){
    return (-b + sqrt(delta))/(2.0 * a);
}

float xDuasLinhas(float delta, int a, int b){
    return (-b - sqrt(delta))/(2.0 * a);
}

int main(){
	
    setlocale(LC_ALL,"");
    
    int a, b, c;
    float d, x1, x2;
    
    printf("Digite as vari�veis a, b e c de uma express�o de 2� grau:");
    scanf("%d %d %d", &a, &b, &c);
    
    //Chamado a fun��o
    d = delta(a, b, c);
    printf("O delta � %.1f\n", d);
    
    if(d > 0){
        x1 = xLinha(d, a, b);
        x2 = xDuasLinhas(d, a, b);
        printf("x'=%.1f\nx''=%.1f\n", x1, x2);
        
    }else if(d == 0){
        printf("A express�o possui uma raiz real, x=%.1f\n", -b/(2.0*a));
        
    }else{
        printf("A express�o n�o possui raizes reais");
    }
    
    return 0;
}
