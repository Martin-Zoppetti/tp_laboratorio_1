/*
 ============================================================================
 Name        : funciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
Realizar un programa que permita el ingreso de 10 n�meros enteros distintos de cero.
Listar los n�meros positivos de manera creciente y negativos de manera decreciente. (Como m�ximo 5 for)
Ejemplo:

Listado 1 : 4, 5, 6, 10, 18, 29
Listado 2 : -1,-5,-9,-12
Listar solo los n�meros primos.
El mayor de los primos
Los n�meros que se repiten

*******************************************************************************/
#include <stdio.h>

#define TAM 10

int PedirEnteroExcluyente(char mensaje[],char mensajeError[], int numeroExcluyente);
int CargarArrayEnterosExcluyente(int lista[], int tam, char mensaje[],char mensajeError[], int numeroExcluyente);
int MostrarArrayEnteros(int lista[], int tam);
int clasificarNumero(int numeroAClasficiar);
int ordenarArrayEnterosExcluyentes(int lista[], int tam);

int main()
{
   int numeros[TAM];
   int verificacionCargaArray;

   verificacionCargaArray = CargarArrayEnterosExcluyente(numeros, TAM, "Ingrese un n�mero distinto de 0",
   "ERROR! Ingrese un n�mero distinto de 0", 0);

   if (verificacionCargaArray == 1)  // se puede dejar como if (verificacionCargaArray)
   {
       if (ordenarArrayEnterosExcluyentes(numeros,TAM)==0)
       {
        printf("No se pudo mostrar su bello array");
       }


       if (MostrarArrayEnteros(numeros, TAM) == 0) {
          printf("No se pudo mostrar su precioso array");
       }
   }




    return 0;
}




int PedirEnteroExcluyente(char mensaje[],char mensajeError[], int numeroExcluyente)
{
    int numeroIngresado;

    printf("%s\n",mensaje);
    scanf("%d",&numeroIngresado);

    while(numeroIngresado ==numeroExcluyente)
    {
        printf("%s\n",mensajeError);
        scanf("%d",&numeroIngresado);
    }

    return numeroIngresado;
}



int CargarArrayEnterosExcluyente(int lista[], int tam, char mensaje[],char mensajeError[], int numeroExcluyente)
{
    int i;
    int banderaTodoBien;

    banderaTodoBien = 0;

    if(lista != NULL && tam>0)
    {
        banderaTodoBien = 1;
        for (i=0; i<tam ;i++)
        {
            lista[i] = PedirEnteroExcluyente(mensaje, mensajeError, numeroExcluyente);

        }
    }

    return banderaTodoBien;

}

int MostrarArrayEnteros(int lista[], int tam) {

    int banderaTodoBien;

    banderaTodoBien = 0;

    if(lista != NULL && tam>0) {
        banderaTodoBien = 1;

        for (int i = 0; i < tam; i++) {
            printf("Posici�n [%d]: %d\n", i, lista[i]);
        }
    }

    return banderaTodoBien;
}

int clasificarNumero(int numeroAClasficiar)
{

    int retorno= 0;

    if (numeroAClasficiar>0)
    {
        retorno = 1;
    }else
    {
        if(numeroAClasficiar<0)
        {
            retorno = -1;
        }
    }

    return retorno;

}

int ordenarArrayEnterosExcluyentes(int lista[], int tam)
{
    int i;
    int j;
    int buffer;//int auxiliar;
    int banderaTodoBien;

    banderaTodoBien = 0;



    if(lista != NULL && tam>0)
    {

        for(i=0;i<tam-1;i++)  // toma el elemento y compara con el if el resto de los elementos
        {
            for(j=i+1;j<tam;j++) // el resto de los elementos
            {

                if(lista[i]>lista[j]) // > de menor a mayor // < de mayor a menor 2 4 3 -1
                {
                    buffer=lista[i];
                    lista[i]=lista[j];
                    lista[j]=buffer;
                }

            }

        }
        banderaTodoBien = 1;
    }

    return banderaTodoBien;

}
