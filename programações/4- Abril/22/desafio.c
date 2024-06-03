#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char cpf[12];
    char nomeCompleto[100];
    char telefone[15];
} Paciente;

typedef struct {
    int dia, mes, ano;
    int hora, minuto;
    Paciente paciente;
    char nomeAtendente[50];
} Consulta;

Consulta consultas[100];
int numConsultas = 0;

void cadastrarPaciente(Consulta *consulta) {
    printf("Digite o CPF do paciente: ");
    scanf("%11s", consulta->paciente.cpf);
    
    printf("Digite o nome completo do paciente: ");
    getchar(); 
    fgets(consulta->paciente.nomeCompleto, sizeof(consulta->paciente.nomeCompleto), stdin);
    consulta->paciente.nomeCompleto[strcspn(consulta->paciente.nomeCompleto, "\n")] = 0;
    
    printf("Digite o telefone do paciente: ");
    scanf("%14s", consulta->paciente.telefone);
}

int verificarPacienteCadastrado(const char *cpf) {
    for (int i = 0; i < numConsultas; i++) {
        if (strcmp(consultas[i].paciente.cpf, cpf) == 0) {
            return 1; 
        }
    }
    return 0;
}

void cadastrarConsulta() {
    Consulta novaConsulta;
    
    printf("Digite o CPF do paciente: ");
    scanf("%11s", novaConsulta.paciente.cpf);
    
    if (!verificarPacienteCadastrado(novaConsulta.paciente.cpf)) {
        printf("Paciente não cadastrado. Por favor, cadastre o paciente.\n");
        cadastrarPaciente(&novaConsulta);
    }
    
    printf("Digite a data da consulta (dd mm aaaa): ");
    scanf("%d %d %d", &novaConsulta.dia, &novaConsulta.mes, &novaConsulta.ano);
    
    printf("Digite a hora da consulta (hh mm): ");
    scanf("%d %d", &novaConsulta.hora, &novaConsulta.minuto);
    
    printf("Digite o nome do atendente: ");
    getchar(); 
    fgets(novaConsulta.nomeAtendente, sizeof(novaConsulta.nomeAtendente), stdin);
    novaConsulta.nomeAtendente[strcspn(novaConsulta.nomeAtendente, "\n")] = 0;
    
    consultas[numConsultas] = novaConsulta;
    numConsultas++;
}


void alterarConsulta() {
    char cpf[12];
    int i;
    printf("Digite o CPF do paciente: ");
    scanf("%s", cpf);
    for (i = 0; i < numConsultas; i++) {
        if (strcmp(consultas[i].paciente.cpf, cpf) == 0) {
            printf("Digite a nova data da consulta (dd mm aaaa): ");
            scanf("%d %d %d", &consultas[i].dia, &consultas[i].mes, &consultas[i].ano);
            printf("Digite a nova hora da consulta (hh mm): ");
            scanf("%d %d", &consultas[i].hora, &consultas[i].minuto);
            break;
        }
    }
}


void cancelarConsulta() {
    char cpf[12];
    int i, encontrado = 0;
    printf("Digite o CPF do paciente: ");
    scanf("%s", cpf);
    for (i = 0; i < numConsultas; i++) {
        if (strcmp(consultas[i].paciente.cpf, cpf) == 0) {
            encontrado = 1;
            printf("Consulta encontrada. Deseja cancelar? (s/n): ");
            char resposta;
            scanf(" %c", &resposta);
            if (resposta == 's' || resposta == 'S') {
                int j = i;
                while (j < numConsultas - 1) {
                    consultas[j] = consultas[j + 1];
                    j++;
                }
                numConsultas--;
                printf("Consulta cancelada com sucesso.\n");
            } else {
                printf("Cancelamento cancelado.\n");
            }
            break;
        }
    }
    if (!encontrado) {
        printf("CPF não encontrado.\n");
    }
}

void exibirConsultas() {
    int i;
    printf("\n*** CONSULTAS CADASTRADAS ***\n");
    for (i = 0; i < numConsultas; i++) {
        printf("Consulta %d:\n", i+1);
        printf("CPF: %s\n", consultas[i].paciente.cpf);
        printf("Nome Completo: %s\n", consultas[i].paciente.nomeCompleto);
        printf("Telefone: %s\n", consultas[i].paciente.telefone);
        printf("Data: %d/%d/%d\n", consultas[i].dia, consultas[i].mes, consultas[i].ano);
        printf("Hora: %d:%d\n", consultas[i].hora, consultas[i].minuto);
        printf("Atendente: %s\n", consultas[i].nomeAtendente);
        printf("\n");
    }
}

void exibirMenu() {
    setlocale(LC_ALL, "");
    
    int opcao;
    do {
        printf("\n*** MENU ***\n");
        printf("1 - Cadastrar paciente e marcar consulta\n");
        printf("2 - Alterar data e horario da consulta\n");
        printf("3 - Cancelar consulta\n");
        printf("4 - Exibir consultas cadastradas\n");
        printf("5 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarConsulta();
                break;
            case 2:
                alterarConsulta();
                break;
            case 3:
                cancelarConsulta();
                break;
            case 4:
                exibirConsultas();
                break;
        }
    } while (opcao!= 5);
}
int main() {
    exibirMenu();
    return 0;
}


