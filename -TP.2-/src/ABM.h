#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#include "employees.h"



#ifndef ABM_H_
#define ABM_H_

/** \brief genera un id disponible para agregar un empleado.
 * * * \param list Employee*
 * * \param len int
 * * \return int -1 si no hay mas ids disponibles ,el int id  en caso contrario* */

int generadorDeId(Employee* list, int len);
/** \brief despliega el formulario para ingresar un nuevo empleado y lo guarda .
 * * * \param list Employee*
 * * \param len int
 * * \return int -1 en caso de no tener mas id disponibles, 0 en caso de carga exitosa* */
int altaEmpleado(Employee* list, int len);
/** \brief permite la modificacion del nombre apellido o sector del empleado .
 * * * \param list Employee*
 * * \param len int
 * * \return int -1 en caso de no completar el circuito de modificacion , 0 en caso contrario* */
int modificarEmpleado(Employee* list, int len);
/** \brief despliega un menu para gestionar la modificacion dentro de la funcion modificarempleado.
 * * * \param list Employee*
 * * \param len int
 * * \return void* */
void menuMod(Employee* list, int len,int id);
/** \brief imprime una lista de empleados.
 * * * \param list Employee*
 * * \param len int
 * * \return void* */
void printListaEmployees(Employee* list, int len);
/** \brief gestiona la eliminacion de un empleado en base al id ingresado por el usuario.
 * * * \param list Employee*
 * * \param len int
 * * \return int -1 en caso de que el id no sea correcto, 0 en caso contrario* */
int bajaEmpleado(Employee* list, int len);
/** \brief .
 * * * \param list Employee*
 * * \param len int
 * * \return int -1 , 0 en caso contrario* */
int informes(Employee* list, int len);
/** \brief .
 * * * \param list Employee*
 * * \param len int
 * * \return int -1 en caso de no utilizar una de las respuestas pertinentes, int respuesta en caso contrario* */
void presentacionSalarial(Employee* list, int len);



#endif /* ABM_H_ */
