#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#define TAM 20

int main()
{
    EPersona persona[TAM];

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("\n\t\t\t\tTRABAJO PRACTICO N2\n\t\t\t       ---------------------\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");

        printf("Ingrese una opcion (1-5): ");
        scanf("%d",&opcion);

        while(opcion<1 || opcion>5)
        {
            printf("\nError!!, Ingrese una opcion (1-5): ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1: agregarPersona(persona, TAM);
                break;
            case 2: borrarPersona(persona, TAM);
                break;
            case 3: imprimirLista(persona, TAM);
                break;
            case 4: grafico(persona, TAM);
                break;
            case 5:seguir = 'n';
                break;
        }
    }

    return 0;
}
