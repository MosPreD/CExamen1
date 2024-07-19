#include "colores.h"
#include <stdlib.h>
#include <stdio.h>
//#include <windows.h>

int main(){
	system("color 11");
	printf(BRED "este texto esta en rojo y esta en negritas \n" reset);
	printf(RED "Si" BLU "tu" YEL "estas" GRN "aburrido" CYN "imprime" MAG "esto! \n" reset); 
	printf(BRED "Si" BBLU "tu" BYEL "estas" BGRN "aburrido" BCYN "imprime" BMAG "esto! \n" reset); 
	printf(URED "Si" UBLU "tu" UYEL "estas" UGRN "aburrido" UCYN "imprime" UMAG "esto! \n" reset);
	getchar();
return 0;}
