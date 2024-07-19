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
    int ci;
    char ciudad[25];
    struct ficha* siguiente;
} Ficha;

void menu();
void cargar_personas(Ficha** lista, int a);
int generarNroCedula(Ficha* lista);
void imprimir_lista(Ficha* lista, int criterio);
void ordenar_lista(Ficha** lista, int contador, int criterio);

int comparar_inscripcion(Ficha* a, Ficha* b);
int comparar_ci(Ficha* a, Ficha* b);
int comparar_apellido(Ficha* a, Ficha* b);
int comparar_edad(Ficha* a, Ficha* b);

void contar_edad(Ficha* lista);
void contar_primos(Ficha* lista);
void contar_hermanos(Ficha* lista);
void contar_ciudad(Ficha* lista);
void contar_tocayos(Ficha* lista);
void contar_genero(Ficha* lista);

int main() {
    srand(time(NULL));
    menu();
    return 0;
}

void menu() {
    int opcion, criterio;
    Ficha* lista = NULL;
    int n = 0;
    while (1) {
        printf("\nMenu de seleccion de ficha de alumnos:\n");
        printf("\nSeleccione una opcion \n");
        printf("1-Generar alumnos\n2-Menu de impresion\n");
        printf("3-Cuantos alumnos tienen la misma edad\n");
        printf("4-Cuantos alumnos son primos (tienen un apellido en comun)\n");
        printf("5-Cuantos alumnos son hermanos (tienen ambos apellidos en comun en el mismo orden)\n");
        printf("6-Cuantos alumnos son de la misma ciudad\n");
        printf("7-Cuantos alumnos son tocayos (al menos un nombre es igual al de otro)\n");
        printf("8-Cuantos varones y cuantas mujeres hay en la lista\n");
        printf("9-Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        system("cls");
        switch (opcion) {
            case 1:
                if (lista == NULL) {
                    printf("Opcion %i seleccionada: Generar alumnos\n", opcion);
                    printf("Ingrese la cantidad de alumnos que desea cargar(de 60 a 70): \n");
                    scanf("%i", &n);
                    system("cls");
                    if (n >= 60 && n <= 70) {
                        cargar_personas(&lista, n);
                        printf("Lista cargada:\n");
                        imprimir_lista(lista, 0);
                    } else {
                        printf("Cantidad de alumnos incorrecta, vuelva a cargar.\n");
                    }
                } else {
                    printf("La lista de alumnos ya ha sido generada anteriormente.\n");
                }
                break;
            case 2:
                printf("Opcion %i seleccionada: Menu de impresion de alumnos\n", opcion);
                printf("Seleccione el criterio de ordenamiento:\n");
                printf("1- Por inscripcion\n2- Por c.i\n3- Por apellido\n4- Por edad\n");
                scanf("%d", &criterio);
                system("cls");
                ordenar_lista(&lista, n, criterio);
                imprimir_lista(lista, criterio);
                break;
            case 3:
                printf("Opcion %i seleccionada: Cuantos alumnos tienen la misma edad\n", opcion);
                contar_edad(lista);
                break;
            case 4:
                printf("Opcion %i seleccionada: Cuantos alumnos son primos\n", opcion);
                contar_primos(lista);
                break;
            case 5:
                printf("Opcion %i seleccionada: Cuantos alumnos son hermanos\n", opcion);
                contar_hermanos(lista);
                break;
            case 6:
                printf("Opcion %i seleccionada: Cuantos alumnos son de la misma ciudad\n", opcion);
                contar_ciudad(lista);
                break;
            case 7:
                printf("Opcion %i seleccionada: Cuantos alumnos son tocayos\n", opcion);
                contar_tocayos(lista);
                break;
            case 8:
                printf("Opcion %i seleccionada: Cuantos varones y cuantas mujeres hay en la lista\n", opcion);
                contar_genero(lista);
                break;
            case 9:
                printf("Opcion %i seleccionada: Saliendo del programa\n", opcion);
                exit(0);
                break;
            default:
                printf("Opcion invalida, vuelva a ingresar.\n");
                menu();
                break;
        }
    }
}

void imprimir_lista(Ficha* lista, int criterio) {
    Ficha* actual = lista;
    while (actual != NULL) 
	{
		if (criterio !=0)
		{
			printf("%i ", criterio);
		}
        printf("%s %s %s %s %i %i %s\n", actual->pnombre,
               actual->snombre, actual->papellido, actual->sapellido,
               actual->edad, actual->ci, actual->ciudad);
        actual = actual->siguiente;
    }
}

void cargar_personas(Ficha** lista, int a) {
    int i, s;
    char nombres[25], apellidos[50];
    char nombre_hombre[][25] = { "ADRIAN","ALBERTO","ALEJANDRO","ALVARO","ANDRES","ANGEL","ANTONIO","CARLOS","DANIEL","DAVID","DIEGO","EDUARDO","ENRIQUE","FERNANDO","FRANCISCO","IVAN","JAVIER","JESUS","JOAQUIN","JORGE","JOSE","JUAN","LUIS","MANUEL","MIGUEL","OSCAR","PABLO","PEDRO","RAFAEL","RAMON","RAUL","RUBEN","SANTIAGO","SERGIO","VICENTE","VICTOR" };
    char nombre_mujer[][25] = { "ANA","ANDREA","ANGELA","ANTONIA","BEATRIZ","CARMEN","CORAL","CRISTINA","DOLORES","ELENA","ENRIQUETA","FRANCISCA","IRENE","ISABEL","JOSEFA","JUANA","JULIA","LAURA","LUCIA","MANUELA","MARIA","MARTA","MERCEDES","MONICA","MONTSERRAT","NURIA","PATRICIA","PAULA","PENELOPE","RAQUEL","ROCIO","ROSA","ROSARIO","SARA","SILVIA","TERESA" };
    char pos_apellidos[][25] = { "ALONSO","ALVAREZ","BLANCO","CANO","CASTILLO","CASTRO","CORTES","DELGADO","DIAZ","DOMINGUEZ","FERNANDEZ","GARCIA","GARRIDO","GIL","GOMEZ","GONZALEZ","GUERRERO","GUTIERREZ","HERNANDEZ","IGLESIAS","JIMENEZ","LOPEZ","LOZANO","MARIN","MARTIN","MARTINEZ","MEDINA","MOLINA","MORALES","MORENO","MUNOZ","NAVARRO","NUNEZ","ORTEGA","ORTIZ","PEREZ","RAMIREZ","RAMOS","RODRIGUEZ","ROMERO","RUBIO","RUIZ","SANCHEZ","SANTOS","SANZ","SERRANO","SUAREZ","TORRES","VAZQUEZ" };
    char ciudad[][25] = { "ASUNCION","LAMBARE","CAACUPE","ITAUGUA","MARIANO ROQUE ALONSO","CAPIATA","LUQUE","SAN LORENZO" };
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

        s = rand() % 8;
        strcpy(nueva_persona->ciudad, ciudad[s]);

        nueva_persona->ci = generarNroCedula(*lista);

        nueva_persona->siguiente = *lista;
        *lista = nueva_persona;
    }
}

