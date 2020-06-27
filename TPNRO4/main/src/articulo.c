#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "articulo.h"

eArticulo* articulo_new()
{
	eArticulo* articulo = (eArticulo*)malloc( sizeof(eArticulo));

		if(articulo != NULL)
		{
			articulo->id = 0;
			strcpy(articulo->articulo,"");
			articulo->precio = 0;
			strcpy(articulo->medida,"");
			articulo->rubroId = 0;
		}
	return articulo;
}
//*******************************************************************************************************
eArticulo* articulo_newParametros(char* idStr,char* articuloStr,char*medidaStr,char* precioStr,char* reubroIdStr)
{
	eArticulo* articulo = articulo_new();

	if(articulo != NULL)
	{
		articulo_setId(articulo,atoi(idStr));
		articulo_setArticulo(articulo,articuloStr);
		articulo_setPrecio(articulo,atoi(precioStr));
		articulo_setMedida(articulo,medidaStr);
		articulo_setRubroId(articulo,atoi(reubroIdStr));
	}
return articulo;
}
//*******************************************************************************************************
int articulo_setId(eArticulo* this,int id)
{
	int retorno = -1;

	if(this!=NULL && id>=0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int articulo_getId(eArticulo* this,int* id)
{
	int retorno = -1;

		if(this!=NULL && id!= NULL)
		{
			*id = this->id;
			retorno = 0;
		}
		return retorno;
}
//*******************************************************************************************************
int articulo_setArticulo(eArticulo* this,char* articulo)
{
	int retorno = -1;

	if(this!=NULL && articulo!= NULL)
	{
		strcpy(this->articulo,articulo);
		retorno = 0;
	}

	return retorno;
}

int articulo_getArticulo(eArticulo* this,char* articulo)
{
	int retorno = -1;

	if(this!=NULL && articulo!= NULL)
	{
		strcpy(articulo,this->articulo);
		retorno = 0;
	}
	return retorno;
}
//*******************************************************************************************************
int articulo_setPrecio(eArticulo* this,int precio)
{
	int retorno = -1;

	if(this!=NULL && precio>=0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

int articulo_getPrecio(eArticulo* this,int* precio)
{
	int retorno = -1;

		if(this!=NULL && precio!= NULL)
		{
			*precio = this->precio;
			retorno = 0;
		}
		return retorno;
}
//*******************************************************************************************************
int articulo_setMedida(eArticulo* this,char* medida)
{
	int retorno = -1;

	if(this!=NULL && medida!= NULL)
	{
		strcpy(this->medida,medida);
		retorno = 0;
	}

	return retorno;
}

int articulo_getMedida(eArticulo* this,char* medida)
{
	int retorno = -1;

	if(this!=NULL && medida!= NULL)
	{
		strcpy(medida,this->medida);
		retorno = 0;
	}
	return retorno;
}
//*******************************************************************************************************
int articulo_setRubroId(eArticulo* this,int idRubro)
{
	int retorno = -1;

	if(this!=NULL && idRubro>=0)
	{
		this->rubroId = idRubro;
		retorno = 0;
	}
	return retorno;
}

int articulo_getRubroId(eArticulo* this,int* idRubro)
{
	int retorno = -1;

	if(this!=NULL && idRubro!= NULL)
	{
		*idRubro = this->rubroId;
		retorno = 0;
	}
	return retorno;
}
//*******************************************************************************************************

int controller_precioMasCien(void* pPrecio)
{
	int retorno = 0;
	eArticulo* articulo;

	if (pPrecio != NULL)
	{
		articulo = (eArticulo*)pPrecio;

		if(articulo->precio>100)
		retorno = 1;
	}
	return retorno;
}

int controller_cantCuidadoRopa(void* pIdRubro)
{
	int retorno = 0;
	eArticulo* articulo;

	if (pIdRubro != NULL)
	{
		articulo = (eArticulo*)pIdRubro;

		if(articulo->rubroId == 1)
		retorno = 1;
	}
	return retorno;
}
