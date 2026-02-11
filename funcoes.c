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

//funcoes do gerenciamento de produtos
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
