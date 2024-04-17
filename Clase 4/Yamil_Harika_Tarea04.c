#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionsort(int vector[], int n);
void carga_vector();
int generar_numeros();
int main()
{
	srand(time(NULL));
	carga_vector();
	return 0;
}
void carga_vector()
{
	int r;
	r=5+rand()%11;
	printf("Cantidad de elementos generado al azar entre 5 y 15:%d\n",r);
	int vector[r];
	printf("Numeros generados entre 99 y 999:\n");
	int i;
	for (i = 0; i<r;i++)
	{
		
		vector[i] = generar_numeros();
	}
	selectionsort(vector, r);
	printf("Vector ordenado de menor a mayor:\n");
	imprimir_vector(vector, r);
}
int generar_numeros()
{
	int n=99+ (rand()%9)*(rand()%9)+rand()%719;
	printf("Numero generado: %d\n",n);
	return n;
}

void selectionsort(int vector[],int  n)
{
	int imin,i,j,aux;
	for (i=0; i<n; i++)
	{
  		imin=i;
  		for (j=i+1; j<n; j++)
  		{
    		if(vector[j]<vector[imin])
    		imin=j;
  		}
  		aux = vector[i];
  		vector[i] = vector[imin];
  		vector[imin] = aux;
	}
}
void imprimir_vector(int vector[], int n)
{
	int i;
	for (i=0; i<n;i++)
	{
		if (i<n-1)
			printf("%d,", vector[i]);
		else
			printf("%d", vector[i]);
	}
}