struct Ficha* intercambiar(Ficha* ptr1, Ficha* ptr2) {
    Ficha* tmp = ptr2->siguiente;
    ptr2->siguiente = ptr1;
    ptr1->siguiente = tmp;
    return ptr2;
}

void ordenar_lista(Ficha** lista, int contador, int criterio) {
    Ficha** h;
    int i, j, intercambio;

    for (i = 0; i <= contador; i++) {
        h = lista;
        intercambio = 0;

        for (j = 0; j < contador - i - 1; j++) {
            Ficha* p1 = *h;
            Ficha* p2 = p1->siguiente;

            int resultado_comparacion;
            switch (criterio) {
                case 1:
                    resultado_comparacion = comparar_inscripcion(p1, p2);
                    break;
                case 2:
                    resultado_comparacion = comparar_ci(p1, p2);
                    break;
                case 3:
                    resultado_comparacion = comparar_apellido(p1, p2);
                    break;
                case 4:
                    resultado_comparacion = comparar_edad(p1, p2);
                    break;
                default:
                    resultado_comparacion = 0;
            }

            if (resultado_comparacion > 0) {
                *h = intercambiar(p1, p2);
                intercambio = 1;
            }

            h = &(*h)->siguiente;
        }

        if (intercambio == 0)
            break;
    }
}

int comparar_inscripcion(Ficha* a, Ficha* b) {
    return 0; 
}

int comparar_ci(Ficha* a, Ficha* b) {
    return a->ci - b->ci;
}

int comparar_apellido(Ficha* a, Ficha* b) {
    char apellidos1[100], apellidos2[100];
    sprintf(apellidos1, "%s%s", a->papellido, a->sapellido);
    sprintf(apellidos2, "%s%s", b->papellido, b->sapellido);
    return strcmp(apellidos1, apellidos2);
}

