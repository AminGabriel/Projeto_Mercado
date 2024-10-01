# Mercado em C

Mercado que permite a adicam de produtos e compra.

##Indice

- [Sobre o projeto](#sobre-o-projeto)
- [Tecnologia Utilizadas](#tecnologias-utilizadas)
- [Instalacao](#instalacao)
- [Uso](#uso)
- [Observacao](#observacao)


##Sobre o Projeto

Este projeto e um sitema de gestao de produtos para um mercado. Ele permite cadastrar, listar, editar e remover produtos, 
alem de permitir um uso como cliente, permitindo a compra de produtos, ver o carrinho, remover produtos do carrinho e fechar o pedido. 

## Funcionalidades 

- Cadastrar produtoscom nome, preco e quantidade.
- Exibir a lista de produtos cadastrados.
- Atualizar informacoes de um produto.
- Remover produtos da lista.
- Adicionar produtos ao carrinho.
- Vizualizar o carrinho.
- Remover produtos e quantidades de produtos do carrinho.
- Fechar o pedido.

#Tecnologias Utilizadas

- C(Linguagem de Programacao)
- Biblioteca padrao do C('stdlib.h','stdio.h', 'string.h', 'dirent.h')
- [Dev-C++](https://sourceforge.net/projects/orwelldevcpp/) (Ambiente de Desenvolvimento)


## Instalacao

### Pelo Git

Para executar o projeto localmente, siga as instrucoes abaixo:

1. Clone o repositorio para o seu ambiente local:

    ```bash
    git clone https://github.com/AminGabriel/Projeto_Mercado.git
    ```

2. Compile o codigo com um compilador C, como o GCC:

    ```bash
    gcc main.c funcoes.c -o sistema_mercado
    ```

3. Execute o programa:

    ```bash
    ./sistema_mercado
    ```
### Pelo Arquivo

1. Instale o arquivo compactado.

2. Descomprima o arquivo.

3. Abra o Dev-C++.

4. Abra o Projeto_Mercado_Final.

5. Abra os arquivos subjacentes.

6. Escolha a opcao 'Compile & Run'.

## Uso

1. Ao iniciar o programa, escolha a opcao para cadastrar um novo produto.
2. Insira o nome, preco e quantidade do produto.
3. Para listar todos os produtos, selecione a opcao "Listar Produtos".
4. Para remover ou editar um produto, escolha a opcao correspondente e insira o codigo do produto.
5. Para comprar um produto escolha a opcao 'Comprar produto' e escreva o codigo do produto.
6. Para visualizar o carrinho, escolha a opcao 'Visualizar carrinho' e entao aparecera os produtos dentro do carrinho.
7. Para remover produtos do carrinho escolha a respectiva opcao, digite o codigo e confirme.
8. Feche o pedido em 'Fechar pedido', ira aparecer o carrinho com o preco da compra e a opcao de confirmar o fechamento do pedido.
9. fecha o programa.

## Observacao

Sem uso de caracteres especiais, pois a biblioteca nao funcionou.