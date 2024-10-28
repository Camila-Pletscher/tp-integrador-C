#include <stdio.h>
#include <string.h>
#include "Util.h"

// Función para pre-cargar datos de empresas
void preCargarEmpresas(Empresa empresas[], int *num_empresas) {
    strcpy(empresas[0].id_ticker, "AAPL");
    strcpy(empresas[0].nombre, "Apple Inc.");
    empresas[0].precio_actual = 150.0;
    (*num_empresas)++;

    strcpy(empresas[1].id_ticker, "GOOGL");
    strcpy(empresas[1].nombre, "Google LLC");
    empresas[1].precio_actual = 2800.0;
    (*num_empresas)++;

    strcpy(empresas[2].id_ticker, "TSLA");
    strcpy(empresas[2].nombre, "Tesla Inc.");
    empresas[2].precio_actual = 750.0;
    (*num_empresas)++;

    printf("Empresas pre-cargadas correctamente.\n");
}

// Función para pre-cargar datos de clientes
void preCargarClientes(Cliente clientes[], int *num_clientes) {
    strcpy(clientes[0].nombre, "Juan Perez");
    strcpy(clientes[0].email, "juanperez@example.com");
    strcpy(clientes[0].cuit, "20304050607");
    strcpy(clientes[0].password, "juan123");
    clientes[0].saldo_cuenta = 10000.0;
    clientes[0].num_inversiones = 0; // Inicialmente sin inversiones
    (*num_clientes)++;

    strcpy(clientes[1].nombre, "Ana Gomez");
    strcpy(clientes[1].email, "anagomez@example.com");
    strcpy(clientes[1].cuit, "20305060708");
    strcpy(clientes[1].password, "ana456");
    clientes[1].saldo_cuenta = 5000.0;
    clientes[1].num_inversiones = 0; // Inicialmente sin inversiones
    (*num_clientes)++;

    printf("Clientes pre-cargados correctamente.\n");
}

// Función para pre-cargar inversiones para un cliente
void preCargarInversiones(Cliente *cliente, Empresa empresas[], int num_empresas) {
    // Simulamos que Juan Perez compró acciones de Apple
    strcpy(cliente->inversiones[0].id_ticker, "AAPL");
    cliente->inversiones[0].cantidad_acciones = 10;
    cliente->inversiones[0].precio_compra = 145.0;  // Precio de compra por acción
    strcpy(cliente->inversiones[0].fecha, "2024-01-15");
    cliente->num_inversiones++;

    // Actualizamos el saldo después de la compra
    cliente->saldo_cuenta -= cliente->inversiones[0].cantidad_acciones * cliente->inversiones[0].precio_compra;

    printf("Inversiones pre-cargadas para %s.\n", cliente->nombre);
}

