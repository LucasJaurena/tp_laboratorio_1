#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}EMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la pelicula a ser agregada al archivo
 */

void agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la pelicula a ser eliminada al archivo
 */

void borrarPelicula(EMovie movie);

/**
 * Modifica una pelicula del archivo binario
 * \param los datos de la pelicula
 */

void modificarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  \param los datos de la pelicula
 */
void generarPagina(EMovie movie);

#endif // FUNCIONES_H_INCLUDED
