#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

void agregarPelicula(EMovie movie)
{
    FILE* miArchivoBIN;
    char seguir;

    if((miArchivoBIN = fopen("archivoBinario.dat","wb"))==NULL)
    {
        printf("\nNo se puede abrir el archivo");
        exit(1);
    }
    do
    {
        printf("\nIngrese el titulo de la pelicula: ");
        fflush(stdin);
        gets(movie.titulo);
        printf("\nIngrese el genero de la pelicula: ");
        fflush(stdin);
        gets(movie.genero);
        printf("\nIngrese la duracion de la pelicula (en minutos): ");
        scanf("%d", &movie.duracion);
        printf("\nIngrese la descripcion de la pelicula: ");
        fflush(stdin);
        gets(movie.descripcion);
        printf("\nIngrese el puntaje de la pelicula: ");
        scanf("%d", &movie.puntaje);
        printf("\nIngrese el link de una imagen de la pelicula: ");
        fflush(stdin);
        gets(movie.linkImagen);

        printf("\nSe agregara la pelicula con los siguientes datos:\n\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de la imagen: %s\n",movie.titulo, movie.genero, movie.duracion, movie.descripcion, movie.puntaje, movie.linkImagen);
        system("pause");

        fwrite(&movie, sizeof(movie), 1, miArchivoBIN);

        printf("\nAccion realizada con exito!!\n");

        printf("\n\nDesea agregar otra pelicula? s/n ");
        seguir = getch();

    }
    while(seguir == 's');

    fclose(miArchivoBIN);

}

void borrarPelicula(EMovie movie)
{
    FILE* miArchivoBIN;
    int cantidad;
    char auxTitulo[20];
    char seguir;

    if((miArchivoBIN = fopen("archivoBinario.dat","rb"))==NULL)
    {
        printf("\nNo se puede abrir el archivo\n\n");
        exit(1);
    }
    while(!feof(miArchivoBIN))
    {
        cantidad = fread(&movie, sizeof(movie), 1, miArchivoBIN);
        if(cantidad != 1)
        {
            if(feof(miArchivoBIN))
            {
                break;
            }
            else
            {
                printf("\nNo se pudo leer la ultima pelicula!!\n\n");
                break;
            }
        }

    }

    printf("\nIngrese el titulo de la pelicula a buscar: ");
    fflush(stdin);
    gets(auxTitulo);
    if(strcmp(auxTitulo,movie.titulo)==0)
    {
        printf("\nSe a encontrado la siguiente pelicula:\n\nTitulo: %s\nGenero: %s\nDuracion: %d\ndescripcion: %s\nPuntaje: %d\nLink de la imagen: %s\n",movie.titulo, movie.genero, movie.duracion, movie.descripcion, movie.puntaje, movie.linkImagen);
        printf("\nEsta seguro que desea borrar la pelicula? s/n ");

        seguir = getch();

        if(seguir == 's')
        {
            printf("\n\nSe a borrado la pelicula correctamente!!\n\n");
        }
    }
}

void modificarPelicula(EMovie movie)
{
    FILE* miArchivoBIN;
    int cantidad;
    char auxTitulo[20];
    char auxGenero[20];
    int auxDuracion;
    char auxDescripcion[50];
    int auxPuntaje;
    char auxLinkImagen[50];

    if((miArchivoBIN = fopen("archivoBinario.dat","rb"))==NULL)
    {
        printf("\nNo se puede abrir el archivo\n\n");
        exit(1);
    }

    while(!feof(miArchivoBIN))
    {
        cantidad = fread(&movie, sizeof(movie), 1, miArchivoBIN);
        if(cantidad != 1)
        {
            if(feof(miArchivoBIN))
            {
                break;
            }
            else
            {
                printf("\nNo se pudo leer la ultima pelicula!!\n\n");
                break;
            }
        }
    }

    printf("\nIngrese el titulo de la pelicula a buscar: ");
    fflush(stdin);
    gets(auxTitulo);
    if(strcmp(auxTitulo,movie.titulo)==0)
    {
        printf("\nSe a encontrado la siguiente pelicula:\n\nTitulo: %s\nGenero: %s\nDuracion: %d\ndescripcion: %s\nPuntaje: %d\nLink de la imagen: %s\n",movie.titulo, movie.genero, movie.duracion, movie.descripcion, movie.puntaje, movie.linkImagen);

        printf("\n\nIngrese el nuevo titulo de la pelicula: ");
        fflush(stdin);
        gets(auxTitulo);
        strcpy(movie.titulo, auxTitulo);
        printf("\nIngrese el nuevo genero de la pelicula: ");
        fflush(stdin);
        gets(auxGenero);
        strcpy(movie.genero, auxGenero);
        printf("\nIngrese la nueva duracion de la pelicula (en minutos): ");
        scanf("%d", &auxDuracion);
        movie.duracion = auxDuracion;
        printf("\nIngrese la nueva descripcion de la pelicula: ");
        fflush(stdin);
        gets(auxDescripcion);
        strcpy(movie.descripcion, auxDescripcion);
        printf("\nIngrese el nuevo puntaje de la pelicula: ");
        scanf("%d", &auxPuntaje);
        movie.puntaje = auxPuntaje;
        printf("\nIngrese el link de una imagen de la pelicula: ");
        fflush(stdin);
        gets(auxLinkImagen);
        strcpy(movie.linkImagen, auxLinkImagen);

        printf("\n\nSe a modificado la pelicula correctamente!!\n\n");

    }
}

void generarPagina(EMovie movie)
{
    FILE* PaginaHTML;
    FILE* miArchivoBIN;


    char buffer[1080]= {};

    if((miArchivoBIN = fopen("archivoBinario.dat","rb"))==NULL)
    {
        printf("\nNo se puede abrir el archivo\n\n");
        exit(1);
    }

    strcat(buffer, "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src=");
    strcat(buffer, movie.linkImagen);
    strcat(buffer, "alt=''>");
    strcat(buffer, "</a><h3><a href='#'>");
    strcat(buffer, movie.titulo);
    strcat(buffer, "</a> </h3><ul><li>Género:");
    strcat(buffer, movie.genero);
    strcat(buffer, "</li><li>Puntaje:");
    strcat(buffer, movie.puntaje);
    strcat(buffer, "</li><li>Duración:");
    strcat(buffer, movie.duracion);
    strcat(buffer, "</li></ul><p>");
    strcat(buffer, movie.descripcion);
    strcat(buffer, ".</p></article>");

    fclose(miArchivoBIN);

    PaginaHTML = fopen("paginaPeliculas.html","w");

    fprintf(PaginaHTML, buffer);

    fclose(PaginaHTML);
}
