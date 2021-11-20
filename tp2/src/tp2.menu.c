/*
 * tp2.menu.c
 *
 *  Created on: 16 oct. 2021
 *      Author: MariaElena
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleadosArray.h"
#include "tp2.gets.h"
#define TRUE 1
#define FALSE 0
#define REINTENTOS 5
#define MIN_RESPUESTA_MOD_MENU 1
#define MAX_RESPUESTA_MOD_MENU 6
#define MIN_RESPUESTA_MENU 1
#define MAX_RESPUESTA_MENU 5
#define MIN_EMPLEADOS 1
#define MAX_EMPLEADOS 1000

/* Brief: la funcion se encarga de generador ID's para cada empleados ingresado, al ser static su valor no se reinicia cada vez que se invoca a la función.
 */

int newID(void){
	static int contador = 1;
	return contador++;
}

void modMenu(Employee* EmployeeList, int len, int modID);
void finalReport(Employee* EmployeeList, int len);

/* Brief: la funcion se encarga de mostrar el menú con el que va a interactuar el usuario. El menu se sigue mostrando hasta que el usuario ingresé la opción numero 5 para salir del programa.
 * Param EmployeeList: lista de empleados
 * Param len: tamaño del array
 */

void menu(Employee* EmployeeList, int len){
	int respuestaUsuario;
	int auxID;
	int banderaAltaDeEmpleados = FALSE;
	char auxNombre[LEN_Nombre];
	char auxApellido[LEN_Nombre];
	float auxsalario;
	int auxSector;
	int IDMod;
	int IDBaja;
	int order;
	int estadoIngresoOrden;
	int estadoIngresoNombre;
	int estadoIngresoApellido;
	int estadoIngresoSalario;
	int estadoIngresoSector;
	do{
		printf("-------------------------------------------------------------------------------------\n");
		printf("--------------------------------MENU PRINCIPAL---------------------------------------\n");
		printf("Bienvenido, seleccione una de las siguientes opciones: \n");
		printf("\t1-ALTA\n");
		printf("\t2-MODIFICACION\n");
		printf("\t3-BAJA\n");
		printf("\t4-INFORME FINAL\n");
		printf("\t5-SALIR\n");
		if(UTN_putsIntReintentosMinMax(&respuestaUsuario,"Ingrese su respuesta: " ,"ERROR, el valor ingresado esta fuera del rango de opciones, reingrese a continuacion: ", MIN_RESPUESTA_MENU, MAX_RESPUESTA_MENU, REINTENTOS) == TRUE){
			switch(respuestaUsuario){
			case 1:
				banderaAltaDeEmpleados = TRUE;
				auxID = newID();
				printf("------------------------ID empleado: %d------------------------\n" ,auxID);
				estadoIngresoNombre = UTN_putsTextoReintentos(auxNombre, LEN_Nombre, "Ingrese el nombre del empleado: ", "ERROR, reingrese a continuacion:\n",REINTENTOS);
				estadoIngresoApellido = UTN_putsTextoReintentos(auxApellido, LEN_Nombre, "Ingrese el apellido del empleado: ", "ERROR, reingrese el apellido a continuacion: ",REINTENTOS);
				estadoIngresoSalario = UTN_putsFloatReintentos(&auxsalario, "Ingrese el salario del empleado: ", "ERROR, el valor ingresado es incorrecto, reingrese a continuación: ", REINTENTOS);
				estadoIngresoSector = UTN_putsIntReintentos(&auxSector, "Ingrese el sector del empleado: ", "ERROR, el valor es incorrecto, reingrese a continuacion: ", REINTENTOS);
				if(estadoIngresoNombre == TRUE && estadoIngresoApellido == TRUE && estadoIngresoSalario == TRUE && estadoIngresoSector == TRUE){
					if(addEmployees(EmployeeList, len, auxID, auxNombre, auxApellido, auxsalario, auxSector) == TRUE){
						printf("La operacion fue exitosa!\n");
					}else{
						printf("Ocurrido un error, vuelva al menu e intentelo nuevamente.\n");
					}
				}else{
					printf("Ocurrio un error en el ingreso de datos, vuelva al menu e intentelo nuevamente.\n");
				}
				break;
			case 2:
				printEmployees(EmployeeList, len);
				if(banderaAltaDeEmpleados == TRUE){
					if(UTN_putsIntReintentosMinMax(&IDMod, "Ingrese la ID del empleado que desea modificar: ", "ERROR, el valor ingresado es incorrecto, reingrese a continuacion: ", MIN_EMPLEADOS, MAX_EMPLEADOS, REINTENTOS) == TRUE){
						modMenu(EmployeeList,len,IDMod);
					}else{
						printf("ERROR en el ingreso del ID, vuelva al menu e intentelo nuevamente\n");
					}
				}else{
					printf("Todavía no se ha realizado ninguna carga de empleados, vuelva al menu y cargue los datos antes de seguir\n");
				}
				break;
			case 3:
				printEmployees(EmployeeList, len);
				if(banderaAltaDeEmpleados == TRUE){
					if(UTN_putsIntReintentosMinMax(&IDBaja, "Ingrese la ID del empleado que desea dar de baja: ", "ERROR, el valor ingresado es incorrecto, reingrese a continuacion: ", MIN_EMPLEADOS, MAX_EMPLEADOS, REINTENTOS) == TRUE){
						if(removeEmployee(EmployeeList,len,IDBaja) == TRUE){
							printf("¡La operacion fue exitosa!\n");
						}else{
							printf("Ocurrió un error inesperado al intentar dar de baja al empleado, vuelva al menu e intentelo nuevamente\n");
						}
					}else{
						printf("Ocurrio un error en el ingreso de datos, vuelva al menu e intentelo nuevamente.\n\n");
					}
				}else{
					printf("Todavía no se ha realizado ninguna carga de empleados, vuelva al menu y cargue los datos antes de seguir\n");
				}
				break;
			case 4:
				if(banderaAltaDeEmpleados == TRUE){
					printf("------------------------1------------------------\n");
					estadoIngresoOrden = UTN_putsIntReintentosMinMax(&order, "Ingrese el orden de apellidos (0 - Descendente | 1 - Ascendente): ", "ERROR, el valor es incorrecto, reingrese a continuacion: ", 0,1,REINTENTOS);
					if(estadoIngresoOrden == FALSE){
						printf("ERROR en el ingreso de datos, vuelva al menú e intentelo nuevamente.");
					}else{
						sortEmployees(EmployeeList,len, order);
						printEmployees(EmployeeList, len);
						printf("------------------------2------------------------\n");
						finalReport(EmployeeList,len);
					}
				}else{
					printf("Todavía no se ha realizado ninguna carga de empleados, vuelva al menu y cargue los datos antes de seguir\n");
				}
				break;
			case 5:
				printf("Fin del programa.");
				break;
			}
		}else{
			printf("Ha ingresado demasiados valores incorrectos, vuelva a intentarlo dentro de unos minutos.\n");
		}
	}while(respuestaUsuario != 5);
}

