/*
 * empleadosArray.c
 *
 *  Created on: 16 oct. 2021
 *      Author: MariaElena
 */


#include "empleadosArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp2.gets.h"

#define TRUE 1
#define FALSE 0
#define LEN_Nombre 51
#define REINTENTOS 5

void printEmployees(Employee* EmployeeList,int len);
int initEmployees(Employee* EmployeeList,int len);

/* Brief: la funcion se encarga de devolver un contador con la cantidad de empleados activos
 * Param EmployeeList: lista de empleados
 * Param len: tamaño del array
 */


int activeEmployeeCount(Employee* EmployeeList, int len){
	int contadorDeEmpleadosActivos = 0;
	for(int i = 0;i<= len;i++){
		if(EmployeeList[i].isEmpty == FALSE){
			contadorDeEmpleadosActivos++;
		}
	}
	return contadorDeEmpleadosActivos;
}

/* Brief: la funcion se encarga de verificar en que orden desea ordenar los empleados según el usuario y luego procede a ordenarlos de forma ascendente o descendente.
 * Param EmployeeList: lista de empleados
 * Param len: tamaño del array
 * Param order: determina en que forma se ordena el array (0 - Descendente | 1 - Ascendente)
 */

int sortEmployees(Employee* EmployeeList,int len,int order){
	int retorno = TRUE;
	int flagSwap;
	int auxID;
	char auxNombre[LEN_Nombre];
	char auxApellido[LEN_Nombre];
	float auxsalario;
	int auxSector;
	switch(order){
		case 0:
			do{
				flagSwap=FALSE;
				for(int i = 0;i<len-1;i++){
					if(EmployeeList[i].isEmpty == FALSE && EmployeeList[i+1].isEmpty == FALSE){
						if(strcmp(EmployeeList[i].Apellido,EmployeeList[i+1].Apellido) < 0){
							flagSwap = TRUE;
							auxID = EmployeeList[i].id;
							strcpy(auxNombre,EmployeeList[i].Nombre);
							strcpy(auxApellido,EmployeeList[i].Apellido);
							auxsalario = EmployeeList[i].salario;
							auxSector = EmployeeList[i].sector;

							EmployeeList[i].id = EmployeeList[i+1].id;
							strcpy(EmployeeList[i].Nombre,EmployeeList[i+1].Nombre);
							strcpy(EmployeeList[i].Apellido,EmployeeList[i+1].Apellido);
							EmployeeList[i].salario = EmployeeList[i+1].salario;
							EmployeeList[i].sector = EmployeeList[i+1].sector;

							EmployeeList[i+1].id = auxID;
							strcpy(EmployeeList[i+1].Nombre,auxNombre);
							strcpy(EmployeeList[i+1].Apellido,auxApellido);
							EmployeeList[i+1].salario = auxsalario;
							EmployeeList[i+1].sector = auxSector;
						}
						if(strcmp(EmployeeList[i].Apellido,EmployeeList[i+1].Apellido) == 0){
							if(EmployeeList[i].sector < EmployeeList[i+1].sector){
								flagSwap = TRUE;
								auxID = EmployeeList[i].id;
								strcpy(auxNombre,EmployeeList[i].Nombre);
								strcpy(auxApellido,EmployeeList[i].Apellido);
								auxsalario = EmployeeList[i].salario;
								auxSector = EmployeeList[i].sector;

								EmployeeList[i].id = EmployeeList[i+1].id;
								strcpy(EmployeeList[i].Nombre,EmployeeList[i+1].Nombre);
								strcpy(EmployeeList[i].Apellido,EmployeeList[i+1].Apellido);
								EmployeeList[i].salario = EmployeeList[i+1].salario;
								EmployeeList[i].sector = EmployeeList[i+1].sector;

								EmployeeList[i+1].id = auxID;
								strcpy(EmployeeList[i+1].Nombre,auxNombre);
								strcpy(EmployeeList[i+1].Apellido,auxApellido);
								EmployeeList[i+1].salario = auxsalario;
								EmployeeList[i+1].sector = auxSector;
							}
						}
					}
				}
			}while(flagSwap==TRUE);
			break;
		case 1:
			do{
				flagSwap=FALSE;
				for(int x = 0;x<len-1;x++){
					if(EmployeeList[x].isEmpty == FALSE && EmployeeList[x+1].isEmpty == FALSE){
						if(strcmp(EmployeeList[x].Apellido,EmployeeList[x+1].Apellido) > 0){
							flagSwap = TRUE;
							auxID = EmployeeList[x].id;
							strcpy(auxNombre,EmployeeList[x].Nombre);
							strcpy(auxApellido,EmployeeList[x].Apellido);
							auxsalario = EmployeeList[x].salario;
							auxSector = EmployeeList[x].sector;

							EmployeeList[x].id = EmployeeList[x+1].id;
							strcpy(EmployeeList[x].Nombre,EmployeeList[x+1].Nombre);
							strcpy(EmployeeList[x].Apellido,EmployeeList[x+1].Apellido);
							EmployeeList[x].salario = EmployeeList[x+1].salario;
							EmployeeList[x].sector = EmployeeList[x+1].sector;

							EmployeeList[x+1].id = auxID;
							strcpy(EmployeeList[x+1].Nombre,auxNombre);
							strcpy(EmployeeList[x+1].Apellido,auxApellido);
							EmployeeList[x+1].salario = auxsalario;
							EmployeeList[x+1].sector = auxSector;
						}
						if(strcmp(EmployeeList[x].Apellido,EmployeeList[x+1].Apellido) == 0){
							if(EmployeeList[x].sector > EmployeeList[x+1].sector){
								flagSwap = TRUE;
								auxID = EmployeeList[x].id;
								strcpy(auxNombre,EmployeeList[x].Nombre);
								strcpy(auxApellido,EmployeeList[x].Apellido);
								auxsalario = EmployeeList[x].salario;
								auxSector = EmployeeList[x].sector;

								EmployeeList[x].id = EmployeeList[x+1].id;
								strcpy(EmployeeList[x].Nombre,EmployeeList[x+1].Nombre);
								strcpy(EmployeeList[x].Apellido,EmployeeList[x+1].Apellido);
								EmployeeList[x].salario = EmployeeList[x+1].salario;
								EmployeeList[x].sector = EmployeeList[x+1].sector;

								EmployeeList[x+1].id = auxID;
								strcpy(EmployeeList[x+1].Nombre,auxNombre);
								strcpy(EmployeeList[x+1].Apellido,auxApellido);
								EmployeeList[x+1].salario = auxsalario;
								EmployeeList[x+1].sector = auxSector;
							}
						}
					}
				}
		}while(flagSwap==TRUE);
		break;
	}
	return retorno;
}

