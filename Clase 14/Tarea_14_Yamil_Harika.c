/*
-Noemi Franco
-Yamil Harika
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct palabra {
    char caracteres[10];
    struct palabra* siguiente;
} Palabra;

void generarPalabras(Palabra **lista);
void ordenarPalabras(Palabra **lista);
void cargarArchivo(FILE *archivo, Palabra *lista);
void imprimir_archivo(FILE *archivo, Palabra *lista);

int main() {
    srand(time(NULL));
    FILE *archivo = fopen("archivo.txt", "w");
    Palabra *lista = NULL;
    generarPalabras(&lista);
    cargarArchivo(archivo, lista);
    fclose(archivo);
    return 0;
}

void generarPalabras(Palabra **lista) {
    int i, n, c, j;
    for (i = 0; i < 10; i++) {
        Palabra *nueva_palabra = (Palabra*)malloc(sizeof(Palabra));
        n = 6 + rand() % 5;
        char palabra[n + 1];
        for (j = 0; j < n; j++) {
            c = rand() % 26;
            palabra[j] = 'A' + c;
        }
        palabra[n] = '\0';
        strcpy(nueva_palabra->caracteres, palabra);
        nueva_palabra->siguiente = *lista;
        *lista = nueva_palabra;
    }
}

Palabra* intercambiar(Palabra *ptr1, Palabra *ptr2) {
    Palabra *tmp = ptr2->siguiente;
    ptr2->siguiente = ptr1;
    ptr1->siguiente = tmp;
    return ptr2;
}

void ordenarPalabras(Palabra **lista) {
    Palabra **h;
    int i, j, intercambio;
    for (i = 0; i < 9; i++) {
        h = lista;
        intercambio = 0;
        for (j = 0; j < 9 - i; j++) {
            Palabra *p1 = *h;
            Palabra *p2 = p1->siguiente;
            if (strcmp(p1->caracteres, p2->caracteres) < 0) {
                *h = intercambiar(p1, p2);
                intercambio = 1;
            }
            h = &(*h)->siguiente;
        }
        if (intercambio == 0)
            break;
    }
}

void imprimir_archivo(FILE *archivo, Palabra *lista) {
    Palabra *actual = lista;
    while (actual != NULL) {
        fprintf(archivo, "\n%s", actual->caracteres);
        actual = actual->siguiente;
    }
    fprintf(archivo, "\n\n");
}

void cargarArchivo(FILE *archivo, Palabra *lista) {
    fprintf(archivo, "Lista Original:");
    imprimir_archivo(archivo, lista);
    fflush(archivo);
    fprintf(archivo, "Lista Ordenada:");
    ordenarPalabras(&lista);
    imprimir_archivo(archivo, lista);
    fflush(archivo);
}

