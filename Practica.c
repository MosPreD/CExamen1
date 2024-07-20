#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* strcpy y strcmp
char comparacion(char cadena1[], char cadena2[]);
char copiar(char string1[], char string2[]);

int main()
{
	char string1[] = "Yamil";
	char string2[] = "Harika";
	char cadena1[] = "hola";
	char cadena2[] = "hola";
	
	copiar(string1,string2);
	comparacion(cadena1, cadena2);
		
	return 0;
}

char comparacion(char cadena1[], char cadena2[])
{
	int resultado = strcmp(cadena1, cadena2);
	
	if (resultado == 0)
	{
		printf("los strings son iguales\n");
	}
	else
	{
		printf("Los strings son distintos\n");
	}
}

char copiar(char string1[], char string2[])
{
	int resultadoCopia = strcmp(string1, string2);
	strcpy(string1, string2);
	printf("%s\n",string1);	
}*/

/* Paso por referencia
void suma_referencia(int *a, int *b);

int main()
{
	int x= 5, y= 3;
	
	printf("Antes de llamar a suma_referencia: x = %d, y = %d\n", x, y);
	suma_referencia(&x,&y);
	printf("Despues de llamar a suma_referencia: x = %d, y = %d\n", x, y );
	return 0;
}

void suma_referencia(int *a, int *b)
{
	*a = *a + *b;
}*/

/* Paso por valor
void suma_valor(int a, int b);

int main()
{
	int x = 5, y = 3;
	
	printf("Antes de llamar a suma_valor: x = %d, y = %d\n", x, y);
	suma_valor(x,y);
	printf("Despues de llamar a suma_valor: x = %d, y = %d\n", x, y);
	
	return 0;
}

void suma_valor(int a, int b)
{
	a = a + b;
	printf("Cambios en suma_valor: x =%d, y =%d\n", a, b);
}*/

/* Punteros
void jugar(int* x)
{
	*x = 1 + 2 + 3;
}

int main()
{
	int x = 10;
	jugar(&x);
	printf("%d\n", x);
	return 0;
}
*/

/* Struct
struct cuenta {
		char nombre[30];
		char apellido[40];
		int identificador;
		int saldo;
	};
	
void imprimir_datos(struct cuenta *c) {
	printf("El cliente %s %s tiene %d euros en cuenta.\n", c->nombre, c->apellido, c->saldo);
}
	
int main()
{
	struct cuenta c1;
	strcpy(c1.nombre, "Pepito");
	strcpy(c1.apellido, "Perez");
	c1.identificador = 1235;
	c1.saldo = 400;
	imprimir_datos(&c1);
	return 0;
}*/


/* Memoria Dinamica
int main()
{
	printf("Cuantos elementos quieres almacenar ");
	int longitud;
	scanf("%d", &longitud);
	float* valores = (float*) malloc(longitud * sizeof(float));
	if (valores == NULL)
	{
		printf("No tienes tanta memoria.\n");
		return 1;
	}
	int i;
	for(i=0;i<longitud;i++)
	{
		valores[i] = 5.55E5;		
	}
	printf("Todo esta correcto.\n");
	free(valores);
	return 0;
	
}*/
