#ifndef EX1_H_INCLUDED
#define EX1_H_INCLUDED

typedef struct pers
{
  char nume[50],tel[11],post[50];
  struct pers *prev;
  struct pers *next;
}pers;

void creare(pers **cap, char nume[50], char tel[11], char post[50]);
void afisare(pers *cap);
void adauga_dupa(pers **cap,int poz);
void introducere_nou(pers **cap);
void stergere(pers **cap);

#endif // EX1_H_INCLUDED
