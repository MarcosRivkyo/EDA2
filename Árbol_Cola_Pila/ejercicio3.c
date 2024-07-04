#include <stdio.h>
#include <string.h>
#include "arbol.h"
#include "genArbol.h"

int evaluar(Arbol);
int operacion(char, int, int);



int main(void)
{ Arbol arbol; 
  char ex_postfija[10];

/* Generación del árbol algebraico */
  strcpy(ex_postfija,"AB+CDE+**\0");


  arbol = genArbol(ex_postfija);


/* Recorrido en amplitud o por niveles */
   amplitud(arbol);
  printf("\n");
   
   

/* Aplicación de algunas operaciones y recorridos al árbol ejemplo */
	
  printf("Recorrido en PRE_ORDEN: ");
  preOrden(arbol);
  printf("\n");

  printf("Recorrido en ORDEN: ");
  enOrden(arbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN: ");
  postOrden(arbol);
  printf("\n");
  printf("Debe coinicidir con la expresión postfija inicial\n");

  printf("El árbol tiene %d nodos \n", numNodos(arbol));
  printf("y altura: %d\n",altura(arbol));

  arbol = anula(arbol);
  printf("Después de anula el arbol queda vacio, por tanto la altura será 0.\n");
  if (altura(arbol)!=-1)		// Cuidado con definición de altura
     printf("El árbol no se ha anulado correctamente\n");
  else
     printf("O.K. Parece que la operación anula funciona!!!\n");


/* Evaluación de un árbol algebraico: operandos entre '0' y '9'*/

  strcpy(ex_postfija,"23+713+**\0");
  arbol = genArbol(ex_postfija);
  printf("evalua: %d\n", evaluar(arbol));
  printf("Recorrido en PRE_ORDEN (prefija): ");
  preOrden(arbol);
  printf("\n");
  printf("Recorrido en ORDEN(infija): ");
  enOrden(arbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN(postfija): ");
  postOrden(arbol);
  printf("\n");

/* Aplicar a este arbol las funciones del ejercicio 2 */


	printf("Este arbol tiene %d nodos hoja", numNodosHoja(arbol));
  	printf("\n");
  	
  	printf("Este arbol tiene %d nodos internos", numNodosInternos(arbol));
  	printf("\n");
	
	printf("Este arbol tiene %d hijos unicos", numHijoUnico(arbol));
  	printf("\n");
  	
  	printf("Se esta sustituyendo los nodos, se han sustituido %d nodos", sustiuye(arbol, '7', '6'));
  	printf("\n");
  	printf("Recorrido sustituido: ");
  	amplitud(arbol);
  	printf("\n");

  printf("evalua: %d\n", evaluar(arbol));



  char preorden[10];
  char enorden[10];
  
  strcpy(preorden,"ABDECFG\0");
  strcpy(enorden,"DBEAFCG\0");


//reconstruir(preorden, enorden, 0);
	reconstruir(preorden, enorden);

/*	arbol = genArbol(reconstruido);
	
	   amplitud(arbol);
  printf("\n");

	
  return 1;*/
}





int operacion(char operador, int x, int y){
	
	switch(operador){
		
		case '+':
			return x+y;
		case '*':
			return x*y;			
		case '-':
			return x-y;					
		case '%':
			return x%y;		
		default:
			return 0;
	
}
}


int evaluar (Arbol a){
	
	int izq;
	int der;
	int resultado;
	
	
	if(a==NULL){									//PASO BASE
		return 0;	
	}
		
	if(a->izq==NULL && a->der==NULL){				//SI ES NODO HOJA
		resultado=a->info;
		return resultado-'0';		
	}
		
		izq=evaluar(a->izq);
		der=evaluar(a->der);

	return operacion(a->info, izq, der);
		
	}
	

int posicion (char raiz, char *enorden){
	
	int indice = 0;
    while (enorden[indice] != '\0')
    {
        char buscado = enorden[indice];
        if (buscado == raiz)
        {
            return indice;
        }
        indice++;
    }
    return -1;
	
}	


 

/*char* reconstruir (char *preorden, char *enorden, int x){
		
	char posorden[10]="";
	char izq[10]=".";
	char der[10]=".";
	char raices[10];
	
	int i=x;


	
if(strlen(izq)==0 && strlen(der)==0 ){

	return NULL;
}

else{
	
	char raiz=preorden[i];
	

	raices[0]=raiz;
	raices[1]='\0';

	int indice=posicion(raiz, enorden);

	printf("La cadena es: %s\n", preorden);
	printf("\n");
	printf("La cadena es: %s\n", enorden);
	printf("\n");
	printf("La posicion es: %d", indice);
	printf("\n");


    
	strncpy(izq, enorden, indice);
	strncpy(der, enorden+indice+1, strlen(enorden));


	strcat(posorden, izq);
	strcat(posorden, der);
	strcat(posorden, raices);
	
	
	printf("La cadena es: %s", izq);
	printf("\n");

	printf("La cadena es: %s", der);	
	printf("\n");
	printf("La cadena es: %s", posorden);
	printf("\n\n\n");
	
	strcpy(enorden, posorden);

	i++;

	reconstruir(preorden, posorden, i);



}

}*/


Arbol reconstruir(char *preorden, char *enorden){
	
	if(strlen(enorden)==0 || strlen(preorden)==0){
		return NULL;
	}
	
	else{
	
		char izquierda[10]="";
		char derecha[10]="";
		
		int x=0;
		
		char raiz=preorden[0];
		while (izquierda[x]!=raiz){
		
			strcat(izquierda,izquierda[x]);
			x=x+1;
		}
		
		strncpy(derecha, enorden+x, strlen(enorden));
		printf("%s  <-- %s -->  %s", izquierda, &raiz, derecha);
		
		char ok[10];
		char ok2[10];
		
		strncpy(ok, preorden, strlen(izquierda)+1);
		strncpy(ok2, preorden+strlen(izquierda), strlen(preorden));


		
        reconstruir(ok,izquierda);
        reconstruir(ok2,derecha)

	
	}
	
	
}














