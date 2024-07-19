#include <stdio.h>

struct Humanoid
{
	char dna[50];
	int age;
	float weight;
};


int main()
{
	int number = 20
	printf("valor: %i\n", number);
	printf("valor: %i\n", &number);
	
	char hello[] = "HI HELLO";
	char *str = malloc(4);
	
	str[0] = 'h';
	str[1] = 'e';
	str[2] = 'y';
	str[3] = '\0';
	
	free(str);
	
	return 0;	
}
