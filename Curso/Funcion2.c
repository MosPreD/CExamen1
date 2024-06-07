#include <stdio.h>

void swap(int *var1, int *var2);
int add(int var1, int var2);

int main()
{
	int var1 = 3, var2 = 2;
	int res = add(var1, var2);
	printf("Antes del intercambio de var1 y var2 es: %d, %d\n",var1, var2);
	swap(&var1, &var2);
	printf("Despues del intercfambio de var1 y var2 es: %d, %d\n", var1, var2);
	printf("Suma: %d", res);
	return 0;
}

void swap(int *var1, int *var2)
{
	int temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}
int add(int var1, int var2)
{
	return var1+var2;
}
