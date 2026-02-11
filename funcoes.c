#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausarSistema() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

void cadastrarProduto(Produto** listaProdutos) {
    Produto* novoProduto = (Produto*) malloc(sizeof(Produto));
    if (novoProduto == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        return;
    }

    printf("\n--- Cadastro de Novo Produto ---\n");
    printf("Codigo unico: ");
    scanf("%d", &novoProduto->codigo);
    limparBuffer();

    if (buscarProdutoPorCodigo(*listaProdutos, novoProduto->codigo) != NULL) {
        printf("Erro: Codigo de produto ja existente!\n");
        free(novoProduto);
        return;
    }

    printf("Nome do produto: ");
    scanf("%99[^\n]", novoProduto->nome);
    limparBuffer();

    printf("Preco: ");
    scanf("%f", &novoProduto->preco);
    limparBuffer();

    printf("Quantidade em estoque: ");
    scanf("%d", &novoProduto->quantidade);
    limparBuffer();

    novoProduto->proximo = *listaProdutos;
    *listaProdutos = novoProduto;

    printf("\nProduto '%s' cadastrado com sucesso!\n", novoProduto->nome);
}

void removerCliente(Cliente** listaClientes, const char* cpf) {
    Cliente* anterior = NULL;
    Cliente* atual = *listaClientes;

    while (atual != NULL && strcmp(atual->cpf, cpf) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Erro: Cliente nao encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *listaClientes = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    printf("\nCliente '%s' (CPF: %s) foi removido com sucesso.\n", atual->nome, atual->cpf);
    free(atual);
}

void adicionarProdutoAoCarrinho(Cliente* listaClientes, Produto* listaProdutos) {
    char cpf[15];
    int codigoProduto, quantidadeDesejada;

    printf("\n--- Adicionar Produto ao Carrinho ---\n");
    printf("Digite o CPF do cliente: ");
    scanf("%14s", cpf);
    limparBuffer();

    Cliente* cliente = buscarClientePorCPF(listaClientes, cpf);
    if (cliente == NULL) {
        printf("Erro: Cliente nao encontrado.\n");
        return;
    }

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigoProduto);
    limparBuffer();

    Produto* produto = buscarProdutoPorCodigo(listaProdutos, codigoProduto);
    if (produto == NULL) {
        printf("Erro: Produto nao encontrado.\n");
        return;
    }

    printf("Produto encontrado: %s | Preco: R$%.2f | Estoque: %d\n",
           produto->nome, produto->preco, produto->quantidade);

    if (produto->quantidade == 0) {
        printf("Produto fora de estoque.\n");
        return;
    }

    printf("Digite a quantidade desejada: ");
    scanf("%d", &quantidadeDesejada);
    limparBuffer();

    if (quantidadeDesejada <= 0 || quantidadeDesejada > produto->quantidade) {
        printf("Erro: Quantidade invalida ou insuficiente em estoque.\n");
        return;
    }

    ItemCarrinho* novoItem = (ItemCarrinho*) malloc(sizeof(ItemCarrinho));
    if (novoItem == NULL) {
        printf("Erro de alocacao de memoria para o item do carrinho!\n");
        return;
    }

    novoItem->produto = produto;
    novoItem->quantidade = quantidadeDesejada;

    novoItem->proximo = cliente->carrinho;
    cliente->carrinho = novoItem;

    produto->quantidade -= quantidadeDesejada;

    printf("\n%d unidade(s) de '%s' adicionada(s) ao carrinho de %s.\n",
           quantidadeDesejada, produto->nome, cliente->nome);
}