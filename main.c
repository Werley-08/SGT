#include <stdio.h>

#include "funcoes.h"


int main(){

    int cadastros = 0;

    cadastros = lerDados(cadastros);

    while(1){

    printf("\n\n+=======================================================================================================================+\n");

    printf("|1 - Adicionar tarefa                                                                                                   |\n");
    printf("|2 - Remover tarefa                                                                                                     |\n");
    printf("|3 - Visualizar todas as tarefas                                                                                        |\n");
    printf("|4 - Pesquisar tarefas                                                                                                  |\n");
    printf("|5 - Atualizar dados de tarefas                                                                                         |\n");
    printf("|6 - Encerrar Programa                                                                                                  |\n");

    printf("+=======================================================================================================================+\n");

    fflush(stdin);
    printf("Digite um dos comandos acima >> ");

    int comando = 0;

    scanf("%d", &comando);

    switch (comando){

    // Adicionar 

    case 1 :

    Cadastro(cadastros);

    cadastros++;

    break;

    // Remover

    case 2 :

    cadastros = Remover(cadastros);

    break;

    // Visualizar

    case 3 : 

    Visualizar(cadastros);

    break;

    // Pesquisar

    case 4 :

    Pesquisar(cadastros);

    break;

    // Atualizar

    case 5 :

    Atualizar(cadastros);

    break;

    // Encerrar

    case 6 :

        salvarDados(cadastros);

        printf("Programa Encerrado");

        return 0;

        break;

     // Erro
    
    default :

        printf("Comando Invalido!\n");

        break;
    }

    }

    return 0;

}