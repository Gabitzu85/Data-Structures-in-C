#include <stdio.h>
#include <stdlib.h>


//nu stiu sa lucrez cu liste circulare sau dublu
//inlantuite deoarece nu au fost facute semestrul
//trecut asa ca voi face o lista simplu inlantuita

typedef struct node_t
{
  char nume[25];
  char tel[25];
  char meserie[25];
  struct lista* urm;
}node_t;

node_t *creare(char nume[25], char tel[25], char meserie[25])
{
  node_t *nod_nou=(node_t*)malloc(sizeof(node_t));
  strcpy(nod_nou->nume,nume);
  strcpy(nod_nou->tel,tel);
  strcpy(nod_nou->meserie,meserie);
  nod_nou->urmator=NULL;

  return nod_nou;
}

node_t *printare(node_t *cap)
{
  node_t *aux;
  aux=cap;
  while(aux!=NULL)
  {
    printf("%s %s %s\n", aux->nume,aux->tel,aux->meserie);
    printf("\n");
    aux=aux->urm;
  }
  return aux;
}


int main()
{
  node_t *cap=NULL;
  creare(cap,"Adi","075646546","inginer");
  printare(cap);
}
