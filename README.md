
# Busca de strings com Busca Sequencial


´´´c 
Funcionario *buscaLinearnome ( int count_fun , Funcionario * funcionario[], char * nome ){

    int i;

    for (i = 0; i < count_fun; i++) {
        if (strcmp(funcionario[i]->nome, nome) == 0) {
            return funcionario[i];
        }
    }
    return NULL; 
} 

´´´