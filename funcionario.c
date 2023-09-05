#include "funcionario.h"
// struct do tipo funcionario , onde farar o armazenamento dos dados (nome, cargo e documento)
// typedef é utilizado para fazer o chamamento da struct
typedef struct funcionario
{

    char nome[100];
    char cargo[50];
    long long int documento;

} Funcionario;

// Função para criar os funcionarios, em seguida serão alocados dinamicamente e estaram armazendo os dados na struct.
Funcionario *criarFuncionario(char *nome, char *cargo, long long int documento)
{
    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));

    if (funcionario == NULL) // verifica se a alocação de memória foi bem sucedida ou não
    {
        exit(1); // encerrar
    }

    strcpy(funcionario->nome, nome);    // string
    strcpy(funcionario->cargo, cargo);  // string
    funcionario->documento = documento; // recebe o parametro documentro da struct

    return funcionario; // retorna para funcionario
}
// função de salvar arquivo
void funcionario_salva(Funcionario *funcionario)
{

    // Abrir/criar o arquivo de saida para escrita (a)
    FILE *fp = fopen("saida.txt", "a"); // abrir arquivo "a" (abre um arquivo no modo de inclusão)
    if (fp == NULL)                     // Retorna NULL se a alocação de memória falhar
    {
        printf("Erro ao abrir o arquivo"); // exibir mensagem de erro
        exit(1);                           // encerrar
    }

    // Remove qualquer caractere de nova linha do nome e do cargo
    char *nome = funcionario->nome;
    char *cargo = funcionario->cargo;
    nome[strcspn(nome, "\n")] = '\0';
    cargo[strcspn(cargo, "\n")] = '\0';

    // escreve os dados no arquivo conforme especificado pela string
    fprintf(fp, " %s\t%s\t%lld\n", nome, cargo, funcionario->documento);
    fclose(fp); // fechar arquivo
}

// função para ler arquivo .txt
void lerarquivo(FILE *fp, Funcionario *funcionario[], int *count_fun)
{
    char linha[100];      // char denominada linha de tamanho 100
    Funcionario auxiliar; // variavel auxilar
                          // fgets é utilizado para fazer a leitura de uma linha e depois armazenar em uma string
                          // sscanf é utilizado para a leitura de uma string
    while (fgets(linha, sizeof(linha), fp) != NULL)
    {
        char nome[100], cargo[50];
        long long int documento;

        // Use sscanf para ler nome e cargo com espaços e o documento com strtol
        if (sscanf(linha, "%99[^\t]\t%49[^\t]\t%lld", nome, cargo, &documento) == 3)
        {
            funcionario[*count_fun] = criarFuncionario(nome, cargo, documento);
            (*count_fun)++;
        }
    }
}
// função para buscar dos funcionarios cadastrado pelo nome.
Funcionario *buscaLinearnome(int count_fun, Funcionario *funcionario[], char *nome)
{

    /// inicia o tempo de execução da função buscaLinearnome
    clock_t inicio = clock();
    double tempo;

    int i;
    for (i = 0; i < count_fun; i++)
    {
        if (strcmp(funcionario[i]->nome, nome) == 0)
        {
            // Calcula o tempo de execução caso um funcionario seja encontrado
            clock_t fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            tempo = tempo * 1000; // milisegundos
            printf("\nTempo de execucao da funcao buscaLinearnome: %.50f\n\n", tempo);
            return funcionario[i]; // retorna a funcionario
        }
    }

    // Calcula o tempo de execução caso nenhum funcionario seja encontrado
    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    tempo = tempo * 1000; // milisegundos
    printf("\nTempo de execucao da funcao buscaLinearnome: %.50f\n\n", tempo);
    return NULL; // Retorna NULL se a alocação de memória falhar
}

// função para busca dos funcionarios cadastrado por numero de indentificação (pode ser ele identidade, cpf ou matricula)
Funcionario *buscaLineardocumento(int count_fun, Funcionario *funcionario[], long long int documento)
{
    // inicia o tempo de execução da função buscaLineardocumento
    clock_t inicio = clock();
    double tempo;
    int i;
    for (i = 0; i < count_fun; i++)
    {
        if (funcionario[i]->documento == documento)
        {
            // Calcula o tempo de execução caso um funcionario seja encontrado
            clock_t fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            tempo = tempo * 1000; // milisegundos
            printf("\nTempo de execucao da funcao buscaLineardocumento: %.50f\n\n", tempo);
            return funcionario[i]; // Retorna a funcionario
        }
    }
    // Calcula o tempo de execução caso nenhum funcionario seja encontrado
    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    tempo = tempo * 1000; // milisegundos
    printf("\nTempo de execucao da funcao buscaLineardocumento: %.50f\n\n", tempo);
    return NULL; // Retorna NULL se a alocação de memória falhar
}

// Função para atualizar o arquivo arquivo "saida.txt" sempre que o programa e encerrado e inicializado novamente.
void atualizarArquivo(Funcionario *funcionario[], int count_fun)
{
    FILE *fp = fopen("saida.txt", "w"); // Abre o arquivo para escrita, substituindo o conteúdo existente

    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo para atualização.\n");
        exit(1); // Trate o erro adequadamente
    }

    for (int i = 0; i < count_fun; i++)
    {
        fprintf(fp, "%s\t%s\t%lld\n", funcionario[i]->nome, funcionario[i]->cargo, funcionario[i]->documento);
    }

    fclose(fp); // Feche o arquivo após a atualização
}

// função libera funcionario vai liberar a memoria ocupada
void libera_funcionario(Funcionario *funcionarios)
{
    free(funcionarios);
}
