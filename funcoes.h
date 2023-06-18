#include "struct.h"

void Cadastro(int cadastros){

    if(cadastros >= 20){

        printf("Tamanho Máximo Excedido >> ");

    }else{

    fflush(stdin);
    printf("\nDigite a tarefa que sera adicionada >> ");
    scanf("%[^\n]", estrutura[cadastros].tarefa);

    // Verifica se o ID ja está cadastrado

    int verifica = 0;

    do{

    fflush(stdin);
    printf("\nDigite um ID de inteiros para a tarefa >> ");
    scanf("%d", &estrutura[cadastros].id);

    verifica = 0;

    for(int i = 0; i < cadastros; i++){

        if(estrutura[cadastros].id == estrutura[i].id){

            verifica = 1;

        }

    }

    if(verifica == 1){

        printf("\nID Ja existente!");

    }

    }while(verifica == 1);

    fflush(stdin);
    printf("\nDigite a prioridade da tarefa (baixa, media, alta) >> ");
    scanf("%[^\n]", estrutura[cadastros].prioridade);

    fflush(stdin);
    printf("\nDigite uma breve observacao/descricao para a tarefa >> ");
    scanf("%[^\n]", estrutura[cadastros].observacoes);

    printf("\nDados Cadastrados com Sucesso!!\n");

    }

    return;

}

// void Remover(int cadastros);

void Visualizar(int cadastros){

    for(int i = 0; i < cadastros; i++){

        if(i == 0){

            printf("\n       ID       ||            Tarefa            ||       Prioridade       ||                 Descricao            \n");

            printf("=========================================================================================================================\n");

            printf("     %d     ||          %s          ||     %s     ||               %s          \n", estrutura[i].id, estrutura[i].tarefa, estrutura[i].prioridade, estrutura[i].observacoes);

        }else{

            printf("     %d     ||          %s          ||     %s     ||               %s          \n", estrutura[i].id, estrutura[i].tarefa, estrutura[i].prioridade, estrutura[i].observacoes);

        }

    }

    return;

}

 void Pesquisar(int cadastros){

    int id = 0;

    fflush(stdin);
    printf("\nDigite o ID da tarefa que voce deseja visualizar >> ");
    scanf("%d", &id);

    int verifica = 0, indice = 0;

    for(int i = 0; i < cadastros; i++){

        if(id == estrutura[i].id){ // Verifica se o ID existe, e qual o indice do vetor referênte aquele ID

            verifica = 1;

            indice = i;

        }

    }

    if(verifica == 1){

        printf("\nOs dados referentes a esse ID sao :  \n");

        printf("\n       ID       ||            Tarefa            ||       Prioridade       ||                 Descricao            \n");

        printf("=========================================================================================================================\n");

        printf("     %d     ||          %s          ||     %s     ||               %s          \n", estrutura[indice].id, estrutura[indice].tarefa, estrutura[indice].prioridade, estrutura[indice].observacoes);

        }else{

        printf("\nID invalido!\n");   

        }


 }

 void Atualizar(int cadastros){

    int id = 0;

    fflush(stdin);
    printf("\nDigite o ID da tarefa que voce deseja atualizar >> ");
    scanf("%d", &id);

    int verifica = 0, indice = 0;

    for(int i = 0; i < cadastros; i++){

        if(id == estrutura[i].id){ // Verifica se o ID existe, e qual o indice do vetor referênte aquele ID

            verifica = 1;

            indice = i;

        }

    }

    if(verifica == 1){

    printf("\nOs dados atuais sao :  \n");

    printf("\n       ID       ||            Tarefa            ||       Prioridade       ||                 Descricao            \n");

    printf("=========================================================================================================================\n");

    printf("     %d     ||          %s          ||     %s     ||               %s          \n", estrutura[indice].id, estrutura[indice].tarefa, estrutura[indice].prioridade, estrutura[indice].observacoes);

    fflush(stdin);
    printf("\nDigite o novo valor de tarefa >> ");
    scanf("%[^\n]", estrutura[indice].tarefa);

    fflush(stdin);
    printf("\nDigite o novo valor de ID >> ");
    scanf("%d", &estrutura[indice].id);

    fflush(stdin);
    printf("\nDigite a nova prioridade da tarefa >> ");
    scanf("%[^\n]", estrutura[indice].prioridade);

    fflush(stdin);
    printf("\nDigite a nova observacao para tarefa >> ");
    scanf("%[^\n]", estrutura[indice].observacoes);

    printf("\nDados atualizados com sucesso!!\n");

    }else{

      printf("\nID invalido!\n");   

    }
    
    return;

 }