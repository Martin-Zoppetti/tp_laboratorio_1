

#include <stdio.h>
#include <stdlib.h>
#include "employees.h"



int initEmployees(Employee* list, int len) {
	int retorno=-1;


	for (int i=0; i<len; i++)
	{
		list[i].isEmpty=0;
		retorno=0;
	}


	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{

	int retorno=-1;
	if(list!=NULL && len > 0 && id >= 0 && findEmployeeById(list, len, id)!=-1)
	{
		if(name != NULL && lastName != NULL && salary > 0){
			list[id].id = id;
			strcpy(list[id].name,name);
			strcpy(list[id].lastName,lastName);
			list[id].salary = salary;
			list[id].sector = sector;
			list[id].isEmpty = 1;
			retorno =0;
		}

	}
	return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{ int retorno=-1;
if(list != NULL && len > 0){
	retorno=id;
}

return retorno;
}
int removeEmployee(Employee* list, int len, int id)
{
	char auxNULL[10]="vacio";
	int auxInt=0;

	int retorno=-1;
	if(list!=NULL && len > 0 && id >= 0 && findEmployeeById(list, len, id)!=-1)
	{
		strcpy(list[id].name,auxNULL);
		strcpy(list[id].lastName,auxNULL);
		list[id].salary = auxInt;
		list[id].sector = auxInt;
		retorno =0;
	}



	return retorno;
}

//Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order *
 *  * \param list Employee*
 *  * \param len int
 *  * \param order int  [1] indicate UP - [0] indicate DOWN
 *  * \return int Return (-1) if Error [Invalid length or NULL pointer]
 *  - (0) if Ok * */
int sortEmployees(Employee* list, int len, int order)
{int retorno=-1;
int auxID;
char auxName[50];
char auxLastName[50];
float auxSalary;
int auxSector;
int swapAux;

switch (order) {
case 0:
	do{ swapAux=0;
	retorno=0;
	for(int i=0;i<len; i++){
		if(list[i].isEmpty == 1 && list[i+1].isEmpty == 1){
			if(strcmp(list[i].lastName,list[i+1].lastName) < 0){
				swapAux = 1;
				auxID = list[i].id;
				strcpy(auxName,list[i].name);
				strcpy(auxLastName,list[i].lastName);
				auxSalary = list[i].salary;
				auxSector = list[i].sector;

				list[i].id = list[i+1].id;
				strcpy(list[i].name,list[i+1].name);
				strcpy(list[i].lastName,list[i+1].lastName);
				list[i].salary = list[i+1].salary;
				list[i].sector = list[i+1].sector;

				list[i+1].id = auxID;
				strcpy(list[i+1].name,auxName);
				strcpy(list[i+1].lastName,auxLastName);
				list[i+1].salary = auxSalary;
				list[i+1].sector = auxSector;
			}
			if(strcmp(list[i].lastName,list[i+1].lastName) == 0){
				if(list[i].sector < list[i+1].sector){
					swapAux = 1;
					auxID = list[i].id;
					strcpy(auxName,list[i].name);
					strcpy(auxLastName,list[i].lastName);
					auxSalary = list[i].salary;
					auxSector = list[i].sector;

					list[i].id = list[i+1].id;
					strcpy(list[i].name,list[i+1].name);
					strcpy(list[i].lastName,list[i+1].lastName);
					list[i].salary = list[i+1].salary;
					list[i].sector = list[i+1].sector;

					list[i+1].id = auxID;
					strcpy(list[i+1].name,auxName);
					strcpy(list[i+1].lastName,auxLastName);
					list[i+1].salary = auxSalary;
					list[i+1].sector = auxSector;
				}
			}
		}
	}
	}while(swapAux==1);
	break;
case 1:
	do{
		swapAux=-1;
		retorno=0;
		for(int ii = 0;ii<len-1;ii++){
			if(list[ii].isEmpty == 1 && list[ii+1].isEmpty == 1){
				if(strcmp(list[ii].lastName,list[ii+1].lastName) > 0){
					swapAux = 1;
					auxID = list[ii+1].id;
					strcpy(auxName,list[ii+1].name);
					strcpy(auxLastName,list[ii+1].lastName);
					auxSalary = list[ii+1].salary;
					auxSector = list[ii+1].sector;

					list[ii+1].id = list[ii].id;
					strcpy(list[ii+1].name,list[ii].name);
					strcpy(list[ii+1].lastName,list[ii].lastName);
					list[ii+1].salary = list[ii].salary;
					list[ii+1].sector = list[ii].sector;

					list[ii].id = auxID;
					strcpy(list[ii].name,auxName);
					strcpy(list[ii].lastName,auxLastName);
					list[ii].salary = auxSalary;
					list[ii].sector = auxSector;
				}
				if(strcmp(list[ii].lastName,list[ii+1].lastName) == 0){
					if(list[ii].sector > list[ii+1].sector){
						swapAux = 1;
						auxID = list[ii+1].id;
						strcpy(auxName,list[ii+1].name);
						strcpy(auxLastName,list[ii+1].lastName);
						auxSalary = list[ii+1].salary;
						auxSector = list[ii+1].sector;

						list[ii+1].id = list[ii].id;
						strcpy(list[ii+1].name,list[ii].name);
						strcpy(list[ii+1].lastName,list[ii].lastName);
						list[ii+1].salary = list[ii].salary;
						list[ii+1].sector = list[ii].sector;

						list[ii].id = auxID;
						strcpy(list[ii].name,auxName);
						strcpy(list[ii].lastName,auxLastName);
						list[ii].salary = auxSalary;
						list[ii].sector = auxSector;

					}
				}
			}
		}
	}while(swapAux==1);
	break;
}

return retorno;
}

int printEmployees(Employee* list, int len)
{ int retorno=-1;
int i;
for(i=0;i<=len;i++){
	if(list[i].isEmpty == 1 && list[i].isEmpty!=0){

		printf("\n");
		printf("ID empleado: %d\n" ,list[i].id);
		printf("Nombre del empleado: %s\n" ,list[i].name);
		printf("Apellido del empleado: %s\n" ,list[i].lastName);
		printf("Salario del empleado: %f\n" ,list[i].salary);
		printf("Sector del empleado: %d\n" ,list[i].sector);
		printf("\n");
	}
	retorno=0;
}
return retorno;
}

int printEmployee(Employee* list, int len, int id)
{ int retorno=-1;

if(list[id].isEmpty == 1 && list[id].isEmpty!=0){

	printf("\n");
	printf("ID empleado: %d\n" ,list[id].id);
	printf("Nombre del empleado: %s\n" ,list[id].name);
	printf("Apellido del empleado: %s\n" ,list[id].lastName);
	printf("Salario del empleado: %f\n" ,list[id].salary);
	printf("Sector del empleado: %d\n" ,list[id].sector);
	printf("\n");
	retorno=0;
}

return retorno;
}

