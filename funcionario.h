/*Biblioteca*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Struct */
typedef struct funcionario Funcionario;


/*Função funcionario
Cadastra um novo arquivo funcionario, alocando memoria*/

Funcionario * criarFuncionario (char * nome, char * cargo, int documento);

/* FUnçao para liberar memoria alocada*/

void funcionario_libera (Funcionario ** fun, FILE * fp);

/* Função ordena 
utilizada para ordenar os funcionarios por ordem alfabética*/

void funcionario_ordena (Funcionario ** fun, int count);

/* Guardar os dados estruturados no arquivo*/
void funcionario_salva ( Funcionario *funcionario);

/*Função para ler arquivos*/
void lerarquivo(FILE *fp, Funcionario * funcionarios[], int * count_fun);

/* Funçao para buscar funcionario por documento*/

Funcionario *buscaLineardocumento(int count_fun, Funcionario * funcionario[], int documento);

/*Função para buscar funcionario por nome*/

Funcionario *buscaLinearnome (int  count_fun, Funcionario * funcionario[], char * nome );



