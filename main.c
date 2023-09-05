#include "funcionario.c"
#define TAMANHO_INICIAL 10

int main(void)
{

    int op, count_fun = 0;
    long long int documento; // Para armazenar um número maior de inteiros 
    int nomeValido = 0;

    char nome[100], cargo[50];
    int tamanho_atual = TAMANHO_INICIAL; // Variável para rastrear o tamanho atual do array de funcionários


    // Aloca memória inicial para o array de ponteiros de funcionários
    Funcionario **funcionario = malloc(sizeof(Funcionario *) * TAMANHO_INICIAL);
    if (funcionario == NULL) // verifica se a alocação de memória foi bem sucedida ou não
    {
        exit(1); // // encerrar
    }

    printf("\nBem vindo ao nosso Programa!\n");
    printf("O presente programa manipula um tipo estruturado Funcionarios e possui a funcionalidade de buscar funcionarios de um arquivo por nome ou documento.\n");
    printf("AUTORES:\nDiego Nascimento de Oliveira\nPaulo Henrique Medeiros da Silva\n\n");

    count_fun = 0;                             // número de funcionários lidos do arquivo
    FILE *dados_fun = fopen("saida.txt", "r"); // abre o arquivo "saida.txt" no modo de leitura ("r"), permitindo ler todos os dados do arquivo.
    if (dados_fun == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
        exit(-1);
    }
    lerarquivo(dados_fun, funcionario, &count_fun); // chama a função lerarquivo para ler os dados do arquivo "saida.txt" e carregá-los na memória.

    do
    {

        printf("\nMENU DE OPÇÕES \n");
        printf("1 - CADASTRAR FUNCIONARIO \n");
        printf("2 - BUSCAR FUNCIONARIO POR NOME \n");
        printf("3 - BUSCAR FUNCIONARIO POR DOCUMENTO  \n");
        printf("4 - FINALIZAR O PROGRAMA \n");

        if (scanf("%d", &op) != 1) // verifica se o que foi digitado é um inteiro
        {
            printf("Entrada inválida. Digite um número.\n");
            while (getchar() != '\n')
            {
                // Limpar o buffer de entrada para evitar loop infinito
            }
            continue; // Volta para o início do loop
        }

        switch (op)
        {
        case 1:
            // Verifica se o nome contém apenas letras
            do
            {
                printf("Digite o nome do funcionario ao qual deseja cadastrar: \n");
                scanf(" %[^\n]", nome);
                getchar(); // Limpar o buffer

                nomeValido = 1;
                for (int i = 0; nome[i] != '\0'; i++)
                {
                    if (!isalpha(nome[i]) && !isspace(nome[i]))// A função isalpha retorna verdadeiro se o caractere for uma letra do alfabeto e falso caso contrário, enquanto isspace retorna verdadeiro se o caractere for um espaço em branco.

                    {
                        nomeValido = 0; //significa que o nome digitado é válido
                        break;
                    }
                }

                if (!nomeValido)
                {
                    printf("O nome digitado contém caracteres inválidos.\n");
                }
            } while (!nomeValido);

            // Verifica se o cargo contém apenas letras
            int cargoValido = 0;
            do
            {
                printf("Digite o cargo do funcionario ao qual deseja cadastrar: \n");
                scanf(" %[^\n]", cargo);
                getchar(); // Limpar o buffer

                cargoValido = 1;
                for (int i = 0; cargo[i] != '\0'; i++)
                {
                    if (!isalpha(cargo[i]) && !isspace(cargo[i]))
                    {
                        cargoValido = 0;
                        break;
                    }
                }

                if (!cargoValido)
                {
                    printf("O cargo digitado contém caracteres inválidos. Digite novamente:\n");
                }
            } while (!cargoValido);

            int documentoValido = 0;
            do
            {
                printf("Digite o número de um documento de identificação: \n");
                if (scanf(" %lld", &documento) == 1)
                {
                    documentoValido = 1;
                }
                else
                {
                    printf("Entrada inválida. Digite novamente:\n");
                    // Limpar o buffer de entrada para evitar loop infinito
                    while (getchar() != '\n')
                        ;
                }
            } while (!documentoValido);

            // para realocar a memória
            if (count_fun >= tamanho_atual)
            {
                // Se o array está cheio, realoque memória para um novo array com tamanho maior
                tamanho_atual *= 2;
                funcionario = realloc(funcionario, sizeof(Funcionario *) * tamanho_atual);

                if (funcionario == NULL)
                {
                    exit(1); // Tratar erro de realocação de memória
                }

            }

            funcionario[count_fun] = criarFuncionario(nome, cargo, documento);
            funcionario_salva(funcionario[count_fun]);
            count_fun++;

            break;

        case 2:
            // Verifica se o nome contém apenas letras
            nomeValido = 0;
            do
            {
                printf("Digite o nome do funcionario ao qual deseja fazer uma busca:\n");
                scanf(" %[^\n]", nome);
                getchar();

                nomeValido = 1;
                for (int i = 0; nome[i] != '\0'; i++)
                {
                    if (!isalpha(nome[i]) && !isspace(nome[i]))
                    {
                        nomeValido = 0;
                        getchar(); // Limpar o buffer
                        break;
                    }
                }

                if (!nomeValido)
                {
                    printf("Nome contém caracteres inválidos.\n");
                }
            } while (!nomeValido);

            //Após verificar se o que foi digitado é valido é feito a busca
            Funcionario *func = buscaLinearnome(count_fun, funcionario, nome);
            if (func != NULL)
            {
                printf("\n\tFuncionario encontrado \n");
                printf("Nome: %s\n", func->nome);
                printf("Documento: %lld\n", func->documento);
                printf("Cargo: %s\n", func->cargo);
            }
            else
            {
                printf("Funcionario não encontrado! \n");
            }
            break;

        case 3:

            do
            {
                printf("Digite o número de um documento de identificação: \n");
                if (scanf(" %lld", &documento) == 1)
                {
                    documentoValido = 1;
                }
                else
                {
                    printf("Entrada inválida. Digite novamente:\n");
                    // Limpar o buffer de entrada para evitar loop infinito
                    while (getchar() != '\n')
                        ;
                }
            } while (!documentoValido);

            //Após verificar se o que foi digitado é valido é feito a busca
            Funcionario *funci = buscaLineardocumento(count_fun, funcionario, documento);
            if (funci != NULL)
            {
                printf("\n Funcionario encontrado! \n");
                printf("Nome: %s\n", funci->nome);
                printf("Documento: %lld\n", funci->documento);
                printf("Cargo: %s\n", funci->cargo);
            }
            else
            {
                printf("Funcionario nao encontrado! \n");
            }

            break;

        case 4:

            printf("Programa finalizado! Obrigado por usar nosso programa.\n");

            break;

        default:

            printf("Tente novamente, opcao fornecida está incorreta! \n");
        }

        atualizarArquivo(funcionario, count_fun); // Atualiza o arquivo sempre que houver alterações na lista de funcionários
    } while (op != 4);

    // Libera a memória alocada para cada funcionário individualmente antes de liberar o array de ponteiros de funcionários
    for (int i = 0; i < count_fun; i++)
    {
        libera_funcionario(funcionario[i]);
    }

    // Libera a memória alocada para o array de ponteiros de funcionários
    free(funcionario);

    return 0;
}
