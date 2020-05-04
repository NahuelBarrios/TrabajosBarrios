/*
 * employee.c
 *
 *  Created on: 4 may. 2020
 *      Author: Nahu_
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "employee.h"

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

//-------------------------------------------------------------------------------------------------------------------------------

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;
	if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary>0 && sector>0)
	{

		list[len].id = id;
	    strcpy(list[len].name, name);
	    strcpy(list[len].lastName, lastName);
	    list[len].salary = salary;
	    list[len].sector = sector;
	    list[len].isEmpty = 1;

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
			utn_getTexto("\nIngrese el nombre: ","\nError",1,51,3,auxName);
			utn_getTexto("\nIngrese el apellido: ","\nError",1,51,3,auxLastName);
			utn_getFloat("\nIngrese el salario: ","\nError",1,sizeof(float),1,1000000,3,&auxSalary);
			utn_getUnsignedInt("\nIngrese el sector: ","\nError",1,sizeof(int),1,10,3,&auxSector);

			addEmployee(list,len,auxId,auxName,auxLastName,auxSalary,auxSector);

		}
	}

	return retorno;
}
int findEmpty(Employee* array, int size, int* posicion)
{
	   int retorno=-1;
	    int i;
	    if(array!= NULL && size>=0 && posicion!=NULL)
	    {
	        for(i=0;i<size;i++)
	        {
	            if(array[i].isEmpty==1)
	            {
	                retorno=0;
	                *posicion=i;
	                break;
	            }
	        }
	    }
	    return retorno;
}
//-------------------------------------------------------------------------------------------------------------------------------

int findEmployeeById(Employee* list, int len,int id,int* posicion)
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
	                *posicion=i;
	                break;
	            }
	        }
	    }
	    return retorno;

}

int modifyEmployee(Employee* array, int sizeArray)
{
	   int retorno=-1;
	    int posicion;
	    int id;
	    char opcion;
	    if(array!=NULL && sizeArray>0)
	    {
	        utn_getUnsignedInt("\nId de empleado a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
	        if(findEmployeeById(array,sizeArray,id,&posicion)==-1)
	        {
	            printf("\nNo existe este ID");
	        }
	        else
	        {
	            do
	            {
	                utn_getChar("\nModificar: \nA-Nombre\nB-Apellido\nC-Salario\nD-Sector S-Salir","\nError",'A','Z',1,&opcion);
	                switch(opcion)
	                {
	                    case 'A':
	                    	utn_getTexto("\nIngrese el nuevo nombre: ","\nError",1,51,3,array[posicion].name);
	                        break;
	                    case 'B':
	                    	utn_getTexto("\nIngrese el nuevo apellido: ","\nError",1,51,3,array[posicion].lastName);
	                        break;
	                    case 'C':
	                    	utn_getFloat("\nIngrese el nuevo salario: ","\nError",1,sizeof(float),0,1,3,&array[posicion].salary);
	                        break;
	                    case 'D':
	                    	utn_getUnsignedInt("\nIngrese nuevo sector: ","\nError",1,sizeof(int),1,1,3,&array[posicion].sector);;
	                        break;
	                    case 'S':
	                        break;
	                    default:
	                        printf("\nOpcion no valida");
	                }
	            }while(opcion!='S');
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
	            printf("\nNo existe este ID");
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

		if(order == 1)
		{
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
		}

		else if(order == 2)
		{
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


		}

		retorno = 0;
	}

 return retorno;
}

