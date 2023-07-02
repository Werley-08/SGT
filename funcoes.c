#ifndef FUNCOES_C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "funcoes.h"

// Funções Básicas

void Cadastro(int cadastros, struct Tarefas *estrutura){

    if(cadastros >= 20){

        printf("Tamanho Máximo Excedido >> ");

    }else{

    fflush(stdin);
    printf("\nDigite a tarefa que sera adicionada >> ");
    scanf(" %[^\n]", (estrutura + cadastros)->tarefa);

    // Verifica se o ID ja está cadastrado

    int verifica = 0;

    do{

    fflush(stdin);
    printf("\nDigite um ID de inteiros para a tarefa >> ");
    scanf("%d", &(estrutura + cadastros)->id);

    verifica = 0;

    for(int i = 0; i < cadastros; i++){

        if((estrutura + cadastros)->id == (estrutura + i)->id){

            verifica = 1;

        }

    }

    if(verifica == 1){

        printf("\nID Ja existente!");

    }

    }while(verifica == 1);

    fflush(stdin);
    printf("\nDigite a prioridade da tarefa (baixa, media, alta) >> ");
    scanf(" %[^\n]", (estrutura + cadastros)->prioridade);

    fflush(stdin);
    printf("\nDigite uma breve observacao/descricao para a tarefa >> ");
    scanf(" %[^\n]", (estrutura + cadastros)->observacoes);

    printf("\nDados Cadastrados com Sucesso!!\n");

    }

    return;

}

int Remover(int cadastros, struct Tarefas *estrutura){

    int id = 0, verifica = 0, indice = 0;

    fflush(stdin);
    printf("\nDigite o ID da tarefa que voce deseja deletar >> ");
    scanf("%d", &id);

    for(int i = 0; i < cadastros; i++){

        if(id == (estrutura + i)->id){ // Verifica se o ID existe, e qual o indice do vetor referênte aquele ID

            verifica = 1;

            indice = i;

        }

    }

    if(verifica == 1){

        for(int i = indice; i < cadastros; i++){
                
                strcpy((estrutura + i)->tarefa, (estrutura + i + 1)->tarefa);
                (estrutura + i)->id = (estrutura + i + 1)->id;
                strcpy((estrutura + i)->prioridade, (estrutura + i + 1)->prioridade);
                strcpy((estrutura + i)->observacoes, (estrutura + i + 1)->observacoes);

                if(i == cadastros - 1){

                    printf("\nDados Deletados com Sucesso!");

                }

            }

            cadastros--;

        }else{

        printf("\nID nao encontrado!\n");

    }

    return cadastros;

}

void Visualizar(int cadastros, struct Tarefas *estrutura){

    for(int i = 0; i < cadastros; i++){

        if(i == 0){

            printf("\n\n+=======================================================================================================================+");

            printf("\n|       ID       ||            Tarefa            ||       Prioridade       ||                 Descricao                 |\n");

            printf("=========================================================================================================================\n");

            printf("|     %d     ||          %s          ||     %s     ||               %s          |\n", (estrutura + i)->id, (estrutura + i)->tarefa, (estrutura + i)->prioridade, (estrutura + i)->observacoes);

        }else{

            printf("|     %d     ||          %s          ||     %s     ||               %s          |\n", (estrutura + i)->id, (estrutura + i)->tarefa, (estrutura + i)->prioridade, (estrutura + i)->observacoes);

        }

    }

    return;

}

void Pesquisar(int cadastros, struct Tarefas *estrutura){

    int id = 0;

    fflush(stdin);
    printf("\nDigite o ID da tarefa que voce deseja visualizar >> ");
    scanf("%d", &id);

    int verifica = 0, indice = 0;

    for(int i = 0; i < cadastros; i++){

        if(id == (estrutura + i)->id){ // Verifica se o ID existe, e qual o indice do vetor referênte aquele ID

            verifica = 1;

            indice = i;

        }

    }

    if(verifica == 1){

        printf("\nOs dados referentes a esse ID sao :  \n");

        printf("\n\n+=======================================================================================================================+");

        printf("\n|       ID       ||            Tarefa            ||       Prioridade       ||                 Descricao                 |\n");

        printf("=========================================================================================================================\n");

        printf("|     %d     ||          %s          ||     %s     ||               %s          |\n", (estrutura + indice)->id, (estrutura + indice)->tarefa, (estrutura + indice)->prioridade, (estrutura + indice)->observacoes);

        }else{

        printf("\nID invalido!\n");   

        }


 }

