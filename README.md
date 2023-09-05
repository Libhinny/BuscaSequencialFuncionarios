
# Busca de strings com Busca Sequencial: 
 

A Busca Sequencial é um método simples de procurar por uma determinada string em uma coleção, como um vetor ou uma lista, em linguagens de programação como C. Ela envolve percorrer cada elemento da coleção, um por um, até encontrar a string desejada ou até percorrer todos os elementos.
  
### Exemplo de uma função com busca sequencial
```c 
Funcionario *buscaLinearnome ( int count_fun , Funcionario * funcionario[], char * nome )
{

    int i;

    for (i = 0; i < count_fun; i++)
    {
        if (strcasecmp(funcionario[i]->nome, nome) == 0)
        {
            return funcionario[i];
        }
    }
    return NULL;
} 

```
Neste exemplo, temos uma estrutura Funcionario que contém um campo nome. A função buscaLinearnome recebe o número total de funcionários (count_fun), um vetor de ponteiros para funcionários (funcionario[ ]) e o nome a ser procurado. Ela percorre cada funcionário no vetor e compara os nomes usando strcmp. Se um nome correspondente for encontrado, a função retorna o ponteiro para esse funcionário. Se não for encontrado, a função retorna NULL.
### Vantagens da busca sequencial:
* Simplicidade
* Flexibilidade
* Implementação em estruturas simples
### Desvantagens da busca sequencial:
* Ineficiência para grandes conjuntos de dados
* Baixa performance
* Menor eficiência em cenários específicos



## Complexidade da busca de strings com busca sequencial
A complexidade de tempo de um algoritmo é denotada por T(n), em que n é o tamanho da entrada. A complexidade de tempo de um algoritmo é a quantidade de tempo que o algoritmo leva para executar uma tarefa com uma entrada de tamanho n.

### Exemplo de complexidade de tempo: 
```c 
Funcionario *buscaLinearnome ( int count_fun , Funcionario * funcionario[], char * nome )
{

    int i;// c1, 1 vez

    for (i = 0; i < count_fun; i++)// c2, n-1 vezes
    {
        if (strcasecmp(funcionario[i]->nome, nome) == 0)// c3, n-1 vezes
        {
            return funcionario[i];// c4, n-1 vezes
        }
    }
    return NULL;// c5, 1 vez
} 

```
Podemos multiplicar a execução de cada linha pelo tempo que leva para executar essa linha. Então, o tempo total de execução será a soma de todos os tempos de execução de cada linha.

$$ T(n) = c1 + c2(n-1) + c3(n-1) + c4(n-1) + c5   $$

$$ T(n) = (c1 + c5) +  (n-1)(c2 + c3 + c4) $$

$$ T(n) = b +  (n-1)a $$

$$ T(n) =  (n-1)a $$

$$ T(n) =  (n-1) $$

$$ T(n) =  O(n) $$




