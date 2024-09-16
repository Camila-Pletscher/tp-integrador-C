#include <stdio.h>
#include <stdlib.h>

int main()
{
// Programa demostración menú de usuario
// Se presenta un menú al usuario y éste deberá elegir una opción
    char tecla;
    int seleccion=1;
    int subseleccion=1;
    while(seleccion!=0)
    {
// Limpiamos pantalla
        system("cls"); //Si es Windows deberá ser system("cls")
        // dejamos dos líneas en blanco
        printf("\r\n\r\n");
        printf("Menú principal:\r\n");
        printf("---------------\r\n\r\n");
        printf("1 - Broker \r\n");
        printf("2 - Cliente \r\n");
        printf("0 - Salir\r\n\r\n");
        printf("Seleccione una opción: ");
        scanf("%d",&seleccion);
        switch(seleccion)
        {
        case 1:
            system("cls");
            printf("Ha elegido la opción Broker.\r\n");
            printf("Menú Broker:\r\n");
            printf("---------------\r\n\r\n");
            printf("1 - Alta clientes \r\n");
            printf("2 - Baja clientes \r\n");
            printf("3 - Modificación de clientes\r\n");
            printf("4 - Alta de empresas \r\n");
            printf("5 - Baja de empresas \r\n");
            printf("6 - Modificación de empresas\r\n");
            printf("7 - Filtrar operaciones por cliente \r\n");
            printf("8 - Filtrar operaciones por ID ticker \r\n");
            printf("9 - Volver al menú principal \r\n");
            printf("Seleccione una opción: ");
            scanf("%d",&subseleccion);
            break;
        case 2:
            system("cls");
            printf("Ha elegido la opción Cliente.\r\n");
            break;
        case 0:
            break;
        default: // default es opcional
            system("cls");
            printf("La opción %d no existe en el menú.\r\n",seleccion);
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

