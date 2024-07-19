/*Dado un vector de 25 elementos que contiene strings como elementos, 
donde los strings tienen una longitud fija 15 letras generadas las lettras al azar, 
una vez cargadas las palabras imprima el vector de strings, 
luego ordénelo y vuelva a imprimirlo*/


#include <stdio.h>
#include <string.h> 
#include <time.h>
//A=65, Z=90
void capturar(char string[]);
void solucion();
void imprimir(int x,int y,char textos[x][y]);

int main()
{
	solucion();
	getchar();
return 0;
}

void solucion()
{
	char textos[6][25];
	char temp[25];
	
	int i,j;
	for (i=0;i<6;i++)
	{
		capturar(textos[i]);
		//printf("Texto %i:%s",i+1,textos[i]);
	}
	printf("Textos Cargados:\n");
	imprimir(6,25,textos);
 
     for(i=0;i<5;i++)	
      {
      	for(j=i+1;j<6;j++)
      	{
		   if(strcmp(textos[i],textos[j])>0) //textos[i]>textos[j]
		   {
		   	   strcpy(temp,textos[i]); //temp=textos[i]
		   	   strcpy(textos[i],textos[j]); //textos[i]=textos[j]
		   	   strcpy(textos[j],temp); //textos[j]=temp
		   }
		}
	  }
	printf("Textos ordenados:\n");
	imprimir(6,25,textos);
}
void capturar(char string[])
{
	printf("Cargue el texto:");
	scanf("%s",string);
	getchar();
}
void imprimir(int x, int y, char textos[x][y])
{
	int i;
	for (i=0;i<6;i++)
	{
		//capturar(textos[i]);
		printf("Texto %i:%s\n",i+1,textos[i]);
	}
}
