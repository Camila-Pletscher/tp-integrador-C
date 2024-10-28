#include <stdio.h>
#include <stdlib.h>
#include "Broker.c"
#include "Empresa.c"
#include "Util.c"
#include "Menu.c"

int main()
{

Empresa empresas[100];   // Creamos un array de empresas
    Cliente clientes[100];   // Creamos un array de clientes
    int num_empresas = 0;    // Contador de empresas
    int num_clientes = 0;    // Contador de clientes
    int opcion;

    // Pre-cargamos empresas, clientes y sus inversiones
    preCargarEmpresas(empresas, &num_empresas);
    preCargarClientes(clientes, &num_clientes);
    preCargarInversiones(&clientes[0], empresas, num_empresas);  // Inversiones para Juan Perez

    do {
        printf("\n--- Menú Principal ---\n");
        printf("1. Operar como Cliente\n");
        printf("2. Operar como Broker\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                menuCliente(clientes, num_clientes, empresas, num_empresas);  // Llamamos al menú de cliente
                break;
            case 2:
                menuBroker(clientes, &num_clientes, empresas, &num_empresas);  // Llamamos al menú de broker
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 3);
    return 0;

}

