#include <stdio.h>
#include <stdlib.h>

#include "funcoes.h"
#include "struct.h"

// Para criar o executável gcc .\main.c .\funcoes.c -o a.exe
// Para rodar .\a.exe

int main(){

    //Alocação de Memória
    struct Tarefas *estrutura = malloc(20 * sizeof(struct Tarefas));

    int cadastros = 0;

    cadastros = lerDados(cadastros, estrutura);

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

    Cadastro(cadastros, estrutura);

    cadastros++;

    break;

    // Remover

    case 2 :

    cadastros = Remover(cadastros, estrutura);

    break;

    // Visualizar

    case 3 : 

    Visualizar(cadastros, estrutura);

    break;

    // Pesquisar

    case 4 :

    Pesquisar(cadastros, estrutura);

    break;

    // Atualizar

    case 5 :

    Atualizar(cadastros, estrutura);

    break;

    // Encerrar

    case 6 :

        salvarDados(cadastros, estrutura);

        printf("Programa Encerrado");

        return 0;

        break;

     // Erro
    
    default :

        printf("\nComando Invalido!\n");

        break;
    }

    }

    return 0;

}