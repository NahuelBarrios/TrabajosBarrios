/*
 * employee.c
 *
 *  Created on: 4 may. 2020
 *      Author: Nahu_
 */

#include "ArrayEmployee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int initEmployees(Employee* list, int len)
{
	int retorno=-1;
	    if(list!= NULL && len>0)
	    {
	        for(;len>0;len--)
	        {
	        	list[len-1].isEmpty=1;
	        }
	        retorno=0;
	    }
	    return retorno;
}

int existEmployees(Employee* list, int len)
{
	int ret = -1;
    int i;

    for( i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            ret = 0;
        }
    }
    return ret;
}

//-------------------------------------------------------------------------------------------------------------------------------

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;
	if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary>0 && sector>0)
	{
		//I add [id] so that in that position all the data is loaded. I use it as a position
		list[id].id = id;
	    strcpy(list[id].name, name);
	    strcpy(list[id].lastName, lastName);
	    list[id].salary = salary;
	    list[id].sector = sector;
	    list[id].isEmpty = 0;

	    retorno = 0;
	}
 return retorno;
}

int loadEmployee(Employee* list,int len,int* idCont)
{
	int retorno=-1;
	int posicion;
	int auxId;
	char auxName[51];
	char auxLastName[51];
	float auxSalary;
	int auxSector;

	if(list!=NULL && len>0)
	{
		if(findEmpty(list,len,&posicion) == -1)
		{
			printf("\nNo hay mas lugar para recibir altas.\n");
		}
		else
		{
			(*idCont)++;
			auxId = *idCont;
			utn_getTexto("\nEnter name: ","\nError",1,51,3,auxName);
			utn_getTexto("\nEnter last name: ","\nError",1,51,3,auxLastName);
			utn_getFloat("\nEnter salary: ","\nError",1,150000,1,120000,3,&auxSalary);
			utn_getUnsignedInt("\nEnter sector: ","\nError",1,sizeof(int),1,10,3,&auxSector);

			addEmployee(list,len,auxId,auxName,auxLastName,auxSalary,auxSector);

		}
	}

	return retorno;
}
int findEmpty(Employee* list, int len, int* position)
{
	   int retorno=-1;
	    int i;
	    if(list!= NULL && len>=0 && position!=NULL)
	    {
	        for(i=0;i<len;i++)
	        {
	            if(list[i].isEmpty==1)
	            {
	                retorno=0;
	                *position=i;
	                break;
	            }
	        }
	    }
	    return retorno;
}
//-------------------------------------------------------------------------------------------------------------------------------

int findEmployeeById(Employee* list, int len,int id,int* position)
{
	int retorno=-1;
	    int i;
	    if(list!= NULL && len>=0 && id>0)
	    {
	        for(i=0;i<len;i++)
	        {
	            if(list[i].isEmpty==1)
	                continue;
	            else if(list[i].id==id)
	            {
	                retorno=0;
	                *position=i;
	                break;
	            }
	        }
	    }
	    return retorno;

}

int modifyEmployee(Employee* list, int len)
{
	   int retorno=-1;
	    int posicion;
	    int id;
	    char opcion;
	    if(list!=NULL && len>0)
	    {
	        utn_getUnsignedInt("\nEmployee ID to modify: ","\nError",1,sizeof(int),1,len,3,&id);
	        if(findEmployeeById(list,len,id,&posicion)==-1)
	        {
	            printf("\nThere is no such Id");
	        }
	        else
	        {
	            do
	            {
	                utn_getChar("\nModify: \nA-Name\nB-Last Name\nC-Salary\nD-Sector \nE-Exit","\nError",'A','Z',1,&opcion);
	                switch(opcion)
	                {
	                    case 'A':
	                    	utn_getTexto("\nEnter new name: ","\nError",1,51,3,list[posicion].name);
	                        break;
	                    case 'B':
	                    	utn_getTexto("\nEnter new last name: ","\nError",1,51,3,list[posicion].lastName);
	                        break;
	                    case 'C':
	                    	utn_getFloat("\nEnter new salary: ","\nError",1,150000,1,120000,3,&list[posicion].salary);
	                        break;
	                    case 'D':
	                    	utn_getUnsignedInt("\nEnter new sector: ","\nError",1,sizeof(int),1,10,3,&list[posicion].sector);;
	                        break;
	                    case 'E':
	                        break;
	                    default:
	                        printf("\nOption not valid");
	                }
	            }while(opcion!='E');
	            retorno=0;
	        }
	    }
	    return retorno;

}

