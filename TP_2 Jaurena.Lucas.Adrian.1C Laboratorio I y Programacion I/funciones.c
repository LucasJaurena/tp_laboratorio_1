#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void cargarPersonas(ePersona lista[], int tam)
{
    int i;
    int cont=1;

    for(i=0;i<tam;i++)
    {
        system("cls");
        printf("1- Agregar personas\n\n");
        printf("Ingresando los datos de la persona Numero %d",cont);
        cont++;
        printf("\n\nIngrese un nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("\nIngrese la edad: ");
        scanf("%d",&lista[i].edad);
        printf("\nIngrese el DNI: ");
        scanf("%ld",&lista[i].dni);
        lista[i].estado = 1;
        system("pause");
        system("cls");
    }
}

void borrarPersonas(ePersona lista[], int tam)
{
    int i;
    long int DNI;
    char respuesta;

    printf("\nIngrese el DNI a buscar: ");
    scanf("%ld",&DNI);
    for (i=0;i<tam;i++)
    {
        if(lista[i].estado == 1 && DNI == lista[i].dni)
        {
            printf("\nSe a encontrado una persona\n\nNOMBRE\t\tEDAD\t\tDNI\n%s\t\t%d\t\t%ld\n",lista[i].nombre,lista[i].edad,lista[i].dni);
            printf("\nEsta seguro que desea borrar a esta persona? s/n\n");
            respuesta = getche();
            if(respuesta == 's')
            {
                lista[i].estado = 0;
                printf("\n\nOperacion realizada con exito\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("\n\nOperacion cancelada con exito\n\n");
                system("pause");
                system("cls");
            }
        }
    }
}

void mostrarDatosOrdenados(ePersona lista[], int tam)
{
    int i,j,k,auxEdad;
    long int auxDNI;
    char auxNombre[50];

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                strcpy(auxNombre,lista[i].nombre);
                strcpy(lista[i].nombre,lista[j].nombre);
                strcpy(lista[j].nombre,auxNombre);

                auxEdad = lista[i].edad;
                lista[i].edad = lista[j].edad;
                lista[j].edad = auxEdad;

                auxDNI = lista[i].dni;
                lista[i].dni = lista[j].dni;
                lista[j].dni = auxDNI;
            }
        }
    }
        printf("\nLISTA:\n\nNOMBRE\t\tEDAD\t\tDNI\n");
        for(k=0;k<tam;k++)
        {
            if(lista[k].estado == 1)
            {
                printf("%s\t\t%d\t\t%ld\n\n",lista[k].nombre,lista[k].edad,lista[k].dni);

            }
        }
                system("pause");
                system("cls");
}

/*void grafico(ePersona lista[], int tam)
{
    int i;
    int menoresDe18 = 0;
    int entre19Y35 = 0;
    int mayoresDe35 =0;
    int hastaAños18 = menoresDe18;
    int de19añosA35años = entre19Y35;
    int flagAños = 0;
    int mayor;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad<=18)
            {
                menoresDe18++;
            }
            if(lista[i].edad>18 && lista[i].edad<=35)
            {
                entre19Y35++;
            }
            if(lista[i].edad>35)
            {
                mayoresDe35++;
            }
        }
    }
        if(hastaAños18 >= de19añosA35años && hastaAños18 >= mayoresDe35)
        {
            mayor = hastaAños18;
        }
        else
        {
            if(de19añosA35años >= hastaAños18 && de19añosA35años >= mayoresDe35)
            {
                mayor = de19añosA35años;
            }
            else
            {
                mayor = mayoresDe35;
            }
        }
        for(i=mayor;i>0;i--)
        {
            if(i<10)
            {
                printf("\n\n\n\n%02d|",i);
            }
            else
                printf("%02d|",i);
            if(i<1=hastaAños18)
            {
                printf("*");
            }
            if(i<=de19añosA35años)
            {
                flagAños = 1;
                printf("\t*");
            }
            if(i<=mayoresDe35)
            {
                if(flagAños==0)
                {
                     printf("\t\t*");
                }


                if(flagAños==1)
                {
                    printf("\t*");
                }

            }
            printf("\n");
        }
        printf("\n  <18\t19-35\t>35");
        printf("\n  %d\t%d\t%d\n",menoresDe18, entre19Y35, mayoresDe35);
}*/

