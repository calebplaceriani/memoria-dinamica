#include <stdio.h>
#include <stdlib.h>
#define CANT 10
#define NEW_CANT 2

int* array_nuevo(int* array,int len);
int array_iniciar(int* arrayInt,int len,int valor);
int array_mostrar(int * array,int len);
int array_liberar(int*);
int* array_redimencionar(int* array,int nuevo_len);

int main()
{
    int* a;
    int* uno,* cinco;
    int dos,tres,cuatro;

    uno=array_nuevo(a,CANT);
    dos=array_iniciar(uno,CANT,7);
    tres=array_mostrar(uno,CANT);
    cuatro=array_liberar(uno);
    cinco=array_redimencionar(uno,NEW_CANT);


    printf("1ra = %d\nSegunda = %d\ntercera = %d\nCuarta = %d\nQuinta = %d\n",*uno,dos,tres,cuatro,*cinco);
    tres=array_mostrar(uno,NEW_CANT);

    return 0;
}

int* array_nuevo(int* array,int len)
{
  int* retorno=-1;

  if(len>0)
  {
    int* auxInt=(int*)malloc(sizeof(int)*len);

    if(auxInt!=NULL)
    {
        array=auxInt;
        retorno=array;
    }
   }

  return retorno;
}

int array_iniciar(int* arrayInt,int len,int valor)
{
    int retorno=-1;
    int i;

    if(arrayInt!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            *(arrayInt+i)=valor;
        }
        retorno=0;
    }

    return retorno;
}

int array_mostrar(int * array,int len)
{
    int i;

    if(array!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        printf("posicion %d en la direccion %p = vale %d\n",i,array+i,*(array+i));
        return 0;
    }
    return -1;
}

int array_liberar(int* array)
{
    int retorno=-1;

    if(array!=NULL)
    {
        free(array);
        retorno=0;
    }

    return retorno;
}

int* array_redimencionar(int* array,int nuevo_len)
{
    int* retorno=-1;

    if(array!=NULL && nuevo_len>0)
    {
        retorno=(int*)realloc(array,sizeof(int)*nuevo_len);
    }

    return retorno;
}
