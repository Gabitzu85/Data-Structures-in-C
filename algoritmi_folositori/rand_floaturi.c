#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"


int main()
{
  int i;
  srand(time(NULL));
  double k[6];

for(i=0; i<5; i++)
{
  k[i]=(double) rand() / RAND_MAX * 10+1;
  printf("%lf\n", k[i]);
}

  return 0;
}
