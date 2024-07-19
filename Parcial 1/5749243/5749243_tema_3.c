#include <stdio.h>

int esBisiesto(int a);
int calcularDiaSemana(int d, int m, int A, int D);
void imprimirDiaSemana(int D);
void imprimirDias(int A, int D);

int main() {
    int d, m, A; 
    printf("Ingrese la fecha dd/mm/aaaa:\n");
    scanf("%d/%d/%d", &d, &m, &A);
    int D = calcularDiaSemana(d, m, A, D);
    imprimirDiaSemana(D);
    printf(" %d/%d/%d\n", d, m, A);
    imprimirDias(A, D);
    return 0;
}
int esBisiesto(int A) {
    return ((A % 4 == 0 && A % 100 != 0) || (A % 400 == 0));
}

int calcularDiaSemana(int d, int m, int A, int D) {
    int diasMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int diasBisiesto[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    int DM = 0;
	int i;	
    for(i = 1; i < m; i++) {
        if (esBisiesto(A))
            DM += diasBisiesto[i];
        else
            DM += diasMes[i];
    }
    if (m > 2 && esBisiesto(A))
        DM++;
        d=((A-1)*365 + (A-1)/4-(3*((A-1)/100+1)/4)+DM+D)%7;
    return d;
}

void imprimirDiaSemana(int D) {
    printf("Dia ");
    switch(D) {
        case 0: 
            printf("Domingo"); 
            break;
        case 1: 
            printf("Lunes"); 
            break;
        case 2: 
            printf("Martes"); 
            break;
        case 3: 
            printf("Miercoles"); 
            break;
        case 4: 
            printf("Jueves"); 
            break;
        case 5: 
            printf("Viernes"); 
            break;
        case 6: 
            printf("Sabado"); 
            break;
        default: 
            printf("Valor ingresado incorrecto.\n"); 
            break;
    }
}
void imprimirDias(int A, int D) {
    char *diasSemana[] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *meses[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    int dTotal = esBisiesto(A) ? 366 : 365;
    int m;
    for (m = 0; m < 12; m++) {
        if (m == 1 && esBisiesto(A)) {
            diasMes[m] = 29;
        }
        int d;
        for (d = 1; d <= diasMes[m]; d++) {
            printf("%s, %d de %s de %d\n", diasSemana[D], d, meses[m], A);
            D = (D + 1) % 7;
        }
    }
    printf("Cantidad de dias: %d\n", dTotal);
}

