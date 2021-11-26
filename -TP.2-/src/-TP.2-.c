
#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"

int main(void) {
	setbuf(stdout,NULL);
	int len=1000;
	Employee list[len];
	int auxEliminar=-1;
	int auxResultado=-1;
	int respuesta=0;
	int banderaPrimeraCargaExitosa=-1;
	auxResultado=initEmployees(list, len);
	if(auxResultado==0){

		do{
			printf("--------------------------------MENU PRINCIPAL---------------------------------------\n");
			printf("Bienvenido, seleccione una de las siguientes opciones: \n");
			printf("\t1-ALTA\n");
			printf("\t2-MODIFICACION\n");
			printf("\t3-BAJA\n");
			printf("\t4-INFORME FINAL\n");
			printf("\t5-SALIR\n");
			if(UTN_ingresoIntReintentosMinMax(&respuesta,"Ingrese una opcion: " ,"ERROR,opcion no disponible, reingrese a continuacion: ", 1, 5, 10) == 1){
				switch (respuesta) {
				case 1:
					printf("---------ALTA---------\n");
					banderaPrimeraCargaExitosa= altaEmpleado(list, len);
					break;
				case 2:
					if(banderaPrimeraCargaExitosa==0){
						printf("--------------MODIFICACION--------------\n");
						modificarEmpleado(list, len);
					}
					else{
						printf("Debe ingresar al menos un empleado antes de seleccionar esta opcion");
					}
					break;
				case 3:
					if(banderaPrimeraCargaExitosa==0){
						printf("--------------BAJA--------------\n");
						auxEliminar= bajaEmpleado(list, len);
						if(auxEliminar!=0){
							printf("Ingreso un id Erroneo, vuelva a intentarlo desde el menu principal\n");
						}
					}
					else{
						printf("Debe ingresar al menos un empleado antes de seleccionar esta opcion\n");
					}

					break;
				case 4:
					if(banderaPrimeraCargaExitosa==0){
						printf("--------------INFORME FINAL--------------\n");
						informes(list, len);
					}
					else{
						printf("Debe ingresar al menos un empleado antes de seleccionar esta opcion");
					}

					break;
				case 5:
					printf("Se cierra el programa.\n");
					break;
				default:
					printf("Preste atencion a lo escrito en pantalla porfavor.\n");
					break;
				}
			}

		}while(respuesta!=5);
	}
	return EXIT_SUCCESS;
}
