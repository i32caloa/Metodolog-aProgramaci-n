#include "funciones.h"

int main(){

	char nombreFichero[50];

	printf("\nIntroduce el nombre del fichero: ");
	fgets(nombreFichero, 50, stdin);

	size_t len=strlen(nombreFichero);
	if(len>0 && nombreFichero[len-1]=='\n'){
		nombreFichero[len-1]='\0';
	}

	convertirFichero(nombreFichero);

	printf("\nEl fichero ha sido creado\n");

	return 0;
}