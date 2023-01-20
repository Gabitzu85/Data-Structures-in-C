#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "string.h"

typedef struct timp
{
  int ora;
  int min;
  int sec;
}timp;

void merge(timp *v, int low, int mid, int high)
{
  int left,right;
  int k,i;
  timp aux[28];
  k=0;
  left=low;
  right=mid+1;

  for(; (left<=mid)&&(right<=high); k++)
  {
    if(v[left].ora <= v[right].ora)
    {
      aux[k]=v[left++];
    }
    else
    {
      aux[k]=v[right++];
    }
  }

  for(; left<=mid; ++left, k++)
  {
    aux[k]=v[left];
  }

  for(; right<=high; ++right, k++)
  {
    aux[k]=v[right];
  }

  k=low;
  i=0;

  for (;  k <= high;  k++, i++)
  {
    v[k]=aux[i];
  }
}

void merge_sort(timp *v, int low, int high)
{
  int mid=(high+low)/2;

  if(high<=low)
  return;
  merge_sort(v,low,mid);
  merge_sort(v,mid+1,high);
  merge(v,low,mid,high);
}


int main()
{
  srand(time(0));
  int n,i;
  n=rand()%10+1;
  timp *v=(timp*)malloc(n*sizeof(timp));

  for(i=0; i<n; i++)
  {
    v[i].ora=rand()%100;
    v[i].min=rand()%100;
    v[i].sec=rand()%100;
  }

  printf("Structura nesortata: \n");

  for(i=0; i<n; i++)
  {
    printf("%d: ora=%d min=%d sec=%d \n", i+1, v[i].ora, v[i].min, v[i].sec);
  }

  merge_sort(v,0,n-1);

  printf("Structura sortata:\n");
  for(i=0; i<n; i++)
  {
    printf("%d: ora=%d min=%d sec=%d \n", i+1, v[i].ora, v[i].min, v[i].sec);
  }

  free(v);
}
