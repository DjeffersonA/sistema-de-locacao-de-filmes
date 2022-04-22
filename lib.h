#ifndef LIB_H
#define LIB_H

#ifdef _WIN32
    #define CLS "cls"
#elif __linux__
    #define CLS "clear"
#endif

#define MAX 50

// Definimos as estruturas de dados
typedef struct{
	int cod;
	char titulo[MAX*2];
    int ano;
	char genero[MAX];
    float valor;
	char cpf_cliente_alugou[20];
}Filme;

typedef struct{
	char nome[MAX];
	char cpf[20];
	char endereco[100];
	char telefone[20];
}Cliente;

struct Relatorio{
    float lucro;
    struct Relatorio *prox;
};

// Menus
void MenuPrincipal();
void MenuCliente();
void MenuFilme();
void MenuLocacao();
void MenuRelatorio(struct Relatorio *rel, float lucroT);

// Menu de Clientes
Cliente NovoCliente();
Cliente *InserirCliente(Cliente *cliente, int *ncliente, Cliente novo);
int ExisteCliente(Cliente *cliente, char cpf[20], int *ncliente);
Cliente *AlterarCliente(Cliente *cliente, char cpf[20], int *ncliente);
Cliente *RemoverCliente(Cliente *cliente, char cpf[20], int *ncliente);
void PesquisarCliente(Cliente *cliente, char cpf[20], int *ncliente);
void ListarClientes(Cliente *cliente, int *ncliente);

// Menu de Filmes
Filme NovoFilme();
Filme *InserirFilme(Filme *filme, int *nfilme, Filme novo);
int ExisteFilme(Filme *filme, int cod, int *nfilme);
Filme *AlterarFilme(Filme *filme, int cod, int *nfilme);
Filme *RemoverFilme(Filme *filme, int cod, int *nfilme);
void PesquisarFilme(Filme *filme, int cod, int *nfilme);
void InsertionSortFilme_PorCod(Filme *filme, int *nfilme);
void SelectionSortFilme_PorAlfa(Filme *filmeC, int *nfilme);
void ListarFilmes(Filme *filme, int *nfilme);

// Menu de Locação
void ListarDisponiveis(Filme *filme, int *nfilme);
void ListarLocados(Filme *filme, int *nfilme);
void InserirLucro(struct Relatorio **rel, float lucro);
void AlugarFilme(Filme *filme, Cliente *cliente, int *nfilme, int *ncliente, struct Relatorio **rel);
void ReporFilme(Filme *filme, int *nfilme);
void VerificarDisponivel(Filme *filme, int cod, int *nfilme);

// Menu de Relatório
void SomaLucros(struct Relatorio *rel, float *lucroT, int *qntf);

#endif