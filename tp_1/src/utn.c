/*
 * utn.c
 *
 *  Created on: 21 sep. 2021
 *      Author: MariaElena
 */

#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
int ret;
int num;
	while(reintentos>0){
		printf(mensaje);
		scanf("%d",&num);
	if(num<=maximo && num>=minimo)
		reintentos--;
		printf(mensajeError);
		break;
	}
	if(reintentos==0){
		ret=-1;
	}
	else{
		ret=0;
		*pResultado = num;
	}

	return ret;
	}

int suma(int operador1, int operador2,float* presultado){
	*presultado= operador1+operador2;
	return 0;
}

int resta(int operador1, int operador2, float* presultado){
	*presultado= operador1-operador2;
	return 0;
}

int dividir(int operador1,int operador2,float* presultado){

	float resultado;
	int estado=0;

	if(operador2!=0){
		estado=0;
	resultado=operador1/operador2;
	*presultado=resultado;

	}
	else{
		estado=1;

		printf("el valor del divisor es 0, no se puede ejecutar la cuenta, reinicie el programa");

		}
	}


	return estado;

}

int multiplicacion(int operador1, int operador2,float* presultado){

	*presultado=operador1*operador2;
	return 0;
}

int factorial(int operador1,float* presultado){
	for(i=operador1, i>=0, i--){
		*presultado= i*(i-1);
	}

	return 0;
}