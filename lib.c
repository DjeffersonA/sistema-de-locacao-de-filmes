#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

// Iniciamos as estruturas
Filme *filme = 0;
Cliente *cliente = 0;
struct Relatorio* rel = NULL;

int i, j, nfilme = 0, ncliente = 0;
float lucroPorCent = 0, lucroT = 0;
char op;
char cpf[20];
int cod, ord;

/*  Função para ler e armazenar os dados do novo cliente 
    em uma struct temporaria até ser armazenada na principal  */
Cliente NovoCliente(){
	Cliente c;
    
    system(CLS);
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                  Cadastrar Cliente                 *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n");
	printf(" Nome: ");
	getchar();
	fgets(c.nome, sizeof(c.nome), stdin);
	setbuf(stdin, NULL);
	
	printf(" CPF: ");
	fgets(c.cpf, sizeof(c.cpf), stdin);
	setbuf(stdin, NULL);
	
	printf(" Endereco: ");
	fgets(c.endereco, sizeof(c.endereco), stdin);
	setbuf(stdin, NULL);
	
	printf(" Telefone: ");
	fgets(c.telefone, sizeof(c.telefone), stdin);
	setbuf(stdin, NULL);
	
	return c;
}

/*  Função para inserir os dados do novo cliente da struct temporaria na struct principal  */
Cliente *InserirCliente(Cliente *cliente, int *ncliente, Cliente novo){
    // Realocamos a struct com +1 espaço
	cliente = (Cliente*) realloc(cliente, (*ncliente+1)*sizeof(Cliente)); 
	if(cliente == 0) return 0;
	
    // Atribuimos a struct temporaria à principal
	cliente[*ncliente] = novo;
	(*ncliente)++;
	
	return cliente;
}

/*  Função para verificar existência de cliente para que não haja repetições de CPF  */
int ExisteCliente(Cliente *cliente, char cpf[20], int *ncliente){
    int i, existe=0;
    for(i=0; i < *ncliente; i++)
        if(strcmp(cliente[i].cpf, cpf) == 0)
            existe = 1;
    return existe;
}

/*  Função para alterar dados de cliente, sendo imutáveis o nome e o CPF  */
Cliente *AlterarCliente(Cliente *cliente, char cpf[20], int *ncliente) {

    int search=0;
    char novo_endereco[100];
	char novo_telefone[20];

    for(i=0; i < *ncliente; i++) {
        if(strcmp(cliente[i].cpf, cpf) == 0) {
            printf("\n\n");
            printf("\t|******************************************************|\n");
            printf("\t|*                                                    *|\n");
            printf("\t|*                  Alterar Cadastro                  *|\n");
            printf("\t|*                                                    *|\n");
            printf("\t|******************************************************|\n\n");

            printf(" Nome: %s", cliente[i].nome);
            printf(" CPF: %s\n", cliente[i].cpf);

            printf(" Endereco Novo: ");
	        fgets(novo_endereco, sizeof(novo_endereco), stdin);
	        setbuf(stdin, NULL);

	        printf(" Telefone Novo: ");
	        fgets(novo_telefone, sizeof(novo_telefone), stdin);
	        setbuf(stdin, NULL);

            // Copiamos os dados novos no lugar dos dados antigos
            strcpy(cliente[i].endereco, novo_endereco);
            strcpy(cliente[i].telefone, novo_telefone);
            search = 1;

            printf("\n Cadastro alterado com sucesso!");
        }
    }
    if(!search)
       	printf("\n CPF nao encontrado.");
    	
    return cliente;
}

/*  Função para remover cliente da struct  */
Cliente *RemoverCliente(Cliente *cliente, char cpf[20], int *ncliente) {

    int search=0;

    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                  Remover Cadastro                  *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n");

    for(i=0; i < *ncliente; i++) {
        if(strcmp(cliente[i].cpf, cpf) == 0) {

            printf(" Nome: %s", cliente[i].nome);
            printf(" CPF: %s", cliente[i].cpf);
            printf(" Endereco: %s", cliente[i].endereco);
            printf(" Telefone: %s\n", cliente[i].telefone);

            char confirma, cmaiusc;
            printf("\n Tem certeza que deseja excluir este cadastro?\n\n");
            printf(" (S) Sim\n");
            printf(" (N) Nao\n\n");
            printf(" Digite a opcao desejada: ");
            scanf("%c",&confirma);
            cmaiusc = toupper(confirma);
            if(cmaiusc == 'S'){
                // Removemos o cliente e realocamos a struct com -1 espaço
                cliente[i] = cliente[*ncliente-1];
                cliente = (Cliente*) realloc(cliente, (*ncliente-1)*sizeof(Cliente));
                (*ncliente)--;
                search = 1;
                printf("\n\n Cadastro removido com sucesso!");
                getchar();
                return cliente;
            }else if(cmaiusc == 'N'){
                printf("\n\n Cadastro nao foi removido.");
                getchar();
                return cliente;
            }else{
                system(CLS);
                cliente = RemoverCliente(cliente, cpf, ncliente);
            }
        }
    }
    if(search == 0)
       	printf("\n CPF nao encontrado.");
    	
    return cliente;
}

