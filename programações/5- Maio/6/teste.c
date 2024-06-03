#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
	char investimento[50];
    char dataInicio[10];
    float valorInvestido;
    float precoInicial;
    float valorAtual;
    int concluido;
}Infos;

Infos investimentos[100];
int numInvestimentos = 0;

void login(){
	char usuario[50];
	char senha[50];
	printf("LOGIN:  ");
	scanf("%s", usuario);
	printf("SENHA:  ");
	scanf("%s", senha);
	if(strcmp(usuario, "jp") == 0 && strcmp(senha, "123") == 0){
		printf("Login realizado com sucesso.\n");
	} else{
		printf("Usuário ou senha incorretos. Tente novamente.\n");
		login();
	}
}

void menu(){
	int opcao;
	printf("______________\n");
	printf("|                  MENU:               |\n");
	printf("|1. ..................Novo investimento|\n");
    printf("|2. ..............Concluir investimento|\n");
    printf("|3. ......Listar todos os Investimentos|\n");
    printf("|4. ..............Listar Carteira Ativa|\n");
    printf("|5. ...............................Sair|\n");
    scanf("%d", &opcao);
    switch (opcao){
    	case 1:
    		cadastrarInvestimento();
    		break;
    	case 2:
    		concluirInvestimento();
    		break;
    	case 3:
    		listarInvestimento();
    		break;
    	case 4:
    		listarCarteiraAtiva();
    		break;
    	case 5:
    		printf("Saindo do programa...\n");
    		exit(0);
    	default:
    		printf("Opção inválida. Tente novamente.\n");
    		menu();
    }
}

void cadastrarInvestimento(){
    Infos novoInvestimento;
    printf("Cadastrar Investimento:\n");
    printf("Investimento: ");
    scanf("%s", novoInvestimento.investimento);
    printf("Data Início: ");
    scanf("%s", novoInvestimento.dataInicio);
    printf("Valor Investido: ");
    scanf("%f", &novoInvestimento.valorInvestido);
    printf("Preço Entrada: ");
    scanf("%f", &novoInvestimento.precoInicial);
    novoInvestimento.concluido = 0;
    investimentos[numInvestimentos] = novoInvestimento;
    numInvestimentos++;
    printf("Número de ações: %.2f\n", novoInvestimento.valorInvestido / novoInvestimento.precoInicial);
    printf("Investimento cadastrado com sucesso!\n");
}


int main(){
	setlocale(LC_ALL, "");
	printf("| CARTEIRA DE INVESTIMENTOS |\n");
	login();
	menu();
	return 0;
}
