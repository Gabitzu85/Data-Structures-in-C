#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  FILE *f;
  int v[100],i=0,j,n=0;

  if((f=fopen("ex2_input.txt","rt"))==NULL)
  {
    printf("Eroare la deschiderea fisierului!\n");
    exit(1);
  }

  while(fscanf(f,"%d \n", &v[i])!=EOF)
  {
    printf("%d ", v[i]);
    i++;
    n++;
  }

  int a=v[0];
  int b=v[1];

  for(i=0; i<n; i++)
  {
    for(j=i+1; j<n; j++)
    {
      if(v[i]*v[j]>a*b)
      {
        a=v[i];
        b=v[j];
      }
    }
  }
  printf("\nProdusul maxim este %d format de perechea (%d,%d)\n", a*b,a,b);
  fclose(f);
}
