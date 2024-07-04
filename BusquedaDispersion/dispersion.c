#include "dispersion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Crea un fichero hash inicialmente vacio seg�n los criterios especificados en la pr�ctica
// Primera tarea a realizar para  crear un fichero organizado mediante DISPERSI�N
void creaHvacio(char *fichHash)
{ FILE *fHash;
  tipoCubo cubo;
  int j;
  int numCubos =CUBOS+CUBOSDESBORDE;

  memset(&cubo,0,sizeof(cubo));

  fHash = fopen(fichHash,"wb");
  for (j=0;j<numCubos;j++) fwrite(&cubo,sizeof(cubo),1,fHash);
  fclose(fHash);
  
}
// Lee el contenido del fichero hash organizado mediante el m�todo de DISPERSI�N seg�n los criterios
// especificados en la pr�ctica. Se leen todos los cubos completos tengan registros asignados o no. La
// salida que produce esta funci�n permite visualizar el m�todo de DISPERSI�N

int leeHash(char *fichHash)
{ FILE *f;
  tipoCubo cubo;
  int j,i=0;
  size_t numLee;

   f = fopen(fichHash,"rb");
   rewind(f);
   fread(&cubo,sizeof(cubo),1,f);
   while (!feof(f)){
	for (j=0;j<C;j++) {
        if (j==0)    	printf("Cubo %2d (%2d reg. ASIGNADOS)",i,cubo.numRegAsignados);
        else  	printf("\t\t\t");
	if (j < cubo.numRegAsignados) 
		    printf("\t%s %s %s %s %s\n",
	    		cubo.reg[j].dni,
			cubo.reg[j].nombre,
			cubo.reg[j].ape1,
		  	cubo.reg[j].ape2,
  	                cubo.reg[j].provincia);
	else printf ("\n");
        }
       i++;
       fread(&cubo,sizeof(cubo),1,f);
   }
   fclose(f);
   return i;
}

/*
int creaHash(char *fichEntrada,char *fichHash){
	
	FILE *fHash, *fEnt;
	tipoAlumno regA;
	tipoCubo cubo;
	int numCubo, numDesb = 0;

	
	creaHvacio(fichHash);

	if(NULL == (fHash = fopen(fichHash, "rb"))) return -2;
	if(NULL == (fEnt = fopen(fichEntrada, "rb"))) return -2;

	
	while(fread(&regA, sizeof(tipoAlumno), 1, fEnt)){
		
		
		numCubo = atoi(regA.dni)%CUBOS;
		
		fseek(fHash, numCubo*sizeof(tipoCubo), SEEK_SET);
		fread(&cubo, sizeof(tipoCubo), 1, fHash);
		
		if(cubo.numRegAsignados < C){
			cubo.reg[cubo.numRegAsignados] = regA;
		}else{
			numDesb++;
		
			if(desborde(fHash, &regA))	printf("Registro no almacenado\n\n");
				
			cubo.numRegAsignados++;
			fseek(fHash, numCubo*sizeof(tipoCubo), SEEK_SET);
			fwrite(&cubo, sizeof(tipoCubo), 1, fHash);
		
		fread(&regA, sizeof(tipoAlumno), 1, fEnt);

		}
	fclose(fEnt);
	fclose(fHash);
	return numDesb;
}

}

*/


int creaHash(char *fichEntrada,char *fichHash) {
	
	FILE *fEnt, *fHash;
	tipoAlumno regA;
	tipoCubo cubo;
	int numDesb = 0;
	int retorno;
	
	
	if((fEnt=fopen(fichEntrada, "rb")) == NULL)
			return -1;
	
	creaHvacio(fichHash);
	
	
	if((fHash=fopen(fichHash, "r+b")) == NULL){
		fclose(fEnt);
		return -1;
	}
	
	numDesb = 0;
	
	fread(&regA, sizeof(tipoAlumno), 1, fEnt);
	while(!feof(fEnt)){

		retorno = insertarReg(fHash, regA);
		
		if(retorno == -1){
			fclose(fEnt);
			fclose(fHash);
			return -1;
		}
		
		//es desborde??
		
		if(retorno >= CUBOS){
			numDesb++;
		}
		
		fread(&regA, sizeof(tipoAlumno), 1, fEnt);
	}
	fclose(fEnt);
	fclose(fHash);
	
	return numDesb;
}


int buscaReg(FILE *fHash, tipoAlumno *reg,char *dni){
	
	
	tipoCubo cubo;
	
}

/*
int desborde(FILE *fHash, tipoAlumno *regA){
	tipoCubo cubo;
	
	int numCubo = CUBOS, totalCubos = CUBOS + CUBOSDESBORDE;
	
	
	while(numCubo<CUBOS + CUBOSDESBORDE){
		fseek(fHash, numCUbo*sizeof(tipoCubo), SEEK_SET);
		fread(&cubo, sizeof(tipoCubo), 1, fHash);
		
		if(cubo.numRegAsignados )
		
		
		
	}
	
	
	return 0;

}
	
*/

int calcularHash(char *clave) {

	
	
	

}

int insertarReg(FILE *fHash, tipoAlumno reg) {
    
	tipoCubo cubo;
	int numCubo;
	int i;
	int suma=0;
	
	

	
	numCubo = atoi(reg.dni) % (CUBOS);
	

	fseek(fHash, sizeof(tipoCubo)*numCubo, SEEK_SET);
	
	
	fread(&cubo, sizeof(tipoCubo), 1, fHash);
	

	if (cubo.numRegAsignados < C) {

		cubo.reg[cubo.numRegAsignados]=reg;
		cubo.numRegAsignados++;
		
		fseek(fHash, sizeof(tipoCubo)*numCubo, SEEK_SET);
		fwrite(&cubo, sizeof(tipoCubo), 1, fHash);
		
		return numCubo;	
	}
	
	fseek(fHash, sizeof(tipoCubo)*CUBOS, SEEK_SET);
	
	for(numCubo = CUBOS; numCubo < CUBOS + CUBOSDESBORDE; numCubo++){
		fread(&cubo, sizeof(cubo), 1, fHash);
		
		if (cubo.numRegAsignados<C) {
	
			cubo.reg[cubo.numRegAsignados] = reg;
			cubo.numRegAsignados++;
			
			
			fseek(fHash, sizeof(tipoCubo)*numCubo, SEEK_SET);
			fwrite(&cubo, sizeof(tipoCubo), 1, fHash);
		
			return numCubo;	
		}
	}
	
	return -1;	
}











