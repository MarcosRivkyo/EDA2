#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

int main(void)
{ Arbol varArbol;
  Arbol varArbol2;

/* Creación arbol ejemplo de las transparencias de recorridos */
  varArbol = creaNodo('A');
  varArbol->izq=creaNodo('B');
  varArbol->der = creaNodo('C');
  varArbol->izq->izq=creaNodo('D');
  varArbol->izq->der=creaNodo('E');
  varArbol->der->izq=creaNodo('F');
  varArbol->der->der=creaNodo('G');
  
  
  varArbol2 = creaNodo('A');
  varArbol2->izq=creaNodo('B');
  varArbol2->der = creaNodo('C');
  varArbol2->izq->izq=creaNodo('D');
  varArbol2->izq->der=creaNodo('E');
  varArbol2->der->izq=creaNodo('F');
  varArbol2->der->der=creaNodo('G');

/* Aplicación de recorridos al arbol ejemplo */

  printf("Recorrido en PRE_ORDEN: ");
  preOrden(varArbol);
  printf("\n");
  printf("Recorrido en ORDEN: ");
  enOrden(varArbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN: ");
  postOrden(varArbol);
  printf("\n");
  printf("Recorrido en AMPLITUD: ");
  amplitud(varArbol);
  printf("\n\n\n");

/* Comenzar a implementar y probar las funciones del ejercicio 2 ... y segunda parte del ejercicio 3 */

	printf("Este arbol tiene %d nodos", numNodos(varArbol));
	printf("\n");
	
	printf("La altura del arbol es %d", altura(varArbol));
	printf("\n");
	
  	
	printf("Este arbol tiene %d nodos hoja", numNodosHoja(varArbol));
  	printf("\n");
  	
  	printf("Este arbol tiene %d nodos internos", numNodosInternos(varArbol));
  	printf("\n");
	
	printf("Este arbol tiene %d hijos unicos", numHijoUnico(varArbol));
  	printf("\n");
  	
  	printf("Se esta sustituyendo los nodos, se han sustituido %d nodos", sustiuye(varArbol, 'F', 'A'));
  	printf("\n");
  	
 	printf("Recorrido sustituido: ");
  	amplitud(varArbol);
  	printf("\n");
  	
  	printf("Los 2 arboles son similares: %d", similares(varArbol, varArbol2));
  	printf("\n");

  	printf("Los 2 arboles son equivalentes: %d", equivalentes(varArbol, varArbol2));
  	printf("\n");
	    	
	printf("Recorrido del arbol VACIO: ");
	varArbol =anula(varArbol);
  	preOrden(varArbol);
  	printf("\n");

  return 1;
}

