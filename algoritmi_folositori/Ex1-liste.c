#include <stdio.h>
#include <stdlib.h>


//nu stiu sa lucrez cu liste circulare sau dublu
//inlantuite deoarece nu au fost facute semestrul
//trecut asa ca voi face o lista simplu inlantuita

typedef struct lista
{
  char nume[25];
  char tel[25];
  char post[25];
  struct lista* urmator;
}lista;

lista *prim, *anterior,*curent;
int apelat=1;

void adaugare()
{
  curent=(lista*) malloc(sizeof(lista));

  if(apelat==1)
  {
    prim=curent;
    apelat=0;
  }
  else
  {
    anterior->urmator=curent;
  }
  curent->urmator=NULL;
  anterior=curent;
  printf("Nume: \n");
  fflush(stdin);
  scanf("%s", &curent->nume);
  printf("Telefon:\n");
  fflush(stdin);
  scanf("%s", &curent->tel);
  printf("Post:\n");
  fflush(stdin);
  scanf("%s", &curent->post);
}

void citire_lista()
{
  curent=prim;
  while(curent->urmator!=NULL)
  {
    printf("%s %s %s\n", curent->nume,curent->tel,curent->post);
    curent=curent->urmator;
  }
  printf("%s %s %s\n", curent->nume,curent->tel,curent->post);
}



int main()
{
  int i;
  for(i=0; i<4; i++)
  {
    adaugare();
  }
  citire_lista();
  //mare_mue(&curent,3,"marian","u","inginer");
}
