#include <stdio.h>
#include <stdlib.h>

int bancnote1[5]={1, 5, 10, 50, 100};
int bancnote2[7]={1, 3, 5, 15, 30, 50, 150};

void rest_bancnote1(int suma)
{
  int i;

  for(i=4; i>=0; i--)
  {
    while(suma>=bancnote1[i])
    {
      suma-=bancnote1[i];
      printf("%d ", bancnote1[i]);
    }
  }
}

void rest_bancnote2(int suma) //metoda greedy nu garanteaza intotdeauna solutia optima
{                             //pt fiecare caz in parte tr sa se verifice daca solutia este optima sau nu
  int i;

  for(i=6; i>=0; i--)
  {
    while(suma>=bancnote2[i])
    {
      suma-=bancnote2[i];
      printf("%d ", bancnote2[i]);
    }
  }
}

int main()
{
  int suma;
  printf("Dati suma pt care doriti rest:\n");
  scanf("%d", &suma);
  rest_bancnote1(suma);

  printf("Un exemplu pt care greedy nu functioneaza este 60!\n");
  rest_bancnote2(60);
  printf("\n60 se descompune in 2 de 30.\n");

}
