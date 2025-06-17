#include "funciones.h"

void convertirFichero(const char* nombreFichero){

	char nombreSalida[100];

	snprintf(nombreSalida, sizeof(nombreSalida), "mayusculas-%s", nombreFichero);

	FILE *entrada = fopen(nombreFichero, "r");
	if(entrada==NULL){
		perror("\nNo se pudo leer el fichero\n");
		(EXIT_FAILURE);
		return;
	}

	FILE *salida=fopen(nombreSalida, "w");
	if(salida==NULL){
		perror("\nNo se pudo abrir el fichero de salida\n");
		(EXIT_FAILURE);
		return;
	}

	int c;
	while ((c=fgetc(entrada))!=EOF){
		fputc(toupper(c), salida);
	}

	fclose(entrada);
	fclose(salida);

}