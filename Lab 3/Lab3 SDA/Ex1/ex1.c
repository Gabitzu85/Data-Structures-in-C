#include "ex1.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void creare(pers **cap, char nume[50], char tel[11], char post[50])
{
  if(*cap == NULL)
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
