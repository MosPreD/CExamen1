#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarAlumnos();
void textoInicio();
void opciones();
void cables();
void ordenarTodo();
void finalizar();

main()
{
	srand(time(NULL));
	textoInicio();
	opciones();
	return 0;
}

void opciones()
{
	int opcion;
	printf("\nOpciones:\n");
	printf("\n1-Desea ver los alumnos por separados\n");
	printf("2-Desea ordenarlos a todos\n");
	printf("3-Salir\nOpcion: ");
	scanf("%i",&opcion);
	getchar();
	switch(opcion)
	{
		case 1: cables();
			break;
		case 2:	ordenarTodo();
			break;
		case 3: finalizar();
			break;
		default: printf("Valor ingresado incorrecto. Vuelva a cargar valor(1-3)\n");
			opciones();
	}
}
void textoInicio()
{
	char *alumnos[]={"Agustin", "Beatriz", "Carlos", "Daniela", "Eugenio", "Fabiola", "Gustavo", "Hilda", "Ignacio", "Juan"};
	printf("Alumnos con cable:\n");
	printf("1-\t %s\n",alumnos[0]);
	printf("2-\t %s\n",alumnos[1]);
	printf("3-\t %s\n",alumnos[2]);
	printf("4-\t %s\n",alumnos[3]);
	printf("5-\t %s\n",alumnos[4]);
	printf("6-\t %s\n",alumnos[5]);
	printf("7-\t %s\n",alumnos[6]);
	printf("8-\t %s\n",alumnos[7]);
	printf("9-\t %s\n",alumnos[8]);
	printf("10-\t %s\n",alumnos[9]);
}
void cables()
{
	int seleccionAlumno;
	system("cls");
	textoInicio();
	printf("Opcion 1: Cables\n");
	printf("Que alumno desea ver?\n");
	scanf("%i",seleccionAlumno);
}
void ordenarTodo()
{
	printf("Opcion 2: Ordenar Todo\n");
}
void finalizar()
{
	printf("Opcion 3: Finalizar\n");
}
