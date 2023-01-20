#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
  srand(time(0));
  int n;
  int v[11]={0};//daca n=10 nu genereaza ultimul nr

  n=rand()%10+1;//genereaza un numar intre 1 si 10
  //n=10;
  printf("n=%d\n", n);

  for (size_t i = 0; i < n; ++i)
  {
    int nr=rand()%10+1;
    if(v[nr]==0)
    {
      printf("%d ", nr);
    }
    else
    {
      i--;
    }
    v[nr]=1;
  }
}
