#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
  char cuv[50];
  struct lista *next;
}lista;

typedef struct stack
{
  struct lista *head;
}stack;

stack *create_stack()
{
  stack *stack=(stack*)malloc(sizeof(stack));
  stack->head=NULL;
  return stack;
}

int stack_empty(stack *stack)
{
	return stack->head==NULL;
}

char stack_pop(stack *stack)
{
	//int val = 0;
	if(stack_empty(stack))
	return 5;

	lista *cap=stack->head;
	char val[50];
  strcpy(val,cap->cuv);

	stack->head=stack->head->next;
	free(cap);
	return val;
}

void stack_print(stack *stack)
{
  while(!stack_empty(stack))
	{
		printf("%s ", stack_pop(stack));
	}
}

void push(stack *stack)
{
  lista *node=(lista*)malloc(sizeof(lista));
  lista *copie=stack->head;
  FILE *f;

  if((f=fopen("propozitie.txt","rt"))==NULL)
  {
    printf("Eroare la deschiderea fisierului!");
  }

  fscanf(f,"%s",copie->cuv);

  while(!feof(f))
  {
    lista *nou=(lista*)malloc(sizeof(lista));
    fscanf(f,"%s ", nou->cuv);
    nou->next=stack->head;
    stack->head=node;
  }


  fclose(f);
}

int main()
{
  stack *stack = create_stack();
  push(stack);
  stack_print(stack);
}
