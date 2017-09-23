#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

void agregarPersona(EPersona lista[], int tam)
{
    int flaglugar = 0;

    int i;
    for (i=0; i<tam; i++)
    {
        if(lista[i].estado == 0)
        {
            printf("\nIngrese un Nombre: ");
            fflush(stdin);
            gets(lista[i].nombre);
            printf("\nIngrese una edad: ");
            scanf("%d", &lista[i].edad);
            printf("\nIngrese un DNI: ");
            scanf("%ld", &lista[i].dni);
            lista[i].estado = 1;
            flaglugar = 1;
                system("pause");
                system("cls");
            break;
        }

    }

    if(!flaglugar)
    {
        printf("\n\nNo hay lugar disponible");
                system("pause");
                system("cls");
    }

}

void borrarPersona(EPersona lista[], int tam)
{
    char opcion;
    long int auxDNI;
    int i;

    printf("\nIngrese el DNI a buscar: ");
    scanf("%ld", &auxDNI);
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 1 && auxDNI == lista[i].dni)
        {
            printf("\nSe a encontrado a la siguiente persona: \n\nNOMBRE\t\tEDAD\t\tDNI\n");
            printf("%s\t\t%d\t\t%ld\n\n Desea Eliminarlo? s/n", lista[i].nombre, lista[i].edad, lista[i].dni);
            opcion = getche();

            if(opcion == 's')
            {
                lista[i].estado = 0;
                printf("\nAccion realizada!!\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Accion cancelada con exito!!!\n");
                system("pause");
                system("cls");
            }
        }
        if(auxDNI != lista[i].dni)
        {
            printf("\nNo se a encontrado un DNI!!!\n");
                system("pause");
                system("cls");
                break;
        }
    }

}

void imprimirLista(EPersona lista[], int tam)
{
   // char auxNombre[50];
   // long int auxDNI;
   // int j, auxEdad, auxEstado;
    int i;

    /*for (i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)>0)
            {
                strcpy(auxNombre, lista[i].nombre);
                strcpy(lista[i].nombre, lista[j].nombre);
                strcpy(lista[j].nombre, auxNombre);

                auxEdad = lista[i].edad;
                lista[i].edad = lista[j].edad;
                lista[j].edad = auxEdad;

                auxDNI = lista[i].dni;
                lista[i].dni = lista[j].dni;
                lista[j].dni = auxDNI;

                  auxEstado = lista[i].estado;
                  lista[i].edad = lista[j].estado;
                  lista[j].estado = auxEstado;
            }
             else
              {
                  if(strcmp(lista[i].nombre, lista[j].nombre)==0)
                  {
                      if(lista[i].dni>lista[j].dni)
                      {
                          auxDNI = lista[i].dni;
                          lista[i].dni = lista[j].dni;
                          lista[j].dni = auxDNI;

                          auxEdad = lista[i].edad;
                          lista[i].edad = lista[j].edad;
                          lista[j].edad = auxEdad;


                          auxEstado = lista[i].estado;
                          lista[i].edad = lista[j].estado;
                          lista[j].estado = auxEstado;
                      }
                  }
              }
        }
    }*/
    printf("\nNOMBRE\t\tEDAD\t\tDNI\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 1)
        {
            printf("%s\t\t%d\t\t%ld\n", lista[i].nombre, lista[i].edad, lista[i].dni);
                system("pause");
                system("cls");
        }
    }
}

void grafico(EPersona lista[], int tam)
{
    int mayor,flag=0;
    int contPersMenor=0;
    int contPersAdulta=0;
    int contPersAnciana=0;
    int i;
    printf("------------------------------------\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad<19)
            {
                contPersMenor++;
            }
            else
            {
                if(lista[i].edad<36)
                {
                    contPersAdulta++;
                }
                else
                {
                    contPersAnciana++;
                }
            }
        }
    }
    if(contPersMenor==0 && contPersAdulta==0 && contPersAnciana==0)
    {
        printf("\nError!!! No se a ingresado ninguna persona\n\n");
    }
    else
    {
        if(contPersMenor >= contPersAdulta && contPersMenor >=contPersAnciana)
        {
            mayor=contPersMenor;
        }
        else
        {
            if(contPersAdulta >= contPersMenor &&contPersAdulta >= contPersAnciana)
            {
                mayor = contPersAdulta;
            }
            else
            {
                mayor = contPersAnciana;
            }
        }
        for(i=mayor; i>0; i--)
        {
            if(i <= contPersMenor)
            {
                printf("*");
            }
            if(i <= contPersAdulta)
            {
                printf("\t*");
                flag=1;
            }
            if(i <= contPersAnciana)
            {
                if(flag==0)
                {
                    printf("\t\t*");
                }
                else
                {
                    printf("\t*");
                }
            }
            printf("\n");
        }
        printf("<19\t19-35\t>35\n");
    }
    printf("------------------------------------\n");
                system("pause");
                system("cls");
}
