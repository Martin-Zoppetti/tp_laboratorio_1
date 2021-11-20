/*
 * tp2.gets.c
 *
 *  Created on: 16 oct. 2021
 *      Author: MariaElena
 */


///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VERDADERO 1
#define FALSO 0
#define TAM_BUFFER 1000

int myGets(char* pputs, int len)
{
	int retorno= FALSO;
	int indexFinal;
	if(fgets(pputs,len,stdin)!=NULL)
	{
		indexFinal = strlen(pputs)-1;
		if(pputs[indexFinal] == '\n')
		{
			pputs[indexFinal] = '\0';
		}
		retorno = VERDADERO;
	}
	return retorno;
}

// VALIDACIONES

int validarNumeroEnteroIngresado(char* pputs){
	int retorno = VERDADERO;
	if(strlen(pputs) > 0){
		for(int i = 0;i< strlen(pputs);i++){
			if(isdigit(pputs[i]) == FALSO){
				if(i == 0){
					if(pputs[0] != '-'){
						retorno = FALSO;
						break;
					}
				}else{
					retorno = 0;
				}
			}
		}
	}else{
		retorno = FALSO;
	}
	return retorno;
}

int validarNumeroFlotanteIngresado(char* pputs){
	int contadorDeSignos = 0;
	int retorno = VERDADERO;
	if(strlen(pputs) > 0){
		for(int i = 0;i < strlen(pputs); i++){
			if(pputs[i] == '.' || pputs[i] == ','){
				contadorDeSignos++;
			}else{
				if(isdigit(pputs[i]) == 0){
					if(i == 0){
						if(pputs[0] != '-'){
							retorno = FALSO;
							break;
						}
					}else{
						retorno = FALSO;
						break;
					}
				}
			}
		}
		if(contadorDeSignos > 1){
			retorno = FALSO;
		}
	}else{
		retorno = FALSO;
	}
	return retorno;
}

int validarCaracterIngresado(char puts){
	int retorno = VERDADERO;
	if(isalpha(puts) == FALSO){
		retorno = FALSO;
	}
	return retorno;
}

int validarCadenaAlfabeticaIngresada(char puts[]){
	int retorno = VERDADERO;
	if(strlen(puts) > 0){
		for(int i = 0;i<strlen(puts);i++){
			if(isalpha(puts[i] == 0)){
				retorno = FALSO;
				break;
			}
		}
	}else{
		retorno = FALSO;
	}
	return retorno;
}

// FIN VALIDACIONES

// putsS INT

int UTN_putsInt(char* variableTexto, char* textoError)
{
	char buffer[TAM_BUFFER];
	int retorno;
	if(variableTexto != NULL && textoError != NULL)
	{
		printf("%s",variableTexto);
		fflush(stdin);
		gets(buffer);
		while(validarNumeroEnteroIngresado(buffer) == FALSO){
			printf("%s",textoError);
			fflush(stdin);
			gets(buffer);
		}
		retorno = atoi(buffer);
	}
	return retorno;
}

int UTN_putsIntReintentos(int* pputs, char* variableTexto, char* textoError, int reintentos)
{
	char buffer[TAM_BUFFER];
	int retorno;
	if(pputs != NULL && variableTexto != NULL && textoError != NULL && reintentos > 0)
	{
		printf("%s",variableTexto);
		fflush(stdin);
		gets(buffer);
		while(validarNumeroEnteroIngresado(buffer) == FALSO){
			if(reintentos == 0){
				printf("Demasiados intentos fallidos.");
				retorno = FALSO;
				break;
			}
			printf("%s",textoError);
			fflush(stdin);
			gets(buffer);
			reintentos--;
		}
		*pputs = atoi(buffer);
		retorno = VERDADERO;
	}
	return retorno;
}

int UTN_putsIntReintentosMinMax(int* pputs, char* variableTexto, char* textoError, int min, int max, int reintentos)
{
	char buffer[TAM_BUFFER];
	int retorno = FALSO;
	if(pputs != NULL && variableTexto != NULL && textoError != NULL && reintentos > 0 && min < max)
	{
		printf("%s",variableTexto);
		fflush(stdin);
		gets(buffer);
		while(validarNumeroEnteroIngresado(buffer) == FALSO || atoi(buffer) > max || atoi(buffer) < min){
			if(reintentos == 0){
				printf("Demasiados intentos fallidos");
				retorno = FALSO;
				break;
			}
			printf("%s",textoError);
			fflush(stdin);
			gets(buffer);
			reintentos--;

		}
		*pputs = atoi(buffer);
		retorno = VERDADERO;
	}
	return retorno;
}

// FIN putsS INT

