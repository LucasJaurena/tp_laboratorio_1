#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

int main()
{
    EMovie movie;

    char seguir='s';
    int opcion=0;


    while(seguir=='s')
    {
        printf("\n\t\t\tTRABAJO PRACTICO N3\n\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        printf("\nElija una opcion: ");
        scanf("%d",&opcion);

        while(opcion < 1 || opcion > 5)
        {
            printf("\nLa opcion ingresada es invalida!!. Ingrese una opcion del 1 al 5: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
        case 1: agregarPelicula(movie);
                printf("\n");
                system("pause");
                system("cls");
            break;

        case 2: borrarPelicula(movie);
                system("pause");
                system("cls");
            break;

        case 3: modificarPelicula(movie);
                system("pause");
                system("cls");
            break;

        case 4: generarPagina(movie);
                system("pause");
                system("cls");
            break;

        case 5: seguir = 'n';

            break;
        }
    }

    return 0;
}
