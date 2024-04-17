#include<stdio.h>

int main()
{
	int n = 0;
	int a = 0;
	int b = 1;
	int z = 0;
	int i = 1;
	
	printf("\nIngrese un numero: ");
	scanf("%i", &n);
	if (n >= 1)
	{
		printf("%d , ", a);
		for (i = 1; i < n; i++)
		{
			a = b;
			b = z;
			z = a + b;
			
			printf("%i , ",z);
		}	
	}
	else
	{
		printf("Valor ingresado incorrecto (Valores > 0). Vuelva a cargar");
		main();
	}
	return 0;
}
