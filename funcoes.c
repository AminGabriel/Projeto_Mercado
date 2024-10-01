#include "biblioteca.h"
#include "funcoes.h"

// variaveis globais para o total produtos e carrinho
int totalProdutos = 0;
int totalCarrinho = 0;

// Array estaticos
Produto produtos[MAX_Prod];
Carrinho carrinho[MAX_PCar];

// Funcao para verificar se o numero e '0' ou '1'
int lerNPI() {
    int num5;
    while (1) {

        // Usando scanf para ler diretamente o número inteiro e positivo
        if (scanf("%d", &num5) == 1 && (num5 == 0 || num5 == 1)) {
            return num5; // Retorna o número válido (0 ou 1)
        } else {
            printf("\nErro! Digite '0' ou '1': ");

            // Limpa o buffer em caso de erro
            while (getchar() != '\n'); // Descarta a entrada inválida
        }
    }
}

// Funcao para verificar se o numero inteiro, positivo e menor que o MAX_INT
int lerNPIQ() {
    int num6;
    while (1) {

        // Usando scanf para ler diretamente o número inteiro
        if (scanf("%d", &num6) == 1 && num6 > 0 && num6 < MAX_INT) {
            return num6; // Retorna o número válido
        } else {
            printf("\nErro! Digite um numero inteiro positivo (maior que 0 e menor que %d):", MAX_INT);

            // Limpa o buffer em caso de erro
            while (getchar() != '\n'); // Descarta a entrada inválida
        }
    }
}

// Funcao para verificar se o numero inteiro, positivo e menor que o MAX_INT
int lerNPIC() {
    int num7;
    while (1) {

        // Usando scanf para ler diretamente o número inteiro
        if (scanf("%d", &num7) == 1 && num7 >= 0) {
            return num7; // Retorna o número válido
        } else {
            printf("\nErro! Digite um numero inteiro e positivo: ");

            // Limpa o buffer em caso de erro
            while (getchar() != '\n'); // Descarta a entrada inválida
        }
    }
}

// Funcao para verificar se o numero float, positivo e menor que o MAX_FLOAT
float lerNPF() {
    float num8;

    while (1) {
        // Usando scanf para ler diretamente o valor float
        if (scanf("%f", &num8) == 1 && num8 > 0.0f && num8 <= MAX_FLOAT) {
            return num8; // Retorna o número válido
        } else {
            printf("\nErro! Digite um numero positivo (menor que %.2f): ", MAX_FLOAT);
            // Limpa o buffer de entrada em caso de erro
            while (getchar() != '\n'); // Descarta a entrada inválida restante
        }
    }
}

// Funcao para cadastrar produtos
void cadastrarProduto(){
	system("cls"); // Limpa a tela
	printf("CADASTRAR PRODUTO:\n\n");
	int num2 = 1; // inicializa 'num2' com '1'
	while(totalProdutos < MAX_Prod){// Enquanto totalProdutos for menor que MAX_Prod o loop continua
		Produto p; // Criacao da variavel do tipo Produto
		p.codigo = totalProdutos; 
		printf("Digite o nome do produto(sem espacos): ");
		scanf("%s", p.nome);
		
		printf("Digite o preco do produto: ");
		p.preco = lerNPF();
		
		produtos[totalProdutos] = p; // Armazena o produto 'p' no array Produto
		totalProdutos++;
		
	
		printf("Produto cadastrado com sucesso! Codigo: %d\n", p.codigo);
		
		printf("\nDigite '1' para cadastrar outro e '0' para parar: ");
		num2 = lerNPI();// Chama a funcao de teste para receber o numero 
		
		if(num2 == 0){ // Sai do loop se 'num2' for igual a 0
			break; 
		}
		
	}
	if(totalProdutos >= MAX_Prod){ // Comparacao entre totalProdutos e MAX_Prod para ver se passou do limite de produtos
		printf("\nLimite atingido!\n\n"); // Se sim aparece esta mensagem
		system("pause"); // funcao da biblioteca <stdlib.h> para pausar a tela
	}
}

