
/*Biblioteca*/
#include <stdio.h>




/* Struct */
typedef struct funcionario Funcionario


/*Função funcionario
Cadastra um novo arquivo funcionario, alocando memoria*/

Funcionario * criarFuncionario (char * nome, char * cargo, int documento);

/* FUnçao para liberar memoria alocada*/

void funcionario_libera (Funcionario ** fun, FILE * fp)

/* Função ordena 
utilizada para ordenar os funcionarios por ordem alfabética*/

void funcionario_ordena (Funcionario ** fun, int count);

/* Guardar os dados estruturados no arquivo*/
void funcionario_salva (Funcionario ** fun,  FILE * fp)




