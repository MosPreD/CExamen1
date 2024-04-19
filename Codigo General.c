#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargar(int x, int y, int matriz[x][y]);
void imprimir(int x, int y, int matriz[x][y]);
void recorrido(int x, int y, int matriz[x][y]);
void generarDimensiones(int *x, int *y);
void tablaASCII();
void numero_float();
void generar_matriz();
void recorridoAlterno(int x, int y, int matriz[x][y]);

main()
{
//generacion de dimensiones, carga e impresion de matrices con numeros aleatorios
	srand(time(NULL));
	int x,y;
	generarDimensiones(&x, &y);
	int matriz[x][y];
	cargar(x,y,matriz);
	imprimir(x,y,matriz);
	printf("\nTabla Ascii\n");
	tablaASCII();
	printf("Numero float pseudo aleatorio\n");
	numero_float();
	printf("Ordenamiento\n");
	generar_matriz();
	return 0;
}
void cargar(int x, int y, int matriz[x][y])
 { int i,j;
 	for (i=0;i<x;i++) 
	{
	  for (j=0;j<y;j++)
      { 
       matriz[i][j]=rand()%11;
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
	*M=rand()%11;
	*N=rand()%11;
}
//Tabla ASCII
void tablaASCII()
{
	int i;
	char letra;
	for (i=0;i<255;i++)
	printf("%d %c\n",i,i);
	//Tabla de caracteres de 65 a 90 - A a Z
	letra=65+rand()%26;
	printf("%c\n",letra);
}
//Numero pseudo aleatorio Float
int numero_primo()
{
	int n,d=0,c=1;
	while (d!=2)
	{
		n=2+rand()%350;
	    c=1;
		d=0;
		while(c<=n)
		{
			if(n%c==0)
			d++;	
			c++;
		}
	}
	return n;
}
void numero_float()
{
	int a,b,c;
	float valor;
    
    a=numero_primo();
    do
    {
    	b=numero_primo();
	}while(a==b);
	
	if(a<b)
	valor=(a*1.0)/b;
	else
	valor=(b*1.0)/a;
	
	printf ("Numero float menor a 1 : %.15f\n",valor);
}
//Generacion Alterna (Hecha por el profe)
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
	recorridoAlterno(m,n,matriz);
}
void recorridoAlterno(int x, int y, int matriz[x][y])
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
