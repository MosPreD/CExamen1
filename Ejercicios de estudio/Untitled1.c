#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cerar(int matriz[3][3]);
void imprimir(int matriz[3][3]);

main()
{
	srand(time(NULL));
	printf("Hola mundo!\n");
	printf("Estudio!\n");
	int vector[3];
	printf("Hora de cargar con numeros pseudo aleatorias al vector!\n");
	int i=0, j=0;
	for(i=0;i<=3;i++)
	{
		vector[i]=rand()%10;
		printf("Numeros cargados!\n");
	}	
	printf("Hora de imprimir el vector!\n");
	for(i=0;i<=3;i++)
	{
		printf("%i\n",vector[i]);
	}
	printf("Hora de las matrices!\n");
	int matriz[3][3];
	printf("Hora de cargar la matriz!\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			matriz[i][j]=rand()%10;
			printf("Numeros cargados!\n");
		}
	}
	printf("Hora de imprimir la matriz!\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
			printf("%d\t",matriz[i][j]);
			printf("\n");
	}
	printf("Hora de las funciones!\n");
	printf("Limpiemos la matriz!\n");
	cerar(matriz);
	imprimir(matriz);
	printf("WOW! Ahora vamos a hacer otra matriz! Y luego vamos a hacer que se imprima al revez!\n");
	int matriz2[4][4];
	cargar(4,4,matriz2)
}

void cerar(int matriz[3][3])
{
	int i,j;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		matriz[i][j]=0;
		printf("numero cerado!\n");
	}
}
void imprimir(int matriz[3][3])
{
	int i,j;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		printf("%d\t",matriz[i][j]);
		printf("\n");
	}
}
void cargar(int x,int y,matriz2)
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		matriz[i][j]=rand()%9
	}
}
