#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char n[9];
	printf("Ingrese un numero de 8 cifras: ");
	scanf("%s", n);

	if(esNumerico(n))
	{
		if(obtenerCifras(n)==8)
		{
			int num = atoi(n);
			printf("El numero ingresado es: %08d\n", num);
			printf("Tiene %d cifras\n", obtenerCifras(n));
			if(esCapicua(n))
			{
				printf("Es capicua\n");
			}
			else
			{
				printf("No es capicua\n");
			}
			convertirNumerosALetras(n);
			printf("Numero convertido a letras: %s\n", n);
		}
		else
		{
			printf("El numero no tiene 8 cifras. Volver a ingresar\n");
			main();
		}
	}
	else
	{
		printf("Solo se admiten valores numericos. Volver a ingresar\n");
		main();
	}
	return 0;
}
	
int obtenerCifras(char* n)
{
	int cifras = 0;
	while (n[cifras] != '\0')
	{
		cifras++;
	}
	return cifras;
}

int esCapicua(char* n)
{
	int inicio = 0;
	int fin = strlen(n) - 1;
	
	while(inicio < fin)
	{
		if(n[inicio] != n[fin])
		{
			return 0;
		}
		inicio++;
		fin--;
	}
	return 1;
}
int esNumerico(char* cadena) 
{
	int i;
    for(i = 0; i < strlen(cadena); i++) 
	{
        if(!isdigit(cadena[i])) 
		{
            return 0;
        }
    }
    return 1;
}
void convertirNumerosALetras(char* n)
{
	int i;
	for(i = 0; i<strlen(n); i++)
	{
		n[i] = 'A' + (n[i] - '0');
	}
}
