#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    long int dni;

}ePersona;

/**
 *
 * \param Ingresa los datos de la persona
 * \return Los datos de la persona
 *
 */

void cargarPersonas(ePersona lista[], int tam);

/**
 *  Borra a una persona cargada
 * \param Pregunta el DNI de la persona a eliminar
 * \param Muestra a la persona
 * \param Pregunta si esta seguro de realizar la operacion
 * \return La persona eliminada
 *
 */


void borrarPersonas(ePersona lista[], int tam);

/**
 * Ordena a las personas ingresadas
 * \param compara los nombres de las personas ingresadas
 * \return La lista de las personas ordenadas
 *
 */


void mostrarDatosOrdenados(ePersona lista[], int tam);

/*void grafico(ePersona lista[], int tam);*/

#endif // FUNCIONES_H_INCLUDED
