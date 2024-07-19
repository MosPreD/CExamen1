#include <stdio.h>

 
int fxFactorial(int Num){
   if(Num==0)
     return 1;
   else
     return (fxFactorial(Num-1)*Num);
}
 
int main(){
  int Num;
  printf("Ingresa un numero para calcular su factorial : ");
  scanf("%d",&Num);
  printf("------\n");
  printf("El factorial de %d es %d\n",Num,fxFactorial(Num));
  system("pause");
}

/*
prueba 5!

f0
5
return f(4)*5

f1
4
return f(3)*4

f2
3
return f(2)*3

f3
2
return f(1)*2

f4
1
return f(0)*1

f5
0
return 1

returns
--------
f5 * f4  *f3 *f2 *f1 *f0
1    1     2   6   24  120

*/
