#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct ficha {
    char genero[2];
    char pnombre[50];
    char snombre[50];
    char papellido[50];
    char sapellido[50];
    char nombreyapellido[102];
    char apellidoynombre[102];
    int edad;
    int ci;
	char ciudad[25];
    struct ficha* siguiente;
} Ficha;

void menu();
void cargar_personas(Ficha** lista, int a);
int generarNroCedula(Ficha* lista);
void imprimir_lista(Ficha* lista);
int ordenar_lista(Ficha** lista, int contador);

int main() {
    srand(time(NULL));
    menu();	
    return 0;
}
void menu()
{
	int opcion;
	Ficha* lista = NULL; 
	int n = 0;
	while(1)
	{
		printf("\nMenu de seleccion de ficha de alumnos:\n");
		printf("Seleccione una opcion \n");
		printf("1-Generar alumnos\n2-Menu de impresion\n3-Salir\n");
		printf("Ingrese opcion: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				printf("Opcion %i seleccionada: Generar alumnos\n", opcion);
				printf("Ingrese la cantidad de alumnos que desea cargar(de 60 a 70): \n");
				scanf("%i",&n);
				if(n>=60 && n<= 70)
				{
					cargar_personas(&lista, n);
					printf("Lista cargada:\n");
					imprimir_lista(lista);	
				}
				else
				{
					printf("Cantidad de alumnos incorrecta, vuelva a cargar.\n");
				}
				break;		
			case 2:
				printf("Opcion %i seleccionada: Menu de impresion de alumnos\n", opcion);
			    imprimir_lista(lista);
				break;
			case 3:
				printf("Opcion %i seleccionada: Saliendo del programa\n", opcion);
				exit(0);
				break;
			default:
				printf("Opcion invalida, vuelva a ingresar.\n");
				menu();
				break;
		}	
	}
	
}
void imprimir_lista(Ficha* lista) {
    Ficha* actual = lista;
    while (actual != NULL) {
        printf("\n %s %s %s %s %i %i %s", actual->pnombre,
               actual->snombre, actual->papellido, actual->sapellido,
               actual->edad, actual->ci, actual->ciudad);
        actual = actual->siguiente;
    }
}
void cargar_personas(Ficha** lista, int a) {
    int i, s;
    char nombres[25], apellidos[50];
    char nombre_hombre[] [25]= { "ADRIAN","ALBERTO","ALEJANDRO","ALVARO","ANDRES","ANGEL","ANTONIO","CARLOS","DANIEL","DAVID","DIEGO","EDUARDO","ENRIQUE","FERNANDO","FRANCISCO","IVAN","JAVIER","JESUS","JOAQUIN","JORGE","JOSE","JUAN","LUIS","MANUEL","MIGUEL","OSCAR","PABLO","PEDRO","RAFAEL","RAMON","RAUL","RUBEN","SANTIAGO","SERGIO","VICENTE","VICTOR"};
	char nombre_mujer[] [25]= { "ANA","ANDREA","ANGELA","ANTONIA","BEATRIZ","CARMEN","CORAL","CRISTINA","DOLORES","ELENA","ENRIQUETA","FRANCISCA","IRENE","ISABEL","JOSEFA","JUANA","JULIA","LAURA","LUCIA","MANUELA","MARIA","MARTA","MERCEDES","MONICA","MONTSERRAT","NURIA","PATRICIA","PAULA","PENELOPE","RAQUEL","ROCIO","ROSA","ROSARIO","SARA","SILVIA","TERESA"};
	char pos_apellidos[] [25]= { "ALONSO","ALVAREZ","BLANCO","CANO","CASTILLO","CASTRO","CORTES","DELGADO","DIAZ","DOMINGUEZ","FERNANDEZ","GARCIA","GARRIDO","GIL","GOMEZ","GONZALEZ","GUERRERO","GUTIERREZ","HERNANDEZ","IGLESIAS","JIMENEZ","LOPEZ","LOZANO","MARIN","MARTIN","MARTINEZ","MEDINA","MOLINA","MORALES","MORENO","MUNOZ","NAVARRO","NUNEZ","ORTEGA","ORTIZ","PEREZ","RAMIREZ","RAMOS","RODRIGUEZ","ROMERO","RUBIO","RUIZ","SANCHEZ","SANTOS","SANZ","SERRANO","SUAREZ","TORRES","VAZQUEZ"};
    char ciudad[] [25]= { "ASUNCION","LAMBARE","CAACUPE","ITAUGUA","MARIANO ROQUE ALONSO","CAPIATA","LUQUE","SAN LORENZO" };
	for (i = 0; i < a; i++) {
        Ficha* nueva_persona = (Ficha*)malloc(sizeof(Ficha));

        s = rand() % 2;
        if (s == 0) {
            strcpy(nueva_persona->genero, "M");

            s = rand() % 36;
            strcpy(nueva_persona->pnombre, nombre_hombre[s]);

            do {
                s = rand() % 36;
                strcpy(nueva_persona->snombre, nombre_hombre[s]);
            } while (strcmp(nueva_persona->snombre, nueva_persona->pnombre) == 0);
        } else {
            strcpy(nueva_persona->genero, "F");

            s = rand() % 36;
            strcpy(nueva_persona->pnombre, nombre_mujer[s]);

            do {
                s = rand() % 36;
                strcpy(nueva_persona->snombre, nombre_mujer[s]);
            } while (strcmp(nueva_persona->snombre, nueva_persona->pnombre) == 0);
        }

        s = rand() % 49;
        strcpy(nueva_persona->papellido, pos_apellidos[s]);
        s = rand() % 49;
        strcpy(nueva_persona->sapellido, pos_apellidos[s]);

        sprintf(nombres, "%s %s", nueva_persona->pnombre, nueva_persona->snombre);
        sprintf(apellidos, "%s %s", nueva_persona->papellido, nueva_persona->sapellido);
        sprintf(nueva_persona->nombreyapellido, "%s %s", nombres, apellidos);
        sprintf(nueva_persona->apellidoynombre, "%s, %s", apellidos, nombres);
        
        nueva_persona->edad = rand() % 6 + 20;

		s = rand() % 8;
        strcpy(nueva_persona->ciudad, ciudad[s]);
        
        nueva_persona->ci = generarNroCedula(*lista);
		
        nueva_persona->siguiente = *lista;
        *lista = nueva_persona;
    }
}
struct Ficha* intercambiar(Ficha* ptr1,Ficha* ptr2) 
{ 
    Ficha* tmp = ptr2->siguiente; 
    ptr2->siguiente = ptr1; 
    ptr1->siguiente = tmp; 
    return ptr2; 
} 
int ordenar_lista(Ficha** lista, int contador) { 
    Ficha** h; 
    int i, j, intercambio; 
    char apellidos1[100], apellidos2[100];
    for (i = 0; i <= contador; i++) 
    { 
  
        h = lista; 
        intercambio = 0; 
  
        for (j = 0; j < contador - i - 1; j++)  
        { 
  
            Ficha* p1 = *h; 
            Ficha* p2 = p1->siguiente;
			sprintf(apellidos1, "%s%s", p1->papellido, p1->sapellido);
			sprintf(apellidos2, "%s%s", p2->papellido, p2->sapellido);
            if (strcmp(apellidos1, apellidos2) > 0) 
            { 
  

                *h = intercambiar(p1, p2); 
                intercambio = 1; 
            } 
  
            h = &(*h)->siguiente; 
        } 
        if (intercambio == 0) 
            break; 
    } 
} 
int generarNroCedula(Ficha* lista)
{
	int ci=0,i=0,unico;
	do
	{
		unico = 1;
		ci = 2500000 + ((rand()% 1871)*(rand()% 1871)-641);
		Ficha* actual = lista;
		while (actual != NULL)
		{
			if(actual->ci == ci)
			{
				unico = 0;
				break;
			}
			actual = actual->siguiente;
		}
	}
	while(!unico);
   	return ci;
}
