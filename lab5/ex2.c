#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct tree
{
  int key;
  int height;
  struct tree *left;
  struct tree *right;
}tree;

int max(int a, int b)
{
  if(a>b)
  {
    return a;
  }
  else
  {
    return b;
  }
}

int nod_height(tree *root)
{
  if(root==NULL)
  {
    return -1;
  }
  else
  {
    return root->height;
  }
}

tree *right_rotation(tree *z)
{
  tree *y=z->left;
  tree *x=y->right;

  y->right=z;
  z->left=x;

  z->height=max(nod_height(z->left),nod_height(z->right))+1;
  y->height=max(nod_height(y->left),nod_height(y->right))+1;

  return y;
}

tree *left_rotation(tree *z)
{
  tree *y=z->right;
  tree *x=y->left;

  y->left=z;
  z->right=x;

  z->height=max(nod_height(z->left),nod_height(z->right))+1;
  y->height=max(nod_height(y->left),nod_height(y->right))+1;

  return y;
}

tree *right_left_rotation(tree *z)
{
  z->right=right_rotation(z->right);
  return left_rotation(z);
}

tree *left_right_rotation(tree *z)
{
  z->left=left_rotation(z->left);
  return right_rotation(z);
}

tree *insert(tree *nod, int key)
{
  if(nod==NULL)
  {
    nod=(tree*)malloc(sizeof(tree));
    nod->key=key;
    nod->height=0;
    nod->left=nod->right=NULL;
    return nod;
  }

  if(key< nod->key)
  {
    nod->left=insert(nod->left,key);
  }
  else if(key > nod->key)
  {
    nod->right=insert(nod->right,key);
  }
  else
  {
    return nod;
  }

  nod->height=1+max(nod_height(nod->left),nod_height(nod->right));

  int k=(nod_height(nod->left)-nod_height(nod->right));

  if(k>1 && key < nod->left->key)
  {
    return right_rotation(nod);
  }

  if(k<-1 && key > nod->right->key)
  {
    return left_rotation(nod);
  }

  if(k>1 && key > nod->left->key)
  {
    return right_left_rotation(nod);
  }

  if(k<-1 && key < nod->right->key)
  {
    return left_right_rotation(nod);
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

int verificare_AVL(tree *root)
{
  int left_height;
  int right_height;
  int diff;

  if(root==NULL)
  {
    return 1;
  }

  left_height=nod_height(root->left);
  right_height=nod_height(root->right);

  if(diff==left_height-right_height)
  {
    return left_height-right_height;
  }
  else
  {
    right_height-left_height;
  }

  if(diff<=1 && verificare_AVL(root->left) && verificare_AVL(root->right))
  {
    return 1;
  }
  return 0;
}

int balance(tree *nod)
{
  if(nod==NULL)
  {
    return 0;
  }
  return nod_height(nod->left)-nod_height(nod->right);
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
    root->left=stergere(root->right,key);
  }
  else
  {
    if(root->left==NULL || root->right==NULL)
    {
      tree *tmp;
      if(tmp==root->left)
      {
        return root->left;
      }
      else
      {
        return root->right;
      }

      if(tmp==NULL)
      {
        tmp=root;
        root=NULL;
      }
      else
      {
        *root=*tmp;
      }
      free(tmp);
    }
    else
    {
      tree *aux=min_val_node(root->right);
      root->key=aux->key;
      root->right=stergere(root->right,aux->key);
    }
  }

  if(root==NULL)
  {
    return root;
  }

  root->height=1+max(nod_height(root->left),nod_height(root->right));
  int bal=balance(root);

  if(bal>1 && balance(root->left)>=0)
  {
    return right_rotation(root);
  }

  if(bal>1 && balance(root->left)<0)
  {
    root->left=left_rotation(root->left);
    return right_rotation(root);
  }

  if(bal<-1 && balance(root->right)<=0)
  {
    return left_rotation(root);
  }

  if(bal<-1 && balance(root->right)>0)
  {
    root->right=right_rotation(root->right);
    return left_rotation(root);
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
  root=insert(root,nr);

  while(!feof(f))
  {
    fscanf(f,"%d", &nr);
    root=insert(root,nr);
  }

  fclose(f);
  printare_inorder(root);

  if(verificare_AVL(root))
  {
    printf("Arborele este AVL!\n");
  }
  else
  {
    printf("Arborele nu este AVL\n");
  }

  printf("\n");
  int nr_cautat=rand()%10+1;
  printf("Nr cautat = %d\n", nr_cautat);

  if(cautare(root,nr_cautat))
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
