#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
/**
 * Structura de mai jos NU reprezinta o coada, ea reprezinta doar un element
 * dintr-o coada implementat ca o lista inlantuita.
 *
 * DON'T TOUCH THIS.
 */
typedef struct queue_node_t{
	int val;	/* Valoarea retinuta de catre nod. */
	struct queue_node_t *next;	/* Pointer catre urmatorul element de tip nod. */
}queue_node_t;

/**
 * Structura ce reprezinta o coada.
 * Cozile pot fi implementate prin mai multe modalitati: vector static/dinamic
 * sau printr-o lista inlantuita.
 *
 * Implementarea prin lista inlantuita este preferata in majoritatea cazurilor
 * pentru ca este foarte eficienta atat din punct de vedere al operatiilor
 * de adaugare/stergere dar si din punct de vedere al memoriei (alocam doar cat
 * avem nevoie).
 *
 * Vom folosi in continuare o coada implementat printr-o lista inlantuita,
 * O coada de tipul 'queue_t' va contine un pointer catre primul nod si un
 * pointer catre ultimul nod.
 *
 * Fiecare element din aceasta lista inlantuita va fi un nod de tipul
 * 'queue_node_t'.
 *
 * DON'T TOUCH THIS.
 */
typedef struct queue_t{
	struct queue_node_t *head;	/* Capul listei inlantuite. */
	struct queue_node_t *tail;	/* Coada listei inlantuite. */
	unsigned int length;	/* Dimensiunea cozii. */
}queue_t;

/**
 * TASK 1.
 *
 * Creeaza o coada vida.
 *
 * Functia nu primeste niciun parametru.
 * Ea doar aloca spatiu de memorie pentru o coada cu tipul 'queue_t' si
 * returneaza un pointer catre spatiul alocat.
 */
queue_t *queue_create()
{
	/* TODO: TASK 1: Alocare memorie pentru o coada vida. Initializare campuri. */
	queue_t *queue = (queue_t*)malloc(sizeof(queue_t));
	if(queue == NULL)
	{
		printf("Eroare la alocarea memoriei!\n");
	}
	queue->head=queue->tail=NULL;
	queue->length=0;
	return queue;
}

/**
 * TASK 2, a)
 *
 * Creeaza un nod nou pentru lista inlantuita.
 *
 * Functia primeste o valoare de tip intreg, aloca dinamic spatiu pentru
 * un nod nou din lista inlantuita, il initializeaza si returneaza
 * un pointer catre acest nod.
 */
queue_node_t *queue_node_create(int val)
{
	/* TODO: TASK 2, a): Alocare si initializare nod. */
	queue_node_t *node = (queue_node_t*)malloc(sizeof(queue_node_t));
	if(node==NULL)
  {
    printf("Eroare la alocarea memoriei!!!!");
  }
	node->val=val;
	node->next=NULL;
	return node;
}

/**
 * TASK 2, b).
 *
 * Adauga un element nou in coada.
 *
 * Functia primeste ca parametrii un pointer catre coada in care se va adauga
 * un element nou cu valoarea 'val'.
 */
void queue_push(queue_t *queue, int val)
{
	/* TODO: Creeare nod. Adaugare in coada. */
	queue_node_t *node = (queue_node_t*)malloc(sizeof(queue_node_t));
	node->val=val;
	node->next=NULL;
	queue->length++;

	if(queue->tail==NULL)
	{
		queue->tail=node;
	}
	else
	{
		(queue->tail)->next=node;
		(queue->tail)=node;
	}

	if(queue->head==NULL)
	{
		queue->head=queue->tail;
	}
}

/**
 * TASK 5 c)
 *
 * Functia returneaza 1 daca coada este vida, 0 in caz contrar.
 *
 * Functia primeste ca parametru un pointer catre coada.
 */

int queue_empty(queue_t *queue)
{
	if(queue->head==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/**
 * TASK 4.
 *
 * Scoate un element din coada.
 *
 * Functia primeste ca parametrii un pointer catre coada din care trebuie
 * scos un element.
 *
 * Functia returneaza valoarea retinuta de catre nod.
 */

int queue_pop(queue_t *queue)
{
	/* TODO: Identificare nod de tipul 'queue_node_t' ce trebuie scos. */
	/* TODO: Copiere valoare. Stergere nod.*/

	int val;
	queue_node_t *copie;
	queue->length--;

	copie=queue->head;
	val=copie->val;
	queue->head=(queue->head)->next;
	free(copie);
	return val;
}

/**
 * TASK 3.
 *
 * Afiseaza la stdout (consola) continutul cozii, impreuna cu lungimea ei.
 *
 * Functia primeste ca parametrii un pointer catre coada care trebuie afisata.
 */
void queue_print(queue_t *queue)
{
	/* TODO: Parcurgere si afisare. */
	while(queue_empty(queue)!=0)	//afiseaza val scoasa = 3 10 7
	{															// daca queue_empty(queue) == 0 afiseaza doar 3 10 7
		printf("%d ", queue_pop(queue));
	}
}

/**
 * TASK 5 a)
 *
 * Functia returneaza valoarea primului element din coada, fara sa il stearga.
 *
 * Functia primeste ca parametru un pointer catre coada din care trebuie
 * intors elementul.
 *
 * In caz ca (virgula) coada e vida, se intoarce valoarea constantei INT_MIN.
 * Ea este definita in biblioteca limits.h
 */
int queue_front(queue_t *queue)
{
	int val;
	return queue->head->val;
}

/**
 * TASK 5 b)
 *
 * Functia returneaza valoarea ultimului element din coada, fara sa il stearga.
 *
 * Functia primeste ca parametru un pointer catre coada din care trebuie
 * intors elementul.
 *
 * In caz ca (virgula) coada e vida, se intoarce valoarea constantei INT_MIN.
 * Ea este definita in biblioteca limits.h
 */
int queue_back(queue_t *queue)
{
	int val;
	return queue->tail->val;
}

/**
 * TASK 5 d)
 *
 * Functia returneaza dimensiunea cozii.
 *
 * Functia primeste ca parametru un pointer catre coada.
 */
int queue_length(queue_t *queue)
{
	return queue->length;
}

/**
 * Cateva teste pentru fiecare functie.
 */
int main()
{
	int val;

	/* Test TASK 1. DO NOT TOUCH. */
	queue_t *queue = queue_create();

	/* Test TASK 2, 3 si 4. DO NOT TOUCH. */
	/*queue_push(queue, 3);
	queue_push(queue, 10);
	queue_push(queue, 7);
	queue_print(queue);

	val = queue_pop(queue);
	printf("Valoarea scoasa = %d\n", val);
	queue_print(queue);

	val = queue_pop(queue);
	printf("Valoarea scoasa = %d\n", val);
	queue_print(queue);

	val = queue_pop(queue);
	printf("Valoarea scoasa = %d\n", val);
	queue_print(queue);

	val = queue_pop(queue);
	printf("Valoarea scoasa = %d\n", val);
	queue_print(queue);*/

	/* TASK 5. */
	queue_push(queue, 5);
	queue_push(queue, 15);
	queue_push(queue, 30);
	queue_push(queue, 1);

	val = queue_front(queue);
	printf("Valoarea primului element = %d\n", val);
	queue_print(queue);

	val = queue_back(queue);
	printf("Valoarea ultimului element = %d\n", val);
	queue_print(queue);

	printf("Dimensiunea cozii = %d\n", queue_length(queue));
	printf("coada vida? %s\n", (queue_empty(queue) ? "DA" : "NU"));

  return 0;
}
