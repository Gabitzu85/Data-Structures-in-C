#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "string.h"

void sortare(char v[][5], int *n)
{
  char aux[5];
  int i,j;

  for(j=0; j<(*n)-1; j++)
  {
    for(i=j+1; i<*n; i++)
    {
      if(strcmp(v[j],v[i])>0)
      {
        strcpy(aux,v[j]);
        strcpy(v[j], v[i]);
        strcpy(v[i], aux);
      }
    }
  }
}

int main()
{
  srand(time(0));
  int n,i,j;
  char v[10][5];
  char alfabet[26]={"abcdefghijklmnopqrstuvxyz"};

  n=rand()%10+1;
  printf("n=%d\n", n);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < 4; j++)
    {
      v[i][j]=alfabet[rand()%25];
      v[i][4]='\0';
    }
  }

  printf("Vector nesortat: \n");
  for (i = 0; i < n; i++)
  {
    printf("%s ", v[i]);
  }

  sortare(v,&n);

  printf("\nVector sortat: \n");
  for (i = 0; i < n; i++)
  {
    printf("%s ", v[i]);
  }
}
