#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int v[20], n = 0, i, j, aux;
  FILE *fin;
  if((fin = fopen("input.txt", "rt")) == NULL)
  {
    printf("Eroare la deschiderea fisierului!");
  }

  while(!feof(fin))
  {
    fscanf(fin,"%d",&v[n]);
    n++;
  }

  fclose(fin);
  for(i = 0; i < n; i++)
  {
    for(j = i + 1; j < n; j++)
    {
      if(v[i] < v[j])
      {
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }
    }
  }

  for(i=0; i<n; i++)
  {
    //printf("%d ", v[i]);  //vectorul creat este ordonat descrescator
  }

  int nr = 0;
  for(i = 0; i < n; i++)
  {
    nr = nr * 10 + v[i];  //nr final nu este corect
  }

  FILE *fout;
  if((fout = fopen("output.txt", "wt")) == NULL)
  {
    printf("Eroare la deschiderea fisierului!");
  }
  fprintf(fout,"%d", nr);
  return 0;
}
