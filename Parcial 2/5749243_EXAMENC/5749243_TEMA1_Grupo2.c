#include <stdio.h>

void menu();
int strlenEmulado(char *str);
void strcpyEmulado(char *dest, char *src);
void strcatEmulado(char *dest, char *src);
int strcmpEmulado(char *str1, char *str2);

int main()
{
	printf("Programa de emulacion de funciones de string.h\n");
	menu();
	
	return 0;
}
	
void menu() {
    char cadena1[100], cadena2[100];
    int opcion;

    do {
        printf("\nMenu:\n");
        printf("1. Longitud de una cadena\n");
        printf("2. Copiar una cadena\n");
        printf("3. Concatenar dos cadenas\n");
        printf("4. Comparar dos cadenas\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese una cadena: ");
                scanf("%s", cadena1);
                printf("La longitud de la cadena es: %d\n", strlenEmulado(cadena1));
                break;
            case 2:
                printf("Ingrese una cadena origen: ");
                scanf("%s", cadena1);
                printf("Copiando la cadena...\n");
                strcpyEmulado(cadena2, cadena1);
                printf("La cadena copiada es: %s\n", cadena2);
                break;
            case 3:
                printf("Ingrese la primera cadena: ");
                scanf("%s", cadena1);
                printf("Ingrese la segunda cadena: ");
                scanf("%s", cadena2);
                printf("Concatenando las cadenas...\n");
                strcatEmulado(cadena1, cadena2);
                printf("La cadena concatenada es: %s\n", cadena1);
                break;
            case 4:
                printf("Ingrese la primera cadena: ");
                scanf("%s", cadena1);
                printf("Ingrese la segunda cadena: ");
                scanf("%s", cadena2);
                if (strcmpEmulado(cadena1, cadena2) == 0) {
                    printf("Las cadenas son iguales.\n");
                } else {
                    printf("Las cadenas son diferentes.\n");
                }
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 5);
}

int strlenEmulado(char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

void strcpyEmulado(char *dest, char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; 
}

void strcatEmulado(char *dest, char *src) {
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; 
}

int strcmpEmulado(char *str1, char *str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            return 0; 
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
