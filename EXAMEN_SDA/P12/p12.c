#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Muchie
{
  int v1, v2, cost;
}Muchie;

typedef struct Graph
{
  int V;
  int E;
  Muchie *e ;
}Graph;

typedef struct
{
  int V,E;
  int **a;
}Graph;

Graph * alocGraph(int var, int muc)
{
  int i, j, k, x, y, w;
  FILE *f;
  Graph g =(Graph*) malloc(sizeof(Graph));

  if (g==NULL)
    return NULL;

  f = fopen("input.txt", "rt");
  if (f == NULL)
  {
    printf("\nEroare la deschidere!!!\n");
  }
  g->V=var;
  g->E=muc;

  g->e = (Muchie*)malloc(sizeof(Muchie)g->E);

for (i=0;i<g->E;i++)
{
  fscanf(f,"%d %d %d",&x , &y, &w);

  (g->e[i].v1)=x;
  (g->e[i].v2)=y;
  (g->e[i].cost )=w;
}
fclose(f);

     return g;
}

int printSolution(int dist[], int n)
{
  FILE *f;
  f = fopen("output.txt", "wt");
  fprintf(f, "%d %d", n, dist[n]);
  fclose(f);
}

int minDistance(int dist[], int sps[], int V)
{
  int v, min =  INT_MAX, min_index;
  for ( v = 0; v < V; v++)
  if (sps[v] == 0 && dist[v] <= min)
  {
     min = dist[v];
     min_index= v;
  }
   return min_index;
}

void dijkstra(Graph *g, int s)
{
  int i, j, u;
  int dist[g->V];
  int sps[g->V];

  for (i=0; i<g->V; i++)
  {
     dist[i] = INT_MAX;
     sps[i] = 0;
  }
  dist[s] = 0;
  for (j = 0; j < g->V-1; j++)
  {
    u = minDistance(dist, sps, g->V);
    printf("%d\n",u);
    sps[u] = 1;
    for (i = 0; i < g->V; i++)
    {
      if (sps[i] == 0 && g->a[u][i]!=0  && dist[u] != INT_MAX &&  dist[u]+g->a[u][i] < dist[i])
      dist[i] = dist[u] + g->a[u][i];
    }
  }
}

int main()
{
  int nod1,nod2,cost;
  Graph *g;
  FILE *f;
  if((f=fopen("input.txt","rt"))==NULL)
  {
    printf("Eroare la deschiderea fisierului!\n");
    exit(1);
  }
  //Am facut doar citirea din fisier a variabilelor nod1 nod2 cost
  while(!feof(f))
  {
    fscanf(f,"%d %d %d", &nod1, &nod2, &cost)
  }

  fclose(f);
}
