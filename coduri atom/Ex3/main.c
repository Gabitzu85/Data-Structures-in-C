#include <stdio.h>
#include <stdlib.h>

typedef struct timp
{
  int ora;
  int min;
  int sec;
}timp;

int main()
{
    srand(time(0));
    int n,i;

    n=rand()%10+1;
    timp *v=(timp*)malloc(n*sizeof(timp));

    for(i=0; i<n; i++)
    {
        v[i].ora=rand()%100;
        v[i].min=rand()%100;
        v[i].sec=rand()%100;
    }

    printf("Structura nesortata: \n");
    for(i=0; i<n; i++)
    {
        printf("Structura %d: ora=%d min=%d sec=%d \n", i+1, v[i].ora, v[i].min, v[i].sec);
    }

    printf("Structura Sortata: \n");
    merge_sort(v,0,n-1);
    for(i=0; i<n; i++)
    {
        printf("Structura %d: ora=%d min=%d sec=%d \n", i+1, v[i].ora, v[i].min, v[i].sec);
    }
}
