/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "empleadosArray.h"
#include "tp2.menu.h"
#define LEN_EmployeeS 1000

int main(void) {
	setbuf(stdout,NULL);
	Employee EmployeeList[LEN_EmployeeS];
	initEmployees(EmployeeList,LEN_EmployeeS);
	menu();
	return 0;
}
