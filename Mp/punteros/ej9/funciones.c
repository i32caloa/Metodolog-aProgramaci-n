#include "funciones.h"

void leerMonomio(Monomio *m){

	printf("\nIntroduce un coeficiente: ");
	scanf("%d", &m->coe);

	printf("Introduce el grado: ");
	scanf("%d", &m->gra);

}

void imprimirMonomio(Monomio m){

	printf("%dx^%d", m.coe, m.gra);

}

void leerPolinomio(Monomio polinomio[], int n){

	printf("\n");

	for(int i=0; i<n; i++){

		printf("\nMonomio %d: ", i+1);
		leerMonomio(&polinomio[i]);

	}

}

void imprimirPolinomio(Monomio polinomio[], int n){

	printf("\n");

	for(int i=0; i<n; i++){

		imprimirMonomio(polinomio[i]);

		if(i<n-1){

		printf(" + ");

		}

	}
}

void mayorMenor(Monomio polinomio[], int n, Monomio *May, Monomio *men){

	*May = polinomio[0];
	*men = polinomio[0];

	for(int i=1; i<n; i++){

		if(polinomio[i].gra > May->gra){
			*May=polinomio[i];
		}

		if(polinomio[i].gra < men->gra){
			*men=polinomio[i];
		}
	}

}