#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "movie.h"
#include "utn.h"
#include "ArrayList.h"
#include "parser.h"
#include "paginaWeb.h"

EMovie* crearPelicula(void)
{
    char auxTitulo[50];
    char auxGenero[30];
    int auxDuracion;
    char auxDescripcion[256];
    int auxPuntaje;
    char auxLinkImagen[256];
    EMovie* auxPelicula;

    if(!getValidString("\nIngrese el titulo\n", "\nEso no es un titulo\n","\nEl maximo es 50\n", auxTitulo, 50,2))
        if(!getValidString("\nIngrese el genero\n","\nEso no es un genero\n","\nEl maximo es 30\n", auxGenero, 30,2))
            if(!getValidInt("\nIngrese la duracion\n","\nEso no es una duracion\n", &auxDuracion, 0, 1440,2))
                if(!getValidString("\nIngrese la descripcion\n","\nEso no es una descripcion\n", "\nEl maximo es 256\n", auxDescripcion, 256,2))
                    if(!getValidInt("\nIngrese el puntaje[0-10]\n", "\nEso no es un puntaje\n", &auxPuntaje, 0, 10, 2))
                        if(!getValidStringLink("\nIngrese el link de la imagen\n", "\nEso no es un link\n", "\nEl maximo es 256\n", auxLinkImagen, 256, 2))
                        {
                            auxPelicula = movie_newP(auxTitulo, auxGenero, auxDuracion, auxDescripcion, auxPuntaje, auxLinkImagen);
                            return auxPelicula;
                        }
    return NULL;
}

int agregarPelicula(ArrayList* pArrayPeliculas, EMovie* movie)
{
    if(movie != NULL)
    {
        al_add(pArrayPeliculas, movie);
        if(!guardarPeliculas(pArrayPeliculas))
        {
            printf("\nPelicula guardada exitosamente\n\n");
            return 0;
        }
    }
    return -1;
}


int borrarPelicula(ArrayList* pArrayPeliculas)
{
    int retorno = -1;
    int i;
    char titulo[50];
    char tituloABorrar[50];
    EMovie* auxPelicula;
    if(!getValidString("\nIngrese el titulo a borrar\n", "\nEso no es un titulo\n","\nEl maximo es 50\n", tituloABorrar, 50,2))
    {
        for(i=0; i<al_len(pArrayPeliculas);i++)
        {
            movie_getTitulo(al_get(pArrayPeliculas, i), titulo);
            toLowerCase(tituloABorrar);
            toLowerCase(titulo);
            if(!strcmp(tituloABorrar, titulo))
            {
                retorno = 0;
                auxPelicula = al_pop(pArrayPeliculas, i);
                movie_delete(auxPelicula);
                guardarPeliculas(pArrayPeliculas);
                printf("\nPelicula removida exitosamente\n\n");
                break;
            }
        }
    }
    return retorno;
}

int modificarPelicula(ArrayList* pArrayPeliculas)
{
    int retorno = -1;
    int i;
    char titulo[50];
    char tituloAModificar[50];
    char genero[30];
    int duracion;
    char descripcion[256];
    int puntaje;
    char linkImg[256];
    EMovie* auxPelicula;
    if(!getValidString("\nIngrese el titulo a modificar\n", "\nNo es un titulo valido\n","\nEl maximo es 50 caracteres\n", tituloAModificar, 50,2))
    {
        for(i=0; i<al_len(pArrayPeliculas);i++)
        {
            movie_getTitulo(al_get(pArrayPeliculas, i), titulo);
            toLowerCase(tituloAModificar);
            toLowerCase(titulo);
            if(!strcmp(tituloAModificar, titulo))
            {
                auxPelicula = al_get(pArrayPeliculas, i);
                if(!getValidString("\nIngrese el titulo\n", "\nNo es un titulo valido\n","\nEl maximo es 50 caracteres\n", titulo, 50,2))
                    if(!getValidString("\nIngrese el genero\n","\nNo es un genero valido\n","\El maximo es 30 caracteres\n", genero, 30,2))
                        if(!getValidInt("\nIngrese la duracion\n","\nNo es una duracion valida\n", &duracion, 0, 1440,2))
                            if(!getValidString("\nIngrese la descripcion\n","\nNo es una descripcion valida\n", "El maximo es 256 caracteres\n", descripcion, 256,2))
                                if(!getValidInt("\nIngrese el puntaje[0-10]\n", "\nPuntaje invalido\n", &puntaje, 0, 10, 2))
                                    if(!getValidStringLink("\nIngrese el link de la imagen\n", "\nEso no es un link\n", "\nEl maximo es 256\n", linkImg, 256, 2))
                                    {
                                        retorno = 0;
                                        movie_setTitulo(auxPelicula, titulo);
                                        movie_setGenero(auxPelicula, genero);
                                        movie_setDuracion(auxPelicula, duracion);
                                        movie_setDescripcion(auxPelicula, descripcion);
                                        movie_setPuntaje(auxPelicula, puntaje);
                                        movie_setLinkImg(auxPelicula, linkImg);
                                        printf("\nPelicula removida exitosamente\n\n");
                                    }
                guardarPeliculas(pArrayPeliculas);
                break;
            }
        }
    }
    return retorno;
}

void generarPagina(ArrayList* pArrayPeliculas)
{
    char nombreArchivo[20];
    if(!getValidString("\nIngrese el nombre del archivo a generar\n", "\nNo es valido\n", "\nEl maximo es 20\n", nombreArchivo, 20, 5))
        generarPaginaWeb(nombreArchivo, pArrayPeliculas);
}
