#include "ABM.h"


int generadorDeId(Employee* list, int len){
	int retorno=-1;
	for(int i=0;i<len;i++){
		if(list[i].isEmpty==0){
			retorno=i;
			break;
		}


	}
	return retorno;
}

int altaEmpleado(Employee* list, int len){
	int tam=50;
	int reintentos=5;
	int retorno=-1;
	int auxId;
	char name[tam];
	char lastName[tam];
	float salary;
	int sector;
	if(generadorDeId(list, len)!=-1){
		auxId=generadorDeId(list, len);
UTN_ingresoTextoReintentos(name,tam , "Escriba el nombre del empleado: \n", "Error, ingreso un nombre incorrecto.\n", reintentos);
UTN_ingresoTextoReintentos(lastName, tam, "Escriba el apellido del empleado: \n", "Error, ingreso un apellido incorrecto. \n", reintentos);
UTN_ingresoFloatReintentos(&salary,  "Escriba el  salario del empleado: \n", "Error, ingreso un salario incorrecto.\n" , reintentos);
UTN_ingresoIntReintentos(&sector, "Escriba el sector del empleado: \n",  "Error, ingreso un sector incorrecto.\n", reintentos);




		addEmployee(list, len, auxId, name, lastName, salary, sector);
printEmployee(list, len, auxId);
		retorno=0;

	}
	else{
		printf("No hay espacio disponible para integrar un nuevo empleado, debe eliminar un empleado para poder ingresar uno nuevo.");
	}
	return retorno;
}


int modificarEmpleado(Employee* list, int len){
	int retorno=-1;
	int auxId;
	int reintentos=5;
	int auxGetId;
	printListaEmployees(list, len);
	printf("------------------Menu de modificaciones------------------\n");
	do{
		auxGetId=UTN_ingresoIntReintentosMinMax(&auxId, "Ingrese el id del empleado a modificar\n", "Error, Id incorrecto, vuelva a ingresar un id correctamente", 0, 1000, reintentos);
		if(findEmployeeById(list, len, auxId)!=-1 && auxGetId==1)
		{
			menuMod(list, len, auxId);
			retorno=0;
		}
		else{
			printf("ingreso un id incorrecto, vuelva a intentarlo\n");

		}
	}while(retorno!=0);


	return retorno;
}


void menuMod(Employee* list, int len,int id){
	int respuesta;
	char auxString[25];
	int auxSector;

	do{printf("Escriba una opcion de modificacion\n Modificar nombre: opcion 1 \n Modificar apellido: opcion 2 \n Modificar sector: opcion 3\n");

	scanf("%d",&respuesta);

	switch (respuesta) {
	case 1:
		printf("Escriba el nuevo nombre: \n");
			scanf("%s",auxString);
			strcpy(list[id].name,auxString);

		break;
	case 2:
		printf("Escriba el nuevo apellido: \n");
			scanf("%s",auxString);
			strcpy(list[id].lastName,auxString);
		break;
	case 3:
		printf("Escriba el nuevo sector: \n");
		scanf("%d",&auxSector);
		list[id].sector=auxSector;
		break;
	default:
		printf("ingreso una opcion incorrecta,vuelva a intentarlo\n");

		break;
	}
	}while(respuesta!=1 && respuesta!=2 && respuesta!=3 );


	printf("Modificacion exitosa! \n Volviendo a menu principal");
}




void printListaEmployees(Employee* list, int len){
	printf("Lista de empleados registrados \n");
	for(int i=0; i<len; i++){
		if(list[i].isEmpty==1 ){
		printEmployee(list, len, i);

	}
}
}



int bajaEmpleado(Employee* list, int len){
	int retorno =1;
	int auxId;
	printListaEmployees(list, len);

	printf("ingrese el id del empleado a dar de baja\n");
	scanf("%d",&auxId);
	if(findEmployeeById(list, len,auxId)!=-1)
	{
		removeEmployee(list, len, auxId);
		retorno=0;
	}

	return retorno;
}



int informes(Employee* list, int len){

	int respuesta=-1;
	int opcion;
	printf("\n Seleccione una opcion:\n Si desea un listado de los empleados ordenados alfabéticamente por Apellido y Sector, ingrese 1. \n Si desea el total y promedio de los salarios, y cuántos empleados superan el salario promedio, ingrese 2.\n Opcion: \n");
	scanf("%d",&respuesta);
	printf("Opciones: \n");
	switch (respuesta) {
		case 1:
			printf("  Si desea el listado alfabeticamente descendente, ingrese 0\n  Si desea el listado alfabeticamente ascendente, ingrese 1 \n");
			scanf("%d",&opcion);
			sortEmployees(list, len, opcion);
			printListaEmployees(list, len);
			break;
		case 2:
			presentacionSalarial(list, len);
			break;
		default:
			break;
	}





	return respuesta;
}



void presentacionSalarial(Employee* list, int len){
float acumuladorSalarios=0;
int contadorDeEmpleados=0;
float resultadoPromedios;
int superadores=0;

for(int i=0; i<len; i++){
	if(list[i].isEmpty!=0){
		acumuladorSalarios=list[i].salary+acumuladorSalarios;
contadorDeEmpleados++;
	}
	resultadoPromedios=acumuladorSalarios/contadorDeEmpleados;

}
for(int i=0; i<len; i++){
	if(list[i].isEmpty!=0 && list[i].salary>resultadoPromedios){
superadores++;
	}


}
printf("El salario total es: %f \n El promedio salarial es: %f \n La cantidad de empleados que superan el salario promedio son: %n \n",acumuladorSalarios,resultadoPromedios,&superadores);

}












