#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{

	int coe;
	int gra;

}Monomio;

void leerMonomio(Monomio *m);
void imprimirMonomio(Monomio m);
void leerPolinomio(Monomio polinomio[], int n);
void imprimirPolinomio(Monomio polinomio[], int n);
void mayorMenor(Monomio polinomio[], int n, Monomio *May, Monomio *men);

#endif