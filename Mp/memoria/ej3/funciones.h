#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **reservarMemoria(int nFil, int nCol);
void rellenarMatriz(int **matriz, int nFil, int nCol);
void imprimirMatriz(int **matriz, int nFil, int nCol);
int *minCol(int **matriz, int nFil, int nCol);
void liberarMemoria(int **matriz, int nFil);

#endif