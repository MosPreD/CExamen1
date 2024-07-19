#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <time.h>

typedef struct Baraja

{

	int color,grupo,estado,valor,visible;//int 0,1 char R,N

	char impresion[4];

	

	

} Carta;

/*

3-corazon

4-diamante

5- trebol

6-espada

*/

char letra (int n)

{

	switch(n)

	{

		case 1: return 'A';

		case 11: return 'J';

		case 12: return 'Q';

		case 13: return 'K';

	}

}



void generar_mazo(Carta Mazo[])

{

	int i,j,c=0;

	for(i=3;i<=6;i++)

	{

		for(j=1;j<=13;j++)

		{

			Mazo[c].valor=j;

			Mazo[c].grupo=i;

			Mazo[c].estado=0;

			Mazo[c].visible=1;

			if(i<=4)

			Mazo[c].color=0;//rojo

			else 

			Mazo[c].color=1;//negro

			if((j>1)&&(j<11))

			sprintf(Mazo[c].impresion,"%d%c",j,i);//puede ser j,i

      		else

			sprintf(Mazo[c].impresion,"%c%c",letra(j),i)	;

			c++;

		}

	}

	

}

void imprimir_mazo(Carta Mazo[])

{

	int i;

	for(i=0;i<52;i++)

	printf("%s\n",Mazo[i].impresion);

	

	

	

}

Carta traer_carta(Carta Mazo[])

{ Carta carta;

  int i;

  do

  {

  

   i=rand()%52;

   carta=Mazo[i];

   

   

  }while(Mazo[i].estado);	

   Mazo[i].estado=1;



return carta;

}





void  desordenar_mazo(Carta Mazo[],Carta Mazo_d[])

{

	int i ;

	for(i=0;i<52;i++)

	{

		Mazo_d[i]=traer_carta(Mazo);

	}

	

}



void cargar_tablero(Carta mazo_d[],int f,int c, Carta tablero[f][c])

{

	

	int i,j,ind=0;

	

	for(i=0;i<7;i++)

	{

		for(j=i;j<7;j++)

		{

			tablero[i][j]=mazo_d[ind];

			ind++;

		}

	}

	////marcar las cartas

}



void imprimir_tablero(int f,int c, Carta tablero[f][c])

{

	int i,j;

	for(i=0;i<19;i++)

	{

		for(j=0;j<7;j++)

		{

			if(tablero[i][j].valor==0)

			{

				printf("  \t");

			}

			else //

			{

				printf("%s\t",tablero[i][j].impresion);

				

			}

		

		}

			printf("\n");

	}

	

}





int main()

{  

    srand(time(NULL));

	Carta Mazo[52],Mazo_d[52],tablero[19][7];

    

    generar_mazo(Mazo);

    desordenar_mazo(Mazo,Mazo_d);

    //imprimir_mazo(Mazo_d);

    int i,j;

    

	for(i=0;i<19;i++)

    	for(j=0;j<7;j++)

    	tablero[i][j].valor=0;

    	

    	

    cargar_tablero(Mazo_d,19,7,tablero);

   imprimir_tablero(19,7,tablero);

    

    

	return 0;

}


