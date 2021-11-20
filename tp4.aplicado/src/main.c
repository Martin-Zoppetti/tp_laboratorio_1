
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Ingresos.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

#define TRUE 1
#define FALSE 0
#define opcionMinima 1
#define opcionMaxima 10
#define Reintentos 5



int main(){
	setbuf(stdout,NULL);
	LinkedList* listaEmpleados = ll_newLinkedList();
	int respuestaUsuario;
	int banderaCargaDatosTexto = FALSE;
	int banderaCargaDatosBinario = FALSE;
	do{
		puts("----------------------------------------------------------------------------------\n");
		printf("Bienvenido al menú, seleccione una de las siguientes opciones:\n");
		puts("\t1 - Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
		puts("\t2 - Cargar los datos de los empleados desde el archivo data.txt (modo binario).");
		puts("\t3 - Alta de empleados");
		puts("\t4 - Modificar empleado");
		puts("\t5 - Baja empleado");
		puts("\t6 - Listar empleados");
		puts("\t7 - Ordenar empleados");
		puts("\t8 - Guardar los datos de los empleados en el archivo data.csv (modo texto)");
		puts("\t9 - Guardar los datos de los empleados en el archivo data.txt (modo binario)");
		puts("\t10 - Salir del programa");
		UTN_ingresoIntReintentosMinMax(&respuestaUsuario,"Escriba una opción del menu: ","ERROR, el valor ingresado es incorrecto, reescriba correctamente: ",opcionMinima,opcionMaxima,Reintentos);
		switch(respuestaUsuario) {
		case 1:
			if(controller_loadFromText("data.csv", listaEmpleados) == TRUE)
			{
				puts("¡Operacion exitosa!");
				banderaCargaDatosTexto = TRUE;
			}
			break;
		case 2:
			if(controller_loadFromBinary("data.txt", listaEmpleados) == TRUE)
			{
				banderaCargaDatosBinario = TRUE;
			}
			break;
		case 3:
			if(banderaCargaDatosTexto == TRUE || banderaCargaDatosBinario == TRUE)
			{
				controller_addEmployee(listaEmpleados);
			}
			else{
				puts("Aun no realiza la carga de datos por archivo, vuelva al menu");
			}
			break;
		case 4:
			if(banderaCargaDatosTexto == TRUE || banderaCargaDatosBinario == TRUE)
			{
				controller_editEmployee(listaEmpleados);
			}
			else{
				puts("Aun no realiza la carga de datos por archivo, vuelva al menu");
			}
			break;
		case 5:
			if(banderaCargaDatosTexto == TRUE || banderaCargaDatosBinario == TRUE)
			{
				controller_removeEmployee(listaEmpleados);
			}
			else{
				puts("Aun no realiza la carga de datos por archivo, vuelva al menu");
			}
			break;
		case 6:
			if(banderaCargaDatosTexto == TRUE || banderaCargaDatosBinario == TRUE)
			{
				controller_ListEmployee(listaEmpleados);
			}
			else{
				puts("Aun no realiza la carga de datos por archivo, vuelva al menu");
			}
			break;
		case 7:
			// ORDENAR EMPLEADOS
			controller_sortEmployee(listaEmpleados);
			break;
		case 8:
			// GUARDAR DATOS EN MODO TEXTO
			if(banderaCargaDatosTexto == TRUE)
			{
				if(controller_saveAsText("data.csv", listaEmpleados) == TRUE)
				{
					puts("¡Operacion exitosa!");
				}
			}
			else{
				puts("Aun no realiza la carga de datos por archivo, vuelva al menu");
			}
			break;
		case 9:
			// GUARDAR DATOS EN MODO BINARIO
			if(banderaCargaDatosTexto == TRUE || banderaCargaDatosBinario == TRUE)
			{
				if(controller_saveAsBinary("data.txt", listaEmpleados) == TRUE)
				{
					puts("¡Operacion exitosa!");
				}
			}
			else{
				puts("Aun no realiza la carga de datos por archivo, vuelva al menu");
			}
			break;
		case 10:
			puts("Fin del programa.");
			break;
		}
	} while (respuestaUsuario != 10);
}
