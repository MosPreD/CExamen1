#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generarDimensiones(int *M, int *N, char figura);
void dibujarRectangulo(int M, int N);
void dibujarTrianguloRectangulo(int N);
void dibujarTrianguloIsoceles(int M, int N);

int main() 
{
	srand(time(NULL));
	int M,N;
    generarDimensiones(&M, &N, 'a');
    printf("Rectangulo (%d x %d):\n", M,N);
    dibujarRectangulo(M, N);
    
    generarDimensiones(&M, &N, 'b');
    printf("\nTriangulo Rectangulo altura %d base %d:\n",N,N);
    dibujarTrianguloRectangulo(N);
    
    generarDimensiones(&M, &N, 'c');
    printf("\nTriangulo isosceles base %d:\n",M);
    dibujarTrianguloIsoceles(M, N);
    
    return 0;
}
void dibujarRectangulo(int M, int N) 
{
	int i, j;
    for(i = 0; i < M; i++) 
	{
        for(j = 0; j < N; j++) 
		{
            if(i == 0 || i == M - 1 || j == 0 || j == N - 1) 
			{
                printf("* ");
            } 
			else 
			{
                printf("  ");
            }
        }
        printf("\n");
    }
}

void dibujarTrianguloRectangulo(int N) 
{
	int i,j;
    for(i = 0; i < N; i++) 
	{
        for(j = 0; j <= i; j++) 
		{
            printf("* ");
        }
        printf("\n");
    }
}

void dibujarTrianguloIsoceles(int M, int N) 
{
    int medio = M / 2;
    int altura = N;
    int i, j;

    for (i = 1; i <= medio + 1; i++) 
    {
        for (j = 0; j < i; j++) 
        {
            printf("*");
        }
        printf("\n");
    }
    if (M % 2 == 0)
    {
        altura--;
    }
    for (i = medio; i >= 1; i--) 
    {
        for (j = 0; j < i; j++) 
        {
            printf("*");
        }
        printf("\n");
    }
}
void generarDimensiones(int *M, int *N, char figura) 
{
    if (figura == 'a') 
	{
        *M =5+rand() % 21;
        *N =5+rand() % 21;
        if (*M==*N)
		{
			*M=5+rand() % 21;
		}
    } 
	else if (figura == 'b') 
	{
        *N = 5+rand() % 13;
        if (*N % 2 == 0) 
		{
    		(*N)++;
    	} 
    }
	else if (figura == 'c') 
	{
        *M = 5 + rand() % 15;
		*N = 5 + rand() % 15;
		while (*M % 2 == 0)
		{
			*M = 5 + rand() % 15;	
		}
		while (*N % 2 == 0)
		{
			*N = 5 + rand() % 15;
		} 
		if (*M==*N)
		{
    		*M = 5 + rand() % 15;
		}
		
	}
}
