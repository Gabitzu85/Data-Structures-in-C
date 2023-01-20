#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * TASK 1.
 *
 * Completati structura din fisierul header.
 */

int main()
{
	printf("Lab 2 - Liste inlantuite.\n");

	/**************************************************************************
	 * Test Task 2.
	 * Creati un nod cu o anumita valoare.
	 * Afisati valoarea la stdout.
	 */
	node_t *cap = NULL;
	cap = create(56);

	/**************************************************************************
	 * Test Task 3.
	 *
	 * Creati o variabila de tip 'node_t' cu numele 'head'.
	 * Ea va reprezenta cap-ul listei cu care veti lucra mai jos.
	 *
	 * Adaugati 5-6 noduri cu valori diferite la final listei.
	 * Aveti un exemplu.
	 */

	cap = append_node(cap, 42);
	cap = append_node(cap, 72);
	cap = append_node(cap, 85);
	cap = append_node(cap, 99);
	cap = append_node(cap, 73);

	node_t *test1,*test2, *test3, *test4;
	test1=get_node(cap,72);
	test2=get_node(cap,10);
	//test3=modify_node(cap,72,3);
    //remove_node(cap,42);
	//remove_node(cap,80);
	insert_node(cap,85,8);

	//printf("test1 = %d\n", test1->val);
	//printf("test2 = %d\n", test2->val);
	//printf("test3 = %d\n", test3->val);


	print_list(cap);

	/**************************************************************************
	 * Test Task 4.
	 */

	/**************************************************************************
	 * Test Task 5.
	 */

	/**************************************************************************
	 * Test Task 6.
	 */

	/**************************************************************************
	 * Test Task 6.
	 */

	/**************************************************************************
	 * Test Task 7.
	 */

	/**************************************************************************
	 * Test Task 8.
	 */

	/**************************************************************************
	 * Test Task 9.
	 */

	return 0;
}

/**
 * TASK 2.
 *
 * Functia primeste o valoare, creeaza un nou nod cu aceasta
 * valoare si returneaza un pointer catre nodul creat.
 */
node_t *create(int val)
{
	node_t *new_node;
	new_node = (node_t *)malloc(sizeof(node_t));

	if(new_node!=NULL)
    {
        new_node->val = val;
        new_node->next = NULL;
    }
    else
    {
      printf("Eroare la alocare!!");
    }

	return new_node;
}

/**
 * TASK 3.
 *
 * Functia creaza un nou nod cu valoarea 'val'
 * si il adauga la finalul listei.
 *
 * Functia returneaza noul cap al listei (daca e cazul), sau vechiul.
 */
node_t *append_node(node_t *list_head, int val)
{
	node_t *aux;
	aux = list_head;

	if (list_head == NULL)
	{
		return create(val);
	}

	while (list_head->next != NULL)
	{
		list_head = list_head->next;
	}
	list_head->next = create(val);

	return aux;
}

/**
 * TASK 4.
 *
 * Functia afiseaza la stdout continutul listei.
 * Valorile sunt separate prin virgula.
 */
void print_list(node_t *list_head)
{
	node_t *aux;
	aux = list_head;

	while (aux != NULL)
	{
		printf("%d ", aux->val);
		printf("\n");
		aux = aux->next;
	}
}

/**
 * TASK 5.
 *
 * Functia creaza un nou nod cu valoarea 'val'
 * si il adauga la finalul liste.
 *
 * Functia returneaza noul cap al listei (daca e cazul), sau vechiul.
 */
node_t *prepend_node(node_t *list_head, int val)
{
	// aceeasi cerinta ca si la task 4
	node_t *aux;
	aux = list_head;

	if (list_head == NULL)
	{
		return create(val);
	}

	while (list_head->next != NULL)
	{
		list_head = list_head->next;
	}
	list_head->next = create(val);

	return aux;
}

/**
 * TASK 6.
 *
 * Functia primeste un numar intreg si cauta in lista acest numar.
 * Daca gaseste numarul in lista, returneaza nodul care il contine.
 * Daca nu il gaseste returneaza NULL.
 * Daca elementul apare de mai multe ori, se returneaza prima aparitie.
 */
node_t *get_node(node_t *list_head, int val)
{
	node_t *aux;	//lucrez cu copii ale capului deoarece
	aux=list_head;	//pozitia capului se poate schimba

	while(aux->next !=NULL && aux->val!=val)
	{
		aux=aux->next;
	}
	if(aux->next==NULL)
	{
		return NULL;
	}
	else
	{
		return aux;
	}
}

/**
 * TASK 7.
 *
 * Functia cauta valoarea 'val' in lista si daca gaseste un element
 * cu aceasta valoare o schimba cu 'new_val'.
 *
 * Functia returneaza un pointer catre acest element, sau
 * NULL daca nodul nu exista.
 */
node_t *modify_node(node_t *list_head, int val, int new_val)
{
	node_t *aux;
	aux=list_head;

	while(aux->next !=NULL && aux->val!=val)
	{
		aux=aux->next;
	}
	if(aux->next==NULL)
	{
		return NULL;
	}
	else
	{
		aux->val=new_val;
		return aux;
	}
}

/**
 * TASK 8.
 *
 * Functia creaza un nod nou cu valoarea 'after_val' si il
 * insereaza dupa nodul cu valoarea 'val'.
 * Se returneaza un pointer catre nodul nou creat.
 *
 * Daca nodul cu valoarea 'val' nu exista in lista, lista
 * ramane nemodificata si se returneaza capul listei.
 */
node_t *insert_node(node_t *list_head, int val, int after_val)
{
    node_t *aux,*nou;
    aux=list_head;
    nou=(node_t*)malloc(sizeof(node_t));


    while(aux!=NULL && aux->val!=val)
    {
        aux=aux->next;
    }

    if(aux->next==NULL)
    {
        return NULL;
    }
    else
    {
        nou->val=after_val;
        nou->next=aux->next;
        aux->next=nou;
    }
    return aux;
}

/**
 * TASK 9.
 *
 * Functia cauta nodul cu valoarea 'val' si il sterge din lista.
 * Functia returneaza noul cap al listei (daca e cazul), sau vechiul.
 *
 * Daca nodul cu valoarea 'val' nu exista in lista, lista
 * ramane nemodificata si se returneaza capul listei.
 */
node_t *remove_node(node_t *list_head, int val)
{
	node_t *copie,*aux;
	aux=list_head;

	while(aux!=NULL && aux->val!=val)
    {
        copie=aux;
        aux=aux->next;
    }
    if(aux->next==NULL)
    {
        return NULL;
    }
    copie->next=aux->next;
    return aux;
}
