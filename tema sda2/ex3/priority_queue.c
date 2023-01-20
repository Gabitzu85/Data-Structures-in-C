#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct queue
{
  unsigned short int prioritate; //prioritate maxima = nr cat mai mic (consider 1 ca fiind prioritatea maxima)
  signed short int val;
  struct queue *next;
} queue;

queue *create_queue(signed short int val, unsigned short int prioritate)
{
  queue *aux = (queue *)malloc(sizeof(queue));
  aux->prioritate = prioritate;
  aux->val = val;
  aux->next = NULL;
  return aux;
}

void push(queue **q, signed short int val, unsigned short int prioritate)
{
  queue *copie = *q;
  queue *tmp = create_queue(val, prioritate);
  if ((*q)->prioritate > prioritate)
  {
    tmp->next = *q;
    *q = tmp;
  }
  else
  {
    while (copie->next != NULL && copie->next->prioritate < prioritate)
    {
      copie = copie->next;
    }
    tmp->next = copie->next;
    copie->next = tmp;
  }
}

void queue_pop(queue **q)
{
  queue *aux = *q;
  *q = (*q)->next;
  free(aux);
}

int queue_empty(queue **q)
{
  return ((*q) == NULL);
}

int main()
{
  srand(time(0));
  queue *q = create_queue(rand() % 1000 - 500, 1); //creez primul element random care are mereu prioritatea 1
  int n = rand() % 10 + 1, i;                      //nr de elemente cuprins intre 1 si 10
  printf("n=%d\n", n);
  for (i = 0; i < n - 1; i++)
  {
    push(&q, rand() % 1000 - 500, rand() % 10 + 1);
  }

  while (!queue_empty(&q))
  {
    printf("Prioritate: %d\n", q->prioritate);
    printf("Valoare: %d\n", q->val);
    queue_pop(&q);
  }
}
