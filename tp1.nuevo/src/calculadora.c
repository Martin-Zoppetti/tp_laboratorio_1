#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"
#include "ingresos.h"
/*
	1. Ingresar 1er operando (A=x)
	2. Ingresar 2do operando (B=y)
 	3.Calcular todas las operaciones
    a)Calcular la suma (A+B)
    b) Calcular la resta (A-B)
    c) Calcular la division (A/B)
    d) Calcular la multiplicacion (A*B)
    e) Calcular el factorial (A!)
    4. Informar resultados
    a) “El resultado de A+B es: r”
    b) “El resultado de A-B es: r”
    c) “El resultado de A/B es: r” o “No es posible dividir por cero”
    d) “El resultado de A*B es: r”
    e) “El factorial de A es: r1 y El factorial de B es: r2”
    5. Salir

• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.

• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */
#define FALSO 0
#define VERDADERO 1
int ingresOperadorA(int* poperadorA,int reintentos){
	int retorno=FALSO;
	retorno=UTN_ingresoIntReintentos(poperadorA, "Ingrese el operador A\n", "Ingreso un valor incorrecto\n", reintentos);
	return retorno;
}
int ingresOperadorB(int* poperadorB,int reintentos){
	int retorno=FALSO;
	retorno=UTN_ingresoIntReintentos(poperadorB, "Ingrese el operador B\n", "Ingreso un valor incorrecto\n", reintentos);
	return retorno;
}

int suma(int operador1, int operador2){
	int resultado;
	resultado=FALSO;

	resultado=operador1+operador2;

	return resultado;
}

int resta(int operador1, int operador2){
	int resultado;
	resultado=FALSO;

	resultado=operador1-operador2;

	return resultado;
}

float division(int operador1, int operador2){
	float resultado;
	resultado=FALSO;
	if(operador2!=0){
		resultado=(float)operador1/(float)operador2;
	}else if(operador2==0){
		printf("no se pueden dividir por 0");
	}
	return resultado;
}

int multiplicacion(int operador1, int operador2){
	int resultado;
	resultado=FALSO;

	resultado=operador1*operador2;

	return resultado;
}

int factorial(int operador1)
{
	int resultado;
	resultado=FALSO;
	if(operador1>0){
		for(int i=0; i<operador1; i++){
			resultado=(i+1)*i;
		}
		if(operador1==0){
			resultado=1;
		}

	}
	return resultado;
}
int calculadora(int A,int B,int *respuestaSuma,int *respuestaResta,float *respuestaDivision,int *respuestaMultiplicacion,int *respuestaFactorialA,int *respuestaFactorialB)
{
	int retorno=FALSO;

	*respuestaSuma=suma(A, B);
	*respuestaResta=resta(A, B);
	*respuestaDivision=division(A, B);
	*respuestaMultiplicacion=multiplicacion(A,B);
	*respuestaFactorialA=factorial(A);
	*respuestaFactorialB=factorial(B);


	if(respuestaDivision!=FALSO && respuestaFactorialA!=FALSO && respuestaFactorialB!=FALSO){
		printf("se generaron todos los calculos\n");
		retorno=1;

	}
	if(respuestaDivision==FALSO){
		printf("no puede dividir por cero\n escriba un nuevo valor para su denominador");
	}
	if(respuestaFactorialA==FALSO || respuestaFactorialB==FALSO){
		printf("no puede realizar la operacion factorial con un valor negativo\n escriba un nuevo valor para su denominador");

	}
	return retorno;
}

int informarResultados(int respuestaSuma,int respuestaResta,float respuestaDivision,int respuestaMultiplicacion,int respuestaFactorialA,int respuestaFactorialB){

	int retorno =FALSO;

	if(respuestaDivision!=FALSO && respuestaFactorialA!=FALSO && respuestaFactorialB!=FALSO){

		printf("Resultados:\n"
				" El resultado de A+B es: %d\n"
				" El resultado de A-B es: %d\n"
				" El resultado de A/B es: %f \n"
				" El resultado de A*B es: %d\n"
				" El factorial de A es: %d\n"
				" El factorial de B es: %d\n"
				,respuestaSuma
				,respuestaResta
				,respuestaDivision
				,respuestaMultiplicacion
				,respuestaFactorialA
				,respuestaFactorialB);
	}

	if(respuestaDivision==FALSO){
		printf("No es posible dividir por cero\n");
	}

	return retorno;
}





