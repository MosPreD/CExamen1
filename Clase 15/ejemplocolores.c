#include <stdio.h>
//#include <windows.h>
#include <stdlib.h>
int main() {
system("color 20");
    // Imprimir texto en diferentes colores

    printf("\x1b[31m Este texto es rojo.\n");

    printf("\x1b[32m Este texto es verde.\n");

    printf("\x1b[33m Este texto es amarillo.\n");

    printf("\x1b[34m Este texto es azul.\n");

    printf("\x1b[35m Este texto es magenta.\n");

    printf("\x1b[36m Este texto es cian.\n");

 

    system("pause");

    return 0;

}
