typedef struct timp
{
  int ora;
  int min;
  int sec;
}timp;


void merge_sort_ora(timp *v, int val_min, int mijloc, int val_max)
{
  int stanga,dreapta;
  int k,i;
  timp aux[28];
  k=0;
  stanga=val_min;
  dreapta=mijloc+1;

  for(; (stanga<=mijloc)&&(dreapta<=val_max); k++)
  {
    if(v[stanga].ora <= v[dreapta].ora) //sortarea crescatoare in functie de ora
    {
      aux[k]=v[stanga++];
    }
    else
    {
      aux[k]=v[dreapta++];
    }
  }

  for(; stanga<=mijloc; stanga++, k++)
  {
    aux[k]=v[stanga];
  }

  for(; dreapta<=val_max; dreapta++, k++)
  {
    aux[k]=v[dreapta];
  }

  k=val_min;
  i=0;

  for (;  k <= val_max;  k++, i++)
  {
    v[k]=aux[i];
  }
}

void merge_sort(timp *v, int val_min, int val_max)
{
  int mijloc;
  mijloc=(val_min+val_max)/2;


  if(val_max<=val_min)
    return;


  merge_sort(v,val_min,mijloc);
  merge_sort(v,mijloc+1,val_max);
  merge_sort_ora(v,val_min,mijloc,val_max);
}
