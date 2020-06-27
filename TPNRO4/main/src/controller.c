/*
 * controller.c
 *
 *  Created on: 24 jun. 2020
 *      Author: Nahu_
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "articulo.h"
#include "parser.h"
#include "utn.h"

int controller_loadData(char* path,LinkedList* pArrayListArticulo)
{
	int retorno = -1;
	FILE* pArchivo;

	if(path != NULL && pArrayListArticulo != NULL)
	{
		pArchivo= fopen(path,"r");
		if(pArchivo != NULL)
		{
			if(parser_loadData(pArchivo,pArrayListArticulo) == 0)
			{
				fclose(pArchivo);
				retorno = 0;
			}
			else
			{
				printf("\nNo se pudo cargar el archivo\n");
			}
		}
	}
	return retorno;
}

int controller_orderByArticulo(void* thisA,void* thisB)
{
	int order = -1;
	char articuloA[51];
	char articuloB[51];

	articulo_getArticulo(thisA,articuloA);
	articulo_getArticulo(thisB,articuloB);

	if(strcmp(articuloA,articuloB)>0)
	{
		order = 1;
	}

	return order;


}

int controller_sortArticulos(LinkedList* pArrayListArticulo)
{
	int retorno = -1;

	if(pArrayListArticulo != NULL)
	{
		if(ll_sort(pArrayListArticulo,controller_orderByArticulo,1)== 0)
			retorno = 0;
	}

	return retorno;
}

int controller_listArticulos(LinkedList* pArrayListArticulo)
{
	int retorno = -1;
	int longitud;
	int i;
	eArticulo* articulo = NULL;
	int bufferId;
	char bufferArticulo[128];
	int bufferPrecio;
	char bufferMedida[51];
	int bufferRubroId;
	char bufferRubroIdStr[51];

	if(pArrayListArticulo != NULL)
	{
		longitud = ll_len(pArrayListArticulo);
		printf("\nid,articulo,medida,precio,rubroId\n");

		for(i=0;i<longitud;i++)
		{
			articulo = (eArticulo*)ll_get(pArrayListArticulo,i);

			if(articulo != NULL)
			{
				if(articulo_getId(articulo,&bufferId)== 0 &&
				articulo_getArticulo(articulo,bufferArticulo)== 0 &&
				articulo_getPrecio(articulo,&bufferPrecio)== 0 &&
				articulo_getMedida(articulo,bufferMedida)== 0 &&
				articulo_getRubroId(articulo,&bufferRubroId)==0)
				{
					switch(bufferRubroId)
					{
					case 1:
						strcpy(bufferRubroIdStr,"CUIDADO DE ROPA");
						break;
					case 2:
						strcpy(bufferRubroIdStr,"LIMPIEZA Y DESINFECCION");
						break;
					case 3:
						strcpy(bufferRubroIdStr,"CUIDADO PERSONAL E HIGIENE");
						break;
					case 4:
						strcpy(bufferRubroIdStr,"CUIDADO DEL AUTOMOTOR");
						break;
					}

					printf("%d,%s,%d,%s,%s\n",bufferId,bufferArticulo,bufferPrecio,bufferMedida,bufferRubroIdStr);
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

int controller_utiliceMap(void* p)
{
	int retorno = -1;
	int bufferPrecio;
	int bufferIdRubro;
	int descuento=0;
	int total=0;

	if(p != NULL)
	{

		p = (eArticulo*)p;
		articulo_getPrecio(p,&bufferPrecio);
		articulo_getRubroId(p,&bufferIdRubro);

		switch(bufferIdRubro)
		{
		case 1:
			if(bufferPrecio>=120)
			{
				descuento = (bufferPrecio*20)/100;
				total = bufferPrecio - descuento;
			}
			else
				total = bufferPrecio;
			break;
		case 2:
			if(bufferPrecio>=200)
			{
				descuento = (bufferPrecio*10)/100;
				total = bufferPrecio - descuento;
			}
			else
				total = bufferPrecio;
			break;
		default:
			total = bufferPrecio;
		}
		articulo_setPrecio(p,total);
		retorno = 0;
	}

	return retorno;
}

int controller_descuentoLimpieza(LinkedList* pArrayListArticulo)
{
	int retorno = -1;

	if(pArrayListArticulo != NULL)
	{
		ll_map(pArrayListArticulo,controller_utiliceMap);
			retorno = 0;
	}

	return retorno;
}

int controller_saveData(char* path,LinkedList* pArrayListArticulo)
{
	int retorno = -1;
	int longitud;
	int i;
	int bufferId;
	char bufferArticulo[51];
	int bufferPrecio;
	char bufferMedida[51];
	int bufferRubroId;
	eArticulo* articulo;
	FILE* pArchivo;

	pArchivo= fopen(path,"w");

	if(pArchivo != NULL && pArrayListArticulo != NULL)
	{
		longitud = ll_len(pArrayListArticulo);
		fprintf(pArchivo,"id,articulo,medida,precio,rubroId\n");
		for(i=0;i<longitud;i++)
		{
			articulo = (eArticulo*)ll_get(pArrayListArticulo,i);
				if(articulo_getId(articulo,&bufferId)== 0 &&
				articulo_getArticulo(articulo,bufferArticulo)== 0 &&
				articulo_getPrecio(articulo,&bufferPrecio)== 0 &&
				articulo_getMedida(articulo,bufferMedida)== 0 &&
				articulo_getRubroId(articulo,&bufferRubroId)==0)
				{
					fprintf(pArchivo,"%d,%s,%s,%d,%d\n",bufferId,bufferArticulo,bufferMedida,bufferPrecio,bufferRubroId);
				}
		}
		retorno = 0;
	}
	fclose(pArchivo);
	return retorno;
}


int controller_informe(LinkedList* pArrayListArticulo)
{
	int retorno = -1;
	int cantPrecioMayor100;
	int cantRubroCuidadoDeRopa;

	if(pArrayListArticulo != NULL)
	{
		cantPrecioMayor100 = ll_count(pArrayListArticulo,controller_precioMasCien);
		cantRubroCuidadoDeRopa = ll_count(pArrayListArticulo,controller_cantCuidadoRopa);

		printf("\nCantidad de Artículos cuyo precio sea mayor a $100: %d\nCantidad de Artículos del Rubro 1 – CUIDADO DE ROPA: %d\n",cantPrecioMayor100,cantRubroCuidadoDeRopa);
		retorno = 0;
	}

	return retorno;
}
