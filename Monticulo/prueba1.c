#include <stdlib.h>
#include <stdio.h>
#include "monticulo.h"
int main(void)
{ Monticulo m;// Monticulo *m (Habria que reservar con un malloc y quitar los & de las llamadas;
  tipoElemento elemento;
  int error,i,n=10;

 iniciaMonticulo(&m);
 elemento.clave=12;
 elemento.informacion=0;

 i=insertar(elemento,&m);

 while (m.tamanno<n)
  { elemento.clave=rand()%100;
    i = insertar(elemento,&m);
  }

 for (i=1;i<=m.tamanno;i++)
   printf("%d ",m.elemento[i].clave);
 printf("\n");

 decrementarClave(6,90,&m);
 for (i=1;i<=m.tamanno;i++)
    printf("%d ",m.elemento[i].clave);
    printf("\n");
    
    for(i=0;i<=n;i++){
    	error=eliminarMinimo(&m, &elemento);
    	if(!error)
    		printf("%d  ", elemento.clave);
    	else
    		printf("Monticulo vacio\n");
	}
}




