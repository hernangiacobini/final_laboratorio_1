#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deposito.h"
#include "utn.h"


int validarDescripcion(char* titulo);
int validarProducto(int producto);
int validarCantidad(int cantidad);

EDeposito* deposito_new(void)
{
    EDeposito* auxDeposito = malloc(sizeof(EDeposito));
    return auxDeposito;
}

EDeposito* deposito_newP(int producto, char* descripcion, int cantidad)
{
    EDeposito* auxDeposito = malloc(sizeof(EDeposito));
    if(auxDeposito != NULL)
    {
        deposito_setProducto(auxDeposito, producto);
        deposito_setDescripcion(auxDeposito, descripcion);
        deposito_setCantidad(auxDeposito, cantidad);
    }
    return auxDeposito;
}


int deposito_setProducto(EDeposito* this,int producto)
{
    int retorno = -1;
    if(this != NULL && !validarProducto(producto))
    {
        this->producto = producto;
        retorno = 0;
    }
    return retorno;
}

int deposito_setDescripcion(EDeposito* this,char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL && validarDescripcion(descripcion))
    {
        strcpy(this->descripcion, descripcion);
        retorno = 0;
    }
    return retorno;
}

int deposito_setCantidad(EDeposito* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL && !validarCantidad(cantidad))
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}


int deposito_getProducto(EDeposito* this,int* producto)
{
    int retorno = -1;
    if(this != NULL && producto != NULL)
    {
        *producto = this->producto;
        retorno = 0;
    }
    return retorno;
}

int deposito_getDescripcion(EDeposito* this,char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion ,this->descripcion);
        retorno = 0;
    }
    return retorno;
}

int deposito_getCantidad(EDeposito* this,int* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}


int validarDescripcion(char* descripcion)
{
    return esAlfaNumerico(descripcion);
}


int validarProducto(int producto)
{
    if(producto > 0)
        return 0;
    return -1;
}

int validarCantidad(int cantidad)
{
    if(cantidad >0 && cantidad < 100)
        return 0;
    return -1;
}
