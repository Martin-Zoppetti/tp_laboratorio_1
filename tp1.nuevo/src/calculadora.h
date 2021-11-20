

#ifndef CALCULADORA_H_
#define CALCULADORA_H_
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"

int ingresOperadorA(int* operadorA,int reintentos);
int ingresOperadorB(int* operadorB,int reintentos);
int suma(int operador1, int operador2);
int resta(int operador1, int operador2);
float division(int operador1, int operador2);
int multiplicacion(int operador1, int operador2);
int factorial(int operador1);
int calculadora(int A,int B,int *respuestaSuma,int *respuestaResta,float *respuestaDivision,int *respuestaMultiplicacion,int *respuestaFactorialA,int *respuestaFactorialB);
int informarResultados(int respuestaSuma,int respuestaResta,float respuestaDivision,int respuestaMultiplicacion,int respuestaFactorialA,int respuestaFactorialB);




#endif /* CALCULADORA_H_ */
/*
1. Ingresar 1er operando (A=x) 2.
 Ingresar 2do operando (B=y) 3.
  Calcular todas las operaciones
   a) Calcular la suma (A+B)
    b) Calcular la resta (A-B)
    c) Calcular la division (A/B)
    d) Calcular la multiplicacion (A*B)
    e) Calcular el factorial (A!)
    4. Informar resultados
    a) �El resultado de A+B es: r�
    b) �El resultado de A-B es: r�
    c) �El resultado de A/B es: r� o �No es posible dividir por cero�
    d) �El resultado de A*B es: r�
    e) �El factorial de A es: r1 y El factorial de B es: r2�
    5. Salir

� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.

� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)

� Deber�n contemplarse los casos de error (divisi�n por cero, etc)
� Documentar todas las funciones
 */
