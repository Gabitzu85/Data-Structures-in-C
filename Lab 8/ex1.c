#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct statie
{
  char nume[100];
  int index;
}statie;

void verificare(char nume_oras[], statie s[], int *nr)  //nr reprezinta nr de statii
{
  int i,gasit=0;

  if(*nr==0)
  {
    strcpy(s[*nr].nume,nume_oras);
    s[*nr].index=*nr;
    (*nr)++;
    gasit=1;
  }
  else
  {
    for (i=0; i<*nr; i++)
    {
      if(strcmp(s[i].nume,nume_oras)==0)
      {
        gasit=1;
        break;
      }
    }
  }

  if(gasit==0)
  {
    strcpy(s[*nr].nume,nume_oras);
    s[*nr].index=*nr;
    (*nr)++;
  }
}

int main()
{
  FILE *f1, *f2;
  statie statii[1000];
  int i,nr=0;
  char nume_fila[50], nume_oras[100], nume_copie_oras[100];

  if ((f1=fopen("all_files.txt","rt"))==NULL)
  {
    printf("Eroare la deschiderea fisierului!\n");
    exit(1);
  }

  while(!feof(f1))
  {
    fscanf(f1,"%s",nume_fila);
    if((f2=fopen(nume_fila,"rt"))==NULL)
    {
      printf("Eroare la deschiderea fisierului!\n");
      exit(1);
    }

    while(!feof(f2))
    {
      fgets(nume_oras,100,f2);
      if(strcmp(nume_oras,nume_copie_oras)!=0)
      {
        verificare(nume_oras,statii,&nr);
      }
      strcpy(nume_copie_oras,nume_oras);
    }
  }

  for(i=0; i<nr; i++)
  {
    printf("%d %s ", statii[i].index, statii[i].nume);
  }

  fclose(f1);
  fclose(f2);
}
