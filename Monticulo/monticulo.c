#define MAX 20

#include <stdio.h>
#include <stdlib.h>
#include "monticulo.h"


int vacioMonticulo(Monticulo m){
	
	if(m.tamanno==0)
		return 1;
	else 
		return 0;
	
}


void iniciaMonticulo(Monticulo *m){
	
	m->tamanno=0;	
	
	
}

/*
int insertar(tipoElemento x, Monticulo *m){
	
	int hueco;
	
	if(m.tamanno>=MAX)//Monticulo lleno
		return -1;
	
	else{
		
		m.tamanno=m.tamanno+1;
		hueco=m.tamanno;
		
			while(m.elementos[hueco/2].clave>x.clave){
			
				m.elementos[hueco]=m.elementos[hueco/2];
			
			}
			
		m.elementos[hueco]=x;

		return 0;

	}
	
}*/


void decrementarClave(int pos, tipoClave cantidad, Monticulo *m){
	
	if(pos==0 || m->tamanno==0){
		
		return;
		
	}
	else{
		
		m->elemento[pos].clave=m->elemento[pos].clave-cantidad;
		filtradoAscendente(m, pos);
		
	}
	
	
	
}


void incrementarClave(int pos, tipoClave cantidad, Monticulo *m){
	
	
	if(pos==0 || m->tamanno==0){
		
		return;
		
	}
	else{
		
		m->elemento[pos].clave=m->elemento[pos].clave+cantidad;
		
		
	}
	
	
}






int insertar(tipoElemento x, Monticulo *m){
	
	int hueco;
	
	if(m->tamanno>=MAX)//Monticulo lleno
		return -1;
	
	else{
	
	m->tamanno++;
	m->elemento[m->tamanno]=x;
	filtradoAscendente(m,m->tamanno);
	return 0;
	
	}
}


/*int eliminarMinimo(Monticulo *m, tipoElemento *minimo){

	int i, hijo;
	int hueco, min;
	tipoElemento ultimo;
	int flag;
	
	if(m->tamanno==0)//Monticulo vacio
		return -1;	
	
	else{
		
		minimo=&(m->elemento[1]);
		ultimo=m->elemento[m->tamanno];
		
		m->tamanno=m->tamanno-1;
		hueco=1;
		flag=0;
		
		while(2*hueco<=m->tamanno && !flag){
			
			hijo=2*hueco;
			
			if(hijo!=m->tamanno){
				if(m->elemento[hijo+1].clave<m->elemento[hijo].clave){
					
					hijo=hijo+1;
					
				}
			}
			
			if(m->elemento[hijo].clave<ultimo.clave){
				
				m->elemento[hueco]=m->elemento[hijo];
				hueco=hijo;
			}
			
			flag=1;
			
		}
		
		m->elemento[hueco]=ultimo;
		

		
	}
	
	
	
	
	
	
}*/


int eliminarMinimo(Monticulo *m, tipoElemento *minimo){


if(!vacioMonticulo(*m)){
	
		*minimo=m->elemento[1];
		m->elemento[1]=m->elemento[m->tamanno];
		m->tamanno--;
		filtradoDescendente(m,1);
		return 0;
	
}
else{
	return -1;
}

}
	



void filtradoAscendente(Monticulo *m, int i){
	
	int padre;
	tipoElemento temp;
	
	while((i!=1) && (m->elemento[i].clave < m->elemento[i/2].clave)){
		
		
		temp=m->elemento[i];
		m->elemento[i]=m->elemento[i/2];
		m->elemento[i/2]=temp;
		i=i/2;
	}
	
	
}

void filtradoDescendente(Monticulo *m, int i){
	
	int padre;
	tipoElemento temp;
	
	while((i!=m->tamanno) && (m->elemento[i].clave > m->elemento[2*i].clave)){
		
		
		temp=m->elemento[i];
		m->elemento[i]=m->elemento[2*i];
		m->elemento[2*i]=temp;
		i=2*i;
	}
	
	
}



void crearMonticulo(Monticulo *m){
	
	int i, n;
	
	n=m->tamanno;
	
	for(i=n/2;i>=1;i--){
		filtradoDescendente(m,i);
	}	
	
}


















