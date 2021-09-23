/*
 * utn.h
 *
 *  Created on: 21 sep. 2021
 *      Author: MariaElena
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int suma(int operador1, int operador2,float* presultado);
int resta(int operador1, int operador2, float* presultado);
int dividir(int operador1,int operador2,float* presultado);
int multiplicacion(int operador1, int operador2,float* presultado);
int factorial(int operador1,float* presultado);
#endif /* UTN_H_ */
