#include "funciones.h"

void saltoLinea(char *cadena){

	size_t len = strlen(cadena);
	if(len>0 && cadena[len-1]=='\n'){
		cadena[len-1]='\0';
	}
}

int comprobarLibros(char *titulo){

	FILE *f = fopen(FICHERO_BIN, "rb");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		exit(EXIT_FAILURE);
	}

	struct libro l;

	while(fread(&l, sizeof(struct libro), 1, f)){

		if(strcmp(l.titulo, titulo)==0){
			fclose(f);
			return 1;
		}
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

	FILE *f = fopen(FICHERO_BIN, "ab");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		exit(EXIT_FAILURE);
	}

	fwrite(&l, sizeof(struct libro), 1, f);
	fclose(f);

	printf("\nLibro introducido con exito\n");
}

int contarLibros(){

	FILE *f =fopen(FICHERO_BIN , "rb");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		exit(EXIT_FAILURE);
	}

	struct libro l;
	int contador=0;

	while(fread(&l, sizeof(struct libro), 1, f)){
		contador++;
	}

	fclose(f);
	printf("\nHay %d libros en stock\n", contador);
}

void listarLibros(){

	FILE *f = fopen(FICHERO_BIN, "rb");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		exit(EXIT_FAILURE);
	}

	struct libro l;
	int contador=0;

	printf("\n- - - Listado de libros - - -\n");

	while(fread(&l, sizeof(struct libro), 1, f)){

		contador++;

		printf("\nLibro %d", contador);
		printf("\nTitulo: %s", l.titulo);
		printf("\nAutor: %s", l.autor);
		printf("\nPrecio: %.2f", l.precio);
		printf("\nUnidades: %d", l.unidades);

		printf("\n---------------------------------------\n");
	}

	if(contador==0){
		printf("\nNo existe stock\n");
	}
}

void incrementarPrecio(float porcentaje){

	FILE *f = fopen(FICHERO_BIN, "rb");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		exit(EXIT_FAILURE);
	}

	FILE *out = fopen("temp.bin", "wb");
	if(out==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		fclose(f);
		exit(EXIT_FAILURE);
	}

	struct libro l;

	while(fread(&l, sizeof(struct libro), 1, f)){
		l.precio += l.precio*(porcentaje/100.00f);
		fwrite(&l, sizeof(struct libro), 1, out);
	}

	fclose(f);
	fclose(out);

	remove(FICHERO_BIN);
	rename("temp.bin", FICHERO_BIN);

	printf("\nPrecios incrementados\n");
}

void venderLibros(char *titulo, int n){

	FILE *f = fopen(FICHERO_BIN, "rb");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		exit(EXIT_FAILURE);
	}

	FILE *temp = fopen("temp.bin", "wb");
	if(temp==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		fclose(f);
		exit(EXIT_FAILURE);
	}

	struct libro l;

	while(fread(&l, sizeof(struct libro), 1, f)){
		if(strcmp(l.titulo, titulo)==0){
			if(l.unidades==0){
				printf("\nNo hay stock\n");
			} else if(l.unidades>=n){
				l.unidades -= n;
				printf("\nQuedan %d libros de %s", l.unidades, l.titulo);
			} else {
				printf("\nSe han vendido %d unidades\n", l.unidades);
				l.unidades = 0;
			}
		}
		fwrite(&l, sizeof(struct libro), 1, temp);
	}
	fclose(f);
	fclose(temp);

	remove(FICHERO_BIN);
	rename("temp.bin", FICHERO_BIN);

	printf("\nSe actualizo con exito\n");
}

void generarFichero(int n){

	FILE *f = fopen(FICHERO_BIN, "rb");
	if(f==NULL){
		perror("\nNo se pudo abrir el archivo\n");
		exit(EXIT_FAILURE);
	}

	FILE *out = fopen("bajo_stock.bin", "wb");
	if(out==NULL){
		perror("\nNo se pudo abrir el archivo\n");
		fclose(f);
		exit(EXIT_FAILURE);
	}

	FILE *outxt = fopen("bajo_stock.txt", "w");
	if(outxt==NULL){
		perror("\nNo se pudo abrir el archivo\n");
		fclose(f);
		exit(EXIT_FAILURE);
	}

	struct libro l;

	while(fread(&l, sizeof(struct libro), 1, f)){
		if(l.unidades<n){
			fprintf(outxt,"%s\n%s\n%.2f %d\n", l.titulo, l.autor, l.precio, l.unidades);
			fwrite(&l, sizeof(struct libro), 1, out);
		}
	}

	fclose(f);
	fclose(out);
	fclose(outxt);
}

void borrarLibros(){

	FILE *f = fopen(FICHERO_BIN, "rb");
	if(f==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		exit(EXIT_FAILURE);
	}

	FILE *out = fopen("temp.bin", "wb");
	if(out==NULL){
		perror("\nNo se pudo abrir el fichero\n");
		fclose(f);
		exit(EXIT_FAILURE);
	}

	FILE *outxt = fopen("bajo_stock.txt", "w");
	if(outxt==NULL){
		perror("\nNo se pudo abrir el archivo\n");
		fclose(f);
		exit(EXIT_FAILURE);
	}

	struct libro l;

	while(fread(&l, sizeof(struct libro), 1, f)){
		if(l.unidades!=0){
			fwrite(&l, sizeof(struct libro), 1, out);
			fprintf(outxt,"%s\n%s\n%.2f %d\n", l.titulo, l.autor, l.precio, l.unidades);

		}
	}

	fclose(f);
	fclose(out);
	fclose(outxt);

}