#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct PERSONA {
    char nombre_alumno[20];
    int edad, ci;
    float examenes[5];
} Persona;

void generar_ci(Persona lista[], int i) {
    int ci_aux, b, j;
    do {
        b = 0;
        ci_aux = 2500000 + rand()%1872*rand()%1872;
        for (j = 0; j < i; j++) {
            if (lista[j].ci == ci_aux)
                b = 1;
        }
    } while (b);
    lista[i].ci = ci_aux;
}

void generar_notas(Persona lista[], int num_alumnos) {
    int i, j;
    for (i = 0; i < num_alumnos; i++) {
        lista[i].edad = 20 + rand() % 21;
        generar_ci(lista, i);
        sprintf(lista[i].nombre_alumno, "Alumno %d", i + 1);
        for (j = 0; j < 4; j++) {
            if (rand() % 2 == 0)
                lista[i].examenes[j] = 60 + rand() % 41;
            else
                lista[i].examenes[j] = rand() % 60;
        }
        float sum = 0;
        for (j = 0; j < 4; j++) {
            sum += lista[i].examenes[j];
        }
        lista[i].examenes[4] = sum / 4;
    }
}

void imprimir_ficha_alumno(Persona alumno) {
    printf("Nombre: %s\n", alumno.nombre_alumno);
    printf("Edad: %d\n", alumno.edad);
    printf("C.I: %d\n", alumno.ci);
    printf("Parcial 1: %.1f\n", alumno.examenes[0]);
    printf("Parcial 2: %.1f\n", alumno.examenes[1]);
    printf("Parcial 3: %.1f\n", alumno.examenes[2]);
    printf("Parcial 4: %.1f\n", alumno.examenes[3]);
    printf("Promedio Materia: %.1f\n\n", alumno.examenes[4]);
}

void imprimir_promedio_general(Persona lista[], int num_alumnos) {
    int i, j;
    float sum[5] = {0};
    for (i = 0; i < num_alumnos; i++) {
        for (j = 0; j < 5; j++) {
            sum[j] += lista[i].examenes[j];
        }
    }
    printf("Promedio general de cada materia:\n");
    for (j = 0; j < 4; j++) {
        printf("Materia %d: %.1f\n", j + 1, sum[j] / num_alumnos);
    }
    printf("Promedio general final: %.1f\n\n", sum[4] / num_alumnos);
}

void generar_fichas_alumnos(Persona lista[], int num_alumnos) {
    int i;
    for (i = 0; i < num_alumnos; i++) {
        printf("Ficha del Alumno %d:\n", i + 1);
        imprimir_ficha_alumno(lista[i]);
    }
}

int main() {
    srand(time(NULL));
    int num_alumnos;
    printf("Ingrese la cantidad de alumnos (entre 10 y 40): ");
    scanf("%d", &num_alumnos);
    getchar();
    if (num_alumnos < 10 || num_alumnos > 40) {
        printf("Cantidad de alumnos no valida. Debe estar entre 10 y 40.\n");
        main();
        return 1;
    }
    Persona lista_alumnos[num_alumnos];
    generar_notas(lista_alumnos, num_alumnos);
    int opcion;
    printf("Seleccione una opcion:\n");
    printf("1. Mostrar todos los alumnos\n");
    printf("2. Seleccionar un alumno por numero de lista\n");
    scanf("%d", &opcion);
    getchar();
    switch (opcion) {
        case 1:
            printf("\n");
            generar_fichas_alumnos(lista_alumnos, num_alumnos);
            imprimir_promedio_general(lista_alumnos, num_alumnos);
            break;
        case 2:
            printf("\n");
            int numero_lista;
            printf("Ingrese el numero de lista del alumno: ");
            scanf("%d", &numero_lista);
            if (numero_lista < 1 || numero_lista > num_alumnos) {
                printf("Numero de lista no valido.\n");
                main();
                return 1;
            }
            imprimir_ficha_alumno(lista_alumnos[numero_lista - 1]);
            break;
        default:
            printf("Opcion no valida.\n");
            main();
            break;
    }
    return 0;
}
