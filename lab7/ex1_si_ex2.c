#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define BYTE 8
#define COUNT_BYTE 256

int cnt_cerne,cnt_make_heap,cnt_interschimbare;

void interschimbare(int v[],int i,int j)
{
  cnt_interschimbare++;
  int aux;
  aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

void cerne(int v[],int n,int k)
{
  cnt_cerne++;
  int f_stanga=2*k+1;
  int f_dreapta=2*k+2;
  int poz_max=f_stanga;

  if(f_stanga>=n)
  {
    return;
  }

  if(f_dreapta<n)
  {
    if(v[f_dreapta]>v[f_stanga])
    {
      poz_max=f_dreapta;
    }
  }

  if(v[k]<v[poz_max])
  {
    interschimbare(v,k,poz_max);
    cerne(v,n,poz_max);
  }
}

void make_heap(int v[],int n)
{
  int i;
  cnt_make_heap++;
  for(i=n/2; i>=0; i--)
  {
    cerne(v,n,i);
  }
}

void heap_sort(int v[],int n)
{
  make_heap(v,n);
  while(n>1)
  {
    interschimbare(v,0,n-1);
    n--;
    cerne(v,n,0);
  }
}

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
  n=1000000;
  int *v1=(int*)malloc(n*sizeof(int));
  int *v2=(int*)malloc(n*sizeof(int));

  for(i=0; i<n; i++)
  {
    v1[i]=v2[i]=rand()%1000000+1;
  }

  clock_t heap_start=clock();
  heap_sort(v1,n);
  clock_t heap_end=clock();

  clock_t radix_start=clock();
  radix_sort(v2,n);
  clock_t radix_end=clock();

  printf("Heap a realizat sortarea in %lf secunde!\n", (double)(heap_end-heap_start)/CLOCKS_PER_SEC);
  printf("Radix a realizat sortarea in %lf secunde!\n", (double)(radix_end-radix_start)/CLOCKS_PER_SEC);

  printf("Functia cerne a fost apelata de %d ori!\n", cnt_cerne);
  printf("Nr de apelari necesare pentru construirea heap-ului este %d!\n", cnt_make_heap);
  printf("Nr de apelari necesare pentru tot algoritmul heap sort este %d!\n", cnt_cerne+cnt_interschimbare+cnt_make_heap+1);  //+1 deoarece functia hea_sort este apelata o singura data in main
}
