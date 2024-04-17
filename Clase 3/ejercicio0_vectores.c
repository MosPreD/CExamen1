/*Ejercicio 0
dado un vector de 7 elementos donde los elementos son cargados 
por el usuario, encuentre el numero mayor, luego defina cuantos elementos
son menores a este numero si es que existen n-1 elementos menores
cree un nuevo vector de dimension n-1 y cargue los valores, en caso de que 
se repita varias veces el numero mayor cree un vector en donde solo guarde 
los elementos menores
*/
#include <stdio.h>
void capturar(int d,int v[]);
int encontrar_may(int d,int v[]);
int encontrar_dim(int d,int v[],int mayor);

int main()
{ int vector[7],dim,mayor,i,c=0;
capturar(7,vector);
mayor=encontrar_may(7,vector);
dim=encontrar_dim(7,vector,mayor);
if(dim==0)
{
	printf("Todos los numeros ingresados son iguales!\n");
}
else if(dim==1)
{
    for(i=0;i<7;i++)
    {
    	if(vector[i]!=mayor)
    	{
    		printf("valor distinto:%d\n",vector[i]);
		}
	}
}
else
{  
     int v[dim];
     printf("Elementos\n");
	 for(i=0;i<7;i++)
     {
     	
     	if(vector[i]!=mayor)
     	{
     		v[c]=vector[i];
     		printf("%d - %d\n",c+1,v[c]);
			 c++;
     		
		}
     	
	 }
  
   
}


return 0;
}


void capturar(int d,int v[])
{
int i,a;	
for(i=0;i<d;i++)
{
  printf("%d -cargue un valor:",i+1);
  scanf("%d",&a);
  //scanf("%d",(v+i));
  getchar();
  v[i]=a;

}
}

int encontrar_may(int d,int v[])
{
  int aux=v[0],i;
  for(i=0;i<d;i++)	
  {
  	if(aux<v[i])
  	{
  		aux=v[i];
	}
  }
return aux;	
}

int encontrar_dim(int d,int v[],int mayor)
{int i,dim=0;

for(i=0;i<d;i++)	
{
	if(mayor!=v[i])
	{
		dim++;
	}
	
}
return dim;	

}