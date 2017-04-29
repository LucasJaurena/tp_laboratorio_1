#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define P 20


int main()
{
    ePersona personas[P];
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("\t\t\tTrabajo Practico N2\n\n");
        printf("1- Agregar personas\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");
        printf("Ingrese una opcion: ");

        scanf("%d",&opcion);

        while(opcion<1||opcion>5)
        {
            printf("\nPor favor ingrese una opcion valida: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1: cargarPersonas(personas, P);
                break;

            case 2: borrarPersonas(personas, P);
                break;

            case 3: mostrarDatosOrdenados(personas, P);
                break;

            case 4: //grafico(personas, P);
            system("pause");
            system("cls");
                break;

            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
