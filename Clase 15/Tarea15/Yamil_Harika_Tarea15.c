#include <stdio.h>
#include <string.h>
#include "colores.h"

char* obtenerColor(char* color) 
{
    if (strcmp(color, "ROJO") == 0) 
	{
        return ROJO;
    } else if (strcmp(color, "VERDE") == 0) 
	{
        return VERDE;
    } else if (strcmp(color, "AZUL") == 0) 
	{
        return AZUL;
    } else if (strcmp(color, "AMARILLO") == 0) 
	{
        return AMARILLO;
    } 
	else if (strcmp(color, "CIAN") == 0) 
	{
        return CIAN;
    } 
	else 
	{
        return reset;
    }
}
int main() 
{
	system("color 11");
	char palabras[5][100];
	char colores[5][10];
	int i;
	printf("Lista de colores:" ROJO "ROJO" VERDE " VERDE" AZUL " AZUL" AMARILLO " AMARILLO" CIAN " CIAN\n" reset);
	printf("*LOS COLORES DEBEN ESTAR EN MAYUSCULA!*\n");
    for (i = 0; i < 5; i++) 
	{
    	printf("Ingrese Palabra: \n");
        scanf("%s", palabras[i]);
        printf("Ingrese Color: \n");
        scanf("%s", colores[i]);
    }
    for (i = 0; i < 5; i++) {
        printf("%s%s%s ", obtenerColor(colores[i]), palabras[i], reset);
    }
    printf("\n");
    return 0;
}

