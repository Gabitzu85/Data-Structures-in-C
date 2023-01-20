#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib_recursiv(int n)
{
  if(n<2)
  {
    return 1;
  }
  return fib_recursiv(n-1)+fib_recursiv(n-2);
}

int fib(int n,int memo[])
{
  if(n<=1)
  {
    return n;
  }

  if(memo[n]==0)
  {
    memo[n]=fib(n-1,memo)+fib(n-2,memo);
  }
  return memo[n];
}

int main()
{
  int n,m;
  n=35;
  printf("n=%d\n",n);

  int *v=(int*)calloc(n+1,sizeof(int));

  clock_t begin = clock();
  m=fib(n,v);
  printf("%d\n",m);
  clock_t end = clock();

  clock_t begin1 = clock();
  fib_recursiv(n);
  clock_t end1 = clock();

  printf("Timp memoizare:%lf\n", (double)(end-begin)/CLOCKS_PER_SEC);
  printf("Timp recursiv:%lf\n", (double)(end1-begin1)/CLOCKS_PER_SEC);
}
