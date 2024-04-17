#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generarNumero();
int determinarGanador(int tiroJ1, int tiroJ2);
void imprimir(int j1,int j2);
void jugar();

int main() {
    srand(time(NULL));
	jugar();
    return 0;
}
void jugar()
{
	int j1=0, j2=0, i;
    for (i = 0; i < 10; i++) 
	{
        int tiroJ1 = generarNumero();
        int tiroJ2 = generarNumero();

        printf("%d\t%d: ", tiroJ1, tiroJ2);
        
        int resultado = determinarGanador(tiroJ1, tiroJ2);
        if (resultado == 1)
        {
        	printf("Gana Jugador 1\n");
            j1++;
        } 
		else if (resultado == 2) 
		{
            printf("Gana Jugador 2\n");
            j2++;
        } 
		else 
		{
            printf("Empate\n");
        }
    }
    imprimir(j1, j2);
}
    
int determinarGanador(int tiroJ1, int tiroJ2)
{
	if (tiroJ1 > tiroJ2) 
	{
        return 1;
    } 
	else if (tiroJ2 > tiroJ1) 
	{
        return 2;
    } 
	else 
	{
        return 0;
    }
}     
void imprimir(int j1, int j2)
{
	printf("\nJugador 1: %d\tJugador 2: %d\n", j1, j2);
    if (j1 > j2) 
	{
        printf("Gano el Jugador 1\n");
    } 
	else if (j2 > j1) 
	{
        printf("Gano el Jugador 2\n");
    } 
	else 
	{
        printf("Hubo un empate\n");
    }
}  
int generarNumero()
{
	return rand()%10;
}
