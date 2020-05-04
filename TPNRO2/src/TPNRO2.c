/*
 ============================================================================
 Name        : TPNRO2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "employee.h"
#define QTY_EMPLOYEE 1000

int main(void) {

	setbuf(stdout,NULL);


	Employee arrayEmployee[QTY_EMPLOYEE];
	initEmployees(arrayEmployee,QTY_EMPLOYEE);

	int option;
	int idEmployee = 0;
	int searchId;
	int option2 = 0;
	int order;
	while(option != 5)
	{
		utn_getUnsignedInt("\nMENU\n1-Alta\n2-Modificar\n3-Baja\n4-Informar\n5-Salir\nSeleccione: ","\nError\n",1,sizeof(int),1,5,3,&option);

		switch(option)
		{
		case 1:
			loadEmployee(arrayEmployee,QTY_EMPLOYEE,&idEmployee);
			break;
		case 2:
			modifyEmployee(arrayEmployee,QTY_EMPLOYEE);
		break;
		case 3:
			utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,QTY_EMPLOYEE,3,&searchId);
			removeEmployee(arrayEmployee,QTY_EMPLOYEE,searchId);
			break;
		case 4:
			while (option2 != 3)
					{
					utn_getUnsignedInt("\n1-Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n3-Salir\nIngrese opcion: ",
							"\nError\n",1,sizeof(int),1,5,3,&option2);
						switch(option2)
						{
						case 1:
							utn_getUnsignedInt("\nOrdenar por apellido:\n1-Ascendete\n2-Descendente: ","\nError\n",1,sizeof(int),1,2,3,&order);
							sortEmployees(arrayEmployee,QTY_EMPLOYEE,order);
							break;
						case 2:
							break;
						}
					}
			break;
			case 5:
			printf("\nGracias vuelva pronto!\n");
			break;
		}


	}//while

	return 0;
}


