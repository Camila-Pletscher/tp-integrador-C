// cliente.c
#include <stdio.h>
#include <string.h>
#include "Cliente.h"

// Función para cargar un cliente
void altaCliente(Cliente clientes[], int *num_clientes)
{
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
void listarClientes(Cliente clientes[], int num_clientes)
{
    printf("\nListado de Clientes:\n");
    for (int i = 0; i < num_clientes; i++)
    {
        printf("Nombre: %s | Email: %s | CUIT: %s | Saldo: %.2f\n",
               clientes[i].nombre, clientes[i].email, clientes[i].cuit, clientes[i].saldo_cuenta);
    }
}

// Función para modificar un cliente
void modificarCliente(Cliente clientes[], int num_clientes)
{
    char cuit[15];
    int encontrado = 0;

    printf("Ingrese el CUIT del cliente a modificar: ");
    scanf("%s", cuit);

    for (int i = 0; i < num_clientes; i++)
    {
        if (strcmp(clientes[i].cuit, cuit) == 0)
        {
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

    if (!encontrado)
    {
        printf("Cliente con CUIT %s no encontrado.\n", cuit);
    }
}

// Función para dar de baja un cliente
void bajaCliente(Cliente clientes[], int *num_clientes)
{
    char cuit[15];
    int encontrado = 0;

    printf("Ingrese el CUIT del cliente a eliminar: ");
    scanf("%s", cuit);

    for (int i = 0; i < *num_clientes; i++)
    {
        if (strcmp(clientes[i].cuit, cuit) == 0)
        {
            printf("Cliente encontrado: %s será eliminado.\n", clientes[i].nombre);

            // Desplazamos los clientes para llenar el hueco
            for (int j = i; j < *num_clientes - 1; j++)
            {
                clientes[j] = clientes[j + 1];
            }

            (*num_clientes)--;  // Reducimos el contador de clientes
            encontrado = 1;
            printf("Cliente eliminado con éxito.\n");
            break;
        }
    }

    if (!encontrado)
    {
        printf("Cliente con CUIT %s no encontrado.\n", cuit);
    }
}

// Función para realizar una inversión (Compra de acciones)
void realizarInversion(Cliente *cliente, Empresa empresas[], int num_empresas)
{
    char id_ticker[10];
    int cantidad_acciones;
    int empresa_encontrada = 0;

    printf("\nListado de Empresas disponibles:\n");
    listarEmpresas(empresas, num_empresas);  // Listamos todas las empresas

    printf("\nIngrese el ID ticker de la empresa en la que desea invertir: ");
    scanf("%s", id_ticker);

    // Buscamos la empresa seleccionada
    for (int i = 0; i < num_empresas; i++)
    {
        if (strcmp(empresas[i].id_ticker, id_ticker) == 0)
        {
            Empresa *empresa = &empresas[i];  // Empresa encontrada
            printf("Empresa seleccionada: %s | Precio actual: %.2f\n", empresa->nombre, empresa->precio_actual);

            printf("Ingrese la cantidad de acciones a comprar: ");
            scanf("%d", &cantidad_acciones);

            float total_compra = cantidad_acciones * empresa->precio_actual;

            // Verificamos que el cliente tenga saldo suficiente
            if (cliente->saldo_cuenta >= total_compra)
            {
                // Restamos el saldo
                cliente->saldo_cuenta -= total_compra;

                // Registramos la inversión en el portafolio del cliente
                Inversion nueva_inversion;
                strcpy(nueva_inversion.id_ticker, empresa->id_ticker);
                nueva_inversion.cantidad_acciones = cantidad_acciones;
                nueva_inversion.precio_compra = empresa->precio_actual;
                printf("Ingrese la fecha de la inversión (AAAA-MM-DD): ");
                scanf("%s", nueva_inversion.fecha);

                cliente->inversiones[cliente->num_inversiones] = nueva_inversion;
                cliente->num_inversiones++;

                printf("Compra realizada con éxito. Nuevo saldo: %.2f\n", cliente->saldo_cuenta);
            }
            else
            {
                printf("Saldo insuficiente para realizar la compra.\n");
            }

            empresa_encontrada = 1;
            break;
        }
    }

    if (!empresa_encontrada)
    {
        printf("Empresa con ID ticker %s no encontrada.\n", id_ticker);
    }
}

// Función para ver el portafolio de inversiones de un cliente
void verPortafolio(Cliente cliente)
{
    printf("\nPortafolio de %s:\n", cliente.nombre);
    for (int i = 0; i < cliente.num_inversiones; i++)
    {
        Inversion inv = cliente.inversiones[i];
        printf("Empresa: %s | Cantidad de acciones: %d | Precio de compra: %.2f | Fecha: %s\n",
               inv.id_ticker, inv.cantidad_acciones, inv.precio_compra, inv.fecha);
    }
    if (cliente.num_inversiones == 0)
    {
        printf("No hay inversiones registradas.\n");
    }
}

