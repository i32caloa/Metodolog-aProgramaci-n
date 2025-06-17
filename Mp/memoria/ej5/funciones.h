#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Ficha_jugador{

	char nombre[50];
	int dorsal; 	/* Nº entero */
	float peso; 	/* Expresado en kilos */
	int estatura; 	/* Expresado en centímetros*/

};

struct Ficha_jugador* reservarMemoria(int num);
struct Ficha_jugador leerJugador();
void rellenarJugadores(struct Ficha_jugador* jugadores, int num);
void listarJugadores(struct Ficha_jugador* jugadores, int num);
int borrarJugadores(struct Ficha_jugador** jugadores, int num, char letra);

#endif