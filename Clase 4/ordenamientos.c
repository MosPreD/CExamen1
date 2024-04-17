#include <stdio.h>
void asignar(int vector[],int vectoraux[], int n);
void imprimir(int vectoraux[],int n);
void bublesort(int vector[],int n);
void selectionsort(int vector[],int n);
void insertionsort(int vector[],int n);
void shellsort(int vector[], int n) ;
int main()
{
	int i,vector[]={8,10,0,1,3,2,4,5,6,7,9},vectoraux[11];
	asignar(vector,vectoraux,11);
    bublesort(vectoraux,11);
	imprimir(vectoraux,11);
	asignar(vector,vectoraux,11);
	selectionsort(vectoraux,11);
	imprimir(vectoraux,11);
	asignar(vector,vectoraux,11);
	insertionsort(vectoraux,11);
	imprimir(vectoraux,11);
	asignar(vector,vectoraux,11);
	shellsort(vectoraux,11);
	imprimir(vectoraux,11);
	
return 0;
}

void bublesort(int vector[],int n)
{
int i,j,aux;
for (i=0; i<n-1; i++)
{
for (j=i+1; j<n; j++)
  {
    if(vector[i]>vector[j])
    {
     aux = vector[i];
     vector[i] = vector[j];
     vector[j] = aux;
    }
  }
}

}



void selectionsort(int vector[],int  n)
{
int imin,i,j,aux;
for (i=0; i<n; i++)
{
  imin=i;
  for (j=i+1; j<n; j++)
  {
    if(vector[j]<vector[imin])
    imin=j;
  }
  aux = vector[i];
  vector[i] = vector[imin];
  vector[imin] = aux;
}

}
void asignar(int vector[],int vectoraux[], int n)
{
int i;
for(i=0;i<n;i++)
vectoraux[i]=vector[i];
}
void imprimir(int vectoraux[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d,",vectoraux[i]);
printf("\n");
}

void insertionsort(int vector[],int n)
{
int i,j,temp,Izq,Der,Medio;

	for(i=1; i<n; i++) {
  temp = vector[i];
  Izq = 0;
  Der = i-1;
  while(Izq <= Der){
    Medio = (Izq+Der)/2;
    if (temp < vector[Medio])
      Der = Medio - 1;
    else
      Izq = Medio + 1;
  }
  for (j=i-1; j>=Izq; j--){
    vector[j+1]=vector[j];
  }
  vector[Izq] = temp;
}

}


void shellsort(int vector[], int n) 
{
  int h,i,j,temp;
    for ( h = n/2; h > 0; h /= 2) 
    { 
        for ( i = h; i < n; i += 1) 
        { 
            temp = vector[i]; 
                        
            for (j = i; j >= h && vector[j - h] > temp; j -= h) 
                vector[j] = vector[j - h]; 
              
              vector[j] = temp; 
        } 
    } 
}

