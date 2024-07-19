#include <stdio.h>
#include <string.h>

int main ()
{
	//'\0' Caracter Especial
	char nombre[25], concatenado[50], impresion[50], nombre_2[30];
	strcpy(nombre_2,"Juan");
	strcpy(nombre,"Ana"); //String Copy (destino, origen)
	if(strcmp(nombre,nombre_2)==0) //String Compare - Comparacion de Strings
	printf("Ambos textos son iguales\n");
	else
	printf("los textos no son iguales\n");
	
	strcpy(concatenado,nombre);
	int l=strlen(nombre); // String Length
	printf("%s longitud:%d\n", nombre,l);
	strcpy(nombre,"Ana");
	strcat(concatenado," y "); //concatenado
	strcat(concatenado,nombre);
	l=strlen(nombre);
	printf("%s longitud:%d\n", nombre,l);
	printf("Concatenado: %s\n",concatenado);
	sprintf(impresion,"concatenado:%s un numero cualquiera %d",concatenado,50); //De donde se carga, Texto, 
	printf("%s\n",impresion);
	return 0;
}

