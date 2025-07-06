#ifndef FUNCIONES_H
#define FUNCIONES_H

#define FICHERO_BIN "libros.bin"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

struct libro{
	char titulo[50];
	char autor[50];
	float precio;
	int unidades;
};

void saltoLinea(char *cadena);
int comprobarLibros();
void introducirLibros();
int contarLibros();
void listarLibros();
void incrementarPrecio(float porcentaje);
void venderLibros(char *titulo, int n);
void generarFichero(int n);
void borrarLibros();

#endif
