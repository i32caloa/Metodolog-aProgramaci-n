#include "funciones.h"

void saltoLinea(char *cadena){

	size_t len = strlen(cadena);
	if(len>0 && cadena[len + 1]=='\n'){
		cadena[len + 1]='\0';
	}
}

int comprobarLibros(char *titulo){

	FILE *f = fopen(FICHERO, "r");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero 1");
		exit(EXIT_FAILURE);
	}

	char linea[100];
	while(fgets(linea, sizeof(linea), f)){  //titulo
		if(strcmp(linea, titulo)==0){
			fclose(f);
			return 1;
		}

		fgets(linea, sizeof(linea), f); //autor
		fgets(linea, sizeof(linea), f); //precio y unidades
	}

	fclose(f);
	return 0;
}

void introducirLibros(){

	struct libro l;

	printf("\nIntroduce el titulo: ");
	fgets(l.titulo, sizeof(l.titulo), stdin);
	saltoLinea(l.titulo);
	if(comprobarLibros(l.titulo)){
		printf("\nYa existe\n");
		return;
	}

	printf("\nIntroduce el autor: ");
	fgets(l.autor, sizeof(l.autor), stdin);
	saltoLinea(l.autor);

	printf("\nIntroduce el precio: ");
	scanf("%f", &l.precio);

	printf("\nIntroduce las unidades: ");
	scanf("%d", &l.unidades);
	getchar(); //limpiar buffer

	FILE *f = fopen(FICHERO, "a");
	if(FICHERO==NULL){
		perror("\nNo se pudo abrir el fichero 2\n");
		exit(EXIT_FAILURE);
	}

	fprintf(f, "%s%s%f %d\n", l.titulo, l.autor, l.precio, l.unidades);

	fclose(f);
}

int contarLibros(){

	int contador=0;

	FILE *f = fopen(FICHERO, "r");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero 3\n");
		exit(EXIT_FAILURE);
	}

	char linea[100];

	while(fgets(linea, sizeof(linea), f)){
		fgets(linea, sizeof(linea),f);
		fgets(linea, sizeof(linea),f);

		contador++;
	}

	return contador;
}

void listarLibros(){

	FILE *f = fopen(FICHERO, "r");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero 4");
		exit(EXIT_FAILURE);
	}

	char linea[100];

	while(fgets(linea, sizeof(linea), f)){

		saltoLinea(linea);
		printf("%s", linea);

		fgets(linea, sizeof(linea), f);
		fgets(linea, sizeof(linea), f);
	}

	fclose(f);
}

void incrementarPrecio(float porcentaje){

	FILE *f = fopen(FICHERO, "r");
	if(FICHERO==NULL){
		perror("\nNo se pudo abrir el fichero 5\n");
		exit(EXIT_FAILURE);
	}

	struct libro *libros=NULL;
	int cantidad=0;
	char linea[100];

		while (fgets(linea, sizeof(linea), f)) {
        libros = realloc(libros, (cantidad + 1) * sizeof(struct libro));
        saltoLinea(linea);
        strcpy(libros[cantidad].titulo, linea);

        fgets(linea, sizeof(linea), f);
        saltoLinea(linea);
        strcpy(libros[cantidad].autor, linea);

        fgets(linea, sizeof(linea), f);
        sscanf(linea, "%f %d", &libros[cantidad].precio, &libros[cantidad].unidades);

        libros[cantidad].precio *= (1 + porcentaje / 100.0f);
        cantidad++;
    }

    fclose(f);

	f = fopen(FICHERO, "w");
	if(FICHERO==NULL){
		perror("\nNo se pudo abrir el fichero 5\n");
		exit(EXIT_FAILURE);
	}

	for(int i=0; i<cantidad; i++){
		fprintf(f, "%s%s%.2f %d\n", libros[i].titulo, libros[i].autor, libros[i].precio, libros[i].unidades);
	}

	printf("\nActualizacion realizada\n");

	fclose(f);
	free(libros);
}

void venderLibros(char *titulo, int n){

	FILE *f = fopen(FICHERO, "r");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero 6\n");
		exit(EXIT_FAILURE);
	}

	struct libro *libros=NULL;
	char linea[100];
	int cantidad=0;
	int encontrado=0;

	while(fgets(linea, sizeof(linea), f)){
		
		libros = realloc(libros, (cantidad+1)*sizeof(struct libro));
		saltoLinea(linea);
		strcpy(libros[cantidad].titulo, linea);

		fgets(linea, sizeof(linea), f);
		saltoLinea(linea);
		strcpy(libros[cantidad].autor, linea);

		fgets(linea, sizeof(linea), f);
		sscanf(linea, "%f %d", &libros[cantidad].precio, &libros[cantidad].unidades);

		if(strcmp(libros[cantidad].titulo, titulo)==0){
			encontrado=1;

			if(libros[cantidad].unidades==0){
				printf("\nNo queda stock\n");

			} else if(libros[cantidad].unidades>=n){
				libros[cantidad].unidades -= n;
				printf("\nQuedan %d unidades de %s\n", libros[cantidad].unidades, libros[cantidad].titulo);
			} else {
				printf("\nSolo habia %d unidades de %s\n", libros[cantidad].unidades, libros[cantidad].titulo);
				libros[cantidad].unidades=0;
			}
		}

		cantidad++;
	}

	fclose(f);

	if(!encontrado){
		("\nNo hay stock\n");
	}

	f = fopen(FICHERO, "w");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero 6\n");
		exit(EXIT_FAILURE);
	}

	for(int i=0; i<cantidad; i++){
		fprintf(f, "%s%s%.2f %d\n", libros[i].titulo, libros[i].autor, libros[i].precio, libros[i].unidades);
	}

	fclose(f);
}

void generarFichero(int n){

	FILE *f = fopen(FICHERO, "r");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		exit(EXIT_FAILURE);
	}

	FILE *out = fopen("bajo-stock", "w");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		exit(EXIT_FAILURE);
	}

	char linea[100];
	int unidades;
	char titulo[50];
	char autor[50];
	float precio;

	while(fgets(titulo, sizeof(titulo), f)){
		fgets(autor, sizeof(autor), f);
		fgets(linea, sizeof(linea), f);
		sscanf(linea, "%f %d", &precio, &unidades);

		if(unidades<n){
			fprintf(out, "%s%s%f %d\n", titulo, autor, precio, unidades);
		}

	}

	fclose(f);
	fclose(out);
	printf("\nSe genero el fichero correctamente\n");
}

void borrarLibros(){

	FILE *f = fopen(FICHERO, "r");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		exit(EXIT_FAILURE);
	}

	FILE *out = fopen("temp.txt", "w");
	if(out==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		exit(EXIT_FAILURE);
	}

	char linea[100];
	char titulo[50];
	char autor[50];
	float precio;
	int unidades;

	while(fgets(titulo, sizeof(titulo), f)){
		fgets(autor, sizeof(autor), f);
		fgets(linea, sizeof(linea), f);
		sscanf(linea, "%f %d", &precio, &unidades);

		if(unidades!=0){
			fprintf(out, "%s%s%f %d\n", titulo, autor, precio, unidades);
		}
	}

	fclose(f);
	fclose(out);

	remove(FICHERO);
	rename("temp.txt", FICHERO);

	printf("\n Se elimino con exito\n");
}
