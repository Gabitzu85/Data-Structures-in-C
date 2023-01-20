#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

typedef struct
{
  char *nume, *prenume;
  char id[6];  //id student
  double note[5];  //aici se salveaza notele obtinute in semestrul anterior
}student;

student *creeaza_student()  //functie ce aloca dinamic memorie pentru campurile nume si prenume
{
  student *stud=(student*)malloc(sizeof(student));
  stud->nume=(char*)malloc(25*sizeof(char));
  stud->prenume=(char*)malloc(25*sizeof(char));
  return stud;
}

void scriere(int *n, student **s)
{
  int i,j,k,nr_restante;  //vector pentru restante
  FILE *f;
  double medie=0;

  if((f=fopen("Studenti.txt","wt"))==NULL)
  {
    printf("Eroare la deschiderea fisierului!\n");
    exit(1);
  }

  for(i=0; i<*n; i++)
  {
    nr_restante=0;
    for(k=0; k<=4; k++)
    {
      medie+=s[i]->note[k];
      if(s[i]->note[k]<5.00)
      {
        nr_restante++;
      }
    }
    medie=(double)(medie/5);      //Am decis ca studentii care nu au media peste 5 nu vor fi trecuti in fisier
    printf("Medie student %d = %lf\n", i+1,medie);  //programul poate fi modificat pentru a functiona pentru maxim 25 de elevi dar pentru scopul demonstratiei am ales maxim 5 elevi
    if(medie<=5.00)
    {
      fprintf(f,"%s %s %s %d \n", s[i]->id,s[i]->nume,s[i]->prenume, nr_restante);
    }
  }
  fclose(f);
}

void printare_fisier()
{
  FILE *f;
  char s[256];
  if((f=fopen("Studenti.txt","rt"))==NULL)
  {
    printf("Eroare la deschiderea fisierului!\n");
    exit(1);
  }
  printf("\nFisierul contine: \n\n");
  while(fgets(s,256,f)!=0)
  {
    printf("%s\n",s);
  }
  fclose(f);
}

void stergere(int *n, student **s)  //voi realiza stergerea doar studentilor cu media sub 5;
{
  int i,k,nr=0;
  double medie;

  for(i=0; i<*n; i++)
  {
    for(k=0; k<=4; k++)
    {
      medie+=s[i]->note[k];
    }
    medie=(double)(medie/5);
    printf("%lf\n", medie);
    if(medie<5.00)
    {
      s[i]->nume=(char*)realloc(*s,25*sizeof(char));
      strcpy(s[i]->nume, "");
      s[i]->prenume=(char*)realloc(*s,25*sizeof(char));
      strcpy(s[i]->prenume, "");
      strcpy(s[i]->id, "");
    }
  }

  for(i=0; i<*n; i++)
  {
    printf("%s %s %s\n", s[i]->nume, s[i]->prenume, s[i]->id);
  }
}

void cautare_id(int *n, student **s)
{
  int i,j,k;
  char id[6];
  char nume[5][20]={"Andrei","Alina","Maria","Greta","Sorin"};
  char prenume[5][20]={"Gigel","Camelia","Ioana","Stefan","Gabi"};
  char numere[10]={"0123456789"};
  int v[5][5]={0};
  printf("Introduceti id-ul pe care doriti sa-l cautati: \n");
  gets(id);

  for(i=0; i<*n; i++)
  {
    if(strcmp(s[i]->id,id)==0)
    {
      int p1=rand()%5;
      int p2=rand()%5;
      if(v[p1][p2]==0)
      {
        strcpy(s[i]->nume,nume[p1]);
        strcpy(s[i]->prenume,prenume[p2]);
        v[p1][p2]==1;
      }
      else
      {
        i--;
      }

      for(j=0; j<5; j++)
      {
        s[i]->id[j]=numere[rand()%10];
        s[i]->id[5]='\0';
      }
    }
  }

  printf("Noua structura este: \n");
  for(i=0; i<*n; i++)
  {
    printf("Date studentul %d\n", i+1);
    printf("Nume: %s\n", s[i]->nume);
    printf("Prenume: %s\n", s[i]->prenume);
    printf("Id: %s\n", s[i]->id);
    printf("\n");
  }
}

int main()
{
  srand(time(0));
  char nume[5][20]={"Andrei","Alina","Maria","Greta","Sorin"};  //Am ales 2 vectori de nume si prenume de cate 5 elemente
  char prenume[5][20]={"Gigel","Camelia","Ioana","Stefan","Gabi"};
  char numere[10]={"0123456789"};

  int n,i,j,k;
  int v[5][5]={0};  //iau un vector gol unde voi verifica daca mai exista sau nu studenti cu acelasi nume/prenume 0-element neocupat, 1-element ocupat
  n=rand()%5+1; //pentru usurarea vizualizarii generez un nr de elevi cuprins intre 1 si 5
  student **s=(student**)malloc(25*sizeof(student*));
  printf("Numarul de studenti este: %d\n\n", n);

  for(i=0; i<n; i++)
  {
    s[i]=creeaza_student();   //aloc memorie pentru fiecare element creat
  }

  for(i=0; i<n; i++)
  {
    int p1=rand()%5;  //generez nr intre 0 si 4 ce reprezinta locurile in matricea v
    int p2=rand()%5;
    if(v[p1][p2]==0)
    {
      strcpy(s[i]->nume,nume[p1]);
      strcpy(s[i]->prenume,prenume[p2]);
      v[p1][p2]==1;   //pun 1 atunci cand o combinatie a fost gasita
    }
    else
    {
      i--;    //daca exista 2 studenti cu acelasi nume si prenume mai incerc generarea inca o data
    }

    for(j=0; j<5; j++)
    {
      s[i]->id[j]=numere[rand()%10];  //nu voi mai face verificarea ca acest cod sa fie unic deoarece
      s[i]->id[5]='\0';               //din punct de vedere matematic este aproape imposibil
    }
  }

  for(i=0; i<n; i++)
  {
    printf("Date studentul %d\n", i+1);
    printf("Nume: %s\n", s[i]->nume);
    printf("Prenume: %s\n", s[i]->prenume);
    printf("Id: %s\n", s[i]->id);
    for(k=0; k<=4; k++)
    {
      s[i]->note[k]=(double) rand() / RAND_MAX * 10+1;    //exista posibilitatea ca rezultatul sa fie peste 10, dar nu am stiut cum sa rezolv aceasta problema
      printf("Nota %d: %.2lf  \n", k+1,s[i]->note[k]);
    }
    printf("\n");
  }
  //scriere(&n,s);
  //printare_fisier();
  //stergere(&n,s);
  cautare_id(&n,s);
  free(s);
  return 0;
}
