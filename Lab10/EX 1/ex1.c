#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int v1,v2,cost;
}Muchie;

typedef struct
{
  int V,E;
  Muchie *e;
}Graph;

void swap(Muchie* a, Muchie* b)
{
  Muchie aux;
  aux=*a;
  *a=*b;
  *b=aux;
}

int partition(Muchie* arr, int low, int high)
{
  int j;
  Muchie aux;
  Muchie pivot=arr[high];

  int i=(low-1);
  for(j=low; j<=high-1; j++)
    if(arr[j].cost<=pivot.cost)
    {
      i++;
      swap(&arr[i],&arr[j]);
    }

  swap(&arr[i+1],&arr[high]);
  return (i+1);
}

void quickSort(Muchie* arr, int low, int high)
{
  if(low<high)
  {
    int pi=partition(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}

Graph* creategraf()
{
  int i=0;
  FILE *f1;

  Graph *g=malloc(sizeof(Graph));
  g->e=(Muchie*)malloc(14*sizeof(Muchie));
  //g->varfuri=rand()%10+1;
  g->V=8;
  printf("Nr varfuri = %d\n",g->V);
  //g->muchii=rand()%10+1;
  g->E=13;
  printf("Nr muchii = %d\n",g->E);

  printf("\n");

  if((f1=fopen("ex1.txt","rt"))==NULL)
  {
    printf("Eroare la deschiderea fisierului!\n");
    exit(0);
  }

  while(fscanf(f1,"%d %d %d", &g->e[i].v1, &g->e[i].v2, &g->e[i].cost)!=EOF)
  {

    printf("%d %d %d\n", g->e[i].v1, g->e[i].v2, g->e[i].cost);
    i++;
  }

  return g;
}

void Kruskal(Graph *g)
{
  int i, j, min, max, nrMuchiiSelectate=0;
  int c[g->V];
  Muchie a[g->V-1];
  for (i=0;i<g->V;i++)
  {
   c[i]=i;
  }

  quickSort(g->e, 0, (g->E)-1);

  for (i=0; nrMuchiiSelectate< g->V-1; i++)
  {
    if (c[g->e[i].v1] != c[g->e[i].v2])
    {
        nrMuchiiSelectate++;
        a[nrMuchiiSelectate]=g->e[i];
    }

    if (c[g->e[i].v1] < c[g->e[i].v2])
    {
        min=c[g->e[i].v1];
        max=c[g->e[i].v2];
    }
    else
    {
        max=c[g->e[i].v1];
        min=c[g->e[i].v2];
    }
      for (j=0;j<g->V ;j++)
      if (c[j]==max)
       c[j]=min;
     }

     for (i=0;i<g->V-1 ;i++)
     printf("%d %d %d\n", a[i].v1, (a[i].v2),(a[i].cost));
}

int main()
{
  Graph *g=creategraf();
  printf("\nKruskal:\n");
  Kruskal(g);
}
