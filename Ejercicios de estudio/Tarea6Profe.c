#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generar_matriz();
void recorrido(int x, int y, int matriz[x][y]);

main()
{
	srand(time(NULL));
	generar_matriz();
	return 0;
}
void generar_matriz()
{
	int i,j,m,n;
	m=4+rand()%12;
	do
	{
		n=4+rand()%12;
	}
	while(m==n);
	int matriz[m][n];
	printf("Matriz %d x %d\n====================\n",m,n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			matriz[i][j]=rand()%27;
			printf("%d\t",matriz[i][j]);
		}
		printf("\n");
	}
	recorrido(m,n,matriz);
}
void recorrido(int x, int y, int matriz[x][y])
{
	int i,j;
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
