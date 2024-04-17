/*
Regla del numero primo:
-Es aquel numero que es divisible solo por 1 y por si mismo
-tiene solo dos divisores
-0 y el 1 no son primos

Que necesitamos para nuestro programa?
variable para la captura
contador para nuestros divisores
contador para las iteraciones

*/
#include<stdio.h>
int capturar();
int primo(int n);

int main()
{
	if(primo(capturar()))
	{
		printf("El numero es primo\n");
	}
	else
	{
		printf("El numero no es primo\n");
	}
getchar();
return 0;
}
int capturar()
{
	int numero=0;
	while(numero<=1)
	{
		printf("Cargue un numero mayor o igual a 2:");// funcion de salida
		scanf("%d",&numero);// se utiliza el ampersan para guardar en la direccion de la variable el contenido del buffer capturado
		getchar();// muletilla
		
	}
	
	return numero;
}

int primo(int n)
{
	int cont=1,divisores=0;
	while(cont<=n)
	{
		if(n%cont==0)// cuando utilizamos el doble igual, sino utilizando el doble igual hacemos una asignacion
		{
			//divisores=divisores+1;
			divisores++;
		}
		cont++;
	}
	
	if(divisores==2)
	return 1;
	else
	return 0;
}

