#include "funcionario.h"
// struct do tipo funcionario , onde farar o armazenamento dos dados (nome, cargo e documento)
// typedef é utilizado para fazer o chamamento da struct
typedef struct funcionario
{

    char nome[100];
    char cargo[50];
    int documento;

} Funcionario;

// Função para criar os funcionarios, em seguida serão alocados dinamicamente e estaram armazendo os dados na struct.
Funcionario *criarFuncionario(char *nome, char *cargo, int documento)
{
    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));

    if (funcionario == NULL) // Retorna NULL se a alocação de memória falhar
    {
        exit(1); // encerrar 
    }

    strcpy(funcionario->nome, nome); // string
    strcpy(funcionario->cargo, cargo); // string 
    funcionario->documento = documento; // recebe o parametro documentro da struct 

    return funcionario; // retorna para funcionario
}
 // função de salvar arquivo 
void funcionario_salva( Funcionario* funcionario)
{

    // Abrir/criar o arquivo de saida para escrita (a)
    FILE*fp = fopen("saida.txt", "a"); // abrir arquivo "a" (abre um arquivo no modo de inclusão)
    if (fp == NULL) // Retorna NULL se a alocação de memória falhar
    {
        printf("Erro ao abrir o arquivo"); //exibir mensagem de erro
        exit(1); //encerrar 
    }
   // escreve os dados no arquivo conforme especificado pela string
    fprintf(fp, " %s\t%s\t%d\n", funcionario->nome, funcionario->cargo, funcionario->documento); 
    fclose(fp);// fechar arquivo
}

// função para ler arquivo .txt
void lerarquivo(FILE *fp, Funcionario * funcionario[], int * count_fun){
    char linha [100]; // char denominada linha de tamanho 100
    Funcionario auxiliar; // variavel auxilar
    // fgets é utilizado para fazer a leitura de uma linha e depois armazenar em uma string 
    // sscanf é utilizado para a leitura de uma string 
        while(fgets (linha, 100, fp) != NULL){
        sscanf(linha, "%s\t%s\t%d", auxiliar.nome, auxiliar.cargo, &auxiliar.documento); 

        funcionario[*count_fun] = criarFuncionario (auxiliar.nome, auxiliar.cargo, auxiliar.documento);
        (*count_fun)++;  
     
    }
}
// função para buscar dos funcionarios cadastrado pelo nome.
 Funcionario *buscaLinearnome ( int count_fun , Funcionario * funcionario[], char * nome ){

    int i;

    for (i = 0; i < count_fun; i++) {
        if (strcmp(funcionario[i]->nome, nome) == 0) {
            return funcionario[i]; //retorna a funcionario
        }
    }
    return NULL; // Retorna NULL se a alocação de memória falhar
} 
// função para busca dos funcionarios cadastrado por numero de indentificação (pode ser ele identidade, cpf ou matricula)
Funcionario *buscaLineardocumento(int count_fun, Funcionario * funcionario[], int  documento) {
   
    int i;
    for (i = 0; i < count_fun; i++) {
        if (funcionario[i]->documento == documento) {
            return funcionario[i]; // Retorna a funcionario
        }
    }
    return NULL; //Retorna NULL se a alocação de memória falhar
} 
// função libera funcionario vai liberar a memoria ocupada 
void libera_funcionario (Funcionario * funcionarios){
    free (funcionarios);
}
