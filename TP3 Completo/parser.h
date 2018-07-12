#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "ArrayList.h"


/**
 *  Inicializa el array con las peliculas guardadas en el archivo binario
 * \param pArrayPeliculas ArrayList*
 * \return int
 *
 */
int cargarPeliculas(ArrayList* pArrayPeliculas);


/**
 *  Guarda en el archivo binario las peliculas cargadas
 * \param pArrayPeliculas ArrayList*
 * \return int
 *
 */
int guardarPeliculas(ArrayList* pArrayPeliculas);

#endif // PARSER_H_INCLUDED