/*  Função para pesquisar cliente na struct
    Utilizando um algoritmo de busca sequencial
    Complexidade: O(n)  */
void PesquisarCliente(Cliente *cliente, char cpf[20], int *ncliente) {
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                  Pesquisar Cliente                 *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n\n");

    int search=0;
    for(i=0; i < *ncliente; i++) {
        if(strcmp(cliente[i].cpf, cpf) == 0){
            
		    printf(" Nome: %s", cliente[i].nome);
            printf(" CPF: %s", cliente[i].cpf);
            printf(" Endereco: %s", cliente[i].endereco);
            printf(" Telefone: %s\n", cliente[i].telefone);

            search = 1;
        }
    }
    if(!search)
       	printf("\n CPF nao encontrado.\n");
}

/*  Função para listar todos os clientes da struct  */
void ListarClientes(Cliente *cliente, int *ncliente) {
    int i;
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                 Cliente Cadastrados                *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n\n");
    
    for(i=0; i < *ncliente; i++) {    
	    printf(" Nome: %s", cliente[i].nome);
        printf(" CPF: %s", cliente[i].cpf);
        printf(" Endereco: %s", cliente[i].endereco);
        printf(" Telefone: %s\n", cliente[i].telefone);
    }
    if(*ncliente == 0)
	    printf(" Nao ha nenhum cliente cadastrado.\n\n");
}

/*  Função para ler e armazenar os dados do novo filme 
    em uma struct temporaria até ser armazenada na principal  */
Filme NovoFilme(){
	Filme f;
    
    system(CLS);
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                   Cadastrar Filme                  *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n");
    printf(" Codigo: ");
	scanf("%d", &f.cod);
	setbuf(stdin, NULL);
	
	printf(" Titulo: ");
	fgets(f.titulo, sizeof(f.titulo), stdin);
	setbuf(stdin, NULL);
	
	printf(" Ano: ");
	scanf("%d", &f.ano);
	setbuf(stdin, NULL);
	
	printf(" Genero: ");
	fgets(f.genero, sizeof(f.genero), stdin);
	setbuf(stdin, NULL);

    printf(" Valor: R$ ");
	scanf("%f", &f.valor);
	setbuf(stdin, NULL);

    f.cpf_cliente_alugou[0] = '0';
	f.cpf_cliente_alugou[1] = 0;
	
	return f;
}

/*  Função para inserir os dados do novo filme da struct temporaria na struct principal  */
Filme *InserirFilme(Filme *filme, int *nfilme, Filme novo){
	filme = (Filme*) realloc(filme, (*nfilme+1)*sizeof(Filme)); 
	if(filme == 0) return 0;
	
	filme[*nfilme] = novo;
	(*nfilme)++;
	
	return filme;
}

/*  Função para verificar existência do codigo do filme na struct para que não haja repetições  */
int ExisteFilme(Filme *filme, int cod, int *nfilme){
    int i, existe=0;
    for(i=0; i < *nfilme; i++)
        if(filme[i].cod == cod)
            existe = 1;
    return existe;
}

