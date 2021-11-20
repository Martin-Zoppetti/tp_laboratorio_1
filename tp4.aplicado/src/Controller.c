
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Ingresos.h"

#define TRUE 1
#define FALSE 0
#define Tamano 128
#define menu_ModificacionesMin 1
#define menu_ModificacionesMax 4
#define Reintentos 5
#define minimoEmpleadosCargados 1

/** \brief La función se encarga de comparar los datos recibidos por parámetro.
 *
 * \param pFirstEmployee puntero a los datos de un empleado
 * \param pSecondEmployee puntero a los datos de un empleado
 * \return int Devuelve TRUE si se debe hacer un swap o FALSE si sucede lo contrario.
 *
 */

int compareEmployees(Employee* pFirstEmployee,Employee* pSecondEmployee,int orden)
{
	int retornoSwap = FALSE;
	char auxNombreUno[Tamano];
	char auxNombreDos[Tamano];
	if(pFirstEmployee != NULL && pSecondEmployee != NULL && orden > 0)
	{
		employee_getNombre(pFirstEmployee, auxNombreUno);
		employee_getNombre(pSecondEmployee, auxNombreDos);
		switch(orden)
		{
		case 1:
			if(strcmp(auxNombreUno,auxNombreDos) > 0)
			{
				retornoSwap = TRUE;
			}
			break;
		case 2:
			if(strcmp(auxNombreUno,auxNombreDos) < 0)
			{
				retornoSwap = TRUE;
			}
			break;
		}
	}
	return retornoSwap;
}

/** \brief La función se encarga de contar la cantidad de datos en los archivos para llevar un control de cual es la última ID registrada.
 *
 * \param pArrayListEmployee lista de punteros
 * \return int Devuelve el contador de datos registrados en el archivo.
 *
 */

int controller_dataCount(LinkedList* pArrayListEmployee)
{
	static int contador;
	FILE* file = fopen("data.csv","r");
	char id[256];
	char nombre[256];
	char horas[256];
	char sueldo[256];
	if(pArrayListEmployee != NULL){
		fscanf(file,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo); // salteo la 1era
		do{
			if(fscanf(file,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo)==4)
			{
				contador++;
			}
		}while(feof(file) == 0);
	}
	return contador;
}

/** \brief La función se encarga de desplegar y utilizar un menú de modificaciones para los datos del empleado.
 *
 * \param respuestaUsuario contiene la respuesta ingresada por el usuario para usarla en el switch.
 * \param employeeMod puntero con la dirección de memoria a los datos que queremos modificar.
 * \return int Retorna true si los parámetros son correctos o false en caso contrario.
 *
 */

