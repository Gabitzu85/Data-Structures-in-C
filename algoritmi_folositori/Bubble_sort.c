#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*void bubble(int v[], int n)
{
  int aux,sortat=1;
  while(sortat!=0)
  {
    sortat=0;
    for (size_t i = 0; i < n-1; ++i)
    {
      if(v[i]>v[i+1])
      {
        aux=v[i];
        v[i]=v[i+1];
        v[i+1]=aux;
        sortat=1;
      }
    }
  }
}*/

/*void quicksort(int number[25],int first,int last)
{
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}*/

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void sort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);


        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}

int main()
{
  srand(time(0));
  int v[50],n;
  n=rand()%10+1;
  printf("n=%d\n", n);
  for (size_t i = 0; i < n; ++i)
  {
    v[i]=rand()%100+1;
  }
  printf("Vector nesortat:\n");
  for (size_t i = 0; i < n; ++i)
  {
    printf("%d ", v[i]);
  }
  printf("\n");
  //bubble(v,n);
  //quicksort(v,0,n-1);
  sort(v,0,n-1);
  printf("Vector sortat:\n");
  for (size_t i = 0; i < n; ++i)
  {
    printf("%d ", v[i]);
  }
}
