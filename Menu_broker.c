#include <stdio.h>
#include "Menu_broker.h"
#include "Empresa.c"

// Funci�n para el men� de broker
void menuBroker(Cliente clientes[], int *num_clientes, Empresa empresas[], int *num_empresas) {
    int opcion;

    do {
        printf("\n--- Men� Broker ---\n");
        printf("1. Alta de clientes\n");
        printf("2. Baja de clientes\n");
        printf("3. Modificar cliente\n");
        printf("4. Listar clientes\n");
        printf("5. Alta de empresas\n");
        printf("6. Baja de empresas\n");
        printf("7. Modificar empresa\n");
        printf("8. Listar empresas\n");
        printf("9. Volver atr�s\n");
        printf("Seleccione una opci�n: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                altaCliente(clientes, num_clientes);
                break;
            case 2:
                bajaCliente(clientes, num_clientes);
                break;
            case 3:
                modificarCliente(clientes, *num_cliententes);
                break;
            case 4:
                listarClientes(clientes, *num_cliententes);
                break;
            case 5:
                altaEmpresa(empresas, num_empresas);
                break;
            case 6:
                bajaEmpresa(empresas, num_empresas);
                break;
            case 7:
                modificarEmpresa(empresas, *num_empresas);
                break;
            case 8:
                listarEmpresas(empresas, *num_empresas);
                break;
            case 9:
                printf("Volviendo al men� principal...\n");
                break;
            default:
                printf("Opci�n no v�lida. Intente nuevamente.\n");
        }
    } while (opcion != 9);
}
