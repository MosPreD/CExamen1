#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generar_matriz();

main ()
{
	srand(time(NULL));
	generar_matriz();
	return 0;
}
void generar_matriz()
{
	int i,j,n,c;
	n=2+rand()%7;
	int matriz[n][n];
	printf("Matriz %d x %d\n====================\n",n,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((i==j)&&(i+j==n-1))
			{
			matriz[i][j]=200;
			}
			else if(i==j)
			{
				do
				{
				c=52+rand()%47;		
				}
				while(c%2!=0);
				matriz[i][j]=c;
			}
			else if((i+j==n-1))
			{
				do
				{
					c=1+rand()%48;		
				}
				while(c%2==0);
				matriz[i][j]=c;
			}
		else
		{
			do
			{
				c=151+rand()%150;		
			}
			while(c==200);
			matriz[i][j]=c;	
		}
		printf("%d\t",matriz[i][j]);
		}
		printf("\n");
	}
}
