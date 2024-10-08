#ifndef BROKER_H_INCLUDED
#define BROKER_H_INCLUDED

//Estructura de la empresa
    typedef struct Empresa
    {
        char id_ticker[10];
        char nombre[50];
        float precio_total;

    } Empresa;

//Estructura de la inversion

    typedef struct Inversion
    {
        char id_ticker[10];
        int cantidad_acciones;
        float precio_compra;
        char fecha[11];
    } Inversion;

//Estructura del cliente

    typedef struct Cliente
    {
        char* nombre[50];
        char* email[50];
        int cuit[15];
        char password[20];
        float saldo_cuenta;
        Inversion Inversiones[500];
        int num_inversiones;

    } Cliente;

//firmas de las fx

//alta cliente

//alta empresa



#endif // BROKER_H_INCLUDED
