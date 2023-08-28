#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

typedef struct funcionario
{

    char nome[51];
    char cargo[11];
    int documento;

} Funcionario;


Funcionario *criarFuncionario(char *nome, char *cargo, int documento)
{
    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));

    if (funcionario == NULL)
    {
        exit(1);
    }

    strcpy(funcionario->nome, nome);
    strcpy(funcionario->cargo, cargo);
    funcionario->documento = documento;

    return funcionario;
}

void funcionario_salva(FILE *fp, Funcionario *funcionario)
{

    // Abrir/criar o arquivo de saida para escrita (w)
    fp = fopen("saida_q3.txt", "w");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

   

        fprintf(fp, "Funcionario\tDocumento\tCargo\t\n%s\t%d\t%s", funcionario->nome, funcionario->documento, funcionario->cargo);

}