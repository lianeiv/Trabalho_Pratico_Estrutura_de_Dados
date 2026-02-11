#ifndef FUNCOES_H
#define FUNCOES_H
#include "structs.h"

//para manter o codigo principal menos poluido
void limparBuffer ();
void pausarSistema (); 

//gerenciamento de clientes
void cadastrarCliente(Cliente** listaClientes);
void listarClientes(Cliente* listaClientes); 
Cliente* buscarClientePorCPF(Cliente* listaClientes, const char* cpf);
void editarCliente(Cliente* listaClientes);
void removerCliente(Cliente** listaClientes, const char* cpf);
