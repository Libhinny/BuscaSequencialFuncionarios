#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#define fun 10


int main (void){


    int op, int documento, count_fun; 
    char nome[51], cargo[11];

    Funcionario ** funcionario = (Funcionario**) malloc (sizeof (Funcionario));

    FILE * dados_fun = fopen ("arquivo.txt", "rt") ;
    if (dados_fun == NULL){
        printf ("Não foi possivel abrir o arquivo .\n");
        exit (-1);
    }
    
    switch (op){
        case 1: 

        printf ("Digite o nome do funcionario ao qual deseja cadastrar: \n");
        scanf("%50[^\n]", nome);

        printf("Diite o cargo do funcionario ao qual deseja cadastrar: \n");
        scanf ("%10[^\n]", cargo);
        
        printf("Digite o N° de um documento de identificação: \n");
        scanf("%d", &documento);

        if (count_fun < fun){
            funcionario[count_fun] = fun_cadastra (nome, cargo, documento);
            count_fun ++;

        }else {
            printf("Quantidade maxima de funcionario foi atingido! ");

        }
        break;

        case 2: 
        
        break;

        case 3: 

        printf ("Finalizar o programa");
        
        break;

        default:

        printf("Tente novamente, opcao fornecida está incorreta! \n");


    }
}


