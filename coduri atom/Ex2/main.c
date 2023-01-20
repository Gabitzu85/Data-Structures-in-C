#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

int main()
{
    srand(time(0));

    int n,i,j;
    char v[10][5];
    char alfabet[26]={"abcdefghijklmnopqrstuvxyz"};

    n=rand()%10+1;
    printf("n=%d\n", n);

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            v[i][j]=alfabet[rand()%25];
            v[i][4]='\0';
        }
    }

    printf("Vector nesortat: \n");

    for(i=0; i<n; i++)
    {
        printf("%s ", v[i]);
    }

    sortare(v,&n);
    printf("\n");
    printf("Vector sortat: \n");

    for(i=0; i<n; i++)
    {
        printf("%s ", v[i]);
    }
    return 0;
}
