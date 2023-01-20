#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>

typedef struct node
{
 char data;
 struct node *right,*left,*prev;
}node;

void printare_postorder(struct node *root)
{
 if(root!=NULL)
 {
  printare_postorder(root->left);
  printare_postorder(root->right);
  printf("%c ",root->data);
 }
}


void main()
{
  char exp[256];
  int lungime,i;
  node *nou;
  node *curent,*anterior,*root=NULL;

  printf("Introduceti expresia matematica:\n");
  gets(exp);
  lungime=strlen(exp);
  for(i=lungime-1 ; i>=0 ; i--)
  {
   nou=(node *)malloc(sizeof(node));
   nou->data=exp[i];
   nou->left=nou->right=nou->prev=NULL;
   if(root==NULL)
   {
     root=nou;
     curent=anterior=root;
   }
   else
   {
    if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*')
    {
     if(anterior->right==NULL)
     {
      curent=nou;
      anterior->right=curent;
      curent->prev=anterior;
      anterior=curent;
     }
     else if(anterior->left==NULL)
     {
      curent=nou;
      anterior->left=curent;
      curent->prev=anterior;
      anterior=curent;
     }
    else
    {
     while(anterior->left!=NULL)
     {
      anterior=anterior->prev;
     }
     curent=nou;
     anterior->left=curent;
     curent->prev=anterior;
     anterior=curent;
    }
   }
   else
   {
    if(anterior->right==NULL)
    {
     curent=nou;
     anterior->right=curent;
     curent->prev=anterior;
    }
    else if(anterior->left==NULL)
    {
     curent=nou;
     anterior->left=curent;
     curent->prev=anterior;
    }
    else
    {
     while(anterior->left!=NULL)
     {
      anterior=anterior->prev;
     }
     curent=nou;
     anterior->left=curent;
     curent->prev=anterior;
    }
   }
  }
  }
  printf("Expresia matematica introdsa este:\n");
  printare_postorder(root);
}
