#include <stdio.h>
#include <stdlib.h> 

void swap(int *x,int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

int choose_pivot(int i,int j )
{
   return((i+j) /2);
}

void quicksort(int list[],int m,int n)
{
   int key,i,j,k;
   if( m < n)
   {
      k = choose_pivot(m,n);
      swap(&list[m],&list[k]);
      key = list[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i] <= key))
                i++;
         while((j >= m) && (list[j] > key))
                j--;
         if( i < j)
                swap(&list[i],&list[j]);
      }
	  // swap two elements
      swap(&list[m],&list[j]);
	  // recursively sort the lesser list
      quicksort(list,m,j-1);
      quicksort(list,j+1,n);
   }
}
int main()
{
   int MAX_ELEMENTS,diff,count=0,mid,m=0,l=0,a,u=0;
   scanf("%d",&MAX_ELEMENTS);
   scanf("%d",&diff);
   int list[MAX_ELEMENTS];
   int i = 0;
   a=MAX_ELEMENTS-1;
   for(; i < MAX_ELEMENTS; i++ ){
	   scanf("%d",&list[i]);
   }
   quicksort(list,0,MAX_ELEMENTS-1);  
   if ( list[0] + diff < list[MAX_ELEMENTS-1]){
      for (i=0;i < MAX_ELEMENTS; i++)
      {
          m = list[i] + diff;
          u=a;
          l=i+1;
          while(l<=u){
          mid=(l+u)/2;
          if(m==list[mid]){
             count+=1;
             break;
         }
         else if(m<list[mid]){
             u=mid-1;
         }
         else
             l=mid+1;
         }
          
      }
   printf("%d",count);
   printf("\n"); }  
   else
   printf("0\n");
   return 0;
}
