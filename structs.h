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
    struct Produto* produto;//encontrar o produto na lista principal de produtos
    int QuantidadeDesejada;
    struct ItemCarrinho* proximo;//liga ao próximo produto dentro do carrinho
}
