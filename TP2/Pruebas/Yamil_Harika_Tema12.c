#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct ficha {
    char genero[2];
    char pnombre[50];
    char snombre[50];
    char papellido[50];
    char sapellido[50];
    char nombreyapellido[102];
    char apellidoynombre[102];
    int edad;
    struct ficha* siguiente;
} Ficha;

void cargar_personas(Ficha** lista, int a);
void imprimir_lista(Ficha* lista);
int ordenar_lista(Ficha** lista, int contador);

int main() {
    int n;
    srand(time(NULL));
    n = rand() % 6 + 10;
    Ficha* lista = NULL; 
    cargar_personas(&lista, n);
    printf("Lista cargada:\n");
    imprimir_lista(lista);
    ordenar_lista(&lista, n);
    printf("\nLista ordenada:\n");
    imprimir_lista(lista);
    return 0;
}

void imprimir_lista(Ficha* lista) {
    Ficha* actual = lista;
    while (actual != NULL) {
        printf("\n%s %s %s %s %s %d", actual->genero, actual->pnombre,
               actual->snombre, actual->papellido, actual->sapellido,
               actual->edad);
        actual = actual->siguiente;
    }
}
	

void cargar_personas(Ficha** lista, int a) {
    int i, s;
    char nombres[25], apellidos[50];
    char nombre_hombre[] [25]= { "ADRIAN","ALBERTO","ALEJANDRO","ALVARO","ANDRES","ANGEL","ANTONIO","CARLOS","DANIEL","DAVID","DIEGO","EDUARDO","ENRIQUE","FERNANDO","FRANCISCO","IVAN","JAVIER","JESUS","JOAQUIN","JORGE","JOSE","JUAN","LUIS","MANUEL","MIGUEL","OSCAR","PABLO","PEDRO","RAFAEL","RAMON","RAUL","RUBEN","SANTIAGO","SERGIO","VICENTE","VICTOR"};
	char nombre_mujer[] [25]= { "ANA","ANDREA","ANGELA","ANTONIA","BEATRIZ","CARMEN","CORAL","CRISTINA","DOLORES","ELENA","ENRIQUETA","FRANCISCA","IRENE","ISABEL","JOSEFA","JUANA","JULIA","LAURA","LUCIA","MANUELA","MARIA","MARTA","MERCEDES","MONICA","MONTSERRAT","NURIA","PATRICIA","PAULA","PENELOPE","RAQUEL","ROCIO","ROSA","ROSARIO","SARA","SILVIA","TERESA"};
	char pos_apellidos[] [25]= { "ALONSO","ALVAREZ","BLANCO","CANO","CASTILLO","CASTRO","CORTES","DELGADO","DIAZ","DOMINGUEZ","FERNANDEZ","GARCIA","GARRIDO","GIL","GOMEZ","GONZALEZ","GUERRERO","GUTIERREZ","HERNANDEZ","IGLESIAS","JIMENEZ","LOPEZ","LOZANO","MARIN","MARTIN","MARTINEZ","MEDINA","MOLINA","MORALES","MORENO","MUNOZ","NAVARRO","NUNEZ","ORTEGA","ORTIZ","PEREZ","RAMIREZ","RAMOS","RODRIGUEZ","ROMERO","RUBIO","RUIZ","SANCHEZ","SANTOS","SANZ","SERRANO","SUAREZ","TORRES","VAZQUEZ"};
    for (i = 0; i < a; i++) {
        Ficha* nueva_persona = (Ficha*)malloc(sizeof(Ficha));

        s = rand() % 2;
        if (s == 0) {
            strcpy(nueva_persona->genero, "M");

            s = rand() % 36;
            strcpy(nueva_persona->pnombre, nombre_hombre[s]);

            do {
                s = rand() % 36;
                strcpy(nueva_persona->snombre, nombre_hombre[s]);
            } while (strcmp(nueva_persona->snombre, nueva_persona->pnombre) == 0);
        } else {
            strcpy(nueva_persona->genero, "F");

            s = rand() % 36;
            strcpy(nueva_persona->pnombre, nombre_mujer[s]);

            do {
                s = rand() % 36;
                strcpy(nueva_persona->snombre, nombre_mujer[s]);
            } while (strcmp(nueva_persona->snombre, nueva_persona->pnombre) == 0);
        }

        s = rand() % 49;
        strcpy(nueva_persona->papellido, pos_apellidos[s]);
        s = rand() % 49;
        strcpy(nueva_persona->sapellido, pos_apellidos[s]);

        sprintf(nombres, "%s %s", nueva_persona->pnombre, nueva_persona->snombre);
        sprintf(apellidos, "%s %s", nueva_persona->papellido, nueva_persona->sapellido);
        sprintf(nueva_persona->nombreyapellido, "%s %s", nombres, apellidos);
        sprintf(nueva_persona->apellidoynombre, "%s, %s", apellidos, nombres);

        nueva_persona->edad = rand() % 6 + 20;

        nueva_persona->siguiente = *lista;
        *lista = nueva_persona;
    }
}

struct Ficha* intercambiar(Ficha* ptr1,Ficha* ptr2) 
{ 
    Ficha* tmp = ptr2->siguiente; 
    ptr2->siguiente = ptr1; 
    ptr1->siguiente = tmp; 
    return ptr2; 
} 

int ordenar_lista(Ficha** lista, int contador) { 
    Ficha** h; 
    int i, j, intercambio; 
    char apellidos1[100], apellidos2[100];
    for (i = 0; i <= contador; i++) 
    { 
  
        h = lista; 
        intercambio = 0; 
  
        for (j = 0; j < contador - i - 1; j++)  
        { 
  
            Ficha* p1 = *h; 
            Ficha* p2 = p1->siguiente;
			sprintf(apellidos1, "%s%s", p1->papellido, p1->sapellido);
			sprintf(apellidos2, "%s%s", p2->papellido, p2->sapellido);
            if (strcmp(apellidos1, apellidos2) > 0) 
            { 
  

                *h = intercambiar(p1, p2); 
                intercambio = 1; 
            } 
  
            h = &(*h)->siguiente; 
        } 
  

        if (intercambio == 0) 
            break; 
    } 
} 