/*  Função para alterar dados do filme, sendo imutável o código  */
Filme *AlterarFilme(Filme *filme, int cod, int *nfilme){
    
    int i, search=0;
    char novo_titulo[100];
	int novo_ano;
    char novo_genero[MAX];
    float novo_valor;

    for(i=0; i < *nfilme; i++) {
        if(filme[i].cod == cod) {
            printf("\n\n");
            printf("\t|******************************************************|\n");
            printf("\t|*                                                    *|\n");
            printf("\t|*                  Alterar Cadastro                  *|\n");
            printf("\t|*                                                    *|\n");
            printf("\t|******************************************************|\n\n");

            printf(" Codigo: %d\n", filme[i].cod);

            printf(" Titulo Atualizado: ");
	        fgets(novo_titulo, sizeof(novo_titulo), stdin);
	        setbuf(stdin, NULL);

            printf(" Ano Atualizado: ");
	        scanf("%d", &novo_ano);
	        setbuf(stdin, NULL);

            printf(" Genero Atualizado: ");
	        fgets(novo_genero, sizeof(novo_genero), stdin);
	        setbuf(stdin, NULL);

            printf(" Valor Atualizado: ");
	        scanf("%f", &novo_valor);
	        setbuf(stdin, NULL);

            strcpy(filme[i].titulo, novo_titulo);
            filme[i].ano = novo_ano;
            strcpy(filme[i].genero, novo_genero);
            filme[i].valor = novo_valor;
            search = 1;

            printf("\n Filme alterado com sucesso!");
        }
    }
    if(!search)
       	printf("\n Nao foi encontrado nenhum filme com o codigo %d.\n",cod);
    	
    return filme;
}

/*  Função para remover filme da struct  */
Filme *RemoverFilme(Filme *filme, int cod, int *nfilme){

    int i, search=0;

    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                    Remover Filme                   *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n");

    for(i=0; i < *nfilme; i++) {
        if(filme[i].cod == cod) {

            printf(" Codigo: %d\n", filme[i].cod);
            printf(" Titulo: %s", filme[i].titulo);
            printf(" Ano: %d\n", filme[i].ano);
            printf(" Genero: %s", filme[i].genero);
            printf(" Valor: R$ %.2f\n", filme[i].valor);
            if(strcmp(filme[i].cpf_cliente_alugou,"0") != 0)
                printf(" Locado por: %s\n", filme[i].cpf_cliente_alugou);

            char confirma, cmaiusc;
            printf("\n Tem certeza que deseja excluir este cadastro?\n\n");
            printf(" (S) Sim\n");
            printf(" (N) Nao\n\n");
            printf(" Digite a opcao desejada: ");
            scanf("%c",&confirma);
            cmaiusc = toupper(confirma);
            if(cmaiusc == 'S'){
                filme[i] = filme[*nfilme-1];
                filme = (Filme*) realloc(filme, (*nfilme-1)*sizeof(Filme));
                (*nfilme)--;
                search = 1;
                printf("\n\n Cadastro removido com sucesso!");
                getchar();
                return filme;
            }else if(cmaiusc == 'N'){
                printf("\n\n Cadastro nao foi removido.");
                getchar();
                return filme;
            }else{
                system(CLS);
                filme = RemoverFilme(filme, cod, nfilme);
            }
        }
    }
    if(search == 0)
       	printf("\n CPF nao encontrado.");
    	
    return filme;
}

/*  Função para pesquisar cliente na struct
    Utilizando o algoritmo de busca binaria
    Complexidade: O(log n)  */
void PesquisarFilme(Filme *filme, int cod, int *nfilme) {
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                  Pesquisar Filme                   *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n\n");

    int search=0;
    int inf=0, sup=(*nfilme)-1 , meio;

    while (inf <= sup) {

        // Calculamos o indice do meio da estrutura
        meio = inf + (sup - inf) / 2;
 
        // Verificamos se o Codigo esta no meio
        if (filme[meio].cod == cod){
            printf(" Codigo: %d\n", filme[meio].cod);
            printf(" Titulo: %s", filme[meio].titulo);
            printf(" Ano: %d\n", filme[meio].ano);
            printf(" Genero: %s", filme[meio].genero);
            printf(" Valor: R$ %.2f\n", filme[meio].valor);
            search = 1;
        }
        // Se o Codigo for maior que o meio, ignora a metade da esquerda
        if (filme[meio].cod < cod)
            inf = meio + 1;
 
        // Se o Codigo for menor que o meio, ignora a metade da direita
        else
            sup = meio - 1;
    }
 
    if(!search)
       	printf(" Nao foi encontrado nenhum filme com o codigo %d.\n",cod);
    
}

/*  Função para ordenar filmes pelo código em ordem crescente
    Utilizando o algoritmo de Insertion Sort
    Complexidade: O(n^2)  */
