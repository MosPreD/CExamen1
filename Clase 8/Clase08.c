#include<stdio.h>
typedef struct PERSONA
{
	char nombre[25], apellido[];
	int edad,estatura,peso;
} 	Persona;
typedef struct materia
{
	Persona Alumnos[35];
	char nombre_materia[35];
}	Materia;
Persona funcion_1();

int main ()
{ 
	Persona humano_1,humano_2;
	humano1=funcion_1;
	strcpy(humano_1.nombre,humano_2.nombre);
	return 0;
}