//-------------------------------------------------------------------------------------------------------------------------------

int removeEmployee(Employee* list, int len, int id)
{
	 int retorno=-1;
	    int posicion;
	    if(list!=NULL && len>0 && id>0)
	    {

	        if(findEmployeeById(list,len,id,&posicion)==-1)
	        {
	            printf("\nThere is no such id");
	        }
	        else
	        {
	        	list[posicion].isEmpty=1;
	        	list[posicion].id=0;
	        	strcpy(list[posicion].name,"");
	        	strcpy(list[posicion].lastName,"");
	        	list[posicion].salary=0;
	        	list[posicion].sector=0;
	            retorno=0;
	        }
	    }
	    return retorno;

}

//-------------------------------------------------------------------------------------------------------------------------------

int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	Employee auxOrder;

	if(list!= NULL && len>0 && order>0)
	{

		switch(order)
		{

		case 1:
			for(int i=0; i<len - 1; i++)
			{
				for(int j=i+1; j<len; j++)
				{
					if(strcmp(list[j].lastName, list[i].lastName) < 0)
					{
						auxOrder = list[i];
						list[i] = list[j];
						list[j] = auxOrder;
					}
					else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector)
					{
						auxOrder = list[i];
						list[i] = list[j];
						list[j] = auxOrder;
					}
				}
			}
			retorno = 0;
			break;


			case 2:
			for(int i = 0; i < len - 1; i++)
			{
				for(int j = i + 1; j < len; j++)
				{
					if(strcmp(list[j].lastName, list[i].lastName) > 0)
					{
						auxOrder = list[i];
						list[i] = list[j];
						list[j] = auxOrder;
					}
					else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector)
					{
						auxOrder = list[i];
						list[i] = list[j];
						list[j] = auxOrder;
					}
				}
			}
			retorno = 0;
			break;
		}

	}

 return retorno;
}

int printEmployees(Employee* list, int length)
{
	 int retorno=-1;
	    int i;
	    if(list!=NULL && length>=0)
	    {
	    	printf("******************************************************************************\nID\tLast Name\t\t\tName\t\tSalary\t\tSector\n******************************************************************************");
	        for(i=0;i<length;i++)
	        {
	            if(list[i].isEmpty==1)
	                continue;
	            else
	            	printf("\n%d\t%s\t\t\t%s\t\t%.2f\t\t%d",list[i].id,list[i].lastName,list[i].name,list[i].salary,list[i].sector);
	        }
	        retorno=0;
	    }
	    return retorno;

}

int salaryReport(Employee* list,int len)
{
	int retorno = -1;
	int i;
	int contador =0;
	float acumulador = 0;
	float total = 0;
	int salarioMasPromedio = 0;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				contador++;
				acumulador = acumulador + list[i].salary;
			}
		}

		total = acumulador/contador;

		for (i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary >total)
			{
				salarioMasPromedio++;
			}
		}

		    printf("\nTotal salary: %.2f ", acumulador);
		    printf("\nAverage salary: %.2f ", total);
		    printf("\nNumber of employees with higher than average salary: %d \n", salarioMasPromedio);


	retorno = 0;
	}
	return retorno;
}

int report(Employee* list, int len)
{
	int retorno = -1;
	int option = 0;
	int order;

	if (list != NULL && len >0)
	{
		while (option != 3)
		{
			utn_getUnsignedInt("\n\n1-List of employees alphabetically by Last Name and Sector\n2-Total and average wages, and how many employees exceed the average wage\n3-Exit\nSelect the option: ",
				"\nError\n",1,sizeof(int),1,5,3,&option);
			switch(option)
			{
			case 1:
				utn_getUnsignedInt("\nSort by last name:\n1-upward\n2-falling\nSelect the option: ","\nError\n",1,sizeof(int),1,2,3,&order);
				sortEmployees(list,len,order);
				printEmployees(list,len);
				break;
			case 2:
				salaryReport(list,len);
				break;
			case 3:
				printf("\nExiting reports\n");
				break;
			default:
				printf("\nEnter an option from 1 to 3\n");
			}
		}
		retorno = 0;
	}
	return retorno;
}
