#include "funciones.h"

int main(){

	int n;
	Monomio May, men;

	printf("\nIntroduce el numero de monomios: ");
	scanf("%d", &n);

	Monomio polinomio[n];

	leerPolinomio(polinomio, n);
	imprimirPolinomio(polinomio, n);

	mayorMenor(polinomio, n, &May, &men);

	printf("\n\nEl monomio de mayor grado es: ");
	imprimirMonomio(May);
	printf("\nEl monomio de menor grado es: ");
	imprimirMonomio(men);
	printf("\n");

	return 0;

}