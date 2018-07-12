#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "ArrayList.h"
#include "movie.h"


int cargarPeliculas(ArrayList* pArrayPeliculas)
{
    int retorno = -1;
    FILE* peliculas = fopen("movies.bin", "r");
    EMovie* auxPelicula = movie_new();
    if(peliculas != NULL)
    {
        while(fread(auxPelicula, sizeof(EMovie), 1, peliculas)==1)
        {
            al_add(pArrayPeliculas, auxPelicula);
            auxPelicula = movie_new();
        }
        movie_delete(auxPelicula);
        fclose(peliculas);
        retorno = 0;
    }
    return retorno;
}

int guardarPeliculas(ArrayList* pArrayPeliculas)
{
    int i;
    int retorno = -1;
    FILE* peliculas = fopen("movies.bin", "w");
    if(peliculas != NULL)
    {
        for(i=0; i<al_len(pArrayPeliculas);i++)
        {
            fwrite(al_get(pArrayPeliculas, i), sizeof(EMovie), 1, peliculas);
        }
        fclose(peliculas);
        retorno = 0;
    }
    return retorno;
}

