#include <stdio.h>
#include <stdlib.h>
#include "time.h"

void count_sort(int *v, int n)
{
  int rez[1000];
  int max=v[0];

  for(int i=1; i<n; i++)
  {
    if(v[i]>max)
    {
      max=v[i];
    }
  }

  int aux[1000];
  for(int i=0; i<=max; ++i)
  {
    aux[i]=0;
  }

  for(int i=0; i<n; i++)
  {
    aux[v[i]]++;
  }

  for(int i=1; i<=max; i++)
  {
    aux[i]+=aux[i-1];
  }
  for(int i=n-1; i>=0; i--)
  {
    rez[aux[v[i]]-1]=v[i];
    aux[v[i]]--;
  }
  for(int i=0; i<n; i++)
  {
    v[i]=rez[i];
  }
}

int main()
{
  srand(time(0));
  int n,i;
  int *v=(int*)malloc(n*sizeof(int));
  n=rand()%20+1;
  printf("n=%d\n", n);
  for ( i = 0; i < n; i++)
  {
    v[i]=rand()%1000;
  }

  printf("Nesortat: \n");
  for (i = 0; i < n; ++i)
  {
    printf("%d ", v[i]);
  }
  printf("\n");
  printf("Sortat: \n");
  count_sort(v,n);
  for (i = 0; i < n; ++i)
  {
    printf("%d ", v[i]);
  }
  free(v);
}
