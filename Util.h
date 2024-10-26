#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

// Prototipos de funciones de pre-carga
void preCargarEmpresas(Empresa empresas[], int *num_empresas);
void preCargarClientes(Cliente clientes[], int *num_clientes);
void preCargarInversiones(Cliente *cliente, Empresa empresas[], int num_empresas);

#endif // UTIL_H_INCLUDED
