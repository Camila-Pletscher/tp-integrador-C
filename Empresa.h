#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct Empresa {
    char id_ticker[10];
    char nombre[50];
    float precio_actual;
} Empresa;

typedef struct Inversion {
    char id_ticker[10];
    int cantidad_acciones;
    float precio_compra;
    char fecha[11];
} Inversion;

// Prototipos de funciones para empresa
void altaEmpresa(Empresa empresas[], int *num_empresas);
void listarEmpresas(Empresa empresas[], int num_empresas);
void modificarEmpresa(Empresa empresas[], int num_empresas);
void bajaEmpresa(Empresa empresas[], int *num_empresas);

#endif // EMPRESA_H_INCLUDED
