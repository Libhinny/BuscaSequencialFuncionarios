
# Busca de strings com Busca Sequencial

## Complexidade da busca de strings com busca sequencial
A complexidade de tempo de um algoritmo é denotada por T(n), em que n é o tamanho da entrada. A complexidade de tempo de um algoritmo é a quantidade de tempo que o algoritmo leva para executar uma tarefa com uma entrada de tamanho n.

### Exemplo de complexidade de tempo: 
```c 
Funcionario *buscaLinearnome ( int count_fun , Funcionario * funcionario[], char * nome )
{

    int i;// c1, 1 vez

    for (i = 0; i < count_fun; i++)// c2, n-1 vezes
    {
        if (strcmp(funcionario[i]->nome, nome) == 0)// c3, n-1 vezes
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


### Exemplo de complexidade de espaço: 

A complexidade de espaço de um algoritmo é denotada por S(n), em que n é o tamanho da entrada. A complexidade de espaço de um algoritmo é a quantidade de memória que o algoritmo consome para executar uma tarefa com uma entrada de tamanho n.

