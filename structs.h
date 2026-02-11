#ifndef STRUCTS_H
#define STRUCTS_H

//struct para data de nascimento
typedef struct {
    int dia;
    int mes;
    int ano;
} DataNascimento;

//struct para adicionar produto ao carrinho
//obs: o carrinho precisa se ligar a um cliete
typedef struct ItemCarrinho {
    Produto* produto;//encontrar o produto na lista principal de produtos
    int QuantidadeDesejada;
    struct ItemCarrinho* proximo;//liga ao próximo produto dentro do carrinho
} ItemCarrinho;

//struct principal para a lista de clientes
typedef struct Cliente {
    char cpf [15];
    char nome [100];
    char email [100];
    char telefone [20];
    DataNascimento dataNasc;

    //conectando ao carrinho
    struct ItemCarrinho* carrinho;
    struct Cliente* proximo; 
} Cliente;

//struct principal para a lista de produtos
typedef struct Produtos {
    int codigo;
    char nome [100];
    float preco;
    int quantidade;

    //seguindo para o proximo produto da lista
    Produto* proximo; 
} Produto;

#endif

