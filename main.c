#include "funcionario.c"
#define fun 10

int main(void)
{
    clock_t inicio = clock();
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    tempo = tempo * 1000; // milisegundos

    int op, documento, count_fun = 0;
    int nomeValido = 0;

    char nome[100], cargo[50];

    Funcionario *funcionario[fun];
    printf("\nBem vindo ao nosso Programa!\n");
    printf("O presente programa manipula um tipo estruturado Funcionarios e possui a funcionalidade de buscar funcionarios de um arquivo por nome ou documento.\n");
    printf("AUTORES:\nDiego Nascimento de Oliveira\nPaulo Henrique Medeiros da Silva\n\n");
    FILE *dados_fun = fopen("saida.txt", "r");
    if (dados_fun == NULL)
    {
        printf("Não foi possivel abrir o arquivo .\n");
        exit(-1);
    }
    lerarquivo(dados_fun, funcionario, &count_fun);

    do
    {

        printf("\nMENU DE OPÇÕES \n");
        printf("1 - CADASTRO DE FUNCIONARIOS \n");
        printf("2 - BUSCAR FUNCIONARIO POR NOME \n");
        printf("3 - BUSCAR FUNCIONARIO POR DOCUMENTO  \n");
        printf("4 - FINALIZAR O PROGRAMA \n");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            // Verifica se o nome contém apenas letras

            while (!nomeValido)
            {
                printf("Digite o nome do funcionario ao qual deseja cadastrar: \n");
                scanf(" %[^\n]", nome);
                getchar(); // Limpar o buffer

                nomeValido = 1;
                for (int i = 0; nome[i] != '\0'; i++)
                {
                    if (!isalpha(nome[i]) && !isspace(nome[i]))
                    {
                        nomeValido = 0;
                        break;
                    }
                }

                if (!nomeValido)
                {
                    printf("O nome digitado contém caracteres inválidos.\n");
                }
            }
            // Verifica se o cargo contém apenas letras
            int cargoValido = 0;
            while (!cargoValido)
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
            }
             int documentoValido = 0;
            while (!documentoValido)
            {
                printf("Digite o número de um documento de identificação: \n");
                if (scanf(" %d", &documento) == 1)
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
            }
            if (count_fun < fun)

            {
                funcionario[count_fun] = criarFuncionario(nome, cargo, documento);
                funcionario_salva(funcionario[count_fun]);
                count_fun++;
            }
            else
            {
                printf("Quantidade maxima de funcionario foi atingido! ");
            }
            break;

        case 2:
            // Verifica se o nome contém apenas letras
            nomeValido = 0;
            while (!nomeValido)
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
            }

            Funcionario *func = buscaLinearnome(count_fun, funcionario, nome);
            if (func != NULL)
            {
                printf("\n\tFuncionario encontrado \n");
                printf("Nome: %s\n", func->nome);
                printf("Documento: %d\n", func->documento);
                printf("Cargo: %s\n", func->cargo);
            }
            else
            {
                printf("Funcionario não encontrado! \n");
            }
            break;

        case 3:
           
            while (!documentoValido)
            {
                printf("Digite o número de um documento de identificação: \n");
                if (scanf(" %d", &documento) == 1)
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
            }

            Funcionario *funci = buscaLineardocumento(count_fun, funcionario, documento);
            if (funci != NULL)
            {
                printf("\n Funcionario encontrado! \n");
                printf("Nome: %s\n", funci->nome);
                printf("Documento: %d\n", funci->documento);
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
    } while (op != 4);

    printf("\nTempo de execucao: %.50f\n\n", tempo);

    return 0;
}
