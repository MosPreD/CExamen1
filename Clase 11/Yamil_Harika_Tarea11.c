#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>

typedef struct NODO {
    int numero;
    struct NODO *siguiente;
} Nodo;

/* Agrega un nodo a lista enlazada */
void agregar_nodo(Nodo **puntero) {
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo)); // se crea un nodo y este espacio en la memoria se enlaza
    nodo->siguiente = *puntero;
    *puntero = nodo;
    nodo->numero = 1 + rand() % 4000;
}

/* Tipo de dato de la funcion ** porque se devolvera una posicion de memoria, donde se espera un puntero en este caso la funcion remover. */
Nodo **buscar(Nodo **nodo, int i) {
    /* Busca la posicion del nodo que contiene el valor sugerido, dicha posicion se utilizar para eliminar en la otra funcion */
    while (*nodo != NULL) {
        if ((*nodo)->numero == i) {
            return nodo;
        }
        nodo = &(*nodo)->siguiente;
    }
    return NULL;
}

void ordenar_burbuja(Nodo *inicio) 
{
	int intercambiado;
	Nodo *ptr1;
	Nodo *lptr = NULL;
	if (inicio == NULL)
		return;
		do 
		{
			intercambiado = 0;
			ptr1 = inicio;

	while (ptr1->siguiente != lptr) 
	{
		if (ptr1->numero > ptr1->siguiente->numero) 
		{
			int temp = ptr1->numero;
			ptr1->numero = ptr1->siguiente->numero;
			ptr1->siguiente->numero = temp;
			intercambiado = 1;
		}
		ptr1 = ptr1->siguiente;
	}
	lptr = ptr1;
	} while (intercambiado);
}

void imprimir(Nodo *nodo) {
    if (nodo == NULL) {
        printf("lista esta vacia\n");
        return;
    }
    /* Recorre la lista para ir imprimiendo los numeros generados al azar */
    while (nodo != NULL) {
        printf("Pos. Mem: %p Pos. sig: %p Valor cont:%d\n", nodo, nodo->siguiente, nodo->numero);
        nodo = nodo->siguiente;
    }
    printf("\n");
}

int main() 
{
	Nodo *nodo = NULL;
	srand(time(NULL));
	int i, num;

/* Se cargan los elementos al azar de la lista, en este caso 5 elementos */
	for (i = 0; i < 5; i++) {
	agregar_nodo(&nodo);
	printf("\n\n");
	imprimir(nodo);
	}
		printf("\n\nLista cargada\n");
		imprimir(nodo);

	ordenar_burbuja(nodo);
	printf("\n\nLista ordenada\n");
	imprimir(nodo);
}

