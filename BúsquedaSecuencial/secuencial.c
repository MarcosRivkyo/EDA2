#include "secuencial.h"

#include <stdio.h>
#include <string.h>



int leeSecuencial(char *fichSecuencial){
	
	FILE * file;
	int numRegistros = 0;
	tipoAlumno registro; 	// No se puede poner como puntero *, porque hay que reservar memoria.
							//Habria que hacer su correspondiente malloc

	
	if(fichSecuencial == NULL || (file = fopen(fichSecuencial, "rb")) == NULL){
		
		fprintf(stderr, "ERROR: No se pudo abrir el fichero %s\n", fichSecuencial);
		return -1;
		
	}
	

	while(fread(&registro, sizeof(registro), 1, file)){
	//	fread(&registro, sizeof(registro), 1, file);
		printf("%-5d%-10s%-20s%-20s%-20s%-11s\n", numRegistros, registro.dni, 
					registro.nombre, registro.ape1, registro.ape2, registro.provincia);
		numRegistros++;
	}
	
	fclose(file);
	
	return numRegistros;
		
}
	
	
int buscaReg(FILE *f, tipoAlumno *reg, char *dni){
	
	tipoAlumno alumno;
	int numRegistros = 0;
	
	if(dni == NULL || f == NULL || reg == NULL){
		
			if(reg != NULL)
				reg = NULL;
			return -1;
	}
	else{
	
		while(fread(&alumno, sizeof(tipoAlumno), 1, f)){
		
			if(strcmp(alumno.dni, dni) == 0){
				*reg = alumno;
				return numRegistros;
			}
			else{
				numRegistros++;
			}
		
		}
	
	reg = NULL;
	return -2;		
		
		
	}
	
	
	
	
	
}




int insertaReg(char *fSecuencial, tipoAlumno *reg){
	
	FILE * file;
	tipoAlumno alumno;
	int numRegistros = 0;
	
	if(fSecuencial == NULL || reg == NULL)
			return -1;
	
	else{
		
	if((file=fopen(fSecuencial, "ab")) == NULL){
		
			fprintf(stderr, "ERROR: No se pudo abrir el fichero %s\n", fSecuencial);
			return -1;
			
	}
	
	numRegistros = ftell(file) / sizeof(tipoAlumno);
		
	fwrite(reg, sizeof(tipoAlumno), 1, file);
	fclose(file);
		
	return numRegistros;	
	}	
}

int modificarReg(char *fSecuencial, char * dni, char * provincia){
	
	FILE * file;
	tipoAlumno alumno;
	int numRegistros = 0;
	
	if(fSecuencial == NULL || dni == NULL || provincia == NULL)
			return -1;
	
	else{
		
		if((file=fopen(fSecuencial, "rb+")) == NULL){
		
			fprintf(stderr, "ERROR: No se pudo abrir el fichero %s\n", fSecuencial);
			return -1;
			
		}
		
		while(fread(&alumno, sizeof(tipoAlumno), 1, file)){
		
			if(strcmp(alumno.dni, dni) == 0){
				strcpy(alumno.provincia, provincia);
				fwrite(&alumno, sizeof(tipoAlumno), 1, file);
				return numRegistros;
			}
			else{
				numRegistros++;
			}
		
		}
		
			fclose(file);

		
		
	}
	
}











