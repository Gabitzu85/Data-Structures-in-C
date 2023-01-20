#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct nume
{
  char num[20000];
  int nr;
};

int x[50];
struct nume v[200];

void Backtrack_C(int pas, int n, int k, FILE* g){ // combinari
    int i;
    if(pas > k){
        for(i=1; i<=k; i++){
            for(int t = 0; t<n; t++)
                if(i == v->nr)
                    fprintf(g, "%s\n", v->num);
        }
        fprintf(g, "\n");
        return;
    }
    for(i=x[pas-1]+1; i<=n; i++){
        x[pas] = i;
        Backtrack_C(pas+1, n, k, g);
    }
}

int main()
{
  FILE *f;
  int p, n;

  int nr_nume = 0;


  f = fopen("input.txt", "rt");
  
  if(f == NULL)
  {
    printf("Eroare la deschidere!");
    exit(1);
  }
  fscanf(f, "%d %d", &p, &n);

  int i=0;
  while(!feof(f))
  {
    fgets(v[i].num, 1000, f );
    v[i].nr = i;
    i++;
  }
  fclose(f);

  f = fopen("output.txt", "wt");

  if(f == NULL)
  {
    printf("Eroare la deschidere!");
    exit(1);
  }
    Backtrack_C(1, p, n, f);

  fclose(f);

  return 0;
}
