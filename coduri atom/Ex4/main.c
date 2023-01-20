#include <stdio.h>
#include <stdlib.h>
#include "count_sort.h"

//count sort este unul dintre algoritmii ce poate produce un timp O(n) pe langa acesta mai este si radix sort

int main()
{
    srand(time(0));
    int n,i;
    int *v=(int*)malloc(n*sizeof(int));

    n=rand()%20+1;
    printf("n=%d\n", n);

    for(i=0; i<n; i++)
    {
        v[i]=rand()%1000;
    }
    printf("Vectorul nesortat: \n");
    for(i=0; i<n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("Vectorul sortat: \n");
    count_sort(v,n);
    for(i=0; i<n; i++)
    {
        printf("%d ", v[i]);
    }
    free(v);
    return 0;
}
