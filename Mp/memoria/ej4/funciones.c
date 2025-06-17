#include "funciones.h"

float **reservarMemoria (int nFil, int nCol){

	float **matriz=(float **)malloc(nFil*sizeof(float *));

	if(matriz==NULL){

	perror("\nNo se pudo reservar memoria (filas)");
	(EXIT_FAILURE);
	}

	for(int i=0; i<nCol; i++){

		matriz[i]=(float *)malloc(nCol*sizeof(float));

		if(matriz[i]==NULL){
		perror("\nNo se pudo reservar memoria (columnas)");
		(EXIT_FAILURE);
		}
	}

	return matriz;
}

void rellenaMatriz (float **matriz, int nFil, int nCol){

	srand(time(NULL));

	for(int i=0; i<nFil; i++){
		for(int j=0; j<nCol; j++){
			matriz[i][j]=rand()% 2;
		}
	}
}

void imprimeMatriz (float **matriz, int nFil, int nCol){

	printf("\n");

	for(int i=0; i<nFil; i++){

		printf("|");
		for(int j=0; j<nCol; j++){
			printf(" %f ", matriz[i][j]);
		}

		printf("|\n");
	}
}

float *maxFil(float **matriz, int nFil, int nCol){



}
void liberarMemoria(float ***matriz){

}