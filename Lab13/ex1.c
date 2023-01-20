#include <stdio.h>
#include <stdlib.h>

float radical(float nr)
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
  printf("Radical din %.2f este %.4f!\n", n,m);
}
