#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc_ln(double n)  //avem formula log(x)=ln(x)/2.303
{
  double suma=0, nr, calc, aux;
  nr=(n-1)/(n+1);

  for(int i=1; i<=100; i++) //precizia
  {
    aux=(2*i)-1;
    calc=pow(nr,aux);
    calc=calc/aux;
    suma+=calc;
  }
  return (2*suma);
}

float calc_log(float lnx)
{
  return (lnx/2.303);
}

int main()
{
  float lnx, logx,n;
  printf("Introduceti un nr:\n");
  scanf("%f", &n);

  lnx=calc_ln(n);
  logx=calc_log(lnx);

  printf("Logaritm in baza 10 din %.3f este %.3f\n", n,logx);
}
