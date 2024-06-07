#include <stdio.h>

int main()
{
	int numeros[5] = {10, 20, 30, 40, 50};
	int i;
	
	printf("Los elementos del aaray son: ");
	for (i=0;i<5;i++)
	{
		printf("%d ", numeros[i]);
	}
	
	return 0;
}
