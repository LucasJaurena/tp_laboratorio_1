#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

/** \brief Agrega una persona a la lista
 *
 * \param la lista
 * \param el tamaño de la lista
 *
 */

void agregarPersona(EPersona lista[], int tam);

/** \brief Elimina una persona de la lista
 *
 * \param la lista
 * \param el tamaño de la lista
 *
 */

void borrarPersona(EPersona lista[], int tam);

/** \brief Muestra la lista de personas ingresadas
 *
 * \param la lista
 * \param el tamaño de la lista
 *
 */

void imprimirLista(EPersona lista[], int tam);

/** \brief Realiza un grafico de las edades de las personas ingresadas
 *
 * \param la lista
 * \param el tamaño de la lista
 *
 */

void grafico(EPersona lista[], int tam);

#endif // FUNCIONES_H_INCLUDED
