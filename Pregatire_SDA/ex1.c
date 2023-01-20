#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  char cuvant[100];
  struct Node *next;
};

struct Node *append(struct Node* head_ref, char new_data[])
{
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

  struct Node *last = head_ref;
  strcpy(new_node->cuvant,new_data);

  new_node->next = NULL;
  if (head_ref == NULL)
  {
    head_ref = new_node;
    return head_ref;
  }

  while (last->next != NULL)
  {
    last = last->next;
  }

  last->next = new_node;
  return head_ref;
}

int main ()
{
  FILE *f;
  char p[200], *cuv, manevra[200];
  struct Node *head = NULL, *headcopy = NULL;
  int lungime = 0;

  f = fopen("ex1_input.txt", "rt");
  if (!f)
  {
    printf("Nu se deschide!");
    exit(1);
  }

  fgets(p, 1000, f);
  fclose(f);

  cuv = strtok(p, " ");
  while (cuv != NULL)
  {
    strcpy (manevra, cuv);
    head = append(head, manevra);
    lungime++;
    cuv = strtok(NULL, " ");
  }

  headcopy = head;
  f = fopen("output1.txt", "wt");
  fprintf(f,"%d\n",lungime);
  while(headcopy != NULL)
  {
    fprintf(f,"%s %d\n",headcopy -> cuvant,strlen(headcopy -> cuvant));
    headcopy = headcopy -> next;
  }

  return 0;
}
