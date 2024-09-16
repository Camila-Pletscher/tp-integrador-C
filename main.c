#include <stdio.h>
#include <stdlib.h>

int main()
{
// Programa demostraci�n men� de usuario
// Se presenta un men� al usuario y �ste deber� elegir una opci�n
    char tecla;
    int seleccion=1;
    int subseleccion=1;
    while(seleccion!=0)
    {
// Limpiamos pantalla
        system("cls"); //Si es Windows deber� ser system("cls")
        // dejamos dos l�neas en blanco
        printf("\r\n\r\n");
        printf("Men� principal:\r\n");
        printf("---------------\r\n\r\n");
        printf("1 - Broker \r\n");
        printf("2 - Cliente \r\n");
        printf("0 - Salir\r\n\r\n");
        printf("Seleccione una opci�n: ");
        scanf("%d",&seleccion);
        switch(seleccion)
        {
        case 1:
            system("cls");
            printf("Ha elegido la opci�n Broker.\r\n");
            printf("Men� Broker:\r\n");
            printf("---------------\r\n\r\n");
            printf("1 - Alta clientes \r\n");
            printf("2 - Baja clientes \r\n");
            printf("3 - Modificaci�n de clientes\r\n");
            printf("4 - Alta de empresas \r\n");
            printf("5 - Baja de empresas \r\n");
            printf("6 - Modificaci�n de empresas\r\n");
            printf("7 - Filtrar operaciones por cliente \r\n");
            printf("8 - Filtrar operaciones por ID ticker \r\n");
            printf("9 - Volver al men� principal \r\n");
            printf("Seleccione una opci�n: ");
            scanf("%d",&subseleccion);
            break;
        case 2:
            system("cls");
            printf("Ha elegido la opci�n Cliente.\r\n");
            break;
        case 0:
            break;
        default: // default es opcional
            system("cls");
            printf("La opci�n %d no existe en el men�.\r\n",seleccion);
            break;
        }
        if(seleccion!=0)
        {
            printf("Presione Enter para continuar.");
            tecla=getchar();
            while (tecla != '\n' && tecla != EOF )
            {
                tecla=getchar();
            }
            getchar();
        }
    }
    system("clear");
    printf("Gracias! Vuelva pronto!\r\n");
    return 0;
}

