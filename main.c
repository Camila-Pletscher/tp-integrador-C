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
        printf("4. Baja de Empresa\n");
        printf("5. Alta de Cliente\n");
        printf("6. Listar Clientes\n");
        printf("7. Modificar Cliente\n");
        printf("8. Baja de Cliente\n");
        printf("9. Realizar Inversión\n");  // Nueva opción
        printf("10. Ver Portafolio\n");     // Nueva opción
        printf("11. Salir\n");
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
            bajaEmpresa(empresas, &num_empresas);
            break;
        case 5:
            altaCliente(clientes, &num_clientes);
            break;
        case 6:
            listarClientes(clientes, num_clientes);
            break;
        case 7:
            modificarCliente(clientes, num_clientes);
            break;
        case 8:
            bajaCliente(clientes, &num_clientes);
            break;
        case 9:
        {
            int cliente_index;
            printf("Ingrese el índice del cliente que realiza la inversión (0 a %d): ", num_clientes - 1);
            scanf("%d", &cliente_index);
            realizarInversion(&clientes[cliente_index], empresas, num_empresas);
            break;
        }
        case 10:
        {
            int cliente_index;
            printf("Ingrese el índice del cliente para ver el portafolio (0 a %d): ", num_clientes - 1);
            scanf("%d", &cliente_index);
            verPortafolio(clientes[cliente_index]);
            break;
        }
        case 11:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción no válida.\n");
        }
    }
    while (opcion != 11);

    return 0;

}

