#ifndef EX2_H_INCLUDED
#define EX2_H_INCLUDED

typedef struct node {
    int val;
    struct node *next;
}node;

void creare( node **cap);
void printare(node *cap);
void stergere(node **cap,int val);

#endif // EX2_H_INCLUDED
