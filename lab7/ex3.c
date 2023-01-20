#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define BYTE 8
#define COUNT_BYTE 256

int obtine_octetul(int n,int byteNr)
{
  int bitsNr =  BYTE * byteNr;
  int mask = COUNT_BYTE - 1;
  return (n >> bitsNr) & mask;
}

void rad(int *a,int *b, int byteNr,int n)
{
  int i;
  int count[COUNT_BYTE] = {0};
  int index[COUNT_BYTE] = {0};

  for(i=0; i<n; i++)
  {
    int car = obtine_octetul(a[i],byteNr);
    count[car]++;
  }

  for(i=1; i<COUNT_BYTE; i++)
  {
    index[i]=index[i-1]+count[i-1];
  }

  for(i=0; i<n; i++)
  {
    int car=obtine_octetul(a[i],byteNr);
    b[index[car]++]=a[i];
  }
}

void radix_sort(int *a,int n)
{
  int *b = (int*)malloc(n*sizeof(int));
  int byteNr;
  int k = sizeof(a[0]);

  for(byteNr=0; byteNr<k; byteNr+=2)
  {
    rad(a, b, byteNr, n);
    rad(b, a, byteNr + 1, n);
  }

  free(b);
}

int main()
{
  srand(time(0));
  int i,n;
  n=rand()%10+1;
  int *v=(int*)malloc(n*sizeof(int));
  printf("n=%d\n", n);

  for(i=0; i<n; i++)
  {
    v[i]=rand()%100-50;
  }

  printf("Vectorul initial nesortat:\n");
  for(i=0; i<n; i++)
  {
    printf("%d ", v[i]);
  }

  printf("\n");
  radix_sort(v,n);


  printf("Vectorul sortat:\n");
  for(i=0; i<n; i++)
  {
    if(v[i]<0)
    printf("%d ", v[i]);
  }

  for(i=0; i<n; i++)
  {
    if(v[i]>=0)
    printf("%d ", v[i]);
  }
}
