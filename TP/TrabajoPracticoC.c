#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {
    int cablesOrdenados[20];
    bool ordenado;
    int pasos;
} AlumnoCables;

void textoInicio(char *alumnos[]);
void opciones(char *alumnos[], AlumnoCables *alumnosCablesOrdenados);
void ordenarSeparado(char *alumnos[], AlumnoCables *alumnosCablesOrdenados);
void ordenarCables(char *alumno, int numCables, int *cables, int *pasos, bool *ordenado);
void imprimirCables(char *alumno, int numCables, int *cables);
void ordenarTodo(char *alumnos[], AlumnoCables *alumnosCablesOrdenados);
void finalizar();

int main() {
    srand(time(NULL));
    int i;
    char *alumnos[] = {"Agustin", "Beatriz", "Carlos", "Daniela", "Eugenio", "Fabiola", "Gustavo", "Hilda", "Ignacio", "Juan"};
    AlumnoCables alumnosCablesOrdenados[10];
    for (i = 0; i < 10; i++) {
        alumnosCablesOrdenados[i].ordenado = false;
        alumnosCablesOrdenados[i].pasos = 0;
    }
    textoInicio(alumnos);
    opciones(alumnos, alumnosCablesOrdenados);
    return 0;
}

void textoInicio(char *alumnos[]) {
    int i;
    printf("Alumnos con cable:\n"); 
    for (i = 0; i < 10; i++) {
        printf("%d-\t %s\n", i + 1, alumnos[i]);
    }
}

void opciones(char *alumnos[], AlumnoCables *alumnosCablesOrdenados) {
    int opcion;
    printf("\nOpciones:\n");
    printf("1-Desea ver los cables de un alumno\n");
    printf("2-Desea ordenar los cables de todos los alumnos\n");
    printf("3-Salir\nOpcion: ");
    scanf("%i", &opcion);
    getchar();
    switch(opcion) {
        case 1:
            ordenarSeparado(alumnos, alumnosCablesOrdenados);
            break;
        case 2:
            ordenarTodo(alumnos, alumnosCablesOrdenados);
            break;
        case 3:
            finalizar();
            break;
        default:
            printf("Valor ingresado incorrecto. Vuelva a cargar valor(1-3)\n");
            opciones(alumnos,alumnosCablesOrdenados);
    }
}

void ordenarSeparado(char *alumnos[], AlumnoCables *alumnosCablesOrdenados) {
    int seleccionAlumno, i;
    printf("Que alumno desea ver? (1-10): ");
    scanf("%i", &seleccionAlumno);
    getchar();
    if (seleccionAlumno < 1 || seleccionAlumno > 10) {
        printf("\nNumero de alumno no valido. Vuelva a ingresar\n");
        opciones(alumnos,alumnosCablesOrdenados);
    }
    int numCables = 20;
    int cables[numCables];
    for (i = 0; i < numCables; i++) {
        cables[i] = 1 + rand() % 35;
    }
    printf("\nCables de %s\n", alumnos[seleccionAlumno - 1]);
    
    if (alumnosCablesOrdenados[seleccionAlumno - 1].ordenado) {
        printf("Los cables ya estaban ordenados en la iteración anterior.\n");
        imprimirCables(alumnos[seleccionAlumno - 1], numCables, alumnosCablesOrdenados[seleccionAlumno - 1].cablesOrdenados);
    } else {
        imprimirCables(alumnos[seleccionAlumno - 1], numCables, cables);
        printf("\nDesea ordenar los cables? (1-Si, 2-No): ");
        int opcion;
        scanf("%d", &opcion);
        getchar();
        if (opcion == 1) {
            int pasos = 0;
            bool ordenado = false;
            ordenarCables(alumnos[seleccionAlumno - 1], numCables, cables, &pasos, &ordenado);
            for (i = 0; i < numCables; i++) {
                alumnosCablesOrdenados[seleccionAlumno - 1].cablesOrdenados[i] = cables[i];
            }
            alumnosCablesOrdenados[seleccionAlumno - 1].ordenado = true;
            alumnosCablesOrdenados[seleccionAlumno - 1].pasos = pasos;
        }
    }
    opciones(alumnos,alumnosCablesOrdenados);
}

void ordenarCables(char *alumno, int numCables, int *cables, int *pasos, bool *ordenado) {
    int i, j, temp;
    while (!(*ordenado)) {
        *ordenado = true;
        for (i = 0; i < numCables - 1; i++) {
            if (cables[i] > cables[i + 1]) {
                temp = cables[i];
                cables[i] = cables[i + 1];
                cables[i + 1] = temp;
                (*pasos)++;
                *ordenado = false;
                printf("\033[H\033[J");
                printf("Paso %d:\n", *pasos);
                imprimirCables(alumno, numCables, cables);
                usleep(100000);
            }
        }
    }
    printf("Cantidad de Pasos: %d\n", *pasos);
}

void imprimirCables(char *alumno, int numCables, int *cables) {
    int i, j;
    printf("Cables de %s\n", alumno);
    printf("=============\n");
    for (i = 0; i < numCables; i++) {
        for (j = 0; j < cables[i]; j++) {
            printf("*");
        }
        printf(" %d\n", cables[i]);
    }
}

void ordenarTodo(char *alumnos[], AlumnoCables *alumnosCablesOrdenados) {
    int i, j;
    printf("Ordenando los cables de todos los alumnos...\n");
    for (i = 0; i < 10; i++) {
        int numCables = 20;
        int cables[numCables];
        for (j = 0; j < numCables; j++) {
            cables[j] = 1 + rand() % 35;
        }
        printf("\nCables de %s\n", alumnos[i]);
        if (alumnosCablesOrdenados[i].ordenado) {
            printf("Paso %d:\n", alumnosCablesOrdenados[i].pasos);
            imprimirCables(alumnos[i], numCables, alumnosCablesOrdenados[i].cablesOrdenados);
            printf("Cantidad de Pasos: %d\n", alumnosCablesOrdenados[i].pasos);
            printf("Presione Enter para continuar con el siguiente alumno...");
            getchar();
        } else {
            int pasos = 0;
            bool ordenado = false;
            ordenarCables(alumnos[i], numCables, cables, &pasos, &ordenado);
            for (j = 0; j < numCables; j++) {
                alumnosCablesOrdenados[i].cablesOrdenados[j] = cables[j];
            }
            alumnosCablesOrdenados[i].ordenado = true;
            alumnosCablesOrdenados[i].pasos = pasos;
            printf("\nPaso %d:\n", pasos);
            imprimirCables(alumnos[i], numCables, cables);
            printf("Cantidad de Pasos: %d\n", pasos);
            printf("Presione Enter para continuar con el siguiente alumno...");
            getchar();
        }
    }
    printf("\nTodos los cables han sido ordenados.\n");
    opciones(alumnos, alumnosCablesOrdenados);
}

void finalizar() {
    printf("Finalizando programa.\n");
}
