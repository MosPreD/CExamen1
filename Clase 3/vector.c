#include <stdio.h>

int main()
{
	int i,vector[5];
	for ( i=0;i<5;i++)
{*(vector+i)=i+1;
printf("%d\n",vector[i]);
}	
	
//	vector[0]=i+1;
	
	printf("%d",*(vector+3));
	return 0;
}
