#include "funciones.h"

void leeVector(double v[], int n){

	for(int i=0; i<n; i++){

		printf("\nElemento %d: ", i+1);
		scanf("%lf", &v[i]);

	}

}
void escribeVector(double v[], int n){

	printf("\n");

	for(int i=0; i<n; i++){

		printf("\n%.2lf", v[i]);

	}

}
void sumaPositivos(double v[], int n, double *suma){

	*suma=0;

	for(int i=0; i<n; i++){
		if(v[i]>0);

		*suma += v[i];
	}

}