void InsertionSortFilme_PorCod(Filme *filme, int *nfilme){
    Filme aux;

    for(i=1;i<(*nfilme);i++){
        if(filme[i-1].cod > filme[i].cod){
            aux = filme[i];
            j=i-1;
            
            /*  Compara o elemento (cod) da struct auxiliar com cada elemento à esquerda
                até que seja encontrado um elemento menor  */
            do{
                filme[j+1]=filme[j];
                j--;
            }while(j>=0 && filme[j].cod >= aux.cod);
            filme[j+1] = aux;
        }
    }
}

/*  Função para ordenar filmes alfabeticamente em ordem crescente
    Utilizando o algoritmo de Selection Sort
    Complexidade: O(n^2)  */
void SelectionSortFilme_PorAlfa(Filme *filmeC, int *nfilme){
    // Recebemos por parametro a struct pelo começo
    
    // Struct principal, struct "exterior", struct "interior" e temporaria 
    Filme *filme, *filmeF, *filmeD, temp;

    for (filme = filmeC; (filme-filmeC) < (*nfilme); filme++){
        filmeD = filme;
        for (filmeF = filmeD + 1; (filmeF-filmeC) < (*nfilme); filmeF++)
            if (strcmp(filmeD->titulo, filmeF->titulo) > 0)
                filmeD = filmeF;
                
        temp = *filme;
        *filme = *filmeD;
        *filmeD = temp;
    }
}

/*  Função para listar todos os filmes da struct  */
void ListarFilmes(Filme *filme, int *nfilme) {
    int i;
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                 Filmes Cadastrados                 *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n\n");
    
    for(i=0; i < *nfilme; i++) {    
	    printf(" Codigo: %d\n", filme[i].cod);
        printf(" Titulo: %s", filme[i].titulo);
        printf(" Ano: %d\n", filme[i].ano);
        printf(" Genero: %s", filme[i].genero);
        printf(" Valor: R$ %.2f\n\n", filme[i].valor);
    }
    if(*nfilme == 0)
	    printf(" Nao ha nenhum filme cadastrado.\n\n");
}

/*  Função para listar todos os filmes disponiveis da struct  */
void ListarDisponiveis(Filme *filme, int *nfilme) {
    int i, disp=0;
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                 Filmes Disponiveis                 *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n\n");
    
    for(i=0; i < *nfilme; i++) {
        // Verifica se a variavel do cpf de quem alugou esta vazia
        if(strcmp(filme[i].cpf_cliente_alugou,"0") == 0){ 
	        printf(" Codigo: %d\n", filme[i].cod);
            printf(" Titulo: %s", filme[i].titulo);
            printf(" Ano: %d\n", filme[i].ano);
            printf(" Genero: %s", filme[i].genero);
            printf(" Valor: R$ %.2f\n\n", filme[i].valor);
            disp=1;
        }
    }
    if(disp == 0)
	    printf(" Nao ha nenhum filme disponivel.\n\n");
}

/*  Função para listar todos os filmes locados da struct  */
void ListarLocados(Filme *filme, int *nfilme) {
    int i, loc=0;
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                   Filmes Locados                   *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n\n");
    
    for(i=0; i < *nfilme; i++) {
        // Verifica se a variavel do cpf de quem alugou nao esta vazia
        if(strcmp(filme[i].cpf_cliente_alugou,"0") != 0){
	        printf(" Codigo: %d\n", filme[i].cod);
            printf(" Titulo: %s", filme[i].titulo);
            printf(" Ano: %d\n", filme[i].ano);
            printf(" Genero: %s", filme[i].genero);
            printf(" Valor: R$ %.2f\n", filme[i].valor);
            printf(" Locado por: %s\n\n", filme[i].cpf_cliente_alugou);
            loc=1;
        }
    }
    if(loc == 0)
	    printf(" Nao ha nenhum filme locado.\n\n");
}

/*  Função para inserir em uma lista encadeada o lucro individual de cada locação  */
void InserirLucro(struct Relatorio **rel, float lucro){
    struct Relatorio *temp = (struct Relatorio*) malloc(sizeof(struct Relatorio));
    struct Relatorio *fim = *rel;

    temp->lucro = lucro;
    temp->prox = 0;
 
    if (*rel == 0){
       *rel = temp;
       return;
    }

    while (fim->prox != 0)
        fim = fim->prox;
 
    fim->prox = temp;
    return;
}

