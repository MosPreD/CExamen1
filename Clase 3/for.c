#include <stdio.h>

int control()
{int a;
printf("cargar(0-1):");
scanf("%d",&a);
getchar();
	
	return a;
}

int main()
{
int i,j=1;

// for basico
/*for(i=0;i<3;i++)
{
		printf("valor: %d\n",i+1);
}*/

/*for(i=0;control();i++)	
{
	printf("valor: %d\n",i+1);
}

while(control())
{
	printf("valor: %d\n",i+1);
	i++;
}
*/

/*
for(;;)	
{
	printf("valor: %d\n",i+1);
	i++;
	if(i==3)
	break;
}

while(true)//1
{
	printf("valor: %d\n",i+1);
	i++;
	if(i==3)
	break;
}
*/

/*for(;;i++)	
{
	printf("valor: %d\n",i+1);
	
	if(control())
	break;
}*/

/*for(;i<3;)	
{
	printf("valor: %d\n",i+1);
	i++;
}

while(i<3)	
{
	printf("valor: %d\n",i+1);
	i++;
}
*/

i=1;
for(;i<27;j++)	
{
	printf("valor: %d\n",i+1);
	i*=j;
}


	
	
	return 0;
}
