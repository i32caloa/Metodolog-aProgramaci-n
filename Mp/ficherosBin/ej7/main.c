#include "funciones.h"

int main(){

	int opcion;
	char titulo[50];

	do{
		printf("\n- - - MENU - - -\n\n");

		printf("1. Comprobar existencias\n");
		printf("2. Introducir libro\n");
		printf("3. Contar libros\n");
		printf("4. Listar libros\n");
		printf("5. Incrementar precio\n");
		printf("6. Vender libros\n");
		printf("7. Generar fichero libros\n");
		printf("8. Borrar libros sin stock\n");
		printf("9. Salir\n");

		printf("\nElija su opcion: ");
		scanf("%d", &opcion);
		printf("\n");
		getchar(); //limpiar buffer

			switch(opcion){
				case 1:

					printf("Introduce el titulo: ");
					fgets(titulo, sizeof(titulo), stdin);
					saltoLinea(titulo);

					if(comprobarLibros(titulo)){
						printf("\nEl libro existe\n");
					} else {
						printf("\nNo existe libro\n");
					}

					break;
				case 2:

					introducirLibros();
					break;
				case 3:

					contarLibros();
					break;

				case 4:

					listarLibros();
					break;

				case 5:

					float porcentaje;
					printf("\nIntroducer el porcentaje: ");
					scanf("%f", &porcentaje);
					getchar();

					incrementarPrecio(porcentaje);
					break;

				case 6:

					char titulo[50];
					int n;
					printf("\nIntroduce el titulo: ");
					fgets(titulo, sizeof(titulo), stdin);
					saltoLinea(titulo);

					printf("\nCuantos libros se van a vender: ");
					scanf("%d", &n);

					venderLibros(titulo, n);
					break;

				case 7:

					int x;
					printf("\nIntroduce el umbral: ");
					scanf("%d", &x);
					getchar();

					generarFichero(x);
					break;

				case 8:

					borrarLibros();
					break;
			}
			
	}while(opcion!=9);

	return 0;
}