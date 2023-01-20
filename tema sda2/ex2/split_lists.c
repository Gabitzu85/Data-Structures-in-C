#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

typedef struct elem
{
  int val;
  struct elem *next;
}elem;

typedef struct elem2
{
  int val;
  struct elem2 *next;
}elem2;

void push(elem **cap,elem2 **cap2)
{
  elem* nod=(elem*)malloc(sizeof(elem));
  elem2* nod2=(elem2*)malloc(sizeof(elem2));
  int x;  //creez cate un element aleator 

  x=rand()%10-5;  //creez cate un element aleator intre -5 si 5


  if(x>=0)
  {
    nod->val=x;
    nod->next=*cap;
    *cap=nod;
  }
  if(x<0)
  {
    nod2->val=x;
    nod2->next=*cap2;
    *cap2=nod2;
  }
}

int empty(elem *cap)
{
  return cap==NULL;
}

int empty2(elem2 *cap)
{
  return cap==NULL;
}

int pop(elem **cap)
{
  elem *aux=*cap;
  int val=aux->val;

  *cap=(*cap)->next;
  free(aux);
  return val;
}

int pop2(elem2 **cap)
{
  elem2 *aux=*cap;
  int val=aux->val;

  *cap=(*cap)->next;
  free(aux);
  return val;
}

void printare(elem *cap)
{
  while(!empty(cap))
	{
		printf("%d ", pop(&cap));
	}
}
void printare2(elem2 *cap)
{
  while(!empty2(cap))
	{
		printf("%d ", pop2(&cap));
	}
}

int main()
{
  srand(time(0));
  int n,i;
  n=rand()%10+1;  //nr de elemente al vectorului
  printf("n=%d\n",n);
  elem *cap=NULL;
  elem2 *cap2=NULL;
  for(i=0; i<n; i++)
  {
    push(&cap,&cap2);
  }

  printf("Elementele pozitive:\n");
  printare(cap);
  printf("\nElementele negative:\n");
  printare2(cap2);
}
