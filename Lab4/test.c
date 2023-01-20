#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int b;

void modificare(int *val)
{
  *val=6;
  b=15;
}

typedef struct node
{
  int val;
  struct node *next;
}node;

node *get_node(int val)
{
  node *newnode=(node*)malloc(sizeof(node));
  newnode->val=val;
  newnode->next=NULL;
  return newnode;
}

void afisare(node *head)
{
  while(head!=NULL)
  {
    printf("%d\n", head->val);
    head=head->next;
  }
}

void inserare(node **head, int val, int poz)
{
  int poz_curenta=0;
  if((*head)==NULL)
  {
    *head=get_node(val);
  }
  else
  {
    node *newnode=get_node(val);
    node *headcopie=*head;
    while(poz_curenta < poz - 1)
    {
      headcopie=headcopie->next;
      poz_curenta++;
    }
    newnode ->next=headcopie->next;
    headcopie->next=newnode;
  }
}

int main()
{
  int var=5;
  b=10;
  printf("a = %d\n", var);
  printf("b = %d\n", b);
  modificare(&var);
  printf("a = %d\n", var);
  printf("b = %d\n", b);
  printf("Adresa a = %x\n", &var);

  node *head=NULL;
  head=get_node(10);
  head->next=get_node(11);
  head->next->next=get_node(12);
  afisare(head);
  printf("\n");
  inserare(&head,13,1);
  afisare(head);
}