void Atualizar(int cadastros, struct Tarefas *estrutura){

    int id = 0;

    fflush(stdin);
    printf("\nDigite o ID da tarefa que voce deseja atualizar >> ");
    scanf("%d", &id);

    int verifica = 0, indice = 0;

    for(int i = 0; i < cadastros; i++){

        if(id == (estrutura + i)->id){ // Verifica se o ID existe, e qual o indice do vetor referênte aquele ID

            verifica = 1;

            indice = i;

        }

    }

    if(verifica == 1){

        printf("\nOs dados atuais sao :  \n");

        printf("\n\n+=======================================================================================================================+");

        printf("\n|       ID       ||            Tarefa            ||       Prioridade       ||                 Descricao                 |\n");

        printf("=========================================================================================================================\n");

        printf("|     %d     ||          %s          ||     %s     ||               %s          |\n", (estrutura + indice)->id, (estrutura + indice)->tarefa, (estrutura + indice)->prioridade, (estrutura + indice)->observacoes);

    fflush(stdin);
    printf("\nDigite o novo valor de tarefa >> ");
    scanf(" %[^\n]", (estrutura + indice)->tarefa);

    fflush(stdin);
    printf("\nDigite o novo valor de ID >> ");
    scanf("%d", &(estrutura + indice)->id);

    fflush(stdin);
    printf("\nDigite a prioridade da tarefa (baixa, media, alta) >> ");
    scanf(" %[^\n]", (estrutura + indice)->prioridade);

    fflush(stdin);
    printf("\nDigite a nova observacao para tarefa >> ");
    scanf(" %[^\n]", (estrutura + indice)->observacoes);

    printf("\nDados atualizados com sucesso!!\n");

    }else{

      printf("\nID invalido!\n");   

    }
    
    return;

 }

// Persistência de Dados

int lerDados(int cadastros, struct Tarefas *estrutura){

    // Abrindo o arquivo para leitura
    FILE *arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL){

        printf("Erro ao abrir o arquivo\n");
    }

    // Lendo os arquivo da struct do arquivo

        fscanf(arquivo, "%d\n", &cadastros);

    for(int i = 0; i < cadastros; i++){

        fgets((estrutura + i)->tarefa, sizeof((estrutura + i)->tarefa), arquivo);
        (estrutura + i)->tarefa[strcspn((estrutura + i)->tarefa, "\n")] = '\0';

        fscanf(arquivo, "%d\n", &(estrutura + i)->id);

        fgets((estrutura + i)->prioridade, sizeof((estrutura + i)->prioridade), arquivo);
        (estrutura + i)->prioridade[strcspn((estrutura + i)->prioridade, "\n")] = '\0';

        fgets((estrutura + i)->observacoes, sizeof((estrutura + i)->observacoes), arquivo);
        (estrutura + i)->observacoes[strcspn((estrutura + i)->observacoes, "\n")] = '\0';

    }

    return cadastros;

}

void salvarDados(int cadastros, struct Tarefas *estrutura){

    // Abrindo o arquivo para escrita
    FILE *arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL) {

        printf("Erro ao abrir o arquivo\n");
        
    }

    // Escrevendo os arquivo da struct no arquivo

        fprintf(arquivo, "%d\n", cadastros);

    for(int i = 0; i < cadastros; i++){

        fprintf(arquivo, "%s\n", (estrutura + i)->tarefa);
        fprintf(arquivo, "%d\n", (estrutura + i)->id);
        fprintf(arquivo, "%s\n", (estrutura + i)->prioridade);
        fprintf(arquivo, "%s\n", (estrutura + i)->observacoes);

    }

    // Fechando o arquivo
    fclose(arquivo);
    free(estrutura);

    printf("arquivo salvos no arquivo 'dados.txt.'\n");

}

#endif