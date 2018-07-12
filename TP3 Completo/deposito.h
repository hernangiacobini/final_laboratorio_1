#ifndef DEPOSITO_H_INCLUDED
#define DEPOSITO_H_INCLUDED

typedef struct
{
    int producto;
    char descripcion[256];
    int cantidad;
}EDeposito;

EDeposito* deposito_new(void);
EDeposito* deposito_newP(int producto, char* descripcion, int cantidad);

int deposito_setProducto(EDeposito* this,int producto);
int deposito_setDescripcion(EDeposito* this,char* descripcion);
int deposito_setCantidad(EDeposito* this,int cantidad);

int deposito_getDuracion(EDeposito* this,int* producto);
int deposito_getDescripcion(EDeposito* this,char* descripcion);
int deposito_getPuntaje(EDeposito* this,int* cantidad);


#endif // DEPOSITO_H_INCLUDED
