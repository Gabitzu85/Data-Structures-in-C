#include "ex2.h"
#include <stdio.h>
#include <stdlib.h>

void creare(node **cap)
{
    *cap = malloc(sizeof(node));
    node *copie = *cap;
    node *nou;

    FILE *f;

    if((f=fopen("fisier.txt","rt"))==NULL)
    {
        printf("Eroare la deschiderea fisierului!");
    }
    fscanf(f,"%d",&(*cap)->val);
    while(!feof(f))
    {
         node *nou = malloc(sizeof(node));
        fscanf(f,"%d", &nou->val);
        nou->next=NULL;
        copie->next=nou;
        copie=nou;
    }
    fclose(f);
}

void printare(node *cap)
{
    node *copie=cap;
    while(copie->next!=NULL)
    {
        printf("%d ", copie->val);
        copie=copie->next;
    }
}

void stergere(node **cap,int val)
{
    node *copie,*aux;
    copie=*cap;
    aux=*cap;

    if(copie->val==val)
    {
        *cap=(*cap)->next;
        free(copie);
    }
    while(copie!=NULL)
    {
        if(copie->val!=val)
        {
            aux=copie;
            copie=copie->next;
        }
        else
        {
            aux->next=copie->next;
            free(copie);
        }
    }
}
