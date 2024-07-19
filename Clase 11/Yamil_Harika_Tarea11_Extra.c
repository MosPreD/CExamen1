#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>

typedef struct NODO {
    int numero;
    struct NODO *siguiente;
} Nodo;

void agregar_nodo(Nodo **puntero) {
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->siguiente = *puntero;
    *puntero = nodo;
    nodo->numero = 1 + rand() % 4000;
}

Nodo **buscar(Nodo **nodo, int i) {
    while (*nodo != NULL) {
        if ((*nodo)->numero == i) {
            return nodo;
        }
        nodo = &(*nodo)->siguiente;
    }
    return NULL;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

Nodo *partition(Nodo *bajo, Nodo *alto) {
    int pivot = alto->numero;
    Nodo *i = bajo->siguiente;
    Nodo *j = bajo;
    while (j != alto) {
        if (j->numero < pivot) {
            swap(&(i->numero), &(j->numero));
            i = i->siguiente;
        }
        j = j->siguiente;
    }
    swap(&(i->numero), &(alto->numero));
    return i;
}

void quickSort(Nodo *bajo, Nodo *alto) {
    if (bajo != NULL && alto != NULL && bajo != alto && bajo != alto->siguiente) {
        Nodo *p = partition(bajo, alto);
        quickSort(bajo, p);
        quickSort(p->siguiente, alto);
    }
}

void imprimir(Nodo *nodo) {
    if (nodo == NULL) {
        printf("La lista está vacía\n");
        return;
    }
    while (nodo != NULL) {
        printf("Pos. Mem: %p Pos. sig: %p Valor cont:%d\n", nodo, nodo->siguiente, nodo->numero);
        nodo = nodo->siguiente;
    }
    printf("\n");
}

int main() {
    Nodo *nodo = NULL;
    srand(time(NULL));
    int i = 0;

    while (i < 5) {
        agregar_nodo(&nodo);
        printf("\n\n");
        imprimir(nodo);
        i++;
    }
    
    printf("\n\nLista cargada\n");
    imprimir(nodo);

    Nodo *temp = nodo;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    quickSort(nodo, temp);

    printf("\n\nLista ordenada\n");
    imprimir(nodo);

    return 0;
}

