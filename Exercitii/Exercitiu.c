#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char *nume, *prenume;
    char id[6];     //id student
    double note[5];   // aici se salveaza notele obtinute in semestrul anterior
};

struct student *s_nou()
{
  struct student* student_nou=(struct student*)malloc(sizeof(struct student));
  student_nou->nume=(char*)malloc(25*sizeof(char));
  student_nou->prenume=(char*)malloc(25*sizeof(char));
  student_nou->id=(char*)malloc(6*sizeof(char));
  student_nou->note=(double*)malloc(5*sizeof(double));
  return student_nou;
}
int main()
{
  srand(time(0));
  struct student **s;

  int i;

  char nume[5][25]={"Maria","Andrei","Gabi","Sorin","Madalin"};     //Am ales un vector de doar 5 nume si prenume
  char prenume[5][25]={"Gicu","Gigel","Stefan","Alex","Stefania"};
  char numere[10]={"0123456789"};
  int v[5][5]={0};      //am ales un vector gol in care 0 inseamna "neocupat" iar 1 "ocupat" cu sensul ca exista un elev cu acelasi nume sau nu

  s=(struct student**)malloc(25*sizeof(struct student*));  //25 este nr maxim de elevi posibil formati

  for(i=0; i<25; i++)
  {
    s[i]=s_nou();
  }

  int p=rand()%25+1;      //nr random de elevi generati
  printf("p=%d\n", p);
  for(i=0; i<p; i++)
  {
    int n_nume=rand()%5;
    int n_prenume=rand()%5;
    if(v[n_nume][n_prenume]==0)
    {
      strcpy(s[i]->nume, nume[n_nume]);
      strcpy(s[i]->prenume, prenume[n_prenume]);
      v[n_nume][n_prenume]=1;
    }
    else
    {
      i--;        //verifica daca exista doi elevi cu acelasi nume si prenume
    }
  }

  for(i=0; i<p; i++)
  {
    strcpy(s[i].id, numere[rand()%strlen(numere)]);
  }


  for(i=0; i<p; i++)
  {
    printf("%s %s %d\n", s[i]->nume, s[i]->prenume, s[i]->id);
  }
  free(s);
  return 0;
}