// putsS FLOAT

float UTN_putsFloat(char* variableTexto, char* textoError){
	char buffer[TAM_BUFFER];
	float retorno;
	if(variableTexto != NULL && textoError != NULL){
		printf("%s",variableTexto);
		fflush(stdin);
		gets(buffer);
		while(validarNumeroFlotanteIngresado(buffer) == FALSO){
			printf("%s",textoError);
			fflush(stdin);
			gets(buffer);
		}
		retorno = atof(buffer);
	}
	return retorno;
}

float UTN_putsFloatReintentos(float* pputs, char* variableTexto, char* textoError, int reintentos){
	char buffer[TAM_BUFFER];
	int retorno;
	if(pputs != NULL && variableTexto != NULL && textoError != NULL && reintentos > 0)
	{
		printf("%s",variableTexto);
		fflush(stdin);
		gets(buffer);
		while(validarNumeroFlotanteIngresado(buffer) == FALSO){
			if(reintentos == 0){
				printf("Demasiados intentos fallidos.");
				retorno = FALSO;
				return retorno;
			}
			printf("%s",textoError);
			fflush(stdin);
			gets(buffer);
			reintentos--;
		}
		*pputs = atof(buffer);
		retorno = VERDADERO;
	}
	return retorno;
}

float UTN_putsFloatReintentosMinMax(float* pputs, char* variableTexto, char* textoError, float min, float max,int reintentos){
	char buffer[TAM_BUFFER];
	int retorno;
	if(pputs != NULL && variableTexto != NULL && textoError != NULL && reintentos > 0 && min < max)
	{
		printf("%s",variableTexto);
		fflush(stdin);
		gets(buffer);
		while(validarNumeroFlotanteIngresado(buffer) == FALSO || atof(buffer) > max || atof(buffer) < min){
			if(reintentos == 0){
				printf("Demasiados intentos fallidos");
				retorno = FALSO;
				return retorno;
			}
			printf("%s",textoError);
			fflush(stdin);
			gets(buffer);
			reintentos--;
		}
		*pputs = atof(buffer);
		retorno = VERDADERO;
	}
	return retorno;
}

// FIN putsS FLOAT

// INICIO puts CHAR

char UTN_putsChar(char* variableTexto, char* textoError){
	char buffer;
	char retorno;
	if(variableTexto != NULL && textoError != NULL){
		printf("%s",variableTexto);
		fflush(stdin);
		buffer = getchar();
		while(validarCaracterIngresado(buffer) == FALSO){
			printf("%s",textoError);
			fflush(stdin);
			buffer = getchar();
		}
		retorno = buffer;
	}
	return retorno;
}

char UTN_putsCharReintentos(char* pputs,char* variableTexto, char* textoError,int reintentos){
	char buffer;
	char retorno;
	if(variableTexto != NULL && textoError != NULL && reintentos > 0){
		printf("%s",variableTexto);
		fflush(stdin);
		buffer = getchar();
		while(validarCaracterIngresado(buffer) == FALSO){
			if(reintentos == 0){
				printf("Demasiados intentos fallidos.");
				retorno = FALSO;
				return retorno;
			}
			printf("%s",textoError);
			fflush(stdin);
			buffer = getchar();
			reintentos--;
		}
		*pputs = buffer;
		retorno = VERDADERO;
	}
	return retorno;
}

char UTN_putsCharReintentosMinMax(char* pputs,char* variableTexto, char* textoError, char min, char max, int reintentos){
	char buffer;
	char retorno;
	if(variableTexto != NULL && textoError != NULL && reintentos > 0 && min < max){
		printf("%s",variableTexto);
		fflush(stdin);
		buffer = getchar();
		while(validarCaracterIngresado(buffer) == FALSO || buffer > max || buffer < min){
			if(reintentos == 0){
				printf("Demasiados intentos fallidos.");
				retorno = FALSO;
				return retorno;
			}
			printf("%s",textoError);
			fflush(stdin);
			buffer = getchar();
			reintentos--;
		}
		*pputs = buffer;
		retorno = VERDADERO;
	}
	return retorno;
}

char UTN_putsTextoReintentos(char pputs[],int tam, char* variableTexto, char* textoError,int reintentos){
	char retorno = VERDADERO;
	if(variableTexto != NULL && textoError != NULL){
		printf("%s",variableTexto);
		fflush(stdin);
		while(myGets(pputs,tam) == FALSO){
			if(reintentos == 0){
				retorno = FALSO;
				break;
			}
			printf("%s", textoError);
			printf("%s",variableTexto);
			fflush(stdin);
			reintentos--;
		}
	}
	return retorno;
}
