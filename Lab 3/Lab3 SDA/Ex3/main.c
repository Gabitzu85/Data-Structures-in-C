#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"


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
