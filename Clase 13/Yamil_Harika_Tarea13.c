#include <stdio.h>

void fibonacci(int a, int b, int contador, int tope) 
{
	int c;
	if(contador <= tope)
	{
		c = a + b;
		printf("%d\n", c);
		contador++;
		fibonacci(b, c, contador, tope);
	}
}

int main() {
    int N, i;
	printf("Ingrese la cantidad de elementos para la sucesion de Fibonacci (mayor a 10 y menor a 25): ");
	scanf("%d", &N);
	while(N <= 10 || N >= 25) 
	{
		printf("El numero ingresado debe ser entre 11 y 24. Intente de nuevo \n");
		main();
	}
	printf("\nSucesion Fibonnacci hasta el elemento %d:\n", N);
	fibonacci(0, 1, 3, N);
    printf("\n");
    system("pause");
    return N;
}
