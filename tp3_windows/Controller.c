#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee,int* idSave)
{
	FILE*pArchivo;
		int retorno=-1;
		if(path != NULL && pArrayListEmployee != NULL)
		{
		   pArchivo=fopen(path,"r");
		   if(pArchivo != NULL)
		   {
		      if(parser_EmployeeFromText(pArchivo,pArrayListEmployee,idSave)==0)
		      {
		    	  fclose(pArchivo);
		    	  retorno=0;
		      }
		      else
		      {
		    	  printf("\nNo se pudo cargar la lista");
		      }

		   }
		   else
		   {
		      printf("\nNo se pudo abrir el archivo...");
		   }
		}
	    return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int id)
{
	int retorno=-1;
	Employee* empleado;
	char bufferNombre[50];
	int bufferHoras;
	int bufferSueldo;
	int bufferId;
	if(pArrayListEmployee!=NULL)
	    	{
				fflush(stdin);
				utn_getTexto("\nIngrese el nombre: ","\nError",1,50,3,bufferNombre);
				utn_getInt(&bufferHoras,"Horas trabajadas: ","\nError",1,1000000,3);
				utn_getInt(&bufferSueldo,"Sueldo: ","\nError",1,1000000,3);
				bufferId = id;
				empleado=employee_new();

				if(empleado != NULL && employee_setId(empleado,bufferId)==0 &&
						employee_setNombre(empleado,bufferNombre)==0 &&
						employee_setSueldo(empleado,bufferSueldo)==0 &&
						employee_setHorasTrabajadas(empleado,bufferHoras)==0)
						{
							if(ll_add(pArrayListEmployee,empleado)==0)
							{
								printf("\nEmpleado cargado\n");
								retorno = 0;
							}
							else
							{
								employee_delete(empleado);
								printf("\nError al agregar empleado\n");
							}
						}

	    	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;



    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	 int retorno=-1;
	    int len;
	    int i;
	    int id;
	    int sueldo;
	    char nombre[50];
	    int horas;
	    Employee* bufferEmployee;
	    if(pArrayListEmployee != NULL)
	    {
	        len=ll_len(pArrayListEmployee);
	        for(i=0;i<len;i++)
	        {
	            bufferEmployee=(Employee*)ll_get(pArrayListEmployee,i);
	            if(bufferEmployee!=NULL)
	            {
	            	employee_getId(bufferEmployee,&id);
	            	employee_getSueldo(bufferEmployee,&sueldo);
	            	employee_getHorasTrabajadas(bufferEmployee,&horas);
	            	employee_getNombre(bufferEmployee,nombre);
	            	printf("%d,%s,%d,%d\n",id,nombre,horas,sueldo);
	            }
	        }
	        retorno=0;
	    }
	    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

