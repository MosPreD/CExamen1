#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void recorrido(int x, int y,int matriz[x][y]);
void cargar(int M, int N, int matriz[M][N]);
void imprimir(int M, int N, int matriz[M][N]);
void generarDimensiones(int *M, int *N);


main()
{
	srand(time(NULL));
	int M,N;
	generarDimensiones(&M, &N);
	int matriz[M][N];
	cargar(M,N,matriz);
	imprimir(M,N,matriz);
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
    recorrido(M,N,matriz);
}
void recorrido(int x, int y, int matriz[x][y])
{
	int i,j;
	printf("recorrido\n");
	for(j=0;j<y;j++)
	{
		if(j%2==0)
		{
			for(i=0;i<x;i++)
			{
				printf("%d,",matriz[i][j]);
			}
		}
		else
		{
			for(i=x-1;i>=0;i--)
			{
				printf("%d,",matriz[i][j]);
			}	
		}	
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
