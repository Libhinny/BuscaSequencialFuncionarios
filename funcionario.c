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

/*
int buscaLinear(int *vetor, int fun, int valor) {
    int i;
    for (i = 0; i < fun; i++) {
        if (vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}


void aluno_ordena(int fun, Funcionario **v)
{

    int i;
    for (i = 0; i < fun; i++)
    {

        if (v[i]->nome[0] < v[i + 1]->nome[0])
        {
        
        }
    }
}
*/
void libera_funcionario (Funcionario * funcionarios){
    free (funcionarios);
}