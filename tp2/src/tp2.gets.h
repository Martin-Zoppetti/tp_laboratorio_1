/*
 * tp2.gets.h
 *
 *  Created on: 16 oct. 2021
 *      Author: MariaElena
 */

#ifndef TP2_GETS_H_
#define TP2_GETS_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int UTN_validarNumeroEnteroIngresado(char *pputs);
int UTN_validarNumeroFlotanteIngresado(char *pputs);
int UTN_validadCaracterIngresado(char puts);
int UTN_validarCadenaAlfabeticaIngresada(char *pputs);


int UTN_putsInt(char* variableTexto, char* textoError);
float UTN_putsFloat(char* variableTexto, char* textoError);
char UTN_putsChar(char* variableTexto, char* textoError);
int UTN_putsTextoReintentos(char pputs[],int tam, char* variableTexto, char* textoError, int reintentos);


int UTN_putsIntReintentosMinMax(int* pputs, char* variableTexto, char* textoError, int min, int max, int reintentos);
float UTN_putsFloatReintentosMinMax(float* pputs, char* variableTexto, char* textoError, float min, float max,int reintentos);
char UTN_putsCharReintentosMinMax(char* pputs,char* variableTexto, char* textoError, char min, char max, int reintentos);


int UTN_putsIntReintentos(int* pputs, char* variableTexto, char* textoError, int reintentos);
float UTN_putsFloatReintentos(float* pputs, char* variableTexto, char* textoError, int reintentos);
char UTN_putsCharReintentos(char* pputs, char* variableTexto, char* textoError,int reintentos);

#endif /* TP2_GETS_H_ */
