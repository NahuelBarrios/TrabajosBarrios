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

int main(void)
{
	setbuf(stdout,NULL);


	Employee arrayEmployee[QTY_EMPLOYEE];
	initEmployees(arrayEmployee,QTY_EMPLOYEE);

	addEmployee(arrayEmployee,QTY_EMPLOYEE,1,"Nahuel","Barrios",12000,4);
	addEmployee(arrayEmployee,QTY_EMPLOYEE,2,"Candelaria","Scanavino",10000,1);
	addEmployee(arrayEmployee,QTY_EMPLOYEE,3,"Walter","Barrios",15000,3);
	addEmployee(arrayEmployee,QTY_EMPLOYEE,4,"Lucas","Balmaceda",10000,4);
	addEmployee(arrayEmployee,QTY_EMPLOYEE,5,"Federico","Scanavino",12000,6);

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
			if(existEmployees(arrayEmployee,QTY_EMPLOYEE) == 0)
			{
				printEmployees(arrayEmployee,QTY_EMPLOYEE);
				modifyEmployee(arrayEmployee,QTY_EMPLOYEE);
			}
			else
				printf("\nYou must load at least one employee before entering this option!\n");
		break;
		case 3:
			if(existEmployees(arrayEmployee,QTY_EMPLOYEE) == 0)
			{
			utn_getUnsignedInt("\nID to cancel: ","\nError",1,sizeof(int),1,QTY_EMPLOYEE,3,&searchId);
			removeEmployee(arrayEmployee,QTY_EMPLOYEE,searchId);
			}
			else
				printf("\nYou must load at least one employee before entering this option!\n");
			break;
		case 4:
			if(existEmployees(arrayEmployee,QTY_EMPLOYEE) == 0)
			report(arrayEmployee,QTY_EMPLOYEE);
			else
				printf("\nYou must load at least one employee before entering this option!\n");
			break;
			case 5:
			printf("\nThanks, come back soon!\n");
			break;

			default:
				printf("\nEnter the options displayed by the menu\n");
		}//switch


	}//while

	return 0;
}


