#include <stdio.h>
#include<unistd.h>
#include <string.h>

int main()
{
	char nombre[20];
	char apellido[20];
	char mc[3] = "Mc";
	char mc2[3] = "Mc";
	printf("BUEENAS\n");
	printf("Ingrese su nombre: ");
	scanf("%s",nombre);
	printf("Ingrese su apellido: ");
	scanf("%s",apellido);
	
	strncat(mc,nombre,20);
	printf("%s ",mc);
	strncat(mc2,apellido,20);
	strncat(mc,mc2,40);
	printf("%s",mc2);
	
	printf(" %s",mc);
	sleep(10);
	return 0;
}
