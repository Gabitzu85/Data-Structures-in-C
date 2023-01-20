#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int vectoru_ala_mare[20000],  iteratotu_pentru_vectoru_ala_mare=-1;

void back(int k, int n, int a, int v[], int sol[])
{
  int i, numar=0;
  if (k != n)
  for (i=0; i<a; i++)
  {
    sol[k] = v[i];
    back(k+1, n, a, v, sol);
  }
  else if(k == n)
  {
    for(i=0;i<n;i++)
    {
      printf("%d ",sol[i]);
      numar += pow(10, i) * sol[i];
    }
    //printf("%d",numar);
    vectoru_ala_mare[++iteratotu_pentru_vectoru_ala_mare] = numar;
    numar = 0;
    printf("\n");
  }

}

int main ()
{
  FILE *f;
  int n=4, a=2, v[]={1,2}, sol[10], i, n2=0, ok=0,j;
  int v2[1000];

  f = fopen("sexclude.txt", "rt");
  if (!f)
  {
    printf("Nu se deschide!");
    exit(1);
  }

  while(!feof(f))
  {
    fscanf(f, "%d", &v2[n2]);
    n2++;
  }
  fclose(f);
  back(0, n, a, v, sol);



 f = fopen("output.txt", "wt");
  for (i=0; i<iteratotu_pentru_vectoru_ala_mare; i++)
  {
    for(j=0; j<n2; j++)
    {
  if(vectoru_ala_mare[i] == v2[j])
    {
      ok = 1;
      break;
    }

    }

    if (ok != 1)
    fprintf(f,"%d \n", vectoru_ala_mare[i]);
    ok = 0;
  }
fclose(f);
    return 0;
}
