#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menuBroker(Cliente clientes[], int *num_clientes, Empresa empresas[], int *num_empresas);
void menuCliente(Cliente clientes[], int num_clientes, Empresa empresas[], int num_empresas);
// Prototipo de función para filtrar operaciones por cliente
void filtrarOperacionesPorCliente(Cliente clientes[], int num_clientes);

// Prototipo de función para filtrar operaciones por ID ticker
void filtrarOperacionesPorTicker(Cliente clientes[], int num_clientes);

#endif // MENU_H_INCLUDED
