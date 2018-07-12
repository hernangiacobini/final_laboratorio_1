#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "movie.h"
#include "ArrayList.h"

/**
 *  Solicita datos al usuario para crear una pelicula
 * \return EMovie* Devuelve la pelicula creada
 *
 */
EMovie* crearPelicula();

/**
 *  Agrega una pelicula y la guarda en el archivo binario
 *  @param movie la estructura a ser agregada
 *  @return int [0] OK , [-1]Error
 */
int agregarPelicula(ArrayList* pArrayPeliculas, EMovie* movie);

/**
 *  Borra una pelicula y guarda la eliminacion en el archivo binario
 *  @param pArrayPeliculas ArrayList*
 *  @return int [0] OK , [-1]Error
 */
int borrarPelicula(ArrayList* pArrayPeliculas);

/**
 *  Modifica pelicula pidiendo el nombre a modificar al usuario, y guarda en el archivo binario
 * \param pArrayPeliculas ArrayList*
 * \return int [0] OK , [-1]Error
 */
int modificarPelicula(ArrayList* pArrayPeliculas);

/**
 *  Genera un archivo html a partir de las peliculas cargadas, solicitando al usuario el nombre para el archivo.
 *  @param pArrayPeliculas El array con las peliculas cargadas.
 */
void generarPagina(ArrayList* pArrayPeliculas);

#endif // FUNCIONES_H_INCLUDED
