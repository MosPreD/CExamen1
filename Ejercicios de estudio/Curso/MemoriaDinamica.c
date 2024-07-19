#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char name[100];
	char *description;
	strcpy(name, "Adam");
	/* allocate memory dynamically */
	description = malloc(200 * sizeof(char));
	if (description == NULL)
	{
		fprintf(stderr, "Error unable to allocate\n");
	}
	else
	{
		strcpy ( description, "Adam a DPS student in class 10th");
	}
	/* suppose you want to store bigger description */
	description = realloc (description, 100 * sizeof(char));
	if (description == NULL )
	{
		fprintf(stderr, "Error unable to allocate");
	}
	else
	{
		strcat(description, "He is in class 10th");
	}
	printf("Name = %s", name);
	printf("Description: %s", description);
	/* release memory using free() function */
	free(description);
	printf("Free description: %s", description);
	return 0;
}