int comparar_edad(Ficha* a, Ficha* b) {
    return a->edad - b->edad;
}

int generarNroCedula(Ficha* lista) {
    int ci = 0, i = 0, unico;
    do {
        unico = 1;
        ci = 2500000 + ((rand() % 1871) * (rand() % 1871) - 641);
        Ficha* actual = lista;
        while (actual != NULL) {
            if (actual->ci == ci) {
                unico = 0;
                break;
            }
            actual = actual->siguiente;
        }
    } while (!unico);
    return ci;
}





void contar_edad(Ficha* lista) {
	int i;
    int contador[100] = {0}; // si pongo que la edad es menor a 100 imprime edades mayores a 25 no se por que
    Ficha* actual = lista;
    while (actual != NULL) {
        contador[actual->edad]++;
        actual = actual->siguiente;
    }
    for (i = 0; i < 100; i++) {
        if (contador[i] > 1) {
            printf("Edad %d: %d alumnos\n", i, contador[i]);
        }
    }
}

void contar_primos(Ficha* lista) {
    int contador = 0;
    Ficha* actual1 = lista;
    while (actual1 != NULL) {
        Ficha* actual2 = actual1->siguiente;
        while (actual2 != NULL) {
            if ((strcmp(actual1->papellido, actual2->papellido) == 0 ||
                strcmp(actual1->papellido, actual2->sapellido) == 0 ||
                strcmp(actual1->sapellido, actual2->papellido) == 0 ||
                strcmp(actual1->sapellido, actual2->sapellido) == 0) &&
                actual1 != actual2) { // Asegurarse de no contar el mismo alumno dos veces
                contador++;
                break; // Salir del bucle interno una vez que se cuenta un alumno primo
            }
            actual2 = actual2->siguiente;
        }
        actual1 = actual1->siguiente;
    }
    printf("Cantidad de alumnos que son primos: %d\n", contador);
}


void contar_hermanos(Ficha* lista) {
    int contador = 0;
    Ficha* actual1 = lista;
    while (actual1 != NULL) {
        Ficha* actual2 = actual1->siguiente;
        while (actual2 != NULL) {
            if (strcmp(actual1->papellido, actual2->papellido) == 0 &&
                strcmp(actual1->sapellido, actual2->sapellido) == 0) {
                contador++;
            }
            actual2 = actual2->siguiente;
        }
        actual1 = actual1->siguiente;
    }
    printf("Cantidad de alumnos que son hermanos: %d\n", contador);
}

void contar_ciudad(Ficha* lista) {
	int i;
    int contador[8] = {0}; // Asumiendo que hay 8 ciudades diferentes
    char ciudades[][25] = { "ASUNCION","LAMBARE","CAACUPE","ITAUGUA","MARIANO ROQUE ALONSO","CAPIATA","LUQUE","SAN LORENZO" };
    Ficha* actual = lista;
    while (actual != NULL) {
        for (i = 0; i < 8; i++) {
            if (strcmp(actual->ciudad, ciudades[i]) == 0) {
                contador[i]++;
            }
        }
        actual = actual->siguiente;
    }
    for (i = 0; i < 8; i++) {
        printf("Ciudad %s: %d alumnos\n", ciudades[i], contador[i]);
    }
}

void contar_tocayos(Ficha* lista) {
    int contador = 0;
    Ficha* actual1 = lista;
    while (actual1 != NULL) {
        Ficha* actual2 = actual1->siguiente;
        while (actual2 != NULL) {
            if (strcmp(actual1->pnombre, actual2->pnombre) == 0 ||
                strcmp(actual1->snombre, actual2->snombre) == 0) {
                contador++;
            }
            actual2 = actual2->siguiente;
        }
        actual1 = actual1->siguiente;
    }
    printf("Cantidad de alumnos que son tocayos: %d\n", contador);
}

void contar_genero(Ficha* lista) {
    int varones = 0, mujeres = 0;
    Ficha* actual = lista;
    while (actual != NULL) {
        if (strcmp(actual->genero, "M") == 0) {
            varones++;
        } else if (strcmp(actual->genero, "F") == 0) {
            mujeres++;
        }
        actual = actual->siguiente;
    }
    printf("Cantidad de varones: %d\n", varones);
    printf("Cantidad de mujeres: %d\n", mujeres);
}

