#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargar(int M, int N, int matriz[M][N]);
void imprimir(int M, int N, int matriz[M][N]);
void imprimirRecorrido(int M, int N,int matriz[M][N]);
void generarDimensiones(int *M, int *N);


main()
{
	srand(time(NULL));
	int M,N;
	generarDimensiones(&M, &N);
	int matriz[M][N];
	cargar(M,N,matriz);
	imprimir(M,N,matriz);
	printf("Recorrido inverso:\n");
	imprimirRecorrido(M,N,matriz);
	return 0;
}
void cargar(int M, int N, int matriz[M][N])
 { int i,j;
 	for (i=0;i<M;i++) 
	{
	  for (j=0;j<N;j++)
      { 
       matriz[i][j]=rand()%27;
      }
    }
}
void imprimir(int M, int N, int matriz[M][N])
 { int i,j;
 	for (i=0;i<M;i++) 
    {
     for (j=0;j<N;j++)
     printf("%d\t",matriz[i][j]);
     printf("\n");
    } 
}
void imprimirRecorrido(int M, int N, int matriz[M][N])
{
	int i,j;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(j%2 == 0)
			{
				printf("%d\t", matriz[i][j]);
			}
			else
			{
				printf("%d\t", matriz[M - i - 1][j]);
			}
		}
		printf("\n");
	}
}
void generarDimensiones(int *M, int *N)
{
	*M=4+rand()%12;
	*N=4+rand()%12;
	if (*M==*N)
	{
		*M=4+rand()%12;
	}
	else if (*N==*M)
	{
		*N=4+rand()%12;
	}
}