/* Brief: la funcion se encarga de encontrar un index disponible donde cargar los datos del empleado
 * Param EmployeeList: lista de empleados
 * Param len: tamaño del array
 * Param pIndex: variable puntero que pretende retornar un index libre en el array.
 */

int findFreeEmployeeIndex(Employee* EmployeeList,int len,int* pIndex){
	int retorno = FALSE;
	if(EmployeeList != NULL && len > 0){
		for(int i = 0;i<= len;i++){
			if(EmployeeList[i].isEmpty == TRUE){
				*pIndex = i;
				retorno = TRUE;
				break;
			}
		}
	}
	return retorno;
}

/* Brief: la funcion se encarga de inicializar todas las variables "isEmpty" del array en TRUE, permitiendo así saber si hay datos cargados o no
 * Param EmployeeList: lista de empleados
 * Param len: tamaño del array
 */

int initEmployees(Employee* EmployeeList,int len){
	int retorno = FALSE;
	if(EmployeeList != NULL && len > 0){
		for(int i = 0;i<= len;i++){
			EmployeeList[i].isEmpty = TRUE;
			retorno = TRUE;
		}
	}
	return retorno;
}

/* Brief: la funcion se encarga de cargar los datos pasados por paramétro dentro del array.
 * Param EmployeeList: lista de empleados
 * Param len: tamaño del array
 * Param ID: numero ID del empleado.
 * Param Nombre: nombre del empleado.
 * Param Apellido: apellido del empleado
 * Param salario: salario del empleado
 * Param sector: sector del empleado
 */

int addEmployees(Employee* EmployeeList, int len, int id, char Nombre[],char Apellido[],float salario, int sector){
	int indexFree;
	int retorno = FALSE;
	if(findFreeEmployeeIndex(EmployeeList, len,&indexFree) == TRUE){
		if(EmployeeList != NULL && len > 0 && id >= 0 && Nombre != NULL && Apellido != NULL && salario > 0){
			EmployeeList[indexFree].id = id;
			strcpy(EmployeeList[indexFree].Nombre,Nombre);
			strcpy(EmployeeList[indexFree].Apellido,Apellido);
			EmployeeList[indexFree].salario = salario;
			EmployeeList[indexFree].sector = sector;
			EmployeeList[indexFree].isEmpty = FALSE;
			retorno = TRUE;
		}
	}else{
		printf("Ya no hay capacidad para mas empleados.\n");
	}
	return retorno;
}

/* Brief: la funcion se encarga de buscar el index de un empleado mediante su ID, comparando con todas las del array hasta que encuentre a que index le pertenece.
 * Param EmployeeList: lista de empleados
 * Param len: tamaño del array
 * Param ID: numero ID del empleado a encontrar.
 */

int findEmployeeById(Employee* EmployeeList,int len, int ID){
	int retorno = -1;
	if(EmployeeList != NULL && len > 0 && ID > -1){
		for(int i = 0;i<= len;i++){
			if(EmployeeList[i].id == ID){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/* Brief: la funcion se encarga de hacer la baja lógica de un empleado mediante la ID ingresada por el usuario
 * Param EmployeeList: lista de empleados
 * Param len: tamaño del array
 * Param ID: numero ID del empleado a dar de baja.
 */

int removeEmployee(Employee* EmployeeList,int len, int ID){
	int index;
	int retorno = FALSE;
	index = findEmployeeById(EmployeeList, len, ID);
	if(index != -1){
		EmployeeList[index].isEmpty = TRUE;
		retorno = TRUE;
	}
	return retorno;
}

/* Brief: la función imprime el array de empleados con sus respectivos datos ingresados siempre y cuando haya algún valor cargado.
 * Param EmployeeList: lista de empleados
 * Param len: tamaño del array
 */
void printEmployees(Employee* EmployeeList,int len){
	for(int i=0;i<=len;i++){
		if(EmployeeList[i].isEmpty == FALSE){
			printf("-------------------------------------------------------------------------------------\n");
			printf("ID empleado: %d\n" ,EmployeeList[i].id);
			printf("Nombre del empleado: %s\n" ,EmployeeList[i].Nombre);
			printf("Apellido del empleado: %s\n" ,EmployeeList[i].Apellido);
			printf("Salario del empleado: %f\n" ,EmployeeList[i].salario);
			printf("Sector del empleado: %d\n" ,EmployeeList[i].sector);
			printf("-------------------------------------------------------------------------------------\n");
		}
	}
}

