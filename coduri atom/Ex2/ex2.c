void sortare(char v[][5], int *n)
{
  char aux[5];
  int i,j;

  for(j=0; j<(*n)-1; j++)
  {
    for(i=j+1; i<*n; i++)
    {
      if(strcmp(v[j],v[i])>0)
      {
        strcpy(aux,v[j]);
        strcpy(v[j], v[i]);
        strcpy(v[i], aux);
      }
    }
  }
}
