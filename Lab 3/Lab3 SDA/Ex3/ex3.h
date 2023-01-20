#ifndef EX2_H_INCLUDED
#define EX2_H_INCLUDED

typedef struct lista
{
  int valoare;
  struct lista* urmator;
}lista;

void adaugare_inceput(lista **cap, int n);
void printare(lista *cap);
void stergere_pare(lista **cap);

#endif // EX2_H_INCLUDED
