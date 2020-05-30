#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Employee.h"
#include "utn.h"

Employee* employee_new()
{
	return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
	Employee* this;
	int idAux;
	int horasTrabajadasAux;
	int sueldoAux;
	this = employee_new();
	  if(this!=NULL)
	  {
		  idAux = atoi(idStr);
		  horasTrabajadasAux = atoi(horasTrabajadasStr);
		  sueldoAux = atoi(sueldo);

		  this->id=idAux;
		  strcpy(this->nombre,nombreStr);
		  this->horasTrabajadas=horasTrabajadasAux;
		  this->sueldo=sueldoAux;
	  }
	  return 0;
}

void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}
//*******************************************************************************************************************************
int employee_setId(Employee* this,int id)
{
	int retorno = -1;

	if(this!=NULL && id>=0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

		if(this!=NULL && id>=0)
		{
			*id = this->id;
			retorno = 0;
		}
		return retorno;
}

static int autoGenerateId = 0;

int employee_generoId()
{
	return autoGenerateId++;
}

//*******************************************************************************************************************************
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL && nombre!= NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL && nombre!= NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}
//*******************************************************************************************************************************

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this!=NULL && horasTrabajadas>0)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

		if(this!=NULL && horasTrabajadas>0)
		{
			*horasTrabajadas = this->id;
			retorno = 0;
		}
		return retorno;
}
//*******************************************************************************************************************************

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this!=NULL && sueldo>0)
	{
		this->sueldo=sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this!=NULL && sueldo>0)
	{
		*sueldo = this->id;
		retorno = 0;
	}
	return retorno;
}
