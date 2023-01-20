#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct muchie
{
  int v1,v2,cost;
}muchie;

typedef struct graf
{
  int varfuri;
  int muchii;
  muchie *e;
}graf;

void swap(muchie *a, muchie *b)
{
  muchie aux;
  aux=*a;
  *a=*b;
  *b=aux;
}

int partition(muchie *arr, int low, int high)
{
  int j,i;
  muchie aux;
  muchie pivot=arr[high];

  i=(low-1);
  for(j=low; j<=high-1; j++)
    if(arr[j].cost<=pivot.cost)
    {
      i++;
      swap(&arr[i],&arr[j]);
    }

  swap(&arr[i+1],&arr[high]);
  return (i+1);
}

void quick_sort(muchie *arr, int low, int high)
{
  if(low<high)
  {
    int pi=partition(arr,low,high);
    quick_sort(arr,low,pi-1);
    quick_sort(arr,pi+1,high);
  }
}

graf *creategraf()
{
  srand(time(0));
  int i;

  graf *g=(graf*)malloc(sizeof(graf));
  g->e=(muchie*)malloc(g->muchii*sizeof(muchie));
  //g->varfuri=rand()%10+1;
  g->varfuri=9;
  printf("Nr varfuri = %d\n",g->varfuri);
  //g->muchii=rand()%10+1;
  g->muchii=14;
  printf("Nr muchii = %d\n",g->muchii);

  printf("\n");

  g->e[0].v1=0;
  g->e[0].v2=1;
  g->e[0].cost=4;

  g->e[1].v1=1;
  g->e[1].v2=2;
  g->e[1].cost=8;

  g->e[2].v1=2;
  g->e[2].v2=3;
  g->e[2].cost=7;

  g->e[3].v1=3;
  g->e[3].v2=4;
  g->e[3].cost=9;

  g->e[4].v1=4;
  g->e[4].v2=5;
  g->e[4].cost=10;

  g->e[5].v1=5;
  g->e[5].v2=6;
  g->e[5].cost=2;

  g->e[6].v1=6;
  g->e[6].v2=7;
  g->e[6].cost=1;

  g->e[7].v1=0;
  g->e[7].v2=7;
  g->e[7].cost=8;

  g->e[8].v1=1;
  g->e[8].v2=7;
  g->e[8].cost=11;

  g->e[9].v1=7;
  g->e[9].v2=8;
  g->e[9].cost=7;

  g->e[10].v1=2;
  g->e[10].v2=8;
  g->e[10].cost=2;

  g->e[11].v1=6;
  g->e[11].v2=8;
  g->e[11].cost=6;

  g->e[12].v1=2;
  g->e[12].v2=5;
  g->e[12].cost=4;

  g->e[13].v1=3;
  g->e[13].v2=5;
  g->e[13].cost=14;

  /*
  for(i=0; i<g->varfuri; i++)
  {
    printf("Date muchia %d:\n", i+1);
    g->e[i].v1=rand()%10+1;
    printf("V1=%d ", g->e[i].v1);
    g->e[i].v2=rand()%10+1;
    printf("V2=%d ", g->e[i].v2);
    g->e[i].cost=rand()%10+1;
    printf("Cost=%d ", g->e[i].cost);
    printf("\n");
  }
  */
  return g;
}

void Kruskal(graf *g)
{
  int i,j,min,max,nrMuchiiSelectate=0;
  int c[g->varfuri];

  for(i=0; i<g->varfuri; i++)
  {
    c[i]=i;
  }
  muchie a[g->varfuri-1];
  quick_sort(g->e,0,(g->muchii)-1);

  for(i=0; nrMuchiiSelectate<g->varfuri-1; i++)
  {
    if(c[g->e[i].v1]!=c[g->e[i].v2])
    {
      a[++nrMuchiiSelectate]=g->e[i];
    }

    if(c[g->e[i].v1]<c[g->e[i].v2])
    {
      min=c[g->e[i].v1];
      max=c[g->e[i].v2];
    }
    else
    {
      max=c[g->e[i].v1];
      min=c[g->e[i].v2];
    }

    for(j=0; j<g->varfuri; j++)
    {
      if(c[j]==max)
      {
        c[j]=min;
      }
    }
  }

  for(i=0; i<g->varfuri-1; i++)
  {
    printf("%d %d %d\n",a[i].v1,a[i].v2,a[i].cost);
  }
}

int main()
{
  graf *g=creategraf();
  printf("\nKruskal:\n");
  Kruskal(g);
}
