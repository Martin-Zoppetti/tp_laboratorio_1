#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"

#define FALSO 0
#define VERDADERO 1

int main(void){

	setbuf(stdout,NULL);

	int respuestaSuma=FALSO;
	int respuestaResta=FALSO;
	float respuestaDivision=FALSO;
	int respuestaMultiplicacion=FALSO;
	int respuestaFactorialA=FALSO;
	int respuestaFactorialB=FALSO;
	int reintentos=10;
	int operadorA;
	int operadorB;
	int respuesta;
	printf("Bienvenido a su mejor calculadora\n");

	do{
		printf("---------MENU----------\n");

		UTN_ingresoIntReintentosMinMax(&respuesta,"Selecciones una opcion:\n 1. Ingresar 1er operando (A)\n 2. Ingresar 2do operando (B)\n 3. Calcular todas las operaciones\n  4. Informar resultados \n 5. Salir\n OPCION:->\n" , "opcion incorrecta", 1, 5, reintentos);

		switch (respuesta) {
		case 1 :
			ingresOperadorA(&operadorA, reintentos);
			break;
		case 2:
			ingresOperadorB(&operadorB, reintentos);
			break;
		case 3:
			calculadora(operadorA, operadorB, &respuestaSuma, &respuestaResta, &respuestaDivision, &respuestaMultiplicacion, &respuestaFactorialA, &respuestaFactorialB);
			break;
		case 4:
			informarResultados(respuestaSuma, respuestaResta, respuestaDivision, respuestaMultiplicacion, respuestaFactorialA, respuestaFactorialB);
			break;
		case 5:
			printf("Se cierra la calculadora, vuelva prontos !");
			break;

		}

	}while(respuesta!=5);



return respuesta;
}
