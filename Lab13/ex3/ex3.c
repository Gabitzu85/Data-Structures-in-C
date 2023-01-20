#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int memo[100000],n;

int fib_recursiv(int n)
{
  if(n<2)
  {
    return 1;
  }
  return fib_recursiv(n-1)+fib_recursiv(n-2);
}

int fib(int n)
{
  if(n<=1)
  {
    return n;
  }

  if(memo[n]!=0)
  {
    return memo[n];
  }
  else
  {
    memo[n]=fib(n-1)+fib(n-2);
    return memo[n];
  }
}

int main()
{
  int n,m;
  n=35;
  printf("n=%d\n",n);


  int *memo=(int*)calloc(n,sizeof(int));

  clock_t begin = clock();
  fib(n);
  clock_t end = clock();
  //printf("%d\n",fib(n));

  clock_t begin1 = clock();
  fib_recursiv(n);
  clock_t end1 = clock();

  printf("Timp memoizare:%lf\n", (double)(end-begin)/CLOCKS_PER_SEC);
  printf("Timp recursiv:%lf\n", (double)(end1-begin1)/CLOCKS_PER_SEC);
}
