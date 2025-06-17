#include "funciones.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {

        char nombreFichero[100];
        int num, min, max;

        printf("Introduce el nombre del fichero a crear: ");
        scanf("%s", nombreFichero);

        printf("Introduce la num de números: ");
        scanf("%d", &num);

        printf("Introduce el límite min: ");
        scanf("%d", &min);

        printf("Introduce el límite max: ");
        scanf("%d", &max);

        if (min > max) {
            printf("Error: El límite min no puede ser mayor que el max.\n");
            exit(EXIT_FAILURE);
        }

        rellenarFichero(nombreFichero, num, min, max);
        printf("Fichero '%s' creado con %d números aleatorios entre %d y %d.\n",
               nombreFichero, num, min, max);
    } else if (argc == 2) {

        float media = mediaPares(argv[1]);

        printf("La media de los números pares en el fichero '%s' es: %.2f\n", argv[1], media);

    } else {

        printf("Uso:\n");
        printf("  %s            -> para crear un fichero\n", argv[0]);
        printf("  %s fichero.txt -> para calcular la media de pares\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
