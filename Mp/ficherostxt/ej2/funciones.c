#include "funciones.h"

void rellenarFichero(const char* nombreFichero, int num, int min, int max){

	FILE *entrada=fopen(nombreFichero, "w");
	if(entrada==NULL){
		perror("\nError al abrir el fichero\n");
		(EXIT_FAILURE);
		return;
	}

	srand(time(NULL));

	for(int i=0; i<num; i++){
		int numero=min+rand()%(max-min+1);
		fprintf(entrada, "%d\n", numero);
	}

	printf("\nFichero rellenado con exito\n");

	fclose(entrada);

}