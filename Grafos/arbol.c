#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "cola.h"


//
// Reserva de memoria para un nuevo nodo de árbol binario
//
Arbol creaNodo(tipoInfo info)
{ tipoNodo * nuevo;

  //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));			
  if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL)       
	return NULL;
  else
  { 	nuevo->info=info;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	return nuevo;
   }
}

//
// Recorrido en amplitud o por niveles: necesita una cola de punteros a nodos de árbol binario!!!
//

void amplitud(Arbol raiz)
{ Cola c;
  tipoNodo *nodo;
  colaCreaVacia(&c);
  nodo = raiz;
  if (raiz!=NULL) colaInserta(&c,nodo);
  while (!colaVacia(&c))
  { nodo = (Arbol) colaSuprime(&c);
    printf(" %c ", nodo->info);
    if (nodo->izq!=NULL) colaInserta(&c,nodo->izq);
    if (nodo->der!=NULL) colaInserta(&c,nodo->der);
  }
}
// 
// Recorridos en profundidad "recursivos"
//
void preOrden(Arbol raiz)
{ if (raiz!=NULL)
  { printf("%c ",raiz->info);
    preOrden(raiz->izq);
    preOrden(raiz->der);
  }
}
void enOrden(Arbol raiz)
{ if (raiz!=NULL)
  { enOrden(raiz->izq);
    printf("%c ",raiz->info);
    enOrden(raiz->der);
  }
}
void postOrden(Arbol raiz)
{ if (raiz!=NULL)
  { postOrden(raiz->izq);
    postOrden(raiz->der);
    printf("%c ",raiz->info);
  }
}

int altura(Arbol raiz){
	
	int altIzq, altDer;
	
	if(raiz==NULL){ //CASO BASE

		return -1;
	
	}else{

		altIzq = altura(raiz->izq);
		altDer = altura(raiz->der);
		
		if(altIzq>=altDer)
			return 1+altIzq;
		else 
			return 1+altDer;
			

	}
	
	
}


int numNodos(Arbol raiz){
	
	int numIzq, numDer;
	
	if(raiz==NULL)   //CASO BASE
		return 0;
	else{		     //CASO GENERAL
		numIzq = numNodos(raiz->izq);		//Estrategia POST-ORDEN
		numDer = numNodos(raiz->der);
		
		return 1+numIzq+numDer;
		
	}
	
	
}



/*Arbol anula(Arbol raiz){
		
	if(raiz==NULL)   //CASO BASE
		return NULL;
	else{		     //CASO GENERAL
		anula(raiz->izq);		//Estrategia POST-ORDEN
		anula(raiz->der);
		
		free(raiz);
		
		return NULL;
	}
	
}*/


Arbol anula(Arbol raiz){
		
	if(raiz!=NULL){
		
		anula(raiz->izq);		//Estrategia POST-ORDEN
		anula(raiz->der);
		
		free(raiz);
		
		return NULL;
	}
	
}



int numNodosHoja(Arbol raiz){
	
	int hojasIzq, hojasDer;
	
	if(raiz==NULL)	     //CASO GENERAL
			return 0;
	else{
			hojasIzq = numNodosHoja(raiz->izq);		//Estrategia POST-ORDEN
			hojasDer = numNodosHoja(raiz->der);
		
			if(raiz->izq==NULL && raiz->der==NULL)
				return 1+hojasIzq+hojasDer;
			else
				return hojasIzq+hojasDer;	
	}
}

int numNodosInternos(Arbol raiz){
	
	int internIzq, internDer;
	
	if(raiz==NULL)	     //CASO BASE
			return 0;
	else{
			internIzq = numNodosInternos(raiz->izq);		//Estrategia POST-ORDEN
			internDer = numNodosInternos(raiz->der);
		
			if((raiz->izq!=NULL || raiz->der!=NULL))
				return 1+internIzq+internDer;
			else
				return internIzq+internDer;	
	}
}
	
	
int numHijoUnico(Arbol raiz){
	
	int hijosIzq, hijosDer;
	
	if(raiz==NULL)	     //CASO BASE
			return 0;
	else{
			hijosIzq = numNodosInternos(raiz->izq);		//Estrategia POST-ORDEN
			hijosDer = numNodosInternos(raiz->der);
		
			if((raiz->izq!=NULL && raiz->der==NULL)||(raiz->izq==NULL && raiz->der!=NULL))
				return 1+hijosIzq+hijosDer;
			else
				return hijosIzq+hijosDer;	
	}
	
	
	
	
	
}

int sustiuye(Arbol raiz, tipoInfo x, tipoInfo y){
	
	int numNodosIzq, numNodosDer;
	
  if (raiz==NULL)
  		return 0;  	
  else{ 
  
    numNodosIzq=sustiuye(raiz->izq, x, y);

    numNodosDer=sustiuye(raiz->der, x, y);
    if(raiz->info==x){
    	
    	raiz->info=y;
    	
    	return 1+numNodosDer+numNodosIzq;
	}else
		return numNodosDer+numNodosIzq;
    
  }
	
	
	
}

/*
Arbol buscarMax(Arbol raiz){

	int izq;
	int der;
	int resultado;
	int* min=izq;
	
	if(a==NULL){									//PASO BASE
		return 0;	
	}
		
	if(a->izq==NULL && a->der==NULL){				//SI ES NODO HOJA
		resultado=a->info;
		return resultado-'0';		
	}
		
		izq=evaluar(a->izq);
		der=evaluar(a->der);
		
		if(izq>der){
			min=der;
		}

	return min;
}



/*Arbol buscarMin(Arbol raiz){
	
	
	
}*/


int similares(Arbol r1,Arbol r2){
	
	if(r1==NULL || r2==NULL)
		return 0;
	else{
		if((altura(r1)==altura(r2))&&(numNodos(r1)==numNodos(r2))&&(numNodosHoja(r1)==numNodosHoja(r2))){
			
			return 1;
			
		}else 
			return 0;
			
	}

}


int equivalentes(Arbol r1,Arbol r2){
	
	
	int numNodosIzq, numNodosDer;
	
	if(r1==NULL || r2==NULL)
		return 0;
	else{
		if((altura(r1)==altura(r2))&&(numNodos(r1)==numNodos(r2))&&(numNodosHoja(r1)==numNodosHoja(r2))){
			
			  
    		numNodosIzq=equivalentes(r1->izq,r2->izq);
				
    		numNodosDer=equivalentes(r1->der,r2->izq);
    		
			if(r1->info==r2->info){
				return 1;    	    	
			}else
				return 0;

	
			
		}else 
			return 0;
			
	}

}



Arbol especular(Arbol raiz){
	
	
	
  if (raiz==NULL)
  		return 0;  	
  else{ 
  
    especular(raiz->izq);

    especular(raiz->der);

	creaNodo(raiz->info);
	
  }
	
	
	
	
}














