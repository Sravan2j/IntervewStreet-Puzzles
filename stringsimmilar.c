#include <stdio.h>
#include<string.h>

int main(void)
{
    int length,tests,count,i,j,found;
    int k=0,m,mcopy,times;
    char s1[100000];
    scanf("%d",&tests);  
    char ch='\0';   
    while(tests--){
        count=0;
        s1[0]='\0';
        scanf("%s",&s1);
        length = strlen(s1);
        ch = s1[0];
        for (j=1;j<length && s1[j]==ch;j++) count+=1;
        if(count==0)
        {
            ++j;
            k=0;
            mcopy=0;
            for(j;j<length && s1[j]!=ch;j++);      
            k=j;                   
            found=0;
            times=0;       
            for(;j<length;)
            {
                for(m=0;m<k;m++)
                {
                    if(j==length || s1[m]!=s1[j])
                    {
                        found=1;
                        break;
                    }
                    j++;                                                                                                 
                }         
                if(found==1)
                {                                
                    mcopy=m;                                                              
                    break;
                }
                times++;                         
            }
            count=(k*times*(times+1))/2 + mcopy*(times+1); 
        }
        else
        {
            count = count*(count+1)/2;
        }
        for(j;j<length;j++){
            if(s1[j]==ch){
                count += 1;
                for(i=1;i<length-j && s1[j+i]==s1[i];i++) count+=1;
            }
        }
        printf("%d",count+length);             
        printf("\n"); 
    }
    return 0; 
}