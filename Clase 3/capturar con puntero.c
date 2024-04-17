#include <stdio.h>

void capturar(int *n);

int main()
{
	int a;
	capturar(&a);
	
	printf("valor de a:%d",a);
	return 0;
}

void capturar(int *n)
{
	printf("Cargue el valor de un numero entero: ");
	scanf("%d",n);
	getchar();
}