// Funcao para chamar a lista de produtos
void listarProduto(){
	system("cls");
	printf("LISTA DE PRODUTOS:\n\n");
	if(totalProdutos == 0){
		printf("Nenhum produto cadastrado!\n");
		system("pause");
		return;
	}
	
	for(int i = 0; i < totalProdutos; i++){ // loop 'for' para mostrar os produtos existentes
		printf("%d. %s:R$ %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco );	
	}
	system("pause");
}

// Funcao para alterar as informacoes do produto
void altInfo() {
	system("cls");

    int codP;
    int confirmacao;
    int confirmacao2;
    int confirmacao3;

    // Exibe a lista de produtos cadastrados antes de solicitar o código
    listarProduto();
    

    // Verifica se há produtos cadastrados
    if(totalProdutos == 0) {
        return;
    }
    
    printf("\nALTERAR INFORMACOES:\n\n");

    // Solicita o código do produto a ser alterado
    printf("\nDigite o codigo do produto: ");
    codP = lerNPIC();
    

    // Verifica se o código do produto é válido
    if(codP < 0 || codP >= totalProdutos) {
        printf("Codigo de produto invalido!\n");
        system("pause");
        return;
    }

    // Exibe as informações atuais do produto
    printf("\nInformacoes atuais do produto:\n");
    printf("Codigo: %d\n", produtos[codP].codigo);
    printf("Nome: %s\n", produtos[codP].nome);
    printf("Preco: R$ %.2f\n", produtos[codP].preco);

    // Pede confirmação para alteração
    printf("\nDigite '1' para alterar ou '0' para cancelar: ");
    confirmacao = lerNPI();
		
	if(confirmacao == 0){
		printf("Operacao cancelada!\n");
	}

    // Se o usuário confirmar a alteração
    if(confirmacao == 1) {
    	printf("\nAlteracao do nome do produto:\n");
    	printf("\nDigite '1' para alterar ou '0' para passar: ");
        confirmacao2 = lerNPI();
    	if(confirmacao2 == 1){
    		// Alteração do nome
            printf("Digite o novo nome do produto(sem espacos): ");
            scanf("%s", produtos[codP].nome);
		}
		printf("\nAlteracao do preco do produto:\n");
		printf("\nDigite '1' para alterar ou '0' para passar: ");
        confirmacao3 = lerNPI();
		if(confirmacao3 == 1){
			// Alteração do preço
            printf("Digite o novo preco do produto: ");
            produtos[codP].preco = lerNPF();
		}
		
		if(confirmacao2 == 1 && confirmacao3 == 1){
			// Confirmação final
            printf("\nProduto alterado com sucesso!\n");
            printf("Novas informacoes do produto:\n");
            printf("Codigo: %d\n", produtos[codP].codigo);
            printf("Nome: %s\n", produtos[codP].nome);
            printf("Preco: R$ %.2f\n", produtos[codP].preco);
		}
		if(confirmacao2 == 0 && confirmacao3 == 0){
			printf("\nSem alteracoes!!\n");
		
		}
    }
    system("pause");
}

// Funcao para remover produtos da lista
void removeProd() {
	system("cls");
	printf("REMOVER PRODUTO:\n\n");
    int codP;
    char confirmacao;

    // Exibe a lista de produtos cadastrados antes de solicitar o codigo
    listarProduto();

    // Verifica se ha produtos cadastrados
    if (totalProdutos == 0) {
        return;
    }

    // Solicita o codigo do produto a ser removido
    printf("Digite o codigo do produto para alteracao: ");
    codP = lerNPIC();

    // Verifica se o codigo do produto e valido
    if (codP < 0 || codP >= totalProdutos) {
        printf("Codigo de produto invalido!\n");
        system("pause");
        return;
    }

    // Exibe as informacoes do produto a ser removido
    printf("\nInformacoes do produto a ser removido:\n");
    printf("Codigo: %d\n", produtos[codP].codigo);
    printf("Nome: %s\n", produtos[codP].nome);
    printf("Preco: R$ %.2f\n", produtos[codP].preco);

    // Pede confirmacao para remocao
    printf("\nDigite '1' para confirmar ou '0' para cancelar: ");
    confirmacao = lerNPI();
			
	if(confirmacao == 0){
		printf("\n\nOperacao cancelada!\n\n");
	}

    // Se o usuario confirmar a remocao
    if (confirmacao == 1) {
        // Remove o produto deslocando os itens no array
        for (int i = codP; i < totalProdutos - 1; i++) {
            produtos[i] = produtos[i + 1];  // Desloca os produtos seguintes
            produtos[i].codigo = i;  // Atualiza o codigo do produto para o indice atual
        }

        totalProdutos--;  // Reduz a contagem de produtos

        printf("Produto removido com sucesso!\n");
    }

    system("pause");
}

// Funcao para comprar produtos
void comprarProduto(){
	system("cls");

	int num3 = 1;
	int codP;
	int q;
	
	listarProduto();

	if(totalProdutos == 0){
		return;
	}
	
	printf("\nCOMPRAR PRODUTOS:\n\n");
	
	while(totalCarrinho < MAX_PCar){
		Carrinho c;
		
		printf("Digite o codigo do produto: ");
		codP = lerNPIC();
		
		if(codP < 0 || codP >= totalProdutos){
			printf("Codigo invalido!!\n");
			continue;
		}
		
		printf("Digite a quantidade do produto: ");
		q = lerNPIQ();
		
		int encontrado = 0;
		int i;
        for(i = 0; i < totalCarrinho; i++) {
            if(carrinho[i].produto.codigo == codP) {
                // Se o produto já estiver no carrinho, aumenta a quantidade
                carrinho[i].quantidade += q;
                printf("\nQuantidade do produto %s atualizada para %d\n", carrinho[i].produto.nome, carrinho[i].quantidade);
                system("pause");
                encontrado = 1;
                break;
            }
        }

//      Se o produto não estava no carrinho, adiciona um novo item
        if(!encontrado) {
            Carrinho c;
            c.produto = produtos[codP];
            c.quantidade = q;

            carrinho[totalCarrinho] = c;
            totalCarrinho++;

            printf("\nProduto adicionado ao carrinho: %s (Quantidade: %d)\n\n", c.produto.nome, c.quantidade);
        }
		
		if(totalCarrinho > MAX_PCar){
		    printf("Limite do carrinho atingido!\n");
		    system("pause");
		    break;
	    }
		
		printf("Digite '0' para finalizar ou '1' para adicionar outro: ");	
		num3 = lerNPI();
		
		if(num3 == 0){
			printf("Operacao cancelada!");
			break;
		}
	}
}

// Funcao para visualzar o carrinho
void visualizarCarrinho(){
	system("cls");
	
	float totalC = 0;
	float totalP = 0;
	
	if(totalProdutos == 0){
		printf("Nenhum produto cadastrado!\n");
		system("pause");
		return;
	}
	if(totalCarrinho == 0){
		printf("Carrinho vazio!\n");
		system("pause");
		return;
	}
	
	printf("\nVISUALIZAR CARRINHO:\n\n");
	
	printf("Carrinho de compras:\n");
	for(int i = 0; i < totalCarrinho; i++){
		
		p = carrinho[i].produto;
		int q = carrinho[i].quantidade;
		
		
		totalP = p.preco * q;
		
		totalC += totalP;
		
		printf("%d. %s:R$ %.2f(Quantidade: %d) - Total: R$%.2f\n", p.codigo, p.nome, p.preco, q, totalP);	
	}
	printf("\nTotal da compra: R$%.2f\n", totalC);
	
	system("pause");
}

// Funcao para remover item do carrinho
void removeCar() {
	system("cls");
	
    int codP;
    int qtdRemover;
    char confirmacao;

    // Exibe os itens do carrinho antes de solicitar o código
    visualizarCarrinho();

    // Verifica se há itens no carrinho
    if (totalCarrinho == 0) {
        printf("Carrinho vazio!\n");
        system("pause");
        return;
    }
    
    printf("\nREMOVER DO CARRINHO:\n\n");

    // Solicita o código do produto a ser removido
    printf("Digite o codigo do produto que deseja remover do carrinho: ");
    codP = lerNPIC();

    // Verifica se o código é válido (com base nos produtos no carrinho)
    int index = -1;
    for (int i = 0; i < totalCarrinho; i++) {
        if (carrinho[i].produto.codigo == codP) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Codigo de produto não encontrado no carrinho!\n");
        system("pause");
        return;
    }

    // Exibe as informações do item a ser removido
    printf("\nInformacoes do item a ser removido:\n");
    printf("Produto: %s\n", carrinho[index].produto.nome);
    printf("Quantidade no carrinho: %d\n", carrinho[index].quantidade);
    printf("Preco total: R$ %.2f\n", carrinho[index].produto.preco * carrinho[index].quantidade);

    // Solicita a quantidade a ser removida
    printf("\nDigite a quantidade que deseja remover: ");
    qtdRemover = lerNPIQ();
		

    // Verifica se a quantidade a ser removida é válida
    if (qtdRemover <= 0 || qtdRemover > carrinho[index].quantidade) {
        printf("Quantidade invalida!\n");
        system("pause");
        return;
    }

    // Pede confirmação para a remoção
    printf("\nDigite '1' para confirmar e '0' para cancelar: ");
    confirmacao = lerNPI();
			
	if(confirmacao == 0){
		printf("\nOperacao cancelada!\n");
		system("pause");
	}

    // Se o usuário confirmar a remoção
    if (confirmacao == 1) {
        if (qtdRemover == carrinho[index].quantidade) {
            // Remove completamente o item do carrinho se a quantidade a remover for igual à quantidade no carrinho
            for (int i = index; i < totalCarrinho - 1; i++) {
                carrinho[i] = carrinho[i + 1];  // Desloca os itens seguintes
            }
            totalCarrinho--;  // Reduz a contagem de itens no carrinho
            printf("Item removido completamente do carrinho!\n");
        } else {
            // Subtrai a quantidade do item no carrinho
            carrinho[index].quantidade -= qtdRemover;
            printf("%d unidade(s) removida(s) do carrinho!\n", qtdRemover);
        }
    }
    
    if(confirmacao == 1){
    	printf("\nCarrinho atualizado:\n\n");
        visualizarCarrinho();
        system("pause");
	}
}

// Funcao para frchar pedido
void fecharPedido(){
	system("cls");
	visualizarCarrinho();
	
	// Verifica se há itens no carrinho
    if (totalCarrinho == 0) {
        return;
    }
    printf("\nFECHAR PEDIDO\n\n");
	
	int conf;
	
	printf("Digite '1' para finalizar ou '0' para nao finalizar o pedido: ");
	conf = lerNPI();
			
	if(conf == 0){
		printf("\nOperacao cancelada!\n");
	}
	
	if(conf == 1){
		totalCarrinho = 0;
		
		printf("\nPedido finalizado com suceso! O carrinho foi esvaziado.\n\n");
	}
	
	system("pause");
	
}

// Funcao do menu principal, mostra as opcoes, recebe o numero e faz o 'switch case' para mandar para a funcao escolhida
void menu(int *num){
	while(1){
		system("cls");
		printf("MENU MERCADO\n");
	    printf("(1)Cadastrar produto\n");
	    printf("(2)Listar produtos\n");
	    printf("(3)Alterar informacao de produtos\n");
	    printf("(4)Remover produtos do estoque\n");
	    printf("(5)Comprar produto\n");
	    printf("(6)Visualizar carrinho\n");
	    printf("(7)Remover produtos do carrinho\n");
	    printf("(8)Fechar pedido\n");
	    printf("(9)Sair\n");
	    printf("Digite o numero da opcao escolhida: ");
	
        *num = lerNPIQ();
	
	    switch(*num){
		    case 1:
			    cadastrarProduto();
			    break;
		    case 2:
			    listarProduto();
		        break;
		    case 3:
			    altInfo();	
			    break; 
		    case 4:
			    removeProd();	
			    break;
		    case 5:
			    comprarProduto();
			    break;
		    case 6:
			    visualizarCarrinho();
			    break;
			case 7:
			    removeCar();
			    break;
			case 8:
			    fecharPedido();
			    break;
			case 9:
			    printf("Tchau!!\n");
			    system("pause");
			    return;
		    default:
			    printf("\nOpcao invalida!!\n\n");
			    system("pause");
			    break;		
	    }
	}
}