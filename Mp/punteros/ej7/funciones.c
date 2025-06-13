#include "funciones.h"

void estadisticasVector(int n, int v[], float *media, float *varianza, float *desviacion){

	int suma=0.0;

	for(int i=0; i<n; i++){

		suma+=v[i];

	}

	*media = (float)suma/n;

	*varianza=0.0;

	for(int i=0; i<n; i++){

		*varianza+=pow(v[i]- *media, 2);

	}

	*desviacion=sqrt(*varianza);

}