#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
  int val;
  struct lista *urmator;
};

struct lista *cap;

void creeare_nod(int n)
{
  struct lista *aux,*nod_nou;
  int i;
  cap=(struct lista*)malloc(sizeof(struct lista));
  if(cap==NULL)
  {
    printf("Problema cu memoria!!!");
  }
  else
  {
    cap->val=NULL;
    cap->urmator=NULL;
    aux=cap;

    for(i=2; i<=n; i++)
    {
      nod_nou=(struct lista*)malloc(sizeof(struct lista));
      if(nod_nou==NULL)
      {
        printf("Problema cu memoria!!!");
        break;
      }
      else
      {
        nod_nou->val=rand()%10;
        nod_nou->urmator=NULL;
        aux->urmator=nod_nou;
        aux=aux->urmator;
      }
    }
  }
}

void pare()
{
  struct lista *aux=cap;
  printf("Doar nr pare:\n");
  while(aux!=NULL)
  {
    if(aux->val%2==0)
    {
      printf("%d ", aux->val);
    }
    aux=aux->urmator;
  }
}


void printare_lista(void)
{
  struct lista *aux;
  if(cap==NULL)
  {
    ;
  }
  else
  {
    aux=cap;
    while(aux!=NULL)
    {
      printf("%d ", aux->val);
      aux=aux->urmator;
    }
  }
}

int main()
{
  srand(time(0));
  int n=rand()%10+1;
  printf("n=%d\n", n);

  creeare_nod(n);
  printare_lista();
  pare();
}
