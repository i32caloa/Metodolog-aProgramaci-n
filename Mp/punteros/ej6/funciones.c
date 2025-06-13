#include "funciones.h"

float media(int num1, int num2){

	float resultado;

	resultado = (num1+num2)/2.0;

	return resultado;

}

void media_referencia(int num1, int num2, float *resultado2){

	*resultado2 = (num1+num2)/2.0;

}