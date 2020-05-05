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
#include "ArrayEmployee.h"
#include "utn.h"
#define QTY_EMPLOYEE 1000

int main(void) {

	setbuf(stdout,NULL);


	Employee arrayEmployee[QTY_EMPLOYEE];
	initEmployees(arrayEmployee,QTY_EMPLOYEE);

	int option;
	int idEmployee = 0;
	int searchId;
	while(option != 5)
	{
		utn_getUnsignedInt("\nMENU\n1-Load employee\n2-Modify employee\n3-Delete employee\n4-Reports\n5-Exit\nSelect the option: ","\nError\n",1,sizeof(int),1,5,3,&option);

		switch(option)
		{
		case 1:
			loadEmployee(arrayEmployee,QTY_EMPLOYEE,&idEmployee);
			break;
		case 2:
			modifyEmployee(arrayEmployee,QTY_EMPLOYEE);
		break;
		case 3:
			utn_getUnsignedInt("\nID to cancel: ","\nError",1,sizeof(int),1,QTY_EMPLOYEE,3,&searchId);
			removeEmployee(arrayEmployee,QTY_EMPLOYEE,searchId);
			break;
		case 4:
			report(arrayEmployee,QTY_EMPLOYEE);
			break;
			case 5:
			printf("\nThanks, come back soon!\n");
			break;
		}


	}//while

	return 0;
}


