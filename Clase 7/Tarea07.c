#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generarAleatorio(char string[]);
void solucion();
void imprimir(int x,char textos[][16]);


int main()
{
	srand(time(NULL));
	solucion();
	getchar();
return 0;
}

void solucion()
{
	char textos[25][16];
	char temp[16];
	
	int i,j;
	for (i=0;i<25;i++)
	{
		generarAleatorio(textos[i]);
	}
	printf("Textos Generados:\n");
	imprimir(25,textos);
 
    for(i=0;i<24;i++)	
    {
      	for(j=i+1;j<25;j++)
      	{
		  	if(strcmp(textos[i],textos[j])>0)
		  	{
		   	   	strcpy(temp,textos[i]);
		   	   	strcpy(textos[i],textos[j]);
		   	   	strcpy(textos[j],temp);
		   	}
		}
	}
	printf("Textos ordenados:\n");
	imprimir(25,textos);
}
void generarAleatorio(char string[])
{
    int i;
    for (i = 0; i < 15; i++)
    {
        string[i] =65+rand()%26;
    }
    string[15] = '\0';
}
void imprimir(int x, char textos[][16])
{
	int i;
	
	for (i=0;i<x;i++)
	{
		//capturar(textos[i]);
		printf("Texto %i:%s\n",i+1,textos[i]);
	}
}
