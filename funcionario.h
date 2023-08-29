
/*Biblioteca*/
#include <stdio.h>




/* Struct */
typedef struct funcionario Funcionario


/* Vai pedir para usuario inserir nome, cargo e documento */


Funcionario *criarFuncionario(char *nome, char *cargo, int documento);



/*Função funcionario
Cadastra um novo arquivo funcionario, alocando memoria*/
    Funcionario * fun_criar (char * nome, char * cargo, int documento);

/* Função ordena 
utilizada para ordenar os funcionarios por ordem alfabética*/

void fun_ordena (Funcionario ** fun, int count);

/* Guardar os dados estruturados no arquivo*/
void fun_salva (Funcionario ** fun,  FILE * f1)



