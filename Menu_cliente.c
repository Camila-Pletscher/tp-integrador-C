#include <stdio.h>
#include "menu_cliente.h"

// Funci�n para el men� de cliente
void menuCliente(Cliente clientes[], int num_clientes, Empresa empresas[], int num_empresas) {
    int opcion;

    do {
        printf("\n--- Men� Cliente ---\n");
        printf("1. Realizar inversi�n\n");
        printf("2. Listar empresas\n");
        printf("3. Calcular rendimiento\n");
        printf("4. Ver portafolio\n");
        printf("5. Volver atr�s\n");
        printf("Seleccione una opci�n: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: {
                int cliente_index;
                printf("Ingrese el �ndice del cliente que realiza la inversi�n (0 a %d): ", num_clientes - 1);
                scanf("%d", &cliente_index);
                realizarInversion(&clientes[cliente_index], empresas, num_empresas);
                break;
            }
            case 2:
                listarEmpresas(empresas, num_empresas);
                break;
            case 3: {
                int cliente_index;
                printf("Ingrese el �ndice del cliente para calcular el rendimiento (0 a %d): ", num_clientes - 1);
                scanf("%d", &cliente_index);
                calcularRendimiento(clientes[cliente_index], empresas, num_empresas);
                break;
            }
            case 4: {
                int cliente_index;
                printf("Ingrese el �ndice del cliente para ver el portafolio (0 a %d): ", num_clientes - 1);
                scanf("%d", &cliente_index);
                verPortafolio(clientes[cliente_index]);
                break;
            }
            case 5:
                printf("Volviendo al men� principal...\n");
                break;
            default:
                printf("Opci�n no v�lida. Intente nuevamente.\n");
        }
    } while (opcion != 5);
}
