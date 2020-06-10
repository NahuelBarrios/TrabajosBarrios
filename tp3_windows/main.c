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
    	printf("/\n****************************************************\
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
    	printf("Option:");
    	scanf("%d",&option);

        switch(option)
        {
            case 1:

            		if(controller_loadFromText("data.csv",listaEmpleados,&idSave)==0)
            		{
            			idSave++;
            			printf("\nCargado en modo Texto con exito.");
            		}
            		else
            			printf("\nError al cargar");


                break;
            case 3:
            	if(controller_addEmployee(listaEmpleados,idSave)==0)
				{
            		idSave++;
				}
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
        }
    }
    return 0;
}
