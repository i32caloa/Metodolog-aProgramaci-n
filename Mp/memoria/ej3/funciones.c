#include "funciones.h"

int **reservarMemoria(int nFil, int nCol){

	int **matriz = (int**)malloc(nFil*sizeof(int*));
	if(matriz == NULL){
		perror("\nNo se pudo reservar memoria (Fila)");
		(EXIT_FAILURE);
	}

	for(int i=0; i<nCol; i++){

		matriz[i] = (int*)malloc(nCol*sizeof(int));

		if(matriz[i] == NULL){
			perror("\nNo se ppudo reservar memoria (columna)");
			(EXIT_FAILURE);
		}
	}
	return matriz;

}

void rellenarMatriz(int **matriz, int nFil, int nCol){

	srand(time(NULL));

	for(int i=0; i<nFil; i++){
		for(int j=0; j<nCol; j++){

			matriz[i][j]=rand()% 20 + 1;

		}
	}

}

void imprimirMatriz(int **matriz, int nFil, int nCol){

	printf("\n");

	for(int i=0; i<nFil; i++){

		printf("|");

		for(int j=0;  j<nCol; j++){

			printf(" %d ", matriz[i][j]);

		}

		printf("|\n");

	}
	
	printf("\n");
}

int *minCol(int **matriz, int nFil, int nCol){

	int *min=(int*)malloc(nCol*sizeof(int));

	if(min==NULL){
		perror("\nNo se pudo reservar memoria (minimo)");
		(EXIT_FAILURE);
	}

	for(int j=0; j<nCol; j++){

		min[j]=matriz[0][j];

	}

	for(int i=1; i<nFil; i++){
		for(int j=0; j<nCol; j++){

			if(matriz[i][j]<min[j]){
				min[j]=matriz[i][j];
			}
		}
	}


	return min;
}

void liberarMemoria(int **matriz, int nFil){

	for(int i=0; i<nFil; i++){

		free(matriz[i]);
	}

	free(matriz);
}