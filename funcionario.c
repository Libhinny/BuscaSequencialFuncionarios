#include "funcionario.h"

typedef struct funcionario
{

    char nome[100];
    char cargo[50];
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

void funcionario_salva( Funcionario* funcionario)
{

    // Abrir/criar o arquivo de saida para escrita (a)
    FILE*fp = fopen("saida.txt", "a");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
   
    fprintf(fp, " %s\t%s\t%d\n", funcionario->nome, funcionario->cargo, funcionario->documento);
    fclose(fp);
}


void lerarquivo(FILE *fp, Funcionario * funcionario[], int * count_fun){
    char linha [100];
    Funcionario auxiliar;
    while(fgets (linha, 100, fp) != NULL){
        sscanf(linha, "%s\t%s\t%d", auxiliar.nome, auxiliar.cargo, &auxiliar.documento); 

        funcionario[*count_fun] = criarFuncionario (auxiliar.nome, auxiliar.cargo, auxiliar.documento);
        (*count_fun)++;  
     
    }
}

 Funcionario *buscaLinearnome ( int count_fun , Funcionario * funcionario[], char * nome ){

    int i;

    for (i = 0; i < count_fun; i++) {
        if (strcmp(funcionario[i]->nome, nome) == 0) {
            return funcionario[i];
        }
    }
    return NULL; 
} 

Funcionario *buscaLineardocumento(int count_fun, Funcionario * funcionario[], int  documento) {
   
    int i;
    for (i = 0; i < count_fun; i++) {
        if (funcionario[i]->documento == documento) {
            return funcionario[i];
        }
    }
    return NULL;
} 

void libera_funcionario (Funcionario * funcionarios){
    free (funcionarios);
}
