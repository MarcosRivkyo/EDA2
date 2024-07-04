/*
 * grafos.c
 *
 *  Created on: 21/04/2014
 *      Author: MJ Polo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cola.h"
#include "grafos.h"

/**********************************************
/ Inicia correctamente directorio de vertices *
***********************************************/
void iniciar(tipoGrafo *g)
{
	int i;
	pArco p;

	for(i=1;i<=g->orden;i++){
		
		g->directorio[i].alcanzado=0;
		g->directorio[i].gradoEntrada=0;
		g->directorio[i].ordenTop=0;
		g->directorio[i].distancia=INF;
		g->directorio[i].peso=INF;		
		g->directorio[i].anterior=0;

	}
	
	
	for(i=0;i<g->orden;i++){
		
		
		p=g->directorio[i].lista;
		while(p!=NULL){
			g->directorio[p->v].gradoEntrada++;
			p=p->sig;
		}	
	}	
}



void profundidadMejorado(int v_inicio,tipoGrafo *g)
{
	int i;
	
	iniciar(g);
	
	profundidad(v_inicio,g);
	
	
	for(i=1;i<=g->orden;i++){
	
	if(!(g->directorio[i].alcanzado)){
			profundidad(i,g);

	}
	
	}	
}


void amplitudMejorado(int v_inicio,tipoGrafo *g)
{
	int i;
	
	iniciar(g);
		
	amplitud(v_inicio,g);
	
	
	for(i=1;i<=g->orden;i++){
	
	if(!(g->directorio[i].alcanzado)){
			profundidad(i,g);

	}
}
	
	
	
}



/* Ejercicio 2*/

int ordenTop1(tipoGrafo *grafo)
{
	int i, j;
	int orden;
	pArco p;
	
	iniciar(grafo);
	
	orden=1;
	
	for(i=1;i<=grafo->orden;i++){
		
		j=1;
		while(j<=grafo->orden && !(grafo->directorio[i].ordenTop && grafo->directorio[i].gradoEntrada==0)){
				j++;
		}
		
		if(j==grafo->orden)
			return -1;
			
		grafo->directorio[j].ordenTop=orden++;
		p=grafo->directorio[i].lista;
		
		while(p!=NULL){
			grafo->directorio[p->v].gradoEntrada--;
			p=p->sig;
			
		}
		
	}

	return 0;
}



int ordenTop2(tipoGrafo *grafo)
{
	int i, v;
	int orden;
	pArco p;
	Cola c;
	
	iniciar(grafo);
	
	colaCreaVacia(&c);
	
	for(i=1;i<=grafo->orden;i++){
		if(grafo->directorio[i].gradoEntrada==0)
			colaInserta(&c, i);
			
	}
	
	orden = 1;
	
	while(!colaVacia(&c)){
		v=colaSuprime(&c);
		grafo->directorio[v].ordenTop=orden++;
		p=grafo->directorio[v].lista;
		
		while(p!=NULL){
			grafo->directorio[p->v].gradoEntrada--;
			if(grafo->directorio[p->v].gradoEntrada==0)
				colaInserta(&c, p->v);
			
			p=p->sig;
		}
		
		
		
	}
	
	if(orden>=grafo->orden)
		return 0;
	
	else 
		return -1;
	
	
}


/******************************************************************************/
/* Recorrido en PROFUNDIDAD de un grafo. ¡CUIDADO! Depende del vertice inicial y del tipo de grafo */
/*********************************************************************************/
void profundidad(int v_inicio,tipoGrafo * grafo)
{ int w;
  pArco  p;
  printf("%d ",v_inicio);
  grafo->directorio[v_inicio].alcanzado=1;
  p = grafo->directorio[v_inicio].lista;
  while (p!=NULL)
  { w=p->v;
    if (!grafo->directorio[w].alcanzado)
        profundidad(w,grafo);
    p = p->sig;
  }
}
/************************************************************************************************/
/* Recorrido en AMPLITUD de un grafo. ¡CUIDADO! Depende del vertice inicial y del tipo de grafo */
/************************************************************************************************/
void amplitud(int v_inicio,tipoGrafo *grafo)
{ int w;
  pArco  p;
  Cola c;

  colaCreaVacia(&c);
  colaInserta(&c,v_inicio);
  while (!colaVacia(&c))  {
	w =colaSuprime(&c);
        if (!grafo->directorio[w].alcanzado) {
		printf("%d ",w);
	        grafo->directorio[w].alcanzado=1;
        	p =grafo->directorio[w].lista;
 		while (p!=NULL){
			w = p->v;
			colaInserta(&c,w);
			p = p->sig;
		}
	}
  }
	  
}

tipoGrafo * prim1(tipoGrafo *grafo){
	
int w;


	
	
	
}

/*
void dijkstra2(int vInicio, tipoGrafo *g){
    int v;
    Monticulo m;
    tipoElementoMonticulo e = {0,0};
    pArco p;
    
    iniciar(g);
    iniciaMonticulo(&m);

    g->directorio[vInicio].distancia = 0;
    g->directorio[vInicio].anterior = 0;

    e.clave = 0;
    e.informacion = vInicio;
    insertar(e,&m);

    while(!vacioMonticulo(m)){
        eliminarMinimo(&m,&e);
        v = e.informacion;

        g->directorio[v].alcanzado = 1;

        p = g->directorio[v].lista;
        while(NULL != p){
            if(g->directorio[p->v].alcanzado == 0 && g->directorio[p->v].distancia > g->directorio[v].distancia + p->peso){
                g->directorio[p->v].anterior = v;
                g->directorio[p->v].distancia = g->directorio[v].distancia + p->peso;
                    e.informacion = p->v;
                    e.clave = g->directorio[p->v].distancia;
                insertar(e,&m);
            }
            p = p->sig;
        }
    }
}

*/

/**********************************************************************************************/
/* Función auxiliar para ver el contenido de la estructura que representa un grafo en memoria */
/**********************************************************************************************/
void verGrafo(tipoGrafo *g)
{  int i;
   pArco p;

   printf("\nGrafo  (Orden %d)\n\n",g->orden);
   printf("       alc gEnt oTop dist peso ant \n");
   printf("     +----+----+----+----+----+----+\n");

   for(i=1;i<=g->orden;i++)
   {  printf("  %2d | %2d | %2d | %2d |", i, g->directorio[i].alcanzado,
                       g->directorio[i].gradoEntrada, g->directorio[i].ordenTop);
       if (g->directorio[i].distancia == INF) printf("  * |");
       else   printf(" %2d |", g->directorio[i].distancia);
       if (g->directorio[i].peso == INF) printf("  * |");
       else   printf(" %2d |", g->directorio[i].peso);
       printf(" %2d |",g->directorio[i].anterior);
       p = g->directorio[i].lista;
       while (p != NULL)
       {   printf(" ->%2d", p->v);	// Grafos no ponderados
           //printf(" ->%2d, %2d", p->v, p->peso); // Grafos ponderados
           p = p->sig;
       }
       printf("\n");
   }
   printf("     +----+----+----+----+----+----+\n\n");
}