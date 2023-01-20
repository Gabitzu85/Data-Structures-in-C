#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct pers
{
  char nume[50],tel[11],post[50];
  struct pers *prev;
  struct pers *next;
}pers;

void creare(pers **cap, char nume[50], char tel[11], char post[50])
{
  if(*cap==NULL)
  {
    pers *new_node=(pers*)malloc(sizeof(pers));
    strcpy(new_node->nume,nume);
    strcpy(new_node->tel,tel);
    strcpy(new_node->post,post);
    new_node->next=new_node->prev=new_node;
    *cap=new_node;
    return;
  }
  else
  {
  pers *ultim=(*cap)->prev;
  pers*new_node=(pers*)malloc(sizeof(pers));
  strcpy(new_node->nume,nume);
  strcpy(new_node->tel,tel);
  strcpy(new_node->post,post);
  new_node->next=*cap;
  (*cap)->prev=new_node;
  new_node->prev=ultim;
  ultim->next=new_node;
  }
}

void afisare(pers *cap)
{
  pers *aux = cap;
  while (aux->next != cap)
  {
    printf("%s %s %s \n", aux->nume, aux->tel, aux->post);
    aux = aux->next;
  }
  printf("%s %s %s \n", aux->nume, aux->tel, aux->post);
}

void adauga_dupa(pers **cap,int poz)
{
  pers *new_node=(pers*)malloc(sizeof(pers));
  pers *copie=*cap;
  while(poz!=1)
  {
    copie=copie->next;
    poz--;
  }
  printf("\nIntroduceti date pentru angajatul ce urmeaza sa fie introdus dupa pozitia a treia:\n");
  printf("Nume:\n");
  fflush(stdin);
  scanf("%s", new_node->nume);
  printf("Telefon:\n");
  fflush(stdin);
  scanf("%s", new_node->tel);
  printf("Post:\n");
  fflush(stdin);
  scanf("%s", new_node->post);

  new_node->prev=copie;
  new_node->next=copie->next;
  copie->next=new_node;
  copie=copie->next->next;
  copie->prev=new_node;
}

void introducere_nou(pers **cap)
{
  pers *new_node=(pers*)malloc(sizeof(pers));
  pers *copie=*cap;

  while(copie->next!=NULL && strcmp(copie->post,"mecanic")!=0)
  {
    copie=copie->next;
  }

  printf("\nIntroduceti alte date:\n");
  printf("Nume:\n");
  fflush(stdin);
  scanf("%s", new_node->nume);
  printf("Telefon:\n");
  fflush(stdin);
  scanf("%s", new_node->tel);
  printf("Post:\n");
  fflush(stdin);
  scanf("%s", new_node->post);
  new_node->next=copie;
  new_node->prev=copie->prev;
  copie->prev=new_node;
  copie=new_node->prev->prev;
  copie->next=new_node;
}

void stergere(pers **cap)
{
  pers *copie=*cap,*sters;
  char telefon[11];
  printf("Introduceit nr de telefon pe care doriti sa il stergeti:\n");
  fflush(stdin);
  gets(telefon);

  while(copie->next!=NULL && strcmp(copie->tel,telefon)!=0)
  {
    copie=copie->next;
  }

  sters=copie;
  copie=copie->next;
  copie->prev=sters->prev;
  copie=copie->prev;
  copie->next=sters->next;
  free(sters);
}

int main()
{
  pers *cap=NULL;
  creare(&cap,"Andrei","0785678432","inginer");
  creare(&cap,"Ioana","0759658538","electrician");
  creare(&cap,"Gica","0567854967","farmacist");
  creare(&cap,"Mirel","0557894286","mecanic");
  creare(&cap,"Badea","0674862389","psiholog");
  creare(&cap,"Bartolomeu","0106584957","antrenor");
  printf("Lista initiala: \n\n");
  //afisare(cap);

  //adauga_dupa(&cap,3);
  //introducere_nou(&cap);
  stergere(&cap);

  afisare(cap);
}
