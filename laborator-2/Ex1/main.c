#include <stdio.h>
#include <stdlib.h>
#include "sortare.h"

int *cnt_bubble, *cnt_quicksort;

int main()
{
  srand(time(0));

  int n,i;
  n=rand()%10+1;
  int *v=(int*)malloc(n*sizeof(int));

  printf("n=%d\n", n);

  for (i = 0; i < n; i++)
  {
    v[i]=rand()%100+1;
  }

  printf("Vector nesortat:\n");

  for (i = 0; i < n; i++)
  {
    printf("%d ", v[i]);
  }
  printf("\n");

  bubble(v,n,&cnt_bubble);


  printf("Vector sortat cu bubble:\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", v[i]);
  }
  printf("\n");

  printf("Bubble a facut %d comparatii totale!", cnt_bubble);

  quick(v,0,n-1,&cnt_quicksort);

  printf("\n");


  printf("Vector sortat cu quicksort:\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", v[i]);
  }
  printf("\n");

  printf("Quicksort a facut %d comparatii totale!", cnt_quicksort);

  free(v);
}
