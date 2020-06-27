/*
 * parser.c
 *
 *  Created on: 24 jun. 2020
 *      Author: Nahu_
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "articulo.h"
#include "controller.h"
#include "parser.h"

int parser_loadData(FILE* pFile , LinkedList* pArrayListArticulo)
{
	int retorno = -1;
	eArticulo* pPelicula;
	char id[51];
	char articulo[51];
	char precio[51];
	char medida[51];
	char rubroId[51];
	int cant;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,articulo,medida,precio,rubroId);

	while(!feof(pFile))
	{
		cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,articulo,medida,precio,rubroId);

		if(cant == 5)
		{
			pPelicula = articulo_newParametros(id,articulo,medida,precio,rubroId);
			if(pPelicula != NULL)
			{
				ll_add(pArrayListArticulo,pPelicula);
				retorno = 0;
			}
			else
			{
				printf("\nNo se pudo cargar los datos\n");
				break;
			}
		}
		else
		{
			printf("\nNo se pudo leer los datos correctamente\n");
			break;
		}
	}

	return retorno;
}
