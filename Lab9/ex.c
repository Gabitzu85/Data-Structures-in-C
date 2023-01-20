#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct statie
{
  char nume[100];
  int index;
}statie;

typedef struct graf
{
  int varfuri;
  int muchii;
  int **a;
}graf;

void separare(char s[256],char a[256])
{
  char *p,aux[256];
  p=strtok(s,",");
  strcpy(a,s);
}

void verificare_copie_oras(char nume_oras[], statie s[], int *nr)  //nr reprezinta nr de statii
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

int indexi_matrice(char nume_statie[100], statie s[], int nr)
{
  for(int i=0; i<nr; i++)
  {
    if(strcmp(nume_statie,s[i].nume)==0)
    {
      return i;
    }
  }
}

graf *creare_graf(int nr, statie s[])
{
  FILE *f1, *f2;
  char nume_fila[50],nume_oras1[100],nume_oras2[100],nume_statie1[100],nume_statie2[100],aux[100];
  int orientat,cnt=0,i;
  int index_matrice1,index_matrice2;
  char *p;

  graf *g=(graf*)malloc(sizeof(graf));

  if(g==NULL)
  {
    printf("Memoria nu este destul de mare!\n");
    return NULL;
  }

  g->varfuri=nr;
  g->a=(int**)malloc(g->varfuri*sizeof(int*));

  for(i=0; i<g->varfuri; i++)
  {
    g->a[i]=(int*)calloc(g->varfuri,sizeof(int));
  }

  if(g->a==NULL)
  {
    printf("Memorie insuficienta pentru crearea matricei!!!\n");
    return NULL;
  }
  g->muchii=0;

  printf("Introduceti:\n\t -0 pentru orientat\n\t -orice alt nr pentru neorientat\n");
  scanf("%d", &orientat);

  if(orientat!=0)
  {
    if ((f1=fopen("_all_files.txt","rt"))==NULL)
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
        fgets(nume_oras2,100,f2);
        if(cnt!=1)
        {
          strcpy(nume_oras1,nume_oras2);
          p=strtok(nume_oras1,",");
          strcpy(nume_statie1,p);
          index_matrice1=indexi_matrice(nume_statie1,s,nr);
          cnt=1;
        }
        p=strtok(nume_oras2,",");
        strcpy(nume_statie2,p);
        index_matrice2=indexi_matrice(nume_statie2,s,nr);

        if(index_matrice1!=index_matrice2)
        {
          if(g->a[index_matrice1][index_matrice2]==0)
          {
            g->a[index_matrice1][index_matrice2]=g->a[index_matrice2][index_matrice1]=1;
            g->muchii=g->muchii+1;
          }
        }
        strcpy(nume_statie1,nume_statie2);
        index_matrice1=index_matrice2;
      }
      cnt=0;
    }
  }
  else
  {
    if ((f1=fopen("_all_files.txt","rt"))==NULL)
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
        fgets(nume_oras2,100,f2);
        if(cnt!=1)
        {
          strcpy(nume_oras1,nume_oras2);
          p=strtok(nume_oras1,",");
          strcpy(nume_statie1,p);
          index_matrice1=indexi_matrice(nume_statie1,s,nr);
          cnt=1;
        }
        p=strtok(nume_oras2,",");
        strcpy(nume_statie2,p);
        index_matrice2=indexi_matrice(nume_statie2,s,nr);

        if(index_matrice1!=index_matrice2)
        {
          if(g->a[index_matrice1][index_matrice2]==0)
          {
            g->a[index_matrice1][index_matrice2]=1;
            g->muchii=g->muchii+1;
          }
          strcpy(nume_statie1,nume_statie2);
          index_matrice1=index_matrice2;
        }
      }
      cnt=0;
    }
  }

  fclose(f1);
  fclose(f2);
  return g;
}

int main()
{
  FILE *f1, *f2;
  statie statii[1000];
  int i,nr=0;
  char nume_fila[50], nume_oras[100], nume_copie_oras[100];
  graf *graf_trenuri;
  char *p, s[256],aux[256];


  if ((f1=fopen("_all_files.txt","rt"))==NULL)
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
      separare(nume_oras,aux);
      printf("%s\n", aux);
      verificare_copie_oras(nume_oras,statii,&nr);
    }
  }

  //printf("%d\n", nr);
  //graf_trenuri=creare_graf(nr,statii);
  fclose(f1);
  fclose(f2);
}
