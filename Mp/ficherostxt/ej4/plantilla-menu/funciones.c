/*!
  \file   funciones.c
  \brief  Código de las funciones auxiliares
  \author Nicolás Luis Fernández García
  \date   28 de marzo de 2023
*/

#include <stdio.h>

/* Para usar malloc */
#include <malloc.h>

/* Para usar las macros de pantalla */
#include "macros.h"

/* Prototipos de las funciones */
#include "funciones.h"


/* Menú */

int menu()
{
 int opcion;

  CLEAR_SCREEN;
  LUGAR(5,10);
  BBLUE;
  printf("Opciones del menú");
  RESET;

	LUGAR(6,10);
  	printf("1.- Comprobar si existe un libro y mostrar sus datos en su caso.");
  	
	LUGAR(7,10);
	printf("2.- Introducir un nuevo libro, comprobando antes que no está en el fichero.");
  
	LUGAR(8,10);
  printf("3.- Contar el número de libros con títulos diferentes.");
		
	LUGAR(9,10);
	printf("4.- Listar los libros del fichero.");

	LUGAR(10,10);
	printf("5.- Incrementar los precios de los libros un porcentaje determinado.");
  LUGAR(11,14); 
  printf("(Los libros se deben almacenar previamente en un vector).");

	LUGAR(12,10);
	printf("6.- Vender ejemplares de un libro.");
  LUGAR(13,14);
	printf("(Se venderán, como máximo, el número de ejemplares que tenga).");
	
	LUGAR(14,10);
	printf("7.- Generar un nuevo fichero con los libros (títulos) que tengan menos de un número de unidades determinado.");

  LUGAR(15,10);
	printf("8.- Borrar los libros sin ejemplares.");
	
	LUGAR(16,10);
	GREEN;
	printf("0.- Salir");
	RESET;

	LUGAR(17,10);
	BIYELLOW;
	printf("Opción --> ");
	RESET;
	scanf("%d",&opcion);
	getchar();

	CLEAR_SCREEN;
	LUGAR(5,1);

	return opcion;
}
