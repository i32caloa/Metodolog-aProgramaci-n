#include "funciones.h"

int main(){

	char nombreFichero[50];
	int min, max, num;

	printf("\nIntroduce el nombre del fichero: ");
	fgets(nombreFichero, 50, stdin);

	size_t len = sizeof(nombreFichero);
	if(len>0 && nombreFichero[len-1]=='\n'){
		nombreFichero[len-1]='\0';
	}

	printf("\nIntroduce el numero de elementos: ");
	scanf("%d", &num);

	printf("\nIntroduce el intervalo minimo: ");
	scanf("%d", &min);

	printf("\nIntroduce el intervalo maximo: ");
	scanf("%d", &max);

	rellenarFichero(nombreFichero, num, min, max);

	return 0;
}