#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee,int* idSave)
{


	int retorno = -1;
	Employee* empleado;
	char id[50];
	char nombre[50];
	char horas[50];
	char sueldo[50];
	int cant;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
	while(!feof(pFile))
	{
		cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);

		if(cant == 4)
		{
			empleado = employee_newParametros(id,nombre,horas,sueldo);
			if(empleado!=NULL)
			{
				ll_add(pArrayListEmployee,empleado);
				(*idSave)++;
				retorno = 0;
			}
			else
			{
				printf("\nNo se pudo crear empleado");
				break;
			}

		}
		else
		{
			printf("\nNo se pudo leer empleado correctamente");
			break;
		}
	}
		return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee,int* idSaveBin)
{
	int retorno = -1;
	Employee* empleado;
	int cant;
	int bufferId;
	char bufferNombre[50];
	int bufferHoras;
	int bufferSueldo;


	if(pFile != NULL && pArrayListEmployee != NULL && idSaveBin != NULL)
	{
		while(!feof(pFile))
		{
			empleado = employee_new();
			cant = fread(empleado,sizeof(empleado),1,pFile);

			if(cant == 1)
			{
				if(employee_getId(empleado,&bufferId)==0 && employee_getNombre(empleado,bufferNombre)==0 &&
						employee_getHorasTrabajadas(empleado,&bufferHoras)==0 && employee_getSueldo(empleado,&bufferSueldo)==0)
				{
					ll_add(pArrayListEmployee,empleado);
					(*idSaveBin)++;
					retorno = 0;
				}

			}
		}
	}
    return retorno;
}
