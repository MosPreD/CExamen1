#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void numero_entre();
void numero_mayor();
void numero_float();
int numero_primo();


int main()
{
srand(time(NULL));
numero_entre();
numero_mayor();
numero_float();
return 0;
}
void numero_entre()
{
	int n;
	n=3+rand()%12;
	printf("Numero generado entre 3 y 14:%d\n",n);
}
void numero_mayor()
{
	/*50.000 y 1.000.000
	950.000 es 974*974 + 1324
	*/
	int n=50000+ (rand()%975)*(rand()%975)+rand()%1325;
	printf("Numero generado entre 50.000 y 1.000.000: %d\n",n);
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
