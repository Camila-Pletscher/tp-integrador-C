// cliente.c
#include <stdio.h>
#include <string.h>
#include "Cliente.h"

// Función para cargar un cliente
void altaCliente(Cliente clientes[], int *num_clientes) {
    Cliente nuevo;

    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nuevo.nombre);

    printf("Ingrese el email del cliente: ");
    scanf("%s", nuevo.email);

    printf("Ingrese el CUIT del cliente: ");
    scanf("%s", nuevo.cuit);

    printf("Ingrese la contraseña del cliente: ");
    scanf("%s", nuevo.password);

    printf("Ingrese el saldo inicial del cliente: ");
    scanf("%f", &nuevo.saldo_cuenta);

    // Inicializamos el número de inversiones en 0
    nuevo.num_inversiones = 0;

    // Guardamos el cliente en el array
    clientes[*num_clientes] = nuevo;
    (*num_clientes)++;
}

// Función para mostrar los clientes cargados
void listarClientes(Cliente clientes[], int num_clientes) {
    printf("\nListado de Clientes:\n");
    for (int i = 0; i < num_clientes; i++) {
        printf("Nombre: %s | Email: %s | CUIT: %s | Saldo: %.2f\n",
               clientes[i].nombre, clientes[i].email, clientes[i].cuit, clientes[i].saldo_cuenta);
    }
}

// Función para modificar un cliente
void modificarCliente(Cliente clientes[], int num_clientes) {
    char cuit[15];
    int encontrado = 0;

    printf("Ingrese el CUIT del cliente a modificar: ");
    scanf("%s", cuit);

    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].cuit, cuit) == 0) {
            printf("Cliente encontrado: %s | Saldo Actual: %.2f\n", clientes[i].nombre, clientes[i].saldo_cuenta);

            // Modificación del email y del saldo
            printf("Ingrese el nuevo email del cliente: ");
            scanf("%s", clientes[i].email);

            printf("Ingrese el nuevo saldo del cliente: ");
            scanf("%f", &clientes[i].saldo_cuenta);

            printf("Datos del cliente modificados con éxito.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente con CUIT %s no encontrado.\n", cuit);
    }
}
