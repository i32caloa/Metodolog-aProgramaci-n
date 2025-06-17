#include "funciones.h"

int main(){

	int nFil, nCol;

	printf("\nIntroduce el numero de Filas: ");
	scanf("%d", &nFil);

	printf("\nIntroduce el numero de columas: ");
	scanf("%d", &nCol);

	float **matriz = reservarMemoria(nFil, nCol);

	rellenaMatriz(matriz, nFil, nCol);
	imprimeMatriz(matriz, nFil, nCol);

	int *V = maxFil(matriz, nFil, nCol);

	



	return 0;
}