#include <stdio.h>
#include <stdlib.h>

float radical(int nr)
{
  float x,y;
  x=nr;
  y=1;
  float eroare=0.000001;

  while(x-y>eroare)
  {
    x=(x+y)/2;
    y=nr/x;
  }
  return x;
}


int main()
{
  float n,m,p;
  printf("n=");
  scanf("%f", &n);
  m=radical(n);
  p=radical_ordin3(n);
  printf("Radical din %.0f este %f!\n", n,m);
}
