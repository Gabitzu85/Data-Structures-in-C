void bubble(int v[], int n, int*p)
{
  int aux,sortat=1,i;
  *p=0;
  while(sortat!=0)
  {
    sortat=0;
    for (i = 0; i < n-1; i++)
    {
      if(v[i]>v[i+1])
      {
        aux=v[i];
        v[i]=v[i+1];
        v[i+1]=aux;
        sortat=1;
        (*p)++;
      }
    }
  }
}

void quick(int v[],int primul,int ultimul, int *q)
{
   int i, j, pivot, aux;
   *q=0;

   if(primul<ultimul)
   {
      pivot=primul;
      i=primul;
      j=ultimul;

    while(i<j)
    {
        while(v[i]<=v[pivot] && i<ultimul)
        {
            i++;
            (*q)++;
        }
        while(v[j] > v[pivot])
        {
            j--;
            (*q)++;
        }
        if(i<j)
        {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
        }
    }

    aux=v[pivot];
    v[pivot]=v[j];
    v[j]=aux;
    quick(v,primul,j-1,&q);
    quick(v,j+1,ultimul,&q);
   }
}
