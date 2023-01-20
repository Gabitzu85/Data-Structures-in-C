#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

int main()
{

  char s[256];
  FILE *f;

  f=fopen("propozitie.txt","rt");

  while(!feof(f))
  {
    fscanf(f,"%s ",s);
    printf("%s ",s);
  }
}