/*  Função para locar filme  */
void AlugarFilme(Filme *filme, Cliente *cliente, int *nfilme, int *ncliente, struct Relatorio **rel){

    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                 Alugar/Locar Filme                 *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n\n");
    
    if(!lucroPorCent){
        printf(" A margem de lucro por filme locado ainda nao foi definida!\n\n");
        printf(" Informe qual sera a porcentagem de lucro: ");
        scanf("%f", &lucroPorCent);
        while (lucroPorCent<0 || lucroPorCent>100){
            printf(" \n A porcentagem deve estar entre 0 e 100!\n Digite novamente: ");
            scanf("%f", &lucroPorCent);
        }
        printf("\n");
        setbuf(stdin, NULL);
    }

    printf(" Codigo do Filme: ");
    scanf("%d", &cod);
    setbuf(stdin, NULL);

    printf(" CPF do Cliente: ");
    fgets(cpf, sizeof(cpf), stdin);
    setbuf(stdin, NULL);

    for(i=0; i < *nfilme; i++){
        for (j=0; j< *ncliente; j++){
            // Verificamos se o codigo informado é o mesmo do filme
            if(cod == filme[i].cod){   
                // Verificamos se o cpf informado é o mesmo do cliente
                if(strcmp(cpf, cliente[j].cpf) == 0){
                    // Atribuimos o cpf informado ao cpf no vetor struct do filme
                    strcpy(filme[i].cpf_cliente_alugou,cpf);
                    printf("\n Filme: %s Cliente: %s\n Filme locado com sucesso!\n",filme[i].titulo,cliente[j].nome);
                    InserirLucro(rel,(lucroPorCent/100)*filme[i].valor);
                }
            }
        }
    }

    if(!ExisteCliente(cliente, cpf, ncliente))
        printf("\n Nao existe cliente com esse CPF\n");
    if(!ExisteFilme(filme, cod, nfilme))
        printf("\n Nao existe filme com esse codigo\n");
}

/*  Função para devolver filme  */
void ReporFilme(Filme *filme, int *nfilme){
    int devolveu=0;
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                Repor/Devolver Filme                *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n\n");

    printf(" Codigo do Filme: ");
    scanf("%d", &cod);
    setbuf(stdin, NULL);

    printf(" CPF do Cliente: ");
    fgets(cpf, sizeof(cpf), stdin);
    setbuf(stdin, NULL);

    for(i = 0; i < *nfilme; i++) {
        // Verificamos se os dados sao condizentes
		if(cod == filme[i].cod) {
			if(strcmp(cpf, filme[i].cpf_cliente_alugou) == 0) {
                // Caso positivo, atribui o valor 0 à struct de filme novamente
				filme[i].cpf_cliente_alugou[0] = '0';
				filme[i].cpf_cliente_alugou[1] = 0;
				devolveu = 1;
			}
		}
	}

    if(devolveu) printf("\n Filme devolvido com sucesso\n");
	else if(!ExisteFilme(filme, cod, nfilme)) 
        printf("\n Nao existe filme com esse codigo\n");
	else printf("\n Locacao inexistente.\n");
}

/*  Função para verificar disponibilidade de locação de filme  */
void VerificarDisponivel(Filme *filme, int cod, int *nfilme){
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*              Verificar Disponibilidade             *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n\n");

    int i, search=0;
    for(i=0; i < *nfilme; i++) {
        if(filme[i].cod == cod){ 
		    printf(" Codigo: %d\n", filme[i].cod);
            printf(" Titulo: %s", filme[i].titulo);
            printf(" Ano: %d\n", filme[i].ano);
            printf(" Genero: %s", filme[i].genero);
            printf(" Valor: R$ %.2f\n", filme[i].valor);

            // Verificamos se a variavel de CPF na vetor struct do filme está vazio
            if(strcmp(filme[i].cpf_cliente_alugou,"0") == 0)
                printf("\n FILME DISPONIVEL PARA LOCACAO !\n\n");
            else
                printf("\n FILME LOCADO POR : %s\n", filme[i].cpf_cliente_alugou);
            search = 1;
        }
    }
    if(!search)
       	printf(" Nao foi encontrado nenhum filme com o codigo %d.\n",cod);
}

/*  Função para somar os lucros na lista encadeada  */
void SomaLucros(struct Relatorio *rel, float *lucroT, int *qntf) {
    if (!rel)
        return;
    SomaLucros(rel->prox, lucroT, qntf); // Utilizando de recursividade até que a lista acabe
    *lucroT = *lucroT + rel->lucro;
    *qntf = *qntf + 1;
}

