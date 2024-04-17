#include <stdio.h>

int funcion(int n);
void funcion2(int *n);

int main()
{
	int valor=67,q;
	q=funcion(valor);
	
	printf("el valor recibido: %d\n",q);
	
	funcion2(&valor);
	printf("el valor recibido: %d",valor);
	return 0;
	
}

int funcion(int n)
{
	return n*5;
}

void funcion2(int *n)
{
	int aux=5;
	*n+=aux;
}
