#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolBB.h"


#ifdef EJERCICIO1
/******************************************************************
* Crboles Binarios de BCrsqueda SIN CLAVES REPETIDAS
* Se incluye un poco de cC³digo para mostrar la diferencia entre   *
* insertar (paso por referencia) y buscar                         * 
*******************************************************************/


int insertar(tipoArbolBB *raiz,tipoClave clave){   
  	if(*raiz==NULL){
  		*raiz = creaNodo(clave, 1);
  		
  		if(*raiz==NULL)	return -1;
  		
  		return 0;
  	} else if((*raiz)->clave == clave){
  		(*raiz)->info += 1;
  		return 0;
  	} else if((*raiz)->clave > clave){
  		return insertar(&(*raiz)->izq, clave);
  	} else if((*raiz)->clave < clave){
		return insertar(&(*raiz)->der, clave);
    }
}




int buscar(tipoClave clave,tipoArbolBB raiz, tipoNodo **nodo){
	if(raiz==NULL){
		*nodo = NULL;
		return 0;
  	} else if(raiz->clave > clave){
  		return buscar(clave, raiz->izq, nodo);
    } else if(raiz->clave < clave){
 		return buscar(clave, raiz->der, nodo);	
	} 
	else{
		*nodo = raiz;
		return raiz->info;
	}
	
}

#endif

#ifdef EJERCICIO3
/******************************************************
* Crboles Binarios de BCrsqueda CON CLAVES REPETIDAS   *
******************************************************/
int insertar(tipoArbolBB *raiz,tipoClave clave, tipoInfo info)
{ 
	tipoNodo *nuevo;

	if(*raiz==NULL){
		*raiz = creaNodo(clave, info);
		return -1;
	} 
	
	else if((*raiz)->clave == clave){
		nuevo = creaNodo(clave, info);
		if((*raiz)->izq != NULL) nuevo->izq = (*raiz)->izq;
		(*raiz)->izq = nuevo;
		return 0;
	} else if((*raiz)->clave > clave) 
			return insertar(&(*raiz)->izq, clave, info);
	  else if((*raiz)->clave < clave)
	  		return insertar(&(*raiz)->der, clave, info);
			  	
}

int eliminar(tipoArbolBB *raiz, tipoClave clave){
	tipoNodo *aBorrar, *aux, *anterior;
	int nNodos;

	if(NULL == (*raiz)) return 0;	//No existe nodo con clave x
    else if((*raiz)->clave > clave) return eliminar(&(*raiz)->izq,clave);
   	else if((*raiz)->clave < clave) return eliminar(&(*raiz)->der,clave);
    else {
		if((*raiz)->izq == NULL && (*raiz)->der == NULL){
			free(*raiz);
			*raiz = NULL;
		} else if((*raiz)->izq == NULL)
			aBorrar = *raiz;
			(*raiz) = (*raiz)->der;
			free(aBorrar);
		} else if((*raiz)->der == NULL){
			aBorrar = *raiz;
			(*raiz) = (*raiz)->izq;
			free(aBorrar);
		} else {
			anterior = (*raiz);
			aux = anterior->izq;
			while(NULL != aux->der){
				anterior = aux;
				aux = aux->der;
			}

			(*raiz)->clave = aux->clave;
			strcpy((*raiz)->info, aux->info);

			if(*raiz == anterior) anterior->izq = aux->izq;
			else anterior->der = aux->izq;

			free(aux);
  		}
	return 1 + eliminar(raiz, clave);
  	}
}

#endif
/*****************************************************************************************
* Funciones GENERALES adaptadas a los dos ejercicios mediante DIRECTIVAS DE COMPILACIC“N  *
/*****************************************************************************************/
tipoNodo *creaNodo(tipoClave clave, tipoInfo info)
{ tipoNodo * nuevo;
  
  //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));
  if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL)
	return NULL;
  else 
  {	nuevo->clave = clave;
  	#ifdef EJERCICIO1
	nuevo->info=info;
  	#endif
  	#ifdef EJERCICIO3
	strcpy(nuevo->info,info);
  	#endif
  	nuevo->izq=NULL;
  	nuevo->der=NULL;
  return nuevo;
  }
}

void preOrden(tipoArbolBB a)
{ if (a) { 
  	#ifdef EJERCICIO1
	printf("%d %d \n", a->clave,a->info);
	#endif
  	#ifdef EJERCICIO3
	printf("%d %s \n", a->clave,a->info);
  	#endif
  	preOrden(a->izq);
  	preOrden(a->der);
  }
} 

void enOrden(tipoArbolBB a)
{ if (a) { 
	enOrden(a->izq);
   	#ifdef EJERCICIO1
	printf("%d %d \n", a->clave,a->info);
   	#endif
   	#ifdef EJERCICIO3
	printf("%d %s \n", a->clave,a->info);
   	#endif
    	enOrden(a->der);
  }
} 

void posOrden(tipoArbolBB a)
{ if (a) {
  	enOrden(a->izq);
  	enOrden(a->der);
   	#ifdef EJERCICIO1
	printf("%d %d \n", a->clave,a->info);
   	#endif
   	#ifdef EJERCICIO3
	printf("%d %s \n", a->clave,a->info);
   	#endif
  }
} 

