#include "funciones.h"

void rellenarFichero(const char *nombreFichero, int num, int min, int max){

	FILE *f = fopen(nombreFichero, "w");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		exit(EXIT_FAILURE);
	}

	srand(time(NULL));

	for(int i=0; i<num; i++){
		int numero=min+rand()%(max-min+1);
		fprintf(f, "%d\n", numero);
	}

	fclose(f);

}
float mediaPares(const char *nombreFichero){

	int suma=0;
	int c=0;

	FILE *f2=fopen(nombreFichero, "r");

	if(f2==NULL){
		perror("\nNo se pudo leer el fichero\n");
		exit(EXIT_FAILURE);
	}

	int numero;

	while(fscanf(f2, "%d", &numero)==1){
		if(numero%2==0){
			suma+=numero;
			c++;
		}
	}

	fclose(f2);

	if(c==0){
		return 0.0;
	} else {
		return (float)suma/c;
	}

}