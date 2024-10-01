#ifndef FUNCOES_H
#define FUNCOES_H


// struct do produto
typedef struct{
	int codigo;
	char nome[30];
	float preco;
}Produto;

Produto p;
// struct do carrinho
typedef struct{
	Produto produto;
	int quantidade;
}Carrinho;

// Declaracao das funcoes
Carrinho c;
int lerNPI();
int lerNPIQ();
int lerNPIC();
float lerNPF();
void cadastrarProduto();
void listarProduto();
void altInfo();
void removeProd();
void comprarProduto();
void visualizarCarrinho();
void removeCar();
void fecharPedido();
void menu(int *num);

#endif