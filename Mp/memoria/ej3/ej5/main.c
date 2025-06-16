#include "funciones.h"

int main(){

	int num;

	struct Ficha_jugador* equipo;

	printf("\nIntroduce el numero de jugadores que desea agregar: ");
	scanf("%d", &num);
	while(getchar()!='\n');

	equipo=reservarMemoria(num);

	rellenarJugadores(equipo, num);
	listarJugadores(equipo, num);

	num=borrarJugadores(&equipo, num, 'a');

	printf("\nDespués de borrar jugadores con 'a': \n");
	
	listarJugadores(equipo, num);

	free(equipo);

	return 0;
}