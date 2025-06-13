#include "funciones.h"

int main(){
	
	int num1, num2;
	float resultado;
	float resultado2;

	printf("\nIntroduce dos numeros para hacer la media: ");
	printf("\nNumero 1: ");
	scanf("%d", &num1);
	printf("\nNumero 2: ");
	scanf("%d", &num2);

	resultado=media(num1, num2);

	media_referencia(num1, num2, &resultado2);

	printf("\n La media es de: %.2f", resultado);
	printf("\n La media pasada por referencia es de: %.2f", resultado2);


	return 0;
}