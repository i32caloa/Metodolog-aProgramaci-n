#include "funciones.h"

int main(){

	int nFil, nCol;

	printf("\nDetermina el numero de filas: ");
	scanf("%d", &nFil);

	printf("\nDetermina el numero de columnas: ");
	scanf("%d", &nCol);

	int **matriz = reservarMemoria(nFil, nCol);

	printf("\nSe va a rellenar la matriz con numeros [1, 20]\n");

	rellenarMatriz(matriz, nFil, nCol);

	printf("\nMatriz generada: \n");

	imprimirMatriz(matriz, nFil, nCol);

	int *min = minCol(matriz, nFil, nCol);

	for(int i=0; i<nCol; i++){

		printf("El elemento de menor valor de la columna %d es: %d\n", i+1, min[i]);	

	}

	printf("\n");

	return 0;

}