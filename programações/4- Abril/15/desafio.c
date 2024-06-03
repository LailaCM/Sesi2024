#include <stdio.h>
#include <locale.h>
#include <string.h>

float INSS(float salario) {
    if (salario<=1412) {
        return (salario * 0.075);
    } else if (salario <= 2666.68) {
        return (salario * 0.09 - 21.18);
    } else if (salario <= 4000.03) {
        return (salario * 0.12 - 101.18);
    } else if (salario <= 7786.02) {
        return (salario * 0.14 - 181.18 );
    } else {
        return (7786.02 * 0.14 - 181.18);
    }
}

float IRRF(float salario, float INSS) {
	
	salario = salario - INSS;
	
    if (salario<=2259.20) {
        return salario;
    } else if (salario <= 2826.65) {
        return (salario * 0.075 - 169.44);
    } else if (salario <= 3751.05) {
        return (salario * 0.15 - 381.44);
    } else if (salario <= 4664.68) {
        return (salario * 0.225 - 662.77);
    } else{
        return (salario * 0.275 - 896);
    }  	
}

float salliq(float INSS, float IRRF, float salario) {
    return salario - IRRF - INSS;
}

int main() {
    setlocale(LC_ALL, "");

    char nome[100];
    float salario, imposto;
    int escolha;

    printf("Digite seu nome: ");
    gets(nome);

    printf("Digite seu salário: ");
    scanf("%f", &salario);
	
	do{
	
    printf("\nSelecione:\n");
    printf("1. FGTS\n");
    printf("2. INSS\n");
    printf("3. IRRF\n");
    printf("4. Salário líquido\n");
    printf("5. Sair\n");

    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
        	imposto = salario * 0.08;
            printf("FGTS: %.2f\n", imposto);
            break;

        case 2:
        	imposto = INSS(salario);
            printf("INSS: %.2f\n", imposto);
            break;

        case 3:
        	imposto = IRRF(salario, INSS(salario));
            printf("IRRF: %.2f\n", imposto);
            break;

        case 4:
        	imposto=salliq(INSS(salario), IRRF(salario,INSS(salario)), salario);
            printf("Salário líquido: %.2f\n", imposto);
            break;

        case 5:
            printf("Saindo... Obrigado por confiar em nosso site!\n");
            break;

        default:
            printf("Opção inválida, por favor escolha corretamente.\n");
            break;
    	}
	} while (escolha!=5);

    return 0;
}

