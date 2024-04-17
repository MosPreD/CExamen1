/*

Apunta a la direccion de la variable con el mismo tipo de dato

variable en la direccion 1111111

el puntero va a guardar esa direccion

recordemos

scanf("%d",&variable);

*/

#include <stdio.h>

int main()
{
 int a;
 a=5;
 printf("valor de a:%d\n",a);
 
 int *ptr;//declaracion del puntero se usa el *
 
 ptr=&a;// solicitamos la direccion de a a través del & y guardamos en ptr
 
printf("valor de a:%d valor guardado en direccion:%d\n",a,*ptr);

*ptr=7;

printf("valor de a:%d direccion de a:%d valor de puntero:%d valor guardado en direccion:%d\n",a,&a,ptr,*ptr);

int b=9;
printf("valor de b:%d  direccion de b:%d\n",b,&b);
ptr=&b;

printf("valor de a:%d direccion de a:%d valor de puntero:%d valor guardado en direccion:%d\n",a,&a,ptr,*ptr);
	
	

return 0;
}
