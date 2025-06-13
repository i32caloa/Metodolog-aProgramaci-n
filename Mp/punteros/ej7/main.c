#include "funciones.h"

int main(){

	int n;
	float media, varianza, desviacion;

	printf("Introduce el numero de elementos del vector: ");
	scanf("%d", &n);

	int v[n];

	for(int i=0; i<n; i++){

		printf("Introduce el numero %d: ", i+1);
		scanf("%d", &v[i]);
	}

	estadisticasVector(n, v, &media, &varianza, &desviacion);

	printf("\nMedia: %.2f\nVarianza: %.2f\nDesviacion: %.2f\n", media, varianza, desviacion);

	return 0;

}