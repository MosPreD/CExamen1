#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char * name = "Miguel";
	printf("%d\n",strlen(name));
	char * name2 = "John";
	
	if(strncmp(name2, "John", 4)==0)
	{
		printf("Hello, John!\n");
	
	}
	else
	{
		printf("NO ERES JOHN, SALI DE ACA\n");
	}
	
	char dest[20]="Hello";
	char src[20]="World";
	strncat(dest,src,3);
	printf("%s\n",dest);
	strncat(dest,src,20);
	printf("%s\n",dest);
	return 0;
}
