#include "funciones.h"

int main(){

	int n;
	double suma;

	printf("\nIntroduce el numero de elementos del vector: ");
	scanf("%d", &n);

	double v[n];

	leeVector(v, n);
	escribeVector(v, n);
	sumaPositivos(v, n, &suma);

	printf("\nLa suma de numeros positivos deñ vector es: %.4lf", suma);

	return 0;	

}