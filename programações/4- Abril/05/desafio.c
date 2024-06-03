#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


float calcular_imc(float peso, float altura) {
    return peso / (altura * altura);
}

float diagnosticar_imc(float imc, char sexo) {
    printf("Classificação IMC: ");
    if (imc < 18.5)
        printf("Abaixo do peso\n");
    else if (imc < 25)
        printf("Peso normal\n");
    else if (imc < 30)
        printf("Sobrepeso\n");
    else if (imc < 35)
        printf("Obesidade grau I\n");
    else if (imc < 40)
        printf("Obesidade grau II\n");
    else
        printf("Obesidade grau III\n");

    if (sexo == 'M') {
        if (imc < 18.5)
            printf("Recomendação: Exercícios de Hipertrofia\n");
        else if (imc < 25)
            printf("Recomendação: Exercícios de moderados e leves\n");
        else if (imc < 30)
            printf("Recomendação: Exercícios Aeróbicos e de Hipertrofia moderados\n");
        else if (imc < 35)
            printf("Recomendação: Exercícios Aeróbicos e de Hipertrofia intensos\n");
        else
            printf("Recomendação: Procurar recomendações médicas de um Endocrinologista\n");
    } 
	
	else {
        if (imc < 18.5)
            printf("Recomendação: Exercícios de Calistenia\n");
        else if (imc < 25)
            printf("Recomendação: Exercícios de moderados e leves\n");
        else if (imc < 30)
            printf("Recomendação: Exercícios aeróbicos e de Calistenia moderados\n");
        else if (imc < 35)
            printf("Recomendação: Exercícios Aeróbicos e de Calistenia intensos\n");
        else
            printf("Recomendação: Procurar recomendações médicas de um Endocrinologista\n");
    }
}

int main() {
	setlocale(LC_ALL,"");
    char nome[100];
    char sexo;
    float imc, peso,altura;
    int opcao;

    printf("Digite o nome completo do paciente: ");
    gets(nome);

    printf("Digite o peso do paciente em kg: ");
    scanf("%f", &peso);

    printf("Digite a altura do paciente em metros: ");
    scanf("%f", &altura);

    printf("Digite o sexo do paciente (M para masculino, F para feminino): ");
    scanf(" %c", &sexo);

    do {
        printf("\nMENU:\n");
        printf("1. Calcular IMC\n");
        printf("2. Diagnosticar IMC\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imc = calcular_imc(peso, altura);
                printf("IMC: %.2f\n", imc);
                break;
            case 2:
                imc = calcular_imc(peso, altura);
                diagnosticar_imc(imc, sexo);
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 3);

    return 0;
}

