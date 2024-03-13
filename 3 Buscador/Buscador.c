#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarCoincidencias(FILE *archivo, const char *clave) {
    char palabra[100];
    int contador = 0;

    while (fscanf(archivo, "%s", palabra) == 1) {
        //strcasecmp para linux
        //stricmp para windows
        if (strcasecmp(palabra, clave) == 0) {
            contador++;
        }
    }

    return contador;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <archivo> <palabra clave>\n", argv[0]);
        return 1;
    }

    FILE *archivo = fopen(argv[1], "r");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    const char *palabraClave = argv[2];
    int resultado = contarCoincidencias(archivo, palabraClave);

    printf("%s se repite %d veces en el texto.\n", palabraClave, resultado);

    fclose(archivo);
    return 0;
}
