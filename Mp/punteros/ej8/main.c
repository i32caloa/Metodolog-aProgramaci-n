#include "funciones.h"

int main(){

	char cad[100];
	int dig=0, May=0, min=0,esp=0; 

	printf("Introduce una cadena: ");
	scanf("%100[^\n]", cad);

	getchar();

	printf("%s", cad);

	estadisticasCadena(cad, &dig, &May, &min, &esp);

	printf("\n La cadena tiene: \n\n mayusculas: %d \n\n minusculas: %d \n\n espacios: %d \n\n digitos: %d\n\n",May,min,esp,dig);
	return 0;

}