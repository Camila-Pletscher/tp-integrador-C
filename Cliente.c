// cliente.c
#include <stdio.h>
#include <string.h>
#include "Cliente.h"

// Funci�n para cargar un cliente
void altaCliente(Cliente clientes[], int *num_clientes)
{
    Cliente nuevo;

    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nuevo.nombre);

    printf("Ingrese el email del cliente: ");
    scanf("%s", nuevo.email);

    printf("Ingrese el CUIT del cliente: ");
    scanf("%s", nuevo.cuit);

    printf("Ingrese la contrase�a del cliente: ");
    scanf("%s", nuevo.password);

    printf("Ingrese el saldo inicial del cliente: ");
    scanf("%f", &nuevo.saldo_cuenta);

    // Inicializamos el n�mero de inversiones en 0
    nuevo.num_inversiones = 0;

    // Guardamos el cliente en el array
    clientes[*num_clientes] = nuevo;
    (*num_clientes)++;
}

// Funci�n para mostrar los clientes cargados
void listarClientes(Cliente clientes[], int num_clientes)
{
    printf("\nListado de Clientes:\n");
    for (int i = 0; i < num_clientes; i++)
    {
        printf("Nombre: %s | Email: %s | CUIT: %s | Saldo: %.2f\n",
               clientes[i].nombre, clientes[i].email, clientes[i].cuit, clientes[i].saldo_cuenta);
    }
}

// Funci�n para modificar un cliente
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

            // Modificaci�n del email y del saldo
            printf("Ingrese el nuevo email del cliente: ");
            scanf("%s", clientes[i].email);

            printf("Ingrese el nuevo saldo del cliente: ");
            scanf("%f", &clientes[i].saldo_cuenta);

            printf("Datos del cliente modificados con �xito.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Cliente con CUIT %s no encontrado.\n", cuit);
    }
}

// Funci�n para dar de baja un cliente
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
            printf("Cliente encontrado: %s ser� eliminado.\n", clientes[i].nombre);

            // Desplazamos los clientes para llenar el hueco
            for (int j = i; j < *num_clientes - 1; j++)
            {
                clientes[j] = clientes[j + 1];
            }

            (*num_clientes)--;  // Reducimos el contador de clientes
            encontrado = 1;
            printf("Cliente eliminado con �xito.\n");
            break;
        }
    }

    if (!encontrado)
    {
        printf("Cliente con CUIT %s no encontrado.\n", cuit);
    }
}

// Funci�n para realizar una inversi�n (Compra de acciones)
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

                // Registramos la inversi�n en el portafolio del cliente
                Inversion nueva_inversion;
                strcpy(nueva_inversion.id_ticker, empresa->id_ticker);
                nueva_inversion.cantidad_acciones = cantidad_acciones;
                nueva_inversion.precio_compra = empresa->precio_actual;
                printf("Ingrese la fecha de la inversi�n (AAAA-MM-DD): ");
                scanf("%s", nueva_inversion.fecha);

                cliente->inversiones[cliente->num_inversiones] = nueva_inversion;
                cliente->num_inversiones++;

                printf("Compra realizada con �xito. Nuevo saldo: %.2f\n", cliente->saldo_cuenta);
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

// Funci�n para ver el portafolio de inversiones de un cliente
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

