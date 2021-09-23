/*
 ============================================================================
 Name        : pFunciones1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 1-1:
Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
a) El promedio de los números positivos.
b) El promedio de los números negativos.

*/

#include <stdio.h>
#include <stdlib.h>
float promedioP(int acumulador,int contador);
int calsificador(int operador);

int main(void) {
	setbuf(stdout,NULL);
int acumuladorPLUS=0;
int acumuladorMINUS=0;
int contadorPLUS=0;
int contadorMINUS=0;
int numero;
int estado;
float resultadoP;
float resultadoM;



while(numero!=0){
printf("escribir numero entero, mayor o menor que cero- con cero frena\n");
scanf("%d",&numero);
if(numero==0){
	printf("se frena el conteo\n");
	break;
}
estado=calsificador(numero);
if(estado==0){
	acumuladorMINUS+=numero;
	contadorMINUS++;
	printf("entro el dato numero negativo=%d ,contadorM=%d , acumuladorM%d \n", numero,contadorMINUS, acumuladorMINUS);
}
else{
	acumuladorPLUS+=numero;
	contadorPLUS++;
printf("entro el dato numero postivo=%d ,contador=%d , acumulador%d \n", numero,contadorPLUS, acumuladorPLUS);
}

}
	resultadoM = promedioP(acumuladorMINUS,contadorMINUS);
	resultadoP = promedioP(acumuladorPLUS,contadorPLUS);
	printf("el promedio de numeros negativos es %f\n",resultadoM);
	printf("el promedio de numeros positivos es %f\n",resultadoP);
	return 0;
}


float promedioP(int acumulador,int contador){
	float resultado;
	resultado= acumulador/contador;
	return resultado;
	}

int calsificador(int operador){
	int estado;

if(operador<0){
		estado=0;
	}
	else{
		estado=1;
		}
	return estado;
}






