#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
  int a=1;
  int b=2;
  int c=3;
  int *p;
  int *q;

  p=a;
  q=&b;

  c=*p;
  p=q;
  *p=13;

  printf("%d %d\n", *p, *q);
  printf("%d %d %d\n", a,b,c);


}