void MenuPrincipal(){
    system(CLS);
    
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                Locadora de Filmes GD               *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n");
    printf("\n (C) - Clientes");
    printf("\n (F) - Filmes");
    printf("\n (L) - Locacao");
    printf("\n (R) - Relatorio");
    printf("\n (S) - Sair");
    printf("\n\n\n Digite a opcao desejada: ");

    while(1){
        scanf("%c",&op);
        switch(toupper(op)){
            case 'S': // Sair
                exit(1);
            case 'C': // Clientes
                MenuCliente();
                break;
            case 'F': // Filmes
                MenuFilme();
                break;
            case 'L': // Locacao
                MenuLocacao();
                break;
            case 'R': // Relatorio
                system(CLS);
                MenuRelatorio(rel,lucroT);
                printf(" Pressione ENTER para voltar ao menu principal...");
                getchar();
                break;
            default:
                MenuPrincipal();
        }
    }
}

void MenuCliente(){
    system(CLS);
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                      Clientes                      *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n");
    printf("\n (C) - Cadastrar");
    printf("\n (A) - Alterar");
    printf("\n (R) - Remover");
    printf("\n (P) - Pesquisar");
    printf("\n (L) - Listar Cadastros");
    printf("\n (V) - Voltar");
    printf("\n\n\n Digite a opcao desejada: ");
    scanf("%c",&op);
    
    switch(toupper(op)){
        case 'V': // Voltar
            MenuPrincipal();
        case 'C': { // Cadastrar novo cliente
            Cliente c = NovoCliente(); 
            if(ExisteCliente(cliente, c.cpf, &ncliente)){
                printf("\n Ja existe um cliente cadastrado com este CPF!");
            }else{
                cliente = InserirCliente(cliente, &ncliente, c);
			    printf("\n Cliente adicionado com sucesso!");
            }
            printf("\n\n Pressione ENTER para voltar ao menu principal...");
            break;
        }
        case 'A': { // Alterar cadastro
			printf("\n Digite o CPF do cadastro a ser alterado: ");
			getchar();
			fgets(cpf, sizeof(cpf), stdin);
			setbuf(stdin, NULL);
            system(CLS);
			cliente = AlterarCliente(cliente, cpf, &ncliente);
            printf("\n\n Pressione ENTER para voltar ao menu principal...");
            break;
        }
        case 'R': { // Remover cadastro
			printf("\n Digite o CPF do cadastro a ser removido: ");
			getchar();
			fgets(cpf, sizeof(cpf), stdin);
			setbuf(stdin, NULL);
            system(CLS);
			cliente = RemoverCliente(cliente, cpf, &ncliente);
            printf("\n\n Pressione ENTER para voltar ao menu principal...");
            break;
        }
        case 'P': { // Pesquisar cadastro
			printf("\n Digite o CPF do cliente a ser pesquisado: ");
			getchar();
			fgets(cpf, sizeof(cpf), stdin);
			setbuf(stdin, NULL);
            system(CLS);
			PesquisarCliente(cliente, cpf, &ncliente);
            printf("\n Pressione ENTER para voltar ao menu principal...");
            break;
        }
        case 'L': { // Listar clientes cadastrados
            system(CLS);
			ListarClientes(cliente, &ncliente);
            printf("\n Pressione ENTER para voltar ao menu principal...");
            getchar();
            break;
        }
        default:
            MenuCliente();
    }
}

