#include "funciones.h"

void estadisticasCadena(char cad[], int *dig, int *May, int *min, int *esp){

	int n=strlen(cad);

	for(int i=0; i<n; i++){
		if(isupper(cad[i])){
			(*May)++;
		}

		if(islower(cad[i])){
			(*min)++;
		}

		if(isdigit(cad[i])){
			(*dig)++;
		}

		if(isspace(cad[i])){
			(*esp)++;
		}
	}

}