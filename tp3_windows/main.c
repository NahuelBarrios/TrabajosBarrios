#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int idSave = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    while(option != 10)
    {
    	printf("/\n\n****************************************************\
    \nMenu:\
     \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\
     \n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\
     \n3. Alta de empleado\
     \n4. Modificar datos de empleado\
     \n5. Baja de empleado\
    \n6. Listar empleados\
     \n7. Ordenar empleados\
     \n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\
     \n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\
    \n10. Salir\
\n*****************************************************/");
    	utn_getInt(&option,"\nElija una opcion: ","\nError",1,10,3);

        switch(option)
        {
            case 1:
            	if(controller_loadFromText("data.csv",listaEmpleados,&idSave)==0)
            	{
            		idSave++;
            		printf("\nCargado en modo Texto con exito.");
            	}
            	else
            		printf("\nError al cargar\n");
                break;
            case 2:
            	if(controller_loadFromBinary("dataBin.csv",listaEmpleados,&idSave)==0)
            	{
            		idSave++;
            		printf("\nCargado en modo Binario con exito.");
            	}
            	else
            		printf("\nError al cargar\n");

            	break;
            case 3:
            	if(controller_addEmployee(listaEmpleados,idSave)==0)
				{
            		idSave++;
				}
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	controller_saveAsText("data.csv",listaEmpleados);
            	break;
            case 9:
            	controller_saveAsBinary("dataBin.csv",listaEmpleados);
            	break;
            case 10:

            	break;
            default: printf("\nIngrese un valor del menú.\n");
        }
    }
    return 0;
}
