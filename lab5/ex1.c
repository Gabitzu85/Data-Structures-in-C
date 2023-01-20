#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct tree
{
  int key;
  struct tree *left;
  struct tree *right;
}tree;

tree *key_root(int key)
{
  tree *root=(tree*)malloc(sizeof(tree));
  root->key=key;
  root->left=root->right=NULL;
  return root;
}

tree *nod_nou(int key)
{
  tree *nod=(tree*)malloc(sizeof(tree));
  nod->key=key;
  nod->left=nod->right=NULL;
  return nod;
}

tree *insert(tree *nod, int key)
{
  if(nod==NULL)
  {
    return nod_nou(key);
  }
  if(key < nod->key)
  {
    nod->left = insert(nod->left,key);
  }
  else if(key > nod->key)
  {
    nod->right = insert(nod->right,key);
  }
  return nod;
}

void printare_inorder(tree *root)
{
  if(root != NULL)
  {
    printare_inorder(root->left);
    printf("%d ", root->key);
    printare_inorder(root->right);
  }
}

int verificare_BTS(tree *nod)
{
  if(nod->right!=NULL && nod->right->key < nod->key)
  {
    return 0;
  }

  if(nod->left!=NULL && nod->left->key > nod->key)
  {
    return 0;
  }

  if(verificare_BTS(nod->left)!=0 || verificare_BTS(nod->right)!=0)
  {
    return 0;
  }

  return 1;
}

int cautare(tree *root, int key)
{
  while(root!=NULL)
  {
    if(key>root->key)
    {
      root=root->right;
    }
    else if(key<root->key)
    {
      root=root->left;
    }
    else
    {
      return 1;
    }
  }
  return 0;
}

tree *min_val_node(tree *nod)
{
  tree *curent=nod;
  while(curent->left!=NULL)
  {
    curent=curent->left;
  }
  return curent;
}

tree *stergere(tree *root, int key)
{
  if(root==NULL)
  {
    return root;
  }

  if(key<root->key)
  {
    root->left=stergere(root->left,key);
  }
  else if(key>root->key)
  {
    root->right=stergere(root->right,key);
  }
  else
  {
      if(root->left==NULL)
      {
        tree *tmp=root;
        root=root->right;
        free(tmp);
        return root;
      }
      else
      {
        if(root->right==NULL)
        {
          tree *tmp=root;
          root=root->left;
          free(tmp);
          return root;
        }
        tree *aux=min_val_node(root->right);
        root->key=aux->key;
        root->right=stergere(root->right,aux->key);
      }
  }
  return root;
}

int main()
{
  srand(time(0));
  tree *root = NULL;
  FILE *f;
  int nr;

  if((f=fopen("input.txt","rt"))==NULL)
  {
    printf("Eroare la deschiderea fisierului!\n");
    exit(1);
  }

  fscanf(f,"%d",&nr);
  root=key_root(nr);

  while(!feof(f))
  {
    fscanf(f,"%d", &nr);
    root=insert(root,nr);
  }

  fclose(f);

  printare_inorder(root);
  printf("\n");

  if(verificare_BTS!=0)
  {
    printf("Arborele este un arbore BTS!\n");
  }
  else
  {
    printf("Arborele nu este un arbore BTS!\n");
  }

  int nr_cautat=rand()%10+1;
  printf("Nr cautat = %d\n", nr_cautat);

  if(cautare(root,nr_cautat)==1)
  {
    printf("Nr a fost gasit!\n");
  }
  else
  {
    printf("Nr nu a fost gasit!\n");
  }

  int nr_inserat=rand()%15+1;
  printf("Nr inserat = %d\n", nr_inserat);
  insert(root,nr_inserat);
  printare_inorder(root);

  printf("\n");
  int nr_sters=rand()%10+1;
  printf("Nr sters = %d\n", nr_sters);

  if(cautare(root,nr_sters)==1)
  {
    printf("Nr a fost gasit!\n");
  }
  else
  {
    printf("Nr nu a fost gasit!\n");
  }
  stergere(root,nr_sters);
  printare_inorder(root);
}
