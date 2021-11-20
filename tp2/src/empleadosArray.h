/*
 * empleadosArray.h
 *
 *  Created on: 16 oct. 2021
 *      Author: MariaElena
 */

#ifndef EMPLEADOSARRAY_H_
#define EMPLEADOSARRAY_H_


#include <stdio.h>
#include <stdlib.h>
#define LEN_EmployeeS 1000
#define LEN_Nombre 51

typedef struct{
	int id;
	char Nombre[LEN_Nombre];
	char Apellido[LEN_Nombre];
	float salario;
	int sector;
	int isEmpty;
}Employee;


int initEmployees(Employee* EmployeeList,int len);
int addEmployees(Employee* EmployeeList, int len, int id, char Nombre[],char Apellido[],float salario, int sector);
int findEmployeeById(Employee* EmployeeList,int len, int ID);
int removeEmployee(Employee* EmployeeList,int len, int ID);
void printEmployees(Employee* EmployeeList,int len);
int sortEmployees(Employee* EmployeeList,int len,int order);


#endif /* EMPLEADOSARRAY_H_ */
