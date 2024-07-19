#include <stdio.h>
int main()
{ 
   char archivoentrada[] = "entrada.txt";
   char archivosalida[] = "salida.txt";
   char nombre[30];
   int idNum;

   FILE *sal, *ent;                    
   ent = fopen(archivoentrada,"r");    
  sal = fopen(archivosalida,"w");   
  
   //fscanf(ent,"%s %d",nombre,&idNum);  
  while (fscanf(ent,"%s %d",nombre,&idNum) != EOF) 
   {   
  
     fprintf(sal,"%d %s\n",idNum, nombre); 
  }
  
  fprintf(sal,"----------\n"); 
   fclose(ent); 
   fclose(sal);       
   return 0;
} 
