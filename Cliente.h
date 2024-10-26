#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "Empresa.h"

typedef struct Cliente{
    char nombre[50];
    char email[50];
    char cuit[15];
    char password[20];
    float saldo_cuenta;
    Inversion inversiones[500];
    int num_inversiones;
} Cliente;

// Prototipos de funciones para cliente
void altaCliente(Cliente clientes[], int *num_clientes);
void listarClientes(Cliente clientes[], int num_clientes);
void modificarCliente(Cliente clientes[], int num_clientes);
void bajaCliente(Cliente clientes[], int *num_clientes);

#endif // CLIENTE_H_INCLUDED
