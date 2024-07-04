#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"
#include "arbol.h"


int 
colaCreaVacia(Cola *c)
{
    c->fondo = NULL;
    c->frente = NULL;
    
    return 0;
    
}

int 
colaVacia(Cola *c)
{
    if(c->fondo == NULL && c->frente == NULL){
    	return -1;	
	}
    
    return 0;		
    
}

int 
colaInserta(Cola *c,tipoElemento elemento)
{
	tipoCelda *nueva = malloc(sizeof(tipoCelda));
	
	if(nueva == NULL){
		return -1;
	}

	
	nueva->elemento = elemento;
	
	nueva->sig = NULL;
	
	if(colaVacia(c)){
		c->frente = nueva;
		c->fondo = nueva;
	}
	else{
		(c->fondo)->sig = nueva;
		c->fondo = nueva; 
	}
		return 0; 
}

tipoElemento 
colaSuprime(Cola *c)
{	
      tipoElemento elemento;
	  tipoCelda *aBorrar = c->frente;

	if(colaVacia(c))
		exit(-1);					
	
	
	elemento = (c->frente)->elemento;

	if(c->frente == c->fondo){
		c->fondo = NULL;
		free(c->frente);
		c->frente = NULL;
	
	}
	else{
		c->frente = aBorrar->sig;
		free(aBorrar);
		aBorrar = NULL;	
	}	
	
	return elemento;
    
}
