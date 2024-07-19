#include <stdio.h>

int main()
{
	//Leer un archivo
	FILE *pF = fopen("archivo.txt", "r");
	char buffer[255];
	if(pF == NULL)
	{
		printf("No se puede abrir el archivo!\n");
	}
	else
	{
		while(fgets(buffer, 255, pF) != NULL)
		{
			printf("%s", buffer);
		}	
	}
	fclose(pF);
	printf("\n");
	FILE *pF2 = fopen("test.txt", "r");
//	fprintf(pF2, "HOLA");
	if(pF2 == NULL)
	{
		printf("NO SE PUEDE ABRIR EL ARCHIVO\n");
	}
	else
	{
		while(fgets(buffer, 255, pF2) != NULL)
		{
			printf("%s", buffer);
		}
	}
	
	fclose(pF2);
	
	return 0;
}
