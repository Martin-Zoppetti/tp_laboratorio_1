/*
 ============================================================================
 Name        : vid1-.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MIN 0
#define MAX 1000
#define reintentos 3
int Ingreso(float* pnum,float numMIN,float numMAX,int intentos);
int dividir(float num1, float num2,float* presultado);
int main(void) {
	setbuf (stdout,NULL);
	float resultado;
	float num1;
	float num2;

	if(Ingreso(&num1,MIN,MAX,reintentos)==0){
	printf("numero 1 es %f", num1);
	}
	else{
printf("reinicia el programa bobo");
}
if(Ingreso(&num2,MIN,MAX,reintentos)==0){
	printf("numero 1 es %f", num1);
	}
	else{
		printf("reinicia el programa bobo\n");
	}

	if(dividir(num1,num2,&resultado)==0){

	printf("resultado%f",resultado);
	}
	else{
		printf("num2 no puede ser 0");

	}
	return EXIT_SUCCESS;
}

int dividir(float num1, float num2,float* presultado){

	float resultado;
	int estado;

	if(num2!=0){
		estado=0;
	resultado=num1/num2;
	*presultado=resultado;
	}
	else{
		estado=1;
	}


	return estado;

}
int Ingreso(float* pnum,float numMIN,float numMAX,int intentos){
	int estado;
	float aux;

	printf("ingrese valor");
	scanf("%f",&aux);
	if(aux>numMAX || aux<numMIN){
		estado=1;
	while(intentos!=0){
		printf("ingrese valor");
		scanf("%f",&aux);

		if(aux<numMAX && aux>numMIN){
				estado=0;
				*pnum=aux;
				break;
			}
	intentos--;

		}
	}

	else {
		estado=0;
		*pnum=aux;
		}
return estado;


}










