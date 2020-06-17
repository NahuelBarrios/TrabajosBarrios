#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size=0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodo = NULL;
	int longitud;
	int i;
	longitud = ll_len(this);

	if(this != NULL && nodeIndex>=0 && nodeIndex < longitud)
	{
			pNodo = this->pFirstNode;
			for(i=0;i<nodeIndex;i++)
			{
				pNodo = pNodo->pNextNode;
			}
			return pNodo;
	}
	else
	{
		return NULL;
	}

}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int longitud;
    Node* pNodo = NULL;
    Node* pNodoAux = NULL;

    longitud = ll_len(this); // pido la longitud del linkedlist

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= longitud)
    {
    	pNodo = (Node*)malloc(sizeof(Node)); // pido espacio de memoria

    	if(pNodo != NULL)
    	{
    		pNodo->pElement = pElement; // guardo el elemento en el nuevo

    		if(nodeIndex == 0) // si es igual a 0
    		{
    			pNodo->pNextNode = this->pFirstNode; //el nodo campo NextNodo le guardo el valor del firsNode osea NULL
    			this->pFirstNode = pNodo; // y en el pFirstNode guardo pNodo
    			this->size++; // aumento en 1 el size
    			returnAux = 0;
    		}
    		else
    		{
    			pNodoAux = getNode(this,nodeIndex-1); // obtengo el nodo de la lista
    			if(pNodoAux != NULL)
    			{
    				pNodo->pNextNode = pNodoAux->pNextNode; // guardo el valor de null al siguiente nodo
    				pNodoAux->pNextNode = pNodo; // guardo el pNodo a next Node del anterior
    				this->size++; // sumo en 1 el size
    				returnAux = 0; // salio todoOk
    			}
    		}
    	}

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int longitud;

    if(this != NULL)
    {
    	longitud = ll_len(this);
    	addNode(this,longitud,pElement);
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodo;

    if(this != NULL && index >=0)
    {
    	pNodo = getNode(this,index);
    	if(pNodo != NULL)
		{
    		returnAux = pNodo->pElement;
		}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int longitud;
    Node* pNodo = NULL;

    longitud = ll_len(this);

    if(this != NULL && index>=0 && index<=longitud)
    {
    	pNodo = getNode(this,index);
    	if(pNodo != NULL)
    	{
    		pNodo->pElement = pElement;
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int longitud;
    Node* pNodo = NULL;
    Node* pNodoRemove = NULL;

    longitud = ll_len(this);

    if(this != NULL && index >=0 && index < longitud) // NO PONERLE <= PELOTUDOOOOOOOOOOOOOOOOOOO es ksi igual al add
    {
    	pNodo = getNode(this,index);

    	if(index == 0)
    	{
    		this->pFirstNode = pNodo->pNextNode;
    		this->size--;
    	}
    	else
    	{
    		pNodoRemove = getNode(this,index-1);
    		pNodoRemove->pNextNode = pNodo->pNextNode;
    		this->size--;
    	}
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int longitud;
    Node* pNodo = NULL;

    longitud = ll_len(this);
    if(this != NULL)
    {
    	if(longitud>=0)
    	{
    		while(longitud>=0)
    		{
    			pNodo = ll_get(this,longitud);
    			ll_remove(this,longitud);
    			free(pNodo);
    			longitud--;
    		}
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int longitud;
    int i;
    Node* pNodo = NULL;

    longitud = ll_len(this);
    if(this != NULL)
    {
    	for(i = 0;i < longitud;i++)
    	{
    		pNodo = getNode(this,i);

    		if(pNodo != NULL)
    		{
    			if(pNodo->pElement == pElement)
    			{
    				returnAux = i;
    				break;
    			}
    		}
    	}

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1; // ES NULL
    int longitud;

    longitud = ll_len(this);
    if(this != NULL)
    {
    	if(longitud != 0)
    	{
    		returnAux = 0; // NO vacia
    	}
    	else
    	{
    		returnAux = 1;// Vacia
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int longitud;

    longitud = ll_len(this);
    if(this != NULL && index >= 0 && index <= longitud)
    {
    	if(addNode(this,index,pElement) == 0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int longitud;
    Node* pNodo = NULL;
    Node* pNodoAuxPrev = NULL;

    longitud = ll_len(this);

    if(this != NULL && index>=0 && index<longitud)
    {
    	pNodo = getNode(this,index);

    	if(pNodo != NULL)
    	{
    		if(index == 0)
    		{
    			returnAux = pNodo->pElement;
    			this->pFirstNode = pNodo->pNextNode;
    			this->size--;
    		}
    		else
    		{
    			returnAux = pNodo->pElement;
    			pNodoAuxPrev = getNode(this,index-1);
    			pNodoAuxPrev->pNextNode = pNodo->pNextNode;
    			this->size--;
    		}
    	}

    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_indexOf(this,pElement) != -1)
    	{
    		returnAux = 1; // Si contiene
    	}
    	else
    	{
    		returnAux = 0; // No contiene
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int longitudThis2;

    if(this != NULL && this2 != NULL)
    {
    	longitudThis2 = ll_len(this2);

        if(longitudThis2 == 0)
        {
        	returnAux = 0;
        }
        for(i=0;i<longitudThis2;i++)
        {
        	if(ll_contains(this,ll_get(this2,i))==1)
        	{
        		returnAux = 1;
        	}
        	else
        	{
        		returnAux = 0;
        		break;
        	}
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pNodeAux = NULL;
    int longitud;
    int i;

    longitud= ll_len(this);
    if(this != NULL && from >= 0 && from <= longitud && to > from && to <= longitud)
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for(i=from;i<to;i++)
    		{
    			pNodeAux = ll_get(this,i);
    			if(pNodeAux != NULL)
    			{
    				ll_add(cloneArray,pNodeAux);
    			}
    		}
    	}

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int longitud;

    if(this != NULL)
    {
    	longitud = ll_len(this);

    	cloneArray = ll_subList(this,0,longitud);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}
