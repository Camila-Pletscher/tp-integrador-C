#include <stdio.h>
#include <stdlib.h>
#include "Empresa.h"

// Función para cargar una empresa
void altaEmpresa(Empresa empresas[], int *num_empresas)
{
    Empresa nueva;

    printf("Ingrese el ID ticker de la empresa: ");
    scanf("%s", nueva.id_ticker);

    printf("Ingrese el nombre de la empresa: ");
    scanf("%s", nueva.nombre);

    printf("Ingrese el precio actual por acción: ");
    scanf("%f", &nueva.precio_actual);

    // Guardamos la empresa en el array
    empresas[*num_empresas] = nueva;
    (*num_empresas)++;
}

// Función para mostrar las empresas cargadas
void listarEmpresas(Empresa empresas[], int num_empresas)
{
    printf("\nListado de Empresas:\n");
    for (int i = 0; i < num_empresas; i++)
    {
        printf("ID Ticker: %s | Nombre: %s | Precio Actual: %.2f\n",
               empresas[i].id_ticker, empresas[i].nombre, empresas[i].precio_actual);
    }
}

// Función para modificar una empresa
void modificarEmpresa(Empresa empresas[], int num_empresas) {
    char id_ticker[10];
    int encontrada = 0;

    printf("Ingrese el ID ticker de la empresa a modificar: ");
    scanf("%s", id_ticker);

    for (int i = 0; i < num_empresas; i++) {
        if (strcmp(empresas[i].id_ticker, id_ticker) == 0) {
            printf("Empresa encontrada: %s | Precio Actual: %.2f\n", empresas[i].nombre, empresas[i].precio_actual);

            // Modificación del nombre y del precio actual
            printf("Ingrese el nuevo nombre de la empresa: ");
            scanf("%s", empresas[i].nombre);

            printf("Ingrese el nuevo precio por acción: ");
            scanf("%f", &empresas[i].precio_actual);

            printf("Datos de la empresa modificados con éxito.\n");
            encontrada = 1;
            break;
        }
    }

    if (!encontrada) {
        printf("Empresa con ID ticker %s no encontrada.\n", id_ticker);
    }
}

// Función para dar de baja una empresa
void bajaEmpresa(Empresa empresas[], int *num_empresas) {
    char id_ticker[10];
    int encontrada = 0;

    printf("Ingrese el ID ticker de la empresa a eliminar: ");
    scanf("%s", id_ticker);

    for (int i = 0; i < *num_empresas; i++) {
        if (strcmp(empresas[i].id_ticker, id_ticker) == 0) {
            printf("Empresa encontrada: %s será eliminada.\n", empresas[i].nombre);

            // Desplazamos las empresas para llenar el hueco
            for (int j = i; j < *num_empresas - 1; j++) {
                empresas[j] = empresas[j + 1];
            }

            (*num_empresas)--;  // Reducimos el contador de empresas
            encontrada = 1;
            printf("Empresa eliminada con éxito.\n");
            break;
        }
    }

    if (!encontrada) {
        printf("Empresa con ID ticker %s no encontrada.\n", id_ticker);
    }
}
