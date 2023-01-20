#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "string.h"

int main()
{
  srand(time(0));
  int n,i,j;
  char v[10][5];
  char alfabet[26]={"abcdefghijklmnopqrstuvxyz"};

  n=rand()%10+1;
  printf("n=%d\n", n);
}
