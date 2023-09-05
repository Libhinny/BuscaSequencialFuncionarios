/*Bibliotecas utilizadas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h> // Para usar a função isalpha



/* Struct */
typedef struct funcionario Funcionario;


/*Função para cadastra um novo arquivo funcionario, alocando memoria*/
Funcionario * criarFuncionario (char * nome, char * cargo,   long long int documento);

/* Guardar os dados estruturados no arquivo*/
void funcionario_salva ( Funcionario *funcionario);

/*Função para ler arquivos*/
void lerarquivo(FILE *fp, Funcionario * funcionarios[], int * count_fun);

/* Funçao para buscar funcionario por documento*/
Funcionario *buscaLineardocumento(int count_fun, Funcionario * funcionario[],   long long int documento);

/*Função para buscar funcionario por nome*/
Funcionario *buscaLinearnome (int  count_fun, Funcionario * funcionario[], char * nome );

/*Função para atualizar o arquivo "saida.txt"*/
void atualizarArquivo(Funcionario *funcionario[], int count_fun);

/* FUnçao para liberar memoria alocada*/
void funcionario_libera (Funcionario ** fun, FILE * fp);


