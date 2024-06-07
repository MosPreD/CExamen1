#include <stdio.h>

void swap(int *a,int *b);

int main()
{
	int x = 5;
	int y = 10;
	swap(&x, &y);
	printf("x: %d\ny: %d\n", x, y);
	return 0;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
