# Trabalho Final de Algoritmos e Estruturas de Dados 1 - UFG

## Sistema de Locação de Filmes - Relatório Técnico

### 1.	RESUMO
A melhor maneira de manter o controle de entrada e saída de uma videolocadora é ter um software capaz de não só permitir uma base formulada para um bom gerenciamento de locações e visualização dos lucros, bem como fornecer-lhes as ferramentas, que lhe trazem vantagens para sua empresa de locação e assim pensamos nessa oportunidade de mostrar a aplicabilidade desse nosso sistema de locação de filmes.
O sistema tem como funcionalidade gerenciar cadastros, movimentar entrada e saída de filmes, bem como pesquisar um filme específico ou listar todos os filmes em ordem alfabética ou por código, e o gerenciamento de locações. Permitirá também que o usuário do sistema, após informar a porcentagem da margem de lucro por filme, visualize em um relatório, os lucros totais e a quantidade de locações efetuadas. Através de todas essas funções, possibilitará um melhor gerenciamento de todas as informações da videolocadora sem que seja necessário um hardware robusto para fazer uso do sistema, somente utilizando de um hardware de baixo custo. 

### 2.	FUNCIONAMENTO DA APLICAÇÃO
O sistema apresentado foi dividido em 4 submenus:
1. Clientes: Neste submenu podemos efetuar o cadastro de clientes, alteração cadastral no endereço e no telefone (sendo imutáveis o nome e CPF), remoção de clientes, pesquisar dados de um cliente, e listar todos os cadastros. Os cadastros de clientes são armazenados em uma estrutura de dados com vetores.
2. Filmes: Neste submenu podemos efetuar o cadastro de filmes, alteração cadastral no título, ano de lançamento, gênero e valor (sendo imutável o código), remoção de filmes, pesquisar dados de um filme, e listar todos os filmes em ordem alfabética ou em ordem crescente pelo código. Os cadastros dos filmes são armazenados em uma estrutura de dados com vetores.
3. Locação: Neste submenu podemos listar os filmes disponíveis e locados, definir a porcentagem da margem de lucro por filme locado, efetuar a locação e devolução de um filme e pesquisar a disponibilidade de um filme específico, com base no seu código.
4. Relatório: Será mostrado nesta página o lucro obtido e a quantidade de filmes locados no dia. O lucro obtido será armazenado em uma estrutura de dados dinâmica (lista encadeada).

### 3.	COMPLEXIDADE COMPUTACIONAL DOS ALGORITMOS
Foram utilizados 4 (quatro) algoritmos diferentes nesta aplicação, sendo 2 (dois) de busca e 2 (dois) de ordenação.
1. Busca Sequencial: Utilizado na função para pesquisar dados de um cliente, tem como complexidade O(1) no melhor caso, onde o cadastro a ser procurado é o primeiro da estrutura e O(n) no pior caso, onde o cadastro é o último da estrutura ou não existe.
2. Busca Binária: Utilizado na função para pesquisar dados de um filme, sendo necessário antes chamar um algoritmo de ordenação (insertion sort, abordado no próximo item), tem como complexidade Ω(1) no melhor caso, onde o filme a ser procurado está exatamente no meio da estrutura e O(log n) no pior caso, onde o filme a ser procurado não existe ou foram utilizados “log n (base 2)” comparações para ser achado.
3. Insertion Sort: Utilizado na função para ordenar filmes em ordem crescente pelo código, possui complexidade Ω(n) no melhor caso, onde o vetor já está ordenado e O(n2) em seu pior caso, onde cada elemento de um vetor com tamanho n precisa percorrer todo o vetor para se mover, ou seja, n*n.
4. Selection Sort: Utilizado na função para ordenar filmes em ordem alfabética, possui também complexidade O(n2) em seu pior caso, mas ao contrário do insertion sort, este possui complexidade Ω(n2) em seu melhor caso, pois trabalha com dois laços de repetição, percorrendo n*n vezes sempre
