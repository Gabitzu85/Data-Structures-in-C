#include <stdio.h>
#include <stdlib.h>

int nr_elemente,cnt_permutari,cnt_combinari,v[100],m,v1[100];

void swap (int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void printare(int v[])
{
  int i;

  for(i=0; i<nr_elemente; i++)
  {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void permutari(int v[], int n)
{
  int i;
  if(n==1)
  {
    printare(v);
    cnt_permutari++;
  }

  for(i=0; i<n; i++)
  {
    permutari(v,n-1);

    if(n%2==1)
    {
      swap(&v[0],&v[n-1]);
    }
    else
    {
      swap(&v[i],&v[n-1]);
    }
  }
}

void combinari(int v[], int tmp_v1[], int start, int end, int index, int k) //index-indexul pt vect auxiliar v1
{
  if(index==k)
  {
    cnt_combinari++;
    for(int i=0; i<m; i++)
    {
      printf("%d ", tmp_v1[i]);
    }
    printf("\n");
    return;
  }
  for(int j=start; j<=end && end-j+1>=k-index; j++)
  {
    tmp_v1[index]=v[j];
    combinari(v,tmp_v1,j+1,end,index+1,k);
  }
}

void printare_combinari(int v[], int n, int k)
{
  int tmp_v1[k];
  combinari(v,tmp_v1,0,n-1,0,k);
}

int main()
{
  int i;
  printf("Cate nr doriti sa introduceti: \n");
  scanf("%d", &nr_elemente);
  printf("Introduceti numerele:\n");
  for(i=0; i<nr_elemente; i++)
  {
    scanf("%d", &v[i]);
  }

  printf("\nPermutari:\n\n");
  permutari(v,nr_elemente);
  printf("Sunt %d permutari!\n", cnt_permutari);

  printf("Introduceti k (k<=n):\n");
  scanf("%d", &m);
  printf("\nCombinari:\n\n");
  printare_combinari(v,nr_elemente,m);
  printf("Sunt %d combinari!\n", cnt_combinari);
}
