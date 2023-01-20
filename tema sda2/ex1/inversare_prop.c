#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct elem
{
  char cuv[256];
  struct elem *next;
}elem;

void push(elem **cap, char cuv[256])
{
  elem* nod=(elem*)malloc(sizeof(elem));
  strcpy(nod->cuv,cuv);
  nod->next=*cap;
  *cap=nod;
}

int empty(elem *cap)
{
  return cap==NULL;
}

char *pop(elem **cap)
{
  elem *aux=*cap;
  static char cuv[256];
  strcpy(cuv,aux->cuv);
  *cap=(*cap)->next;
  free(aux);
  return cuv;
}

void printare(elem *cap)
{
  FILE *fp;

  if((fp=fopen("output.txt","w"))==NULL)
  {
    printf("Eroare la deschiderea fisierului!");
  }

  while(!empty(cap))
	{
		fprintf(fp,"%s ", pop(&cap));
	}
  fclose(fp);
}

void printare_txts()
{
  FILE *f1,*f2;
  char s1[256],s2[256];

  if((f1=fopen("input.txt","rt"))==NULL)
  {
    printf("Eroare la deschiderea fisierului!");
  }

  if((f2=fopen("output.txt","rt"))==NULL)
  {
    printf("Eroare la deschiderea fisierului!");
  }

  printf("Continutul input.txt:\n");
  while(!feof(f1))
  {
    fscanf(f1,"%s ", s1);
    printf("%s ", s1);
  }

  printf("\nContinutul output.txt:\n");
  while(!feof(f2))
  {
    fscanf(f2,"%s ", s2);
    printf("%s ", s2);
  }
  fclose(f1);
  fclose(f2);
}

int main()
{
  FILE *f;
  char s[256];
  elem *cap=NULL;

  if((f=fopen("input.txt","rt"))==NULL)
  {
    printf("Eroare la deschiderea fisierului!");
  }

  while(!feof(f))
  {
    fscanf(f,"%s ",s);
    push(&cap,s);
  }
  printare(cap);

  printare_txts();

  fclose(f);
}
