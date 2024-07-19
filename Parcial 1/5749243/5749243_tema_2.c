#include <stdio.h>

void opciones();
int suma();
int resta();
int multiplicacion();
int division();
int cargaNumeros();

int main()
{
	opciones();
	return 0;
}
void opciones()
{
	int opcion;
	printf("Menu\n");
	printf("Que operacion de fracciones desea realizar?\n", opcion);
	printf("1-\tSuma (+)\n");
	printf("2-\tResta (-)\n");
	printf("3-\tMultiplicacion (*)\n");
	printf("4-\tDivision (/)\n");
	scanf("%i",&opcion);
	getchar();
	printf("Opcion: %d\n", opcion);
	switch(opcion)
	{
		case 1: suma();
			break;
		case 2:	resta();
			break;
		case 3: multiplicacion();
			break;
		case 4: division();
			break;
		default: printf("Valor ingresado incorrecto. Vuelva a cargar valor(1-4)\n");
			opciones();
	}
}
int suma()
{
	printf("Opcion suma\n");
	cargaNumeros();
}
int resta()
{
	printf("Opcion resta\n");
	cargaNumeros();
}
int multiplicacion()
{
	printf("Opcion multiplicacion\n");
	cargaNumeros();
}
int division()
{
	printf("Opcion division\n");
	cargaNumeros();
}
int cargaNumeros(int x, int y, int m, int n)
{
	printf("Ingrese la primera fraccion\n");
	printf("Numerador:\n");
	scanf("%i",&x);
	printf("Denominador:\n");
	scanf("%i",&y);
	printf("\nAhora cargue la segunda fraccion\n");
	printf("\nNumerador(2):\n");
	scanf("%i",&m);
	printf("Denominador(2):\n");
	scanf("%i",&n);
	return x,y,m,n;
}

//--------


//numerador1/denominador1 operador numerador2/denominador2 a lo que debe imprimir
//numerador1/denominador1 operador numerador2/denominador2 =
//numerador_res/denominador_res Ej
//Entrada: 45/70 + 18/20
//Salida: 45/70 + 18/20 =
//54/35
