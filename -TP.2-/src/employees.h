#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"

#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_

struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

/** \brief Imprime el un empleado del array de empleados de forma encolumnada.
 * * * \param list Employee*
 * * \param length int
 * * \return int -1 en caso de no conseguir ningun empleado registrado - 0 en caso contrario* */
int printEmployee(Employee* list, int len, int id);

/** \brief Para indicar que todas las posiciones del array están vacías,
 *   esta función pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
 * *          this function put the flag (isEmpty) in TRUE in all
 * *          position of the array *
 *  \param list Employee* Pointer to array of employees *
 *  \param len int Array length *
 *  \return int Return (-1) if Error [Invalid length or NULL pointer] -
 *  (0) if Ok * */
int initEmployees(Employee* list, int len);
/**
 *  \brief  //Agrega en un array de empleados existente los valores recibidos como parámetro en la primer posición libre.
 *  * \param list employee*
 *  * \param len int
 *  * \param id int
 *  * \param name[] char
 *  * \param lastName[] char
 *   * \param salary float
 *   * \param sector int
 *   * \return int Return
 *   (-1) if Error [Invalid length or NULL pointer
 *    or without free space] - (0) if Ok *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
 * * * \param list Employee*
 * * \param len int
 * * \param id int
 * * \return Return employee index position or (-1)
 * if [Invalid length or NULL pointer received or employee not found] * */
int findEmployeeById(Employee* list, int len,int id);
/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
 *  * \param list Employee*
 *   * \param len int
 *  * \param id int
 *  * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok * */
int removeEmployee(Employee* list, int len, int id);
/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 *  * \param list Employee*
 *  * \param len int
 *  * \param order int  [1] indicate UP - [0] indicate DOWN
 *  * \return int Return (-1) if Error [Invalid length or NULL pointer]
 *  - (0) if Ok * */
int sortEmployees(Employee* list, int len, int order);
/** \brief Imprime el array de empleados de forma encolumnada.
 * * * \param list Employee*
 * * \param length int
 * * \return int * */
int printEmployees(Employee* list, int len);

#endif /* EMPLOYEES_H_ */
