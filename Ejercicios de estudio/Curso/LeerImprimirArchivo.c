#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *archivo;
	
	archivo = fopen("ejemplo.txt", "w");
	if (archivo == NULL)
	{
		printf("No se pudo abrir el archivo\n");
		return 1;
	}
	fprintf(archivo, "Hola!\n");
	fprintf(archivo, "Archivo de ejemplo\n");
	
	fclose(archivo);
	
	archivo = fopen("ejemplo.txt", "r");
	if (archivo == NULL)
	{
		printf("no se pudo abrir el archivo\n");
		return 1;
	}	
	char lineas[100];
	while (fgets(lineas, sizeof(lineas), archivo) != NULL)
	{
		printf("%s", lineas);
	}
	fclose(archivo);

	return 0;
}
