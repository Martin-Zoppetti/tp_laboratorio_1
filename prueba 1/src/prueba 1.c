/*
 ============================================================================
 Name        : prueba1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout,NULL);
int minimo;
int MAXIMO;

int bufferInt;
int flag = TRUE;

do{
	printf("ingrese un numero ( ingrese 888 para frenar el ingreso): \n");




	scanf("%d",&bufferInt);
if(flag==TRUE){
	flag=FALSE;
	MAXIMO= bufferInt;
	minimo= bufferInt;
}
else{
if(bufferInt==888)
{
	break;
}
else {
			if(bufferInt> MAXIMO){
			MAXIMO=bufferInt;
			}
			if(bufferInt < minimo){
			minimo= bufferInt;
			}

		}

}

}

while(1);


printf("El valor minimo es: %d y el valor maximo es: %d",minimo,MAXIMO);
return 0;
}




/*for(i=0;i<5;i++)
{
	printf(" ingrese un numero %d \n", i+1);



	scanf("%d",&bufferInt);

	if(i==0){
	MAXIMO= bufferInt;
	minimo= bufferInt;

	}

	else {
			if(bufferInt> MAXIMO){
			MAXIMO=bufferInt;
		}
			if(bufferInt < minimo){
			minimo= bufferInt;
		}

	}
}*/
