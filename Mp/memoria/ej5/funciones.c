#include "funciones.h"

struct Ficha_jugador* reservarMemoria(int num){
	return(struct Ficha_jugador*)malloc(num*sizeof(struct Ficha_jugador));
}

struct Ficha_jugador leerJugador(){

	struct Ficha_jugador jugadores;

	printf("\nIntroduce el nombre del jugador: ");
	fgets(jugadores.nombre, 50, stdin);

	jugadores.nombre[strcspn(jugadores.nombre, "\n")], '\0';

	printf("\nIntroduce el dorsal: ");
	scanf("%d", &jugadores.dorsal);

	printf("\nItroduce el peso(kg): ");
	scanf("%f", &jugadores.peso);

	printf("\nIntroduce la estatura(cm): ");
	scanf("%d", &jugadores.estatura);

	while(getchar()!='\n'); //limpia buffer

	return jugadores;
}

void rellenarJugadores(struct Ficha_jugador* jugadores, int num){

	for(int i=0; i<num; i++){
		printf("\n  Jugador %d  ", i+1);
		jugadores[i]=leerJugador();
	}
}

void listarJugadores(struct Ficha_jugador* jugadores, int num){

	for(int i=0; i<num; i++){
		printf("Nombre: %s | Dorsal: %d | Peso: %.2f | Estatura: %d\n",
			jugadores[i].nombre, jugadores[i].dorsal, jugadores[i].peso, jugadores[i].estatura);
	}
}

int borrarJugadores(struct Ficha_jugador** jugadores, int num, char letra){

	int j=0;
	letra=tolower(letra);

	for(int i=0; i<num; i++){
		int c=0;

		for(int k=0; (*jugadores)[i].nombre[k]!='\0'; k++){
			if(tolower((*jugadores)[i].nombre[k])==letra){
				c=1;
				break;
			}
		}
		if(!c){
			(*jugadores)[j++]=(*jugadores)[i];
		}
	}

	struct Ficha_jugador* temp = realloc(*jugadores, j * sizeof(struct Ficha_jugador));
    	if (temp != NULL || j == 0) { 
        *jugadores = temp;
    	} else {
    
        printf("\nError al redimensionar memoria con realloc.\n");
        (EXIT_FAILURE);
    }

    return j;
}
