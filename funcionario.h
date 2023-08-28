

/* Vai pedir para usuario inserir nome, cargo e documento */

typedef struct funcionario Funcionario;

Funcionario *criarFuncionario(char *nome, char *cargo, int documento);

void funcionario_salva(FILE *fp, Funcionario *funcionario);
