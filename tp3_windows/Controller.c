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
	Employee* empleado;
	int bufferId;
	int auxBufferId;
	char bufferNombre[50];
	int bufferHoras;
	int bufferSueldo;
	int i;
	int len;
	int option = 0;


	if(pArrayListEmployee != NULL)
	{
		utn_getInt(&auxBufferId,"\nId de empleado a modificar: ","\nError",1,1000000,3);
		len = ll_len(pArrayListEmployee);

		for(i=0;i<len;i++)
		{
			empleado = (Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(empleado,&bufferId);

			if(bufferId != auxBufferId)
				continue;
					else
					{
						employee_getSueldo(empleado,&bufferSueldo);
						employee_getHorasTrabajadas(empleado,&bufferHoras);
						employee_getNombre(empleado,bufferNombre);
						printf("\nId\t\tNombre\tHoras\tSueldo\n");
						printf("%d\t\t%s\t%d\t%d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);

						while(option!=4)
						{
							utn_getInt(&option,"\nModificar:\n1-Nombre\n2-Sueldo\n3-Cantidad de horas\n4-No desea modificar nada.\nElija una opcion: ","\nError",1,4,3);

							switch(option)
							{
							case 1:
								fflush(stdin);
								utn_getName("\nIngrese el nombre: ","\nError",1,50,2,bufferNombre);
								employee_setNombre(empleado,bufferNombre);
								break;
							case 2:
								utn_getInt(&bufferSueldo,"\nIngrese el sueldo: ","\nError",1,9999,2);
								employee_setSueldo(empleado,bufferSueldo);
								break;
							case 3:
								utn_getInt(&bufferHoras,"\nIngrese cantidad de horas: ","\nError",1,9999,2);
								employee_setHorasTrabajadas(empleado,bufferHoras);
								break;
							case 4:
								printf("\nSalió\n");
								break;
							default: printf("\nIngrese una opcion valida!\n");

							}//switch
						}//while
					}//else
				}//for
				retorno=0;
			}//if
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
	int retorno = -1;
	Employee* empleado;
	int bufferId;
	int auxBufferId;
	char bufferNombre[50];
	int bufferHoras;
	int bufferSueldo;
	int i;
	int len;
	int option = 0;

	if(pArrayListEmployee != NULL)
	{
		utn_getInt(&auxBufferId,"\nId de empleado a eliminar: ","\nError",1,1000000,3);
		len = ll_len(pArrayListEmployee);

		for(i=0;i<len;i++)
		{
			empleado = (Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(empleado,&bufferId);

			if(bufferId != auxBufferId)
				continue;
			else
			{
				employee_getSueldo(empleado,&bufferSueldo);
				employee_getHorasTrabajadas(empleado,&bufferHoras);
				employee_getNombre(empleado,bufferNombre);
				printf("\nId\t\tNombre\tHoras\tSueldo\n");
				printf("%d\t\t%s\t%d\t%d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);

				while(option != 2)
				{
					utn_getInt(&option,"\nEsta seguro que desea eliminar este empleado?\n1-Eliminar\n2-No eliminar\nElija una opcion: ","\nError",1,10,3);
					switch(option)
					{
					case 1:
						ll_remove(pArrayListEmployee,i);
						printf("\nSe eliminó el empleado.\n");
						break;
					case 2:
						printf("\nSalió\n");
						break;
					default: printf("\nIngrese una opcion valida\n");
					}//switch
				}//While

			}//else
		}//for
	retorno = 0;
	}//if
    return retorno;
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
	    int bufferId;
	    int bufferSueldo;
	    char bufferNombre[50];
	    int bufferHoras;
	    Employee* bufferEmployee;
	    if(pArrayListEmployee != NULL)
	    {
	        len=ll_len(pArrayListEmployee);
	        printf("\nId\t\tNombre\tHoras\tSueldo\n");
	        for(i=0;i<len;i++)
	        {
	            bufferEmployee=(Employee*)ll_get(pArrayListEmployee,i);
	            if(bufferEmployee!=NULL)
	            {
	            	employee_getId(bufferEmployee,&bufferId);
	            	employee_getSueldo(bufferEmployee,&bufferSueldo);
	            	employee_getHorasTrabajadas(bufferEmployee,&bufferHoras);
	            	employee_getNombre(bufferEmployee,bufferNombre);
	            	printf("%d\t\t%s\t%d\t%d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);
	            }
	        }
	        retorno=0;
	    }
	    return retorno;
}


int order_byId(void* pUno,void* pDos)
{
	int retorno = -1;



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

	return 0;
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

