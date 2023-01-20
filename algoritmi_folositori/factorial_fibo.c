#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int factorial(signed int n)
{
  if(n==0)
    return 1;
  else
    return n*factorial(n-1);
}

int fibonacci(signed int n)
{
  if(n==0)
    return 0;
  else if(n==1)
    return 1;
  else
  return (fibonacci(n-1)+fibonacci(n-2));
}

int main()
{
  signed int n;
  srand(time(0));
  n=rand()%10+1;
  //printf("%d! este %d.\n", n, factorial(n));
  printf("%d\n", n);
  for (size_t i = 0; i < n; ++i)
  {
    printf("%d ", fibonacci(i));
  }
}
