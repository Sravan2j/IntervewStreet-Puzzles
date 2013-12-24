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
    int MAX_ELEMENTS,tests,i,maxch,k;
    float diff,ans,olddiff;
    scanf("%d",&tests);
    while(tests--)
    {
        i=0;
        k=0;
        scanf("%d",&MAX_ELEMENTS);
        int list[MAX_ELEMENTS];
        for(; i < MAX_ELEMENTS; i++ ){
            scanf("%d",&list[i]);
        }
        quicksort(list,0,MAX_ELEMENTS-1);
        if ( list[0] != list[MAX_ELEMENTS-1]){
            maxch=0;
            ans=0.0;
            for (i=0;i < MAX_ELEMENTS; i++) ans= ans + (MAX_ELEMENTS-i)/(float)(i+1);
            diff=0.0;
            olddiff=0.0;
            if(list[0]==list[1])
            {
                olddiff = 1/(float)MAX_ELEMENTS;
                ans= ans-olddiff;
            }
            maxch=MAX_ELEMENTS-1;
            for (i=1;i < maxch; i++)
            {
                if(list[i]==list[i+1])
                {
                    diff=0.0;
                    k=MAX_ELEMENTS-i;
                    diff+=1;
                    if(MAX_ELEMENTS-k>0) diff+=(MAX_ELEMENTS-k)/(float)(k+1);
                    diff=diff/(float)k;
                    if(list[i-1]==list[i]) diff=diff+olddiff;
                    olddiff=diff;
                    ans=ans-olddiff;
                }
            }   
            printf("%.2f",ans);
            printf("\n"); 
        }
        else{
            ans=MAX_ELEMENTS;
            printf("%.2f",ans);
            printf("\n");
        }
    }
    return 0;         
}