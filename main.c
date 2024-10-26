#include <stdio.h>
#include <stdlib.h>
#include "Broker.c"
#include "Util.h"
#include "Cliente.h"
#include "Empresa.c"

int main()
{

    Empresa empresas[100];  // Creamos un array de empresas
    Cliente clientes[100];  // Creamos un array de clientes
    int num_empresas = 0;    // Contador de empresas
    int num_clientes = 0;    // Contador de clientes
    int opcion;

    do
    {
        printf("\nSeleccione una opción:\n");
        printf("1. Alta de Empresa\n");
        printf("2. Listar Empresas\n");
        printf("3. Modificar Empresa\n");
        printf("4. Alta de Cliente\n");
        printf("5. Listar Clientes\n");
        printf("6. Modificar Cliente\n");
        printf("7. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            altaEmpresa(empresas, &num_empresas);
            break;
        case 2:
            listarEmpresas(empresas, num_empresas);
            break;
        case 3:
            modificarEmpresa(empresas, num_empresas);
            break;
        case 4:
            altaCliente(clientes, &num_clientes);
            break;
        case 5:
            listarClientes(clientes, num_clientes);
            break;
        case 6:
            modificarCliente(clientes, num_clientes);
            break;
        case 7:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción no válida.\n");
        }
    }
    while (opcion != 7);

    return 0;

}

