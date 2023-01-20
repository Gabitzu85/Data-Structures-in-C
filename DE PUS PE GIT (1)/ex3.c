#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
  int valoare;
  struct lista* urmator;
}lista;

void adaugare_inceput(lista **cap, int n)
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


int main()
{
  srand(time(0));
  int i,n;
  n=rand()%10+1;

  printf("n=%d\n", n);

  lista *cap=NULL;
  for ( i = 0; i < n; i++)
  {
    adaugare_inceput(&cap,i);
  }
  printf("Elementele listei sunt: \n");
  printare(cap);
  stergere_pare(&cap);
  printf("\n");
  printf("Lista fara numere pare:\n");
  printare(cap);
}
