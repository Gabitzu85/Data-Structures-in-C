void count_sort(int *v, int n)
{
  int rez[1000],i;
  int max=v[0];

  for(int i=1; i<n; i++)
  {
    if(v[i]>max)
    {
      max=v[i];
    }
  }

  int aux[1000];
  for(i=0; i<=max; ++i)
  {
    aux[i]=0;
  }

  for(i=0; i<n; i++)
  {
    aux[v[i]]++;
  }

  for(i=1; i<=max; i++)
  {
    aux[i]+=aux[i-1];
  }
  for(i=n-1; i>=0; i--)
  {
    rez[aux[v[i]]-1]=v[i];
    aux[v[i]]--;
  }
  for(i=0; i<n; i++)
  {
    v[i]=rez[i];
  }
}
