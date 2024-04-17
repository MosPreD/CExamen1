#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga_matriz();
void imprimir(int x, int y, int matriz[x][y]);
int main()
{
srand(time(NULL));
carga_matriz();
return 0;
}
void carga_matriz()
{
	int f,c,i,j;
	f=2+rand()%14;
	do{
	 c=2+rand()%14;		
	}while(f==c);
	int matriz[f][c];
	for(i=0;i<f;i++)
	{
		for(j=0;j<c;j++)
		{
			matriz[i][j]=1+rand()%350;
		}
	}
	imprimir(f,c,matriz);
}
void imprimir(int x, int y, int matriz[x][y])
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			printf("%d\t",matriz[i][j]);
		}
		printf("\n");
	}
}
