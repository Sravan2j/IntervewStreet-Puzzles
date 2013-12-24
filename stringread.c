#include <stdio.h>
#include<string.h>

int main(void)
{
   	char ch;
   	
   	int length,tests,a,b,c,i,j;
   	char s1[100];
    scanf("%d",&tests);
   	int ans[tests];
   	for(j=0; j<tests; j++)
   	{   		
        memset(s1,'\0',100);
		scanf("%s",&s1);
        a=0;
        b=0;
        c=0; 
        length = strlen(s1);

		for(i=0; i<length; i++)
		{
			if(s1[i]=='a')
 			{
 				a=a+1;
 			}
 			if(s1[i]=='b')
 			{
 				b=b+1;
 			}
 			if(s1[i]=='c')
 			{
 				c=c+1;
 			} 			
		}
        if (((a==0) && (b==0)) || ((c==0) && (b==0)) || ((a==0) && (c==0)))
        {
           ans[j] = strlen(s1);
        }
        else
        {
            a=a%2;
            b=b%2;
            c=c%2;
            if( (a==b) && (b==c))
            {
                ans[j] = 2;
            }
            else
            {
                ans[j] = 1;
            }
        }
    }		
	for(i=0; i<tests; i++)
   	{
   		printf("%d",ans[i]);	
   		printf("\n");
   	}  	
	return 0;  	   	
}
