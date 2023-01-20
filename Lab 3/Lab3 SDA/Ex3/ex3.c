#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex2.h"
void adaugare_inceput(lista **cap)
{
  lista* nod_nou=(lista*)malloc(sizeof(lista));
  if(nod_nou!=NULL)
  {
    nod_nou->valoare=rand()%10;
    nod_nou->urmator=*cap;
    *cap=nod_nou;
  }
  else
  {
    printf("Alocare esuata!\n");
  }
}

void printare(lista *cap)
{
  while (cap!=NULL)
  {
    printf("%d ", cap->valoare);
    cap=cap->urmator;
  }
}

void stergere_pare(lista **cap)
{
  lista* aux=*cap;
  lista* par;

  while(aux!=NULL && aux->valoare%2==0)
  {
    aux=aux->urmator;
  }

  *cap=aux;

  if(aux==NULL)
  {
    return;
  }

  par=aux;
  aux=aux->urmator;

  while(aux!=NULL)
  {
    if(aux->valoare%2!=0)
    {
      par->urmator=aux;
      par=aux;
    }
    aux=aux->urmator;
  }
  par->urmator=NULL;
}
