#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <time.h>



int encuentra_guion (char string [])

{

  int pos=0,len;

  len=strlen(string);

  while ((string[pos]!='-')&&(len>1))

   pos++;

  return pos;

}

void capturar(char string[])

{

    printf("posicion: ");

    scanf("%s",string);

    getchar();

}

void imprimir_accion(char string[])

{

    int pos,longitud,po,pd;

    char origen,destino;

    pos=encuentra_guion(string);

    longitud=strlen(string);



    switch (pos){

    case 0: printf("se llama al mazo para cambiar carta");

            break;

    case 1: if(longitud==3){

            sscanf(string,"%c-%c",&origen,&destino);

            printf("se pasa de mazo a palo ordenado, Mazo a palo:%c ",destino);

            break;

            }

            else

            {

            sscanf(string,"%c-%c%d",&origen,&destino,&pd);

              if(origen=='M')

              {printf("se pasa de Mazo a Columna:%c fila:%d",destino,pd);}

              else

              {printf("se pasa de Palo:%c a Columna:%c fila:%d",origen,destino,pd);}

            }

            break;

    case 2: if(longitud==4)

            {

                sscanf(string,"%c%d-%c",&origen,&po,&destino);

                printf("se pasa de tablero columna:%c fila:%d a palo:%c",origen,po,destino);

            }

            else

            {

                sscanf(string,"%c%d-%c%d",&origen,&po,&destino,&pd);

                printf("se pasa de columna:%c fila:%d a columna:%c fila:%d",origen,po,destino,pd);

            }

            break;

    

    case 3: if(longitud==5)

            {

                sscanf(string,"%c%d-%c",&origen,&po,&destino);

                printf("se pasa de tablero columna:%c fila:%d a palo:%c",origen,po,destino);

            }

            else

            {

                sscanf(string,"%c%d-%c%d",&origen,&po,&destino,&pd);

                printf("se pasa de columna:%c fila:%d a columna:%c fila:%d",origen,po,destino,pd);

            }

    }

   

 }



int main ()

{

char string[8];
int i;

for(i=0;i<4;i++)
{capturar(string);
	imprimir_accion(string);
printf("\n");
}

return 0;
}



