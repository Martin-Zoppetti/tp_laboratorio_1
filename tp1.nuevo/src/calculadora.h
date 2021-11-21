

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresos.h"




/*brief guarda el dato del operador A
 *
 * \param int* operador
 * \param int reintentos
 * \return int devuelve falso(0) en el caso de en el caso de que no se consiga escribir un numero correcto, o verdadero(1) en caso contrario
 *
 */
int ingresOperadorA(int* operadorA,int reintentos);
/*brief guarda el dato del operador B
 *
 * \param int* operador
 * \param int reintentos
 * \return int devuelve falso(0) en el caso de en el caso de que no se consiga escribir un numero correcto, o verdadero(1) en caso contrario
 *
 */
int ingresOperadorB(int* operadorB,int reintentos);
/*brief Suma dos operadores
 *
 * \param int operador1
 * \param int operador2
 * \return int falso (0) si alguno de los datos es NULL o resultado de la suma
 *
 */
int suma(int operador1, int operador2);
/*brief Resta dos operadores
 *
 * \param int operador1
 * \param int operador2
 * \return int falso (0) si alguno de los datos es NULL o resultado de la resta
 *
 */
int resta(int operador1, int operador2);
/*brief divide el primer operador por el segundo
 *
 * \param int operador1
 * \param int operador2
 * \return int falso (NULL) si el operador2 es cero o si algun operador es NULL, en caso contrario devuelve el resultado de la division
 *
 */
float division(int operador1, int operador2);
/*brief multiplica un operador por el otro
 *
 * \param int operador1
 * \param int operador2
 * \return int falso (0) si algun operador es NULL o el resultado en caso contrario
 *
 */
int multiplicacion(int operador1, int operador2);
/*brief realiza el factorial del operador que se ingrese
 *
 * \param int operador
 * \return retorna falso(0) si el operador es negativo o NULL, o el resultado en caso contrario
 *
 */
int factorial(int operador);
/*brief llama a las funciones sumar, restar, dividir, multiplicar y factorial para que obtener los resultados de dichas operaciones con los valores asignados A y B
 * \param int A
 * \param int B
 * \param int *respuestaSuma
 * \param int *respuestaResta
 * \param float *respuestaDivision
 * \param int *respuestaMultiplicacion
 * \param int *respuestaFactorialA
 * \param int *respuestaFactorialB
 * \return int falso(0) si alguno de los parametros es NULL, si la division tiene un divisor cero o si alguno de los operadores es negativo ya que no se puede operar un factorial con negativos, en caso contrario devuelve 1
 *
 */
int calculadora(int A,int B,int *respuestaSuma,int *respuestaResta,float *respuestaDivision,int *respuestaMultiplicacion,int *respuestaFactorialA,int *respuestaFactorialB);
/*brief muestra los resultados de los calculos realizados por la calculadora
 * \param int respuestaSuma
 * \param int respuestaResta
 * \param float respuestaDivision
 * \param int respuestaMultiplicacion
 * \param int respuestaFactorialA
 * \param int respuestaFactorialB
 * \return int falso(0) si alguno de los parametros es NULL o si el resultado de la division es falso, en caso contrario devuelve 1
 *
 */
int informarResultados(int respuestaSuma,int respuestaResta,float respuestaDivision,int respuestaMultiplicacion,int respuestaFactorialA,int respuestaFactorialB);




#endif /* CALCULADORA_H_ */

