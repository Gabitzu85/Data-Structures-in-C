#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int val;
    struct node *next;
}node;

void adaugare(struct node **head, int x)
{

    struct node *new_node = malloc(sizeof(struct node));
    struct node *curr = *head;

    new_node->val = x;
    new_node->next = NULL;

    if (*head == NULL)
    {
      *head = new_node;
      return;
    }

    while (curr->next != NULL)
    {
      curr = curr->next;
    }
    curr->next = new_node;
}

struct node *stergere(struct node *head, int val)
{
  struct node *copie,*aux;
	aux=head;

	while(aux->next!=NULL && aux->val!=val)
    {
        copie=aux;
        aux=aux->next;
    }
    if(aux->next==NULL)
    {
      return NULL;
    }
    copie->next=aux->next;
}

void printare(struct node *nod)
{
    while (nod != NULL)
    {
      printf("%s ", nod->val);
      nod = nod->next;
    }
}

int main() {
    char s[256];
    struct node *head = NULL;
    FILE *f;
    if((f=fopen("fisier.txt","rt"))==NULL)
    {
      printf("Eroare la deschiderea fisierului!\n");
    }

    while (fgets(s, sizeof(s), f))
    {
      adaugare(&head, s);
    }
    fclose(f);


    printare(head);
    //stergere(head,8); //functia de stergere nu functioneaza
    //printare(head);
    return 0;
}
