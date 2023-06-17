#include <stdio.h>

#include "funcoes.h"

int main(){

    int cadastros = 0;

    while(1){

    printf("==============================================\n");

    printf("1 - Adicionar tarefa\n");
    printf("2 - Remover tarefa\n");
    printf("3 - Visualizar todas as tarefas\n");
    printf("4 - Pesquisar tarefas\n");
    printf("5 - Atualizar dados de tarefas\n");
    printf("6 - Encerrar Programa.\n");

    printf("==============================================\n");

    printf("Digite um dos comandos acima >> ");

    int comando = 0;

    scanf("%d", &comando);

    switch (comando){

    // Adicionar 

    case 1 :

    cadastro(cadastros);

    cadastros++;

    break;

    // Remover

    case 2 :

    break;

    // Visualizar

    case 3 : 

    break;

    // Pesquisar

    case 4 :

    break;

    // Atualizar

    case 5 :

    break;

    // Encerrar

    case 6 :

        printf("Programa Encerrado");

        return 0;

        break;

     // Erro
    
    default:

        printf("Comando Inválido!");

        break;
    }

    }

    return 0;

}