int controller_modMenu(int respuestaUsuario,Employee* employeeMod)
{
	char auxNombre[Tamano];
	int auxHorasTrabajadas;
	int auxSueldo;
	int estadoIngresoNombre;
	int estadoIngresoHorasTrabajadas;
	int estadoIngresoSueldo;
	int retorno = FALSE;
	if(respuestaUsuario > 0 && employeeMod != NULL){
		retorno = TRUE;
		switch(respuestaUsuario){
		case 1:
			estadoIngresoNombre = UTN_ingresoTextoReintentos(auxNombre, Tamano,
					"Escriba el nuevo nombre del empleado: ",
					"El valor ingresado es incorrecto, reescriba: ", Reintentos);
			if(estadoIngresoNombre == TRUE)
			{

				employee_setNombre(employeeMod, auxNombre);
				puts("¡Operacion exitosa!\n");
			}
			else{
				puts("Error en la modificación, vuelva al menu e intentelo nuevamente.\n");
			}
			break;
		case 2:
			estadoIngresoHorasTrabajadas = UTN_ingresoIntReintentos(&auxHorasTrabajadas, "Escriba la nueva cantidad de horas trabajadas: ", "El valor ingresado es incorrecto, reingrese: ",Reintentos);
			if(estadoIngresoHorasTrabajadas == TRUE){
				employee_setHorasTrabajadas(employeeMod, auxHorasTrabajadas);
				puts("¡Operacion exitosa!\n");
			}
			else{
				puts("Error en la modificación, vuelva al menu e intentelo nuevamente.\n");
			}
			break;
		case 3:
			estadoIngresoSueldo = UTN_ingresoIntReintentos(&auxSueldo, "Escriba el nuevo sueldo: ", "El valor ingresado es incorrecto, reingrese: ",Reintentos);
			if(estadoIngresoSueldo == TRUE){
				employee_setSueldo(employeeMod, auxSueldo);
				puts("¡Operacion exitosa!\n");
			}
			else{
				puts("Error en la modificación, vuelva al menu e intentelo nuevamente.\n");
			}
			break;
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = FALSE;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* file = fopen(path,"r");
		if(file != NULL)
		{
			parser_EmployeeFromText(file, pArrayListEmployee);
			fclose(file);
			retorno = TRUE;
		}
		else{
			printf("ERROR, No se pudo abrir el archivo: %s",path);
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = FALSE;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* file = fopen(path,"rb");
		if(file != NULL)
		{
			parser_EmployeeFromBinary(file, pArrayListEmployee);
			fclose(file);
			retorno = TRUE;
		}
		else{
			printf("ERROR, No se pudo abrir el archivo: %s",path);
		}
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = FALSE;
	static int variable = 1;
	int auxID;
	char nuevaID[Tamano];
	char auxNombre[Tamano];
	char auxHorasTrabajadas[Tamano];
	char auxSueldo[Tamano];
	int estadoIngresoNombre;
	int estadoIngresoHorasTrabajadas;
	int estadoIngresoSueldo;
	Employee* pEmpleadoAuxiliar;
	if(pArrayListEmployee != NULL)
	{
		auxID = controller_dataCount(pArrayListEmployee) + variable;
		variable++;
		sprintf(nuevaID,"%d",auxID);
		printf("------------------------ ID: %d ------------------------\n" ,auxID);
		estadoIngresoNombre = UTN_ingresoTextoReintentos(auxNombre, Tamano, "Escriba el nombre del empleado a continuacion: ", "ERROR, el valor ingresado es incorrecto, reescriba: ", Reintentos);
		estadoIngresoHorasTrabajadas = UTN_ingresoTextoReintentos(auxHorasTrabajadas,Tamano, "Escriba la cantidad de horas trabajadas del empleado: ","ERROR, el valor ingresado es incorrecto, reescriba: ",Reintentos);
		estadoIngresoSueldo = UTN_ingresoTextoReintentos(auxSueldo,Tamano, "Escriba el sueldo del empleado: ", "ERROR, el valor ingresado es incorrecto, reescriba: ", Reintentos);
		if(estadoIngresoNombre == TRUE && estadoIngresoHorasTrabajadas == TRUE && estadoIngresoSueldo == TRUE)
		{
			pEmpleadoAuxiliar = employee_newParametros(nuevaID, auxNombre, auxHorasTrabajadas, auxSueldo);
			if(pEmpleadoAuxiliar != NULL)
			{
				ll_add(pArrayListEmployee,pEmpleadoAuxiliar);
				retorno = TRUE;
				puts("¡Operacion exitosa!\n");
			}
			else{
				puts("Error en la carga de datos, vuelva al menú e intentelo nuevamente.\n");
			}
		}
		else{
			puts("Error en el ingreso de datos, vuelva al menú y cargue los datos nuevamente.");
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = FALSE;
	int modID;
	int maximoEmpleadosCargados;
	int respuestaUsuario;
	int indiceMod;
	Employee* employeeMod;
	if(pArrayListEmployee != NULL)
	{
		maximoEmpleadosCargados = controller_dataCount(pArrayListEmployee);
		puts("--------------------- MENU DE MODIFICACIONES ---------------------\n");
		puts("Bienvenido al menu de modificaciones.\n");
		if(UTN_ingresoIntReintentosMinMax(&modID, "Escriba la ID del empleado del que desea modificar sus datos:", "ERROR, el valor ingresado es incorrecto, reescriba: ", minimoEmpleadosCargados, maximoEmpleadosCargados, Reintentos) == TRUE)
		{
			indiceMod = employee_findById(pArrayListEmployee, modID);
			if(indiceMod != -1)
			{
				employeeMod = ll_get(pArrayListEmployee,indiceMod);
				if(employeeMod != NULL)
				{
					do{
						printf("--------------------- ID seleccionada: %d ---------------------\n" ,modID);
						puts("Seleccione una de las siguientes opciones:\n");
						puts("\t1 - Modificar el nombre");
						puts("\t2 - Modificar la cantidad de horas trabajadas");
						puts("\t3 - Modificar el sueldo");
						puts("\t4 - Salir del menú.");
						if(UTN_ingresoIntReintentosMinMax(&respuestaUsuario, "Escriba su respuesta: ", "ERROR, el valor ingresado es incorrecto, reescriba: ", menu_ModificacionesMin, menu_ModificacionesMax, Reintentos) == TRUE)
						{
							controller_modMenu(respuestaUsuario,employeeMod);
							retorno = TRUE;
						}
						else{
							puts("Demasiados intentos en el ingreso de opción, vuelva al menú e intentelo nuevamente\n");
						}
					}while(respuestaUsuario != 4);
				}
			}
			else{
				puts("No se pudo encontrar la ID solicitada, vuelva al menú e intentelo nuevamente\n");
			}
		}
		else{
			puts("Error en el ingreso de ID, vuelva al menú e intentelo nuevamente\n");
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = FALSE;
	int bajaID;
	int maximoEmpleadosCargados;
	int indiceBaja;
	maximoEmpleadosCargados = controller_dataCount(pArrayListEmployee);
	Employee* employeeDown;
	if(pArrayListEmployee != NULL)
	{
		if(UTN_ingresoIntReintentosMinMax(&bajaID,
				"Escriba la ID del empleado del que desea dar de baja:",
				"ERROR, el valor ingresado es incorrecto, reescriba: ",
				minimoEmpleadosCargados,
				maximoEmpleadosCargados,
				Reintentos) == TRUE)
		{
			indiceBaja = employee_findById(pArrayListEmployee, bajaID);
			if(indiceBaja != -1)
			{
				employeeDown = ll_get(pArrayListEmployee,indiceBaja);
				if(employeeDown != NULL)
				{
					free(employeeDown);
					ll_remove(pArrayListEmployee,indiceBaja);
					puts("¡Operacion exitosa!\n");
					retorno = TRUE;
				}
				else{
					puts("Error en la busqueda del empleado, vuelva al menú e intentelo nuevamente.\n");
				}
			}
			else{
				puts("No se pudo encontrar al empleado con la ID solicitada, vuelva al menú e intentelo nuevamente.\n");
			}
		}
		else{
			puts("Supero la cantidad de intentos disponibles, vuelva al menú e intentelo nuevamente");
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = FALSE;
	int tamanoLista;
	if(pArrayListEmployee != NULL)
	{
		tamanoLista = ll_len(pArrayListEmployee);
		for(int i = 0;i<tamanoLista;i++)
		{
			Employee* pAuxiliarEmpleado = ll_get(pArrayListEmployee,i);
			printf("-----------------------------------\n");
			printf("ID empleado: %d\n",pAuxiliarEmpleado->id);
			printf("Nombre: %s\n",pAuxiliarEmpleado->nombre);
			printf("Horas trabajadas: %d\n",pAuxiliarEmpleado->horasTrabajadas);
			printf("Sueldo: %d\n",pAuxiliarEmpleado->sueldo);
			puts("----------------------\n");
			retorno = TRUE;
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmpleadoAuxiliar;
	Employee* pEmpleadoAuxiliarDos;
	Employee* pEmpleadoAuxiliarTres;
	int flagSwap;
	int tamanoLista;
	int retorno = FALSE;
	int respuestaUsuario;
	int estadoRespuestaUsuario;
	tamanoLista = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL)
	{
		puts("Escriba el numero de opcion para el orden que desea en su lista de empleados:\n 1 - Ascendente | 2 - Descendente");
		estadoRespuestaUsuario = UTN_ingresoIntReintentosMinMax(&respuestaUsuario, "Escriba su respuesta: ", "ERROR, el valor ingresado es incorrecto, reescriba su opcion: ", 1, 2, Reintentos);
		if(estadoRespuestaUsuario == TRUE)
		{
			do{
				flagSwap = FALSE;
				for(int i=0; i<tamanoLista-1; i++)
				{
					pEmpleadoAuxiliar = ll_get(pArrayListEmployee,i);
					pEmpleadoAuxiliarDos = ll_get(pArrayListEmployee,i+1);
					if(compareEmployees(pEmpleadoAuxiliar, pEmpleadoAuxiliarDos,respuestaUsuario) == TRUE)
					{
						flagSwap = TRUE;
						pEmpleadoAuxiliarTres = pEmpleadoAuxiliar;
						ll_set(pArrayListEmployee, i, pEmpleadoAuxiliarDos);
						ll_set(pArrayListEmployee, i+1, pEmpleadoAuxiliarTres);
						retorno = TRUE;
					}
				}
			}while(flagSwap == TRUE);
		}
		else{
			puts("Supero la cantidad de intentos disponibles, vuelva al menu e intentelo de nuevo.");
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* file = fopen(path,"w");
	Employee* pEmpleadoAuxiliar;
	int tamanoLista;
	int retorno = FALSE;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		if(file != NULL)
		{
			fprintf(file,"id,nombre,horasTrabajadas,sueldo\n");
			tamanoLista = ll_len(pArrayListEmployee);
			for(int i=0; i<tamanoLista; i++)
			{
				pEmpleadoAuxiliar = ll_get(pArrayListEmployee,i);
				if(fprintf(file,"%d,%s,%d,%d\n",
						pEmpleadoAuxiliar->id,
						pEmpleadoAuxiliar->nombre,
						pEmpleadoAuxiliar->horasTrabajadas,
						pEmpleadoAuxiliar->sueldo) > 0){
					retorno = TRUE;
				}

			}
			fclose(file);
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* file = fopen(path,"wb");
	int tamanoLista;
	int retorno = FALSE;
	int i;
	if(file != NULL)
	{
		tamanoLista = ll_len(pArrayListEmployee);
		for(i = 0;i<tamanoLista+1;i++)
		{
			fwrite(ll_get(pArrayListEmployee,i),sizeof(Employee),1,file);
			retorno = TRUE;
		}
	}
	fclose(file);
	return retorno;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
