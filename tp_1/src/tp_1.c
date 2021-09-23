

/*
 ============================================================================
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main(void) {
	setbuf(stdout,NULL);
	int A;
	int B;
	int opcion;
	float resultado;
	int estado=0;

		printf("escriba el primer numero :");
	scanf("%d",A);
	printf("el numero que se guardo es: %d\n",A);

	printf("escriba el segundo numero :");
	scanf("%d",B);
	printf("el numero que se guardo es: %d\n",B);

	printf("escibra que opcion desea (suma, resta, division, multiplicacion, factorial)");
	scanf("%c", opcion);
	switch (opcion){

	case "suma":
		suma(A,B,resultado);
	printf("el resultado de la suma es: %f", resultado);
	break;

	case "resta":
		resta(A,B,resultado);
	printf("el resultado de la resta es: %f", resultado);
	break;

	case "division":
		division(A,B,resultado);

		printf("el resultado de la suma es: %f", resultado);

		break;

	case "multiplicacion" :
		multiplicacion(A,B,resultado);
		printf("el resultado de la multiplicacion es: %f", resultado);

		break;


	case "factorial":
		factorial(A,B,resultado);
		printf("el resultado del factorial es: %f", resultado);


		break;

	}


	return EXIT_SUCCESS;
}
