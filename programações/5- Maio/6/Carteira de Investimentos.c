#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define MAX_INVESTIMENTOS 100
#define MAX_USUARIOS 10
#define MAX_USUARIO 20
#define MAX_SENHA 20


// Estrutura para armazenar informa��es de um investimento
typedef struct {
    char investimento[50];
    char dataInicio[20];
    float valorInvestido;
    float precoEntrada;
    float metaGanho;
    float limitePerda;
    float valorAtual;
} Investimento;

typedef struct {
    char usuario[MAX_USUARIO];
    char senha[MAX_SENHA];
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int numUsuarios = 0;

// Prot�tipo da fun��o fazerlogin
bool fazerlogin();

// Fun��o para cadastrar um novo usu�rio
void cadastrarUsuario() {
    if (numUsuarios >= MAX_USUARIOS) {
        printf("Limite de usu�rios atingido.\n");
        return;
    }

    printf("Novo Cadastro:\n");
    printf("Usu�rio: ");
    scanf("%s", usuarios[numUsuarios].usuario);
    printf("Senha: ");
    scanf("%s", usuarios[numUsuarios].senha);

    numUsuarios++;
    printf("Usu�rio cadastrado com sucesso.\n");

    // Ap�s cadastrar um novo usu�rio, pedimos para fazer login novamente
    fazerlogin();
}

// Fun��o para autenticar o usu�rio
bool fazerlogin() {
    char usuario[MAX_USUARIO];
    char senha[MAX_SENHA];
    int i;

    printf("Login:\n");
    printf("Usu�rio: ");
    scanf("%s", usuario);
    printf("Senha: ");
    scanf("%s", senha);

    // Verificar se o nome de usu�rio e a senha s�o v�lidos
    for (i = 0; i < numUsuarios; i++) {
        if (strcmp(usuario, usuarios[i].usuario) == 0 && strcmp(senha, usuarios[i].senha) == 0) {
            printf("Login bem-sucedido!\n");
            return true;
        }
    }

    // Se n�o encontrou o usu�rio, pergunte se deseja cadastrar um novo
    char resposta;
    printf("Nome de usu�rio ou senha incorretos. Deseja cadastrar um novo usu�rio? (S/N): ");
    scanf(" %c", &resposta); // Note o espa�o antes de %c para consumir o caractere de nova linha
    if (resposta == 'S' || resposta == 's') {
        cadastrarUsuario();
    } else if (resposta == 'N' || resposta == 'n') {
        printf("Deseja tentar novamente? (S/N): ");
        scanf(" %c", &resposta);
        if (resposta == 'S' || resposta == 's') {
            fazerlogin();
        } else {
            return false;
        }
    }
}

// Fun��o para exibir o menu e solicitar a escolha do usu�rio
int exibirMenu() {
    int escolha;
    printf("\n--- MENU ---\n");
    printf("1. Novo investimento\n");
    printf("2. Concluir investimento\n");
    printf("3. Listar todos os investimentos\n");
    printf("4. Listar carteira ativa\n");
    printf("5. Sair\n");
    printf("Escolha uma op��o: ");
    scanf("%d", &escolha);
    return escolha;
}

// Fun��o para cadastrar um novo investimento
void cadastrarInvestimento(Investimento investimentos[], int *numInvestimentos) {
    if (*numInvestimentos >= MAX_INVESTIMENTOS) {
        printf("Limite de investimentos atingido.\n");
        return;
    }

    Investimento novoInvestimento;
    printf("Nome do investimento: ");
    scanf(" %[^\n]s", novoInvestimento.investimento);

    printf("Data de in�cio (DD/MM/AAAA): ");
    scanf(" %[^\n]s", novoInvestimento.dataInicio);

    printf("Valor investido: ");
    scanf("%f", &novoInvestimento.valorInvestido);

    printf("Pre�o de entrada: ");
    scanf("%f", &novoInvestimento.precoEntrada);

    printf("Meta de ganho: ");
    scanf("%f", &novoInvestimento.metaGanho);

    printf("Limite de perda: ");
    scanf("%f", &novoInvestimento.limitePerda);

    novoInvestimento.valorAtual = novoInvestimento.valorInvestido;
    
    investimentos[*numInvestimentos] = novoInvestimento;
    (*numInvestimentos)++;
    printf("Investimento cadastrado com sucesso.\n");
}

// Fun��o para listar todos os investimentos
void listarInvestimentos(Investimento investimentos[], int numInvestimentos) {
    printf("\n--- TODOS OS INVESTIMENTOS ---\n");
    float ganhosTotais = 0;
    float perdasTotais = 0;

    int i; // Declare a vari�vel 'i' fora do loop
    for (i = 0; i < numInvestimentos; i++) {
        // Solicitar e atualizar o valor atual do investimento
        printf("Digite o pre�o atual do investimento %s: ", investimentos[i].investimento);
        scanf("%f", &investimentos[i].valorAtual);
        getchar(); // Consumir o caractere de nova linha

        printf("Investimento: %s\n", investimentos[i].investimento);
        printf("Data de in�cio: %s\n", investimentos[i].dataInicio);
        printf("Valor investido: %.2f\n", investimentos[i].valorInvestido);
        printf("Pre�o de entrada: %.2f\n", investimentos[i].precoEntrada);
        printf("Meta de ganho: %.2f\n", investimentos[i].metaGanho);
        printf("Limite de perda: %.2f\n", investimentos[i].limitePerda);

        // Calcular o ganho ou perda
        float lucro =  (investimentos[i].valorInvestido/investimentos[i].precoEntrada)* investimentos[i].valorAtual;
        lucro = lucro - investimentos[i].valorInvestido;
        
        if (lucro >= 0) {
            printf("Ganho: %.2f\n", lucro);
            ganhosTotais += lucro;
        } else {
            printf("Perda: %.2f\n", lucro);
            perdasTotais += lucro;
        }
        printf("----------------------\n");
    }

    // Exibir os ganhos e perdas totais
    printf("Ganhos totais: %.2f\n", ganhosTotais);
    printf("Perdas totais: %.2f\n", perdasTotais);
}

// Fun��o para concluir um investimento
void concluirInvestimento(Investimento investimentos[], int numInvestimentos) {
    int indice;
    int i;
    printf("\n--- CONCLUIR INVESTIMENTO ---\n");
    printf("Digite o �ndice do investimento a concluir (investimento 1, investimento 2, ...): ");
    scanf("%d", &indice);
    getchar(); // consume newline character

    // Verificar se o �ndice est� dentro dos limites
    if (indice >= 1 && indice <= numInvestimentos) {
        int investimentoIndex = indice - 1; // �ndice do investimento no array
        printf("Digite o pre�o atual do investimento %d (%s): ", indice, investimentos[investimentoIndex].investimento);
        scanf("%f", &investimentos[investimentoIndex].valorAtual);
        getchar(); // consume newline character

        // Calcular o lucro ou preju�zo
        float lucro =  (investimentos[i].valorInvestido/investimentos[i].precoEntrada)* investimentos[i].valorAtual;
        lucro = lucro - investimentos[i].valorInvestido;
        
        // Exibir o resultado
        printf("Lucro/Preju�zo do investimento %d (%s): %.2f\n", indice, investimentos[investimentoIndex].investimento, lucro);
        
        // Implementar a l�gica para concluir um investimento
        printf("Investimento %d conclu�do com sucesso.\n", indice);
    } else {
        printf("�ndice inv�lido.\n");
    }
}


// Fun��o para listar a carteira ativa
void listarCarteiraAtiva(Investimento investimentos[], int numInvestimentos) {
    printf("Carteira ativa:\n");
    int i; // Declare a vari�vel 'i' fora do loop
    for (i = 0; i < numInvestimentos; i++) {
        // Verifique se o investimento est� ativo
        if (investimentos[i].valorAtual > 0) {
            printf("- Investimento: %s\n", investimentos[i].investimento);
        }
    }
}

void mostrarValorAtual(Investimento investimentos[], int numInvestimentos) {
    printf("\n--- VALOR ATUAL DOS INVESTIMENTOS ---\n");
    int i; // Declare a vari�vel 'i' fora do loop
    for (i = 0; i < numInvestimentos; i++) {
        printf("%d. Investimento: %s\n", i+1, investimentos[i].investimento);
        printf("   Valor atual: %.2f\n", investimentos[i].valorAtual);
    }
}

// Fun��o principal
int main() {
    setlocale(LC_ALL, "");
    
    Investimento investimentos[MAX_INVESTIMENTOS];
    int numInvestimentos = 0;
    int opcao;

    if (!fazerlogin()) {
        // Se o login n�o for bem-sucedido, saia do programa
        return 0;
    }

    do {
        opcao = exibirMenu();
        switch(opcao) {
            case 1:
                cadastrarInvestimento(investimentos, &numInvestimentos);
                break;
            case 2:
                mostrarValorAtual(investimentos, numInvestimentos); // Mostrar valor atual
                concluirInvestimento(investimentos, numInvestimentos);
                break;
            case 3:
                listarInvestimentos(investimentos, numInvestimentos);
                break;
            case 4:
                listarCarteiraAtiva(investimentos, numInvestimentos);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Op��o inv�lida.\n");
        }
    } while (opcao != 5);

    return 0;
}
