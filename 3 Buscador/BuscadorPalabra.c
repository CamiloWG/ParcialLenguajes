#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int contarCoincidencias(FILE *archivo, const wchar_t *clave) {
    wchar_t palabra[100];
    int contador = 0;
    int indice = 0;
    wint_t c;

    while ((c = fgetwc(archivo)) != WEOF) {
        if (iswalpha(c) || c == L'\'' || c == L'-') {
            palabra[indice++] = towlower(c);
        } else if (indice > 0) {
            palabra[indice] = L'\0';
            if (wcscasecmp(palabra, clave) == 0) {
                contador++;
            }
            indice = 0;
        }
    }

    if (indice > 0) {
        palabra[indice] = L'\0';
        if (wcscasecmp(palabra, clave) == 0) {
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

    setlocale(LC_ALL, "");

    FILE *archivo = fopen(argv[1], "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Convertir la palabra clave a wchar_t *
    size_t len = mbstowcs(NULL, argv[2], 0);
    if (len == (size_t)-1) {
        perror("Error al convertir la palabra clave");
        fclose(archivo);
        return 1;
    }

    wchar_t *palabraClave = (wchar_t *)malloc((len + 1) * sizeof(wchar_t));
    if (palabraClave == NULL) {
        perror("Error al reservar memoria");
        fclose(archivo);
        return 1;
    }

    mbstowcs(palabraClave, argv[2], len + 1);

    int resultado = contarCoincidencias(archivo, palabraClave);

    printf("%ls se repite %d veces en el texto.\n", palabraClave, resultado);

    fclose(archivo);
    free(palabraClave);
    return 0;
}
