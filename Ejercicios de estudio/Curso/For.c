#include <stdio.h>

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int factorial = 1;
  int i;

  for(i=10;i>0;i--)
  {
  	factorial *= array[i];
  }

  printf("10! es %d.\n", factorial);
}
