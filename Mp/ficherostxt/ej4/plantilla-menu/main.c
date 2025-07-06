/*!
  \file   menu.c
  \brief  Fichero de ejemplo de un menú que utiliza macros de pantalla: colores, subrayado, negrita
  \author Nicolás Luis Fernández García
  \date   28 de marzo de 2023
*/
/*!
 \mainpage Programa de ejemplo que muestra un menú usando macros de visualización
 \author Nicolás Luis Fernández García
v
 \version  1.0
*/

#include <stdio.h>
#include <string.h>
#include "macros.h"
#include "funciones.h"


/*!
   \brief Programa principal que muestra el menú de opciones
*/
int main(int argc, char *argv[])
{
 int opcion;
 char *nombreFichero;
 
 /* Se comprueban si los argumentos son correctos */
 if (argc !=2 )
	{
		printf("Número de argumentos incorrecto\n");
		printf("El programa se debe ejecutar de la siguente forma:\n\t %s <nombre de fichero>\n",argv[0]);
		return -1;
	}

  /* Se toma el nombre del fichero */
  nombreFichero = argv[1];
 
  CLEAR_SCREEN;
  LUGAR(5,1);
  BIYELLOW;
  printf("Gestión de libros usando el fichero <%s>\n\n",nombreFichero);
  RESET;
  printf("Pulsa enter para continuar");
  getchar();
 
 do{
		/* Se elige la opción del menún */
		opcion = menu();	

  CLEAR_SCREEN;
  LUGAR(5,1);
  switch(opcion)
	{
		case 0:  /* FIN DEL PROGRAMA */
			  	LUGAR(5,1);
			    INVERSE;
			    printf("Fin del programa %s.\n",argv[0]);
			    RESET;
			    LUGAR(7,1);
				return 0;
				
			    break;

		case 1: /* COMPROBAR SI EXISTE UN LIBRO Y MOSTRAR SUS DATOS EN SU CASO */
		  		BIYELLOW;
 				printf("Opción 1: COMPROBAR SI EXISTE UN LIBRO Y MOSTRAR SUS DATOS EN SU CASO \n");
  				RESET;
				printf("Esta opción está pendiente ser codificada \n");
        		break;

		case 2:   /* INTRODUCIR UN NUEVO LIBRO. SE COMPRUEBA QUE NO EXISTA */
				BIYELLOW;
				printf("Opción 2.- INTRODUCIR UN LIBRO. SE COMPRUEBA QUE NO EXISTA \n");		
			  	RESET;

				printf("Esta opción está pendiente ser codificada \n");

				break;

		case 3: /* CONTAR LOS LIBROS CON TÍTULOS DIFERENTES DEL FICHERO */
			  	BIYELLOW;
                printf("Opción 3.- CONTAR LOS LIBROS CON TÍTULOS DIFERENTES DEL FICHERO \n");	
				RESET;

				printf("Esta opción está pendiente ser codificada \n");
				break;

		case 4:  /* LISTAR LOS LIBROS DEL FICHERO */
				BIYELLOW;
				printf("Opción 4.- LISTAR LOS LIBROS DEL FICHERO \n");	
				RESET;

				printf("Esta opción está pendiente ser codificada \n");
				
				break;
				
		case 5: /* INCREMENTAR EL PRECIO DE LOS LIBROS UN PORCENTAJE, ALMACNÁNDOLOS PREVIAMENTE EN UN VECTOR DINÁNMICO  */
				BIYELLOW;
				printf("Opción 5.- INCREMENTAR EL PRECIO DE LOS LIBROS UN PORCENTAJE, ALMACNÁNDOLOS PREVIAMENTE EN UN VECTOR DINÁNMICO \n");	
				RESET;

				printf("Esta opción está pendiente ser codificada \n");

				break;

		case 6: /* VENDER EJEMPLARES DE UN LIBRO  */
			    BIYELLOW;
				printf("Opción 6.- VENDER EJEMPLARES DE UN LIBRO \n");	
				RESET;

				printf("Esta opción está pendiente ser codificada \n");

				break;

		case 7: /* GENERAR UN FICHERO CON LOS LIBROS (TÍTULOS) QUE TENGAN MENOS DE UN NÚMERO DE EJEMPLARES SIN UTILIZAR UN VECTOR INTERMEDIO */

				BIYELLOW;
				printf("Opción 7.- GENERAR UN FICHERO CON LOS LIBROS (TÍTULOS) QUE TENGAN MENOS DE UN NÚMERO DE EJEMPLARES SIN UTILIZAR UN VECTOR INTERMEDIO \n");	
				RESET;

				printf("Esta opción está pendiente ser codificada \n");

				break;

		case 8: /* BORRAR LIBROS SIN EJEMPLARES */
				BIYELLOW;
				printf("Opción 8.- BORRAR LIBROS SIN EJEMPLARES  \n");	
			  	RESET;

				printf("Esta opción está pendiente ser codificada \n");
				
				break;

		default: /* OPCIÓN INCORRECTA */
				 RESET;
				 RED;
				 LUGAR(10,10);
				 printf("Opción incorrecta");
				 RESET;
	}

	LUGAR(11,10);
    printf("pulse ");
	UNDERLINE;
	printf("ENTER");
	RESET;
	printf(" para ");
	INVERSE;
	printf(" regresar al menú"); 
	RESET;      
	getchar();	

		
  }while(opcion!=0);



return 0;
}