void MenuFilme(){
    system(CLS);
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                       Filmes                       *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n");
    printf("\n (C) - Cadastrar");
    printf("\n (A) - Alterar");
    printf("\n (R) - Remover");
    printf("\n (P) - Pesquisar");
    printf("\n (L) - Listar Cadastros");
    printf("\n (V) - Voltar");
    printf("\n\n\n Digite a opcao desejada: ");
    scanf("%c",&op);
    switch(toupper(op)){
        case 'V': // Voltar
            MenuPrincipal();
        case 'C': { // Cadastrar novo filme
            Filme f = NovoFilme(); 
            if(ExisteFilme(filme, f.cod, &nfilme)){
                printf("\n Ja existe um filme cadastrado com este Codigo!");
            }else{
                filme = InserirFilme(filme, &nfilme, f);
			    printf("\n Filme adicionado com sucesso!");
            }
            printf("\n\n Pressione ENTER para voltar ao menu principal...");
            break;
        }
        case 'A': { // Alterar cadastro
			printf("\n Digite o Codigo do filme a ser alterado: ");
			scanf("%d", &cod);
	        setbuf(stdin, NULL);
            system(CLS);
			filme = AlterarFilme(filme, cod, &nfilme);
            printf("\n\n Pressione ENTER para voltar ao menu principal...");
            break;
        }
        case 'R': { // Remover cadastro
			printf("\n Digite o Codigo do filme a ser removido: ");
			scanf("%d", &cod);
	        setbuf(stdin, NULL);
            system(CLS);
			filme = RemoverFilme(filme, cod, &nfilme);
            printf("\n\n Pressione ENTER para voltar ao menu principal...");
            break;
        }
        case 'P': { // Pesquisar cadastro
			printf("\n Digite o Codigo do filme a ser pesquisado: ");
	        scanf("%d", &cod);
	        setbuf(stdin, NULL);
            system(CLS);
            InsertionSortFilme_PorCod(filme, &nfilme);
			PesquisarFilme(filme, cod, &nfilme);
            printf("\n\n Pressione ENTER para voltar ao menu principal...");
            break;
        }
        case 'L': { // Listar filmes cadastrados
            printf("\n Ordenar por ordem alfabetica ou por codigo?\n\n");
            printf(" (1) Ordem Alfabetica\n");
            printf(" (2) Codigo\n\n");
            printf(" Digite a opcao desejada: ");
	        scanf("%d",&ord);
            if(ord == 1){
                SelectionSortFilme_PorAlfa(filme, &nfilme); // Por ordem alfabética
            }else if(ord == 2){
                InsertionSortFilme_PorCod(filme, &nfilme); // Por ordem de código
            }else{
                MenuFilme();
            }
            system(CLS);
			ListarFilmes(filme, &nfilme);
            printf("\n Pressione ENTER para voltar ao menu principal...");
            getchar();
            break;
        }
        default:
            MenuFilme();
    }
}

void MenuLocacao(){
    system(CLS);
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                       Locacao                      *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n");
    printf("\n (D) - Listar Filmes Disponiveis");
    printf("\n (L) - Listar Filmes Locados");
    printf("\n (A) - Alugar Filme");
    printf("\n (R) - Repor Filme");
    printf("\n (P) - Pesquisar Disponibilidade");
    printf("\n (V) - Voltar");
    printf("\n\n\n Digite a opcao desejada: ");
    scanf("%c",&op);
    switch(toupper(op)){
        case 'V': // Voltar
            MenuPrincipal();
        case 'D': { // Listar filmes disponiveis para locacao
            system(CLS);
			ListarDisponiveis(filme, &nfilme);
            printf("\n Pressione ENTER para voltar ao menu principal...");
            getchar();
            break;
        }
        case 'L': { // Listar filmes locados
            system(CLS);
			ListarLocados(filme, &nfilme);
            printf(" Pressione ENTER para voltar ao menu principal...");
            getchar();
            break;
        }
        case 'A': { // Alugar/locar filme
            system(CLS);
			AlugarFilme(filme, cliente, &nfilme, &ncliente, &rel);
            printf("\n Pressione ENTER para voltar ao menu principal...");
            break;
        }
        case 'R': { // Repor/devolver filme
            system(CLS);
			ReporFilme(filme, &nfilme);
            printf("\n Pressione ENTER para voltar ao menu principal...");
            break;
        }
        case 'P': { // Pesquisar disponibilidade de filme
			printf("\n Digite o Codigo do filme a ser pesquisado: ");
	        scanf("%d", &cod);
	        setbuf(stdin, NULL);
            system(CLS);
			VerificarDisponivel(filme, cod, &nfilme);
            printf("\n Pressione ENTER para voltar ao menu principal...");
            break;
        }
        default:
            MenuLocacao();
    }
}

void MenuRelatorio(struct Relatorio *rel, float lucroT){

    int qntf = 0;
    printf("\n\n");
    printf("\t|******************************************************|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|*                      RELATORIO                     *|\n");
    printf("\t|*                                                    *|\n");
    printf("\t|******************************************************|\n\n\n");

    SomaLucros(rel,&lucroT,&qntf);
    printf("\tLucro: R$ %.2f\n\n", lucroT);
    printf("\tQuantidade de Filmes Locados: %d\n\n\n", qntf);
}