/* Brief: la funcion se encarga de mostrar un menu para la modificación de datos sobre un empleado. El menú se repite hasta que el usuario ingresa la opción 6 para salir del programa.
 * Param EmployeeList: lista de empleados
 * Param len: tamaño del array
 * Param modID: ID del empleado que se desea modificar sus datos.
 */


void modMenu(Employee* EmployeeList, int len, int modID){
	int indexMod;
	int respuestaUsuario;
	char auxNombre[LEN_Nombre];
	char auxApellido[LEN_Nombre];
	indexMod = findEmployeeById(EmployeeList,len, modID);
	do{
		printf("-------------------------------------------------------------------------------------\n");
		printf("-----------------------------MENU DE MODIFICACIONES----------------------------------\n");
		printf("¿Que dato desea modificar?\n");
		printf("\t1-ID\n");
		printf("\t2-Nombre\n");
		printf("\t3-Apellido\n");
		printf("\t4-Salario\n");
		printf("\t5-Sector\n");
		printf("\t6-Salir\n");
		if(UTN_putsIntReintentosMinMax(&respuestaUsuario,"Ingrese su respuesta: ","ERROR, el numero ingresado no coincide con una opcion del menu", MIN_RESPUESTA_MOD_MENU, MAX_RESPUESTA_MOD_MENU, REINTENTOS) == TRUE){
			switch(respuestaUsuario){
				case 1:
					if(UTN_putsIntReintentosMinMax(&EmployeeList[indexMod].id,"Ingrese el nuevo ID: \n","ERROR, reingrese el valor\n",MIN_EMPLEADOS,MAX_EMPLEADOS,REINTENTOS)){
						printf("La modificacion fue exitosa!\n");
					}else{
						printf("Ocurrio un error inesperado en la modificación, por favor intentelo nuevamente.\n");
					}
					break;
				case 2:
					if(UTN_putsTextoReintentos(auxNombre,LEN_Nombre,"Ingrese el nombre del empleado: \n","ERROR, reingrese el nombre: \n",REINTENTOS)){
						strcpy(EmployeeList[indexMod].Nombre,auxNombre);
						printf("La modificacion fue exitosa!\n");
					}else{
						printf("Ocurrio un error inesperado en la modificación, por favor intentelo nuevamente.\n");
					}
					break;
				case 3:
					if(UTN_putsTextoReintentos(auxApellido,LEN_Nombre,"Ingrese el apellido del empleado: \n","ERROR, reingrese el apellido: \n",REINTENTOS)){
						strcpy(EmployeeList[indexMod].Apellido,auxApellido);
						printf("La modificacion fue exitosa!\n");
					}else{
						printf("Ocurrio un error inesperado en la modificación, por favor intentelo nuevamente.\n");
					}
					break;
				case 4:
					if(UTN_putsFloatReintentos(&EmployeeList[indexMod].salario,"Ingrese el nuevo salario del empleado: \n","ERROR, reingrese el valor\n",REINTENTOS)){
						printf("La modificacion fue exitosa!\n");
					}else{
						printf("Ocurrio un error inesperado en la modificación, por favor intentelo nuevamente.\n");
					}
					break;
				case 5:
					if(UTN_putsIntReintentos(&EmployeeList[indexMod].sector,"Ingrese el nuevo sector del empleado: \n","ERROR, reingrese el valor\n",REINTENTOS)){
						printf("La modificacion fue exitosa!\n");
					}else{
						printf("Ocurrio un error inesperado en la modificación, por favor intentelo nuevamente.\n");
					}
					break;
				case 6:
					printf("¡Fin de las modificaciones!\n");
					break;
			}
		}else{
			printf("Ha ingresado demasiados valores incorrectos, vuelva a intentarlo dentro de unos minutos.\n");
		}
	}while(respuestaUsuario != 6);
}

/* Brief: la funcion se encarga de calcular el promedio de sueldos y contar cuantos de ellos superan dicho promedio.
 * Param EmployeeList: lista de empleados
 * Param len: tamaño del array
 */

void finalReport(Employee* EmployeeList, int len){
	float acumuladorDeSueldos = 0;
	int contadorDeEmpleados = 0;
	float promedioDeSueldos;
	int contadorDeEmpleadosQueSuperanElPromedio = 0;
	for(int i = 0;i<= len;i++){
		if(EmployeeList[i].isEmpty == FALSE){
			acumuladorDeSueldos += EmployeeList[i].salario;
			contadorDeEmpleados++;
		}
	}
	promedioDeSueldos = acumuladorDeSueldos / contadorDeEmpleados;
	printf("Promedio de sueldos: %f\n" ,promedioDeSueldos);
	for(int x = 0;x<= len;x++){
		if(EmployeeList[x].isEmpty == FALSE){
			if(EmployeeList[x].salario > promedioDeSueldos){
				contadorDeEmpleadosQueSuperanElPromedio++;
			}
		}
	}
	printf("Contador de empleados que superan el promedio: %d\n" ,contadorDeEmpleadosQueSuperanElPromedio);
}