// Funci�n para vender acciones
void venderAcciones(Cliente *cliente, Empresa empresas[], int num_empresas) {
    if (cliente->num_inversiones == 0) {
        printf("El cliente no tiene inversiones para vender.\n");
        return;
    }

    printf("\nPortafolio de %s:\n", cliente->nombre);
    for (int i = 0; i < cliente->num_inversiones; i++) {
        Inversion inv = cliente->inversiones[i];
        printf("%d. Empresa: %s | Cantidad de acciones: %d | Precio de compra: %.2f | Fecha: %s\n",
               i + 1, inv.id_ticker, inv.cantidad_acciones, inv.precio_compra, inv.fecha);
    }

    int seleccion;
    printf("Seleccione el n�mero de la inversi�n que desea vender: ");
    scanf("%d", &seleccion);
    seleccion--;  // Ajustamos el �ndice

    if (seleccion < 0 || seleccion >= cliente->num_inversiones) {
        printf("Selecci�n inv�lida.\n");
        return;
    }

    Inversion *inv = &cliente->inversiones[seleccion];
    Empresa *empresa = NULL;

    // Buscamos la empresa correspondiente
    for (int i = 0; i < num_empresas; i++) {
        if (strcmp(empresas[i].id_ticker, inv->id_ticker) == 0) {
            empresa = &empresas[i];
            break;
        }
    }

    if (!empresa) {
        printf("Error: Empresa no encontrada.\n");
        return;
    }

    int cantidad_a_vender;
    printf("Ingrese la cantidad de acciones a vender (m�ximo %d): ", inv->cantidad_acciones);
    scanf("%d", &cantidad_a_vender);

    if (cantidad_a_vender <= 0 || cantidad_a_vender > inv->cantidad_acciones) {
        printf("Cantidad de acciones inv�lida.\n");
        return;
    }

    // Calculamos el total de la venta
    float total_venta = cantidad_a_vender * empresa->precio_actual;
    cliente->saldo_cuenta += total_venta;  // Sumamos al saldo del cliente
    inv->cantidad_acciones -= cantidad_a_vender;  // Restamos las acciones vendidas

    printf("Venta realizada con �xito. Total recibido: %.2f | Nuevo saldo: %.2f\n",
           total_venta, cliente->saldo_cuenta);

    // Si el cliente vendi� todas las acciones de esa empresa, eliminamos la inversi�n
    if (inv->cantidad_acciones == 0) {
        // Desplazamos las inversiones para llenar el hueco
        for (int i = seleccion; i < cliente->num_inversiones - 1; i++) {
            cliente->inversiones[i] = cliente->inversiones[i + 1];
        }
        cliente->num_inversiones--;  // Reducimos el n�mero de inversiones
    }
}
// Funci�n para calcular el rendimiento de las inversiones de un cliente
void calcularRendimiento(Cliente cliente, Empresa empresas[], int num_empresas) {
    if (cliente.num_inversiones == 0) {
        printf("El cliente no tiene inversiones.\n");
        return;
    }

    printf("\nRendimiento de las inversiones de %s:\n", cliente.nombre);

    // Iteramos por cada inversi�n del cliente
    for (int i = 0; i < cliente.num_inversiones; i++) {
        Inversion inv = cliente.inversiones[i];
        Empresa *empresa = NULL;

        // Buscamos la empresa correspondiente
        for (int j = 0; j < num_empresas; j++) {
            if (strcmp(empresas[j].id_ticker, inv.id_ticker) == 0) {
                empresa = &empresas[j];
                break;
            }
        }

        if (!empresa) {
            printf("Error: Empresa no encontrada para la inversi�n %s.\n", inv.id_ticker);
            continue;
        }

        // Calcular el valor actual de la inversi�n
        float valor_actual = inv.cantidad_acciones * empresa->precio_actual;
        float valor_compra = inv.cantidad_acciones * inv.precio_compra;

        // Calcular el rendimiento en porcentaje
        float rendimiento = ((empresa->precio_actual - inv.precio_compra) / inv.precio_compra) * 100;

        // Mostrar resultados
        printf("Empresa: %s | Cantidad: %d | Precio de compra: %.2f | Precio actual: %.2f\n",
               inv.id_ticker, inv.cantidad_acciones, inv.precio_compra, empresa->precio_actual);
        printf("Valor de compra: %.2f | Valor actual: %.2f\n", valor_compra, valor_actual);
        printf("Rendimiento: %.2f%%\n", rendimiento);
        printf("-----------------------------\n");
    }
}
