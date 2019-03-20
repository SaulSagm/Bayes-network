#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char name[10];
}s1[10];

int main()
{
    char nodes[20],prob[30];
    int i,j,nnodes=0,nprob;
    scanf("%s",&nodes);
    
    
    for(i=0;i<20;i++)
    {
        if(nnodes==0&&nodes[i]!=' '&&nodes[i]!=',')
            s1[nnodes].name[i]=nodes[i];
        else
            if(nodes[i]==',')
                nnodes++;
            else
                if(nnodes==1&&nodes[i]!=' '&&nodes[i]!=',')
                {
                    s1[nnodes].name[i]=nodes[i];
                    j++;
                }
                else
                    if(nodes[i]=='\0')
                        i=20;
    }
    
    printf("%s \n",s1[0].name);
    printf("%s \n",s1[1].name);
    /*initial1=nodes[0];
    
    for(i=0;i<20;i++)
    {
        if(nodes[i]==','&&nodes[i+1]==' ')
            initial2=nodes[i+1];
        else
            if(nodes[i]==',')
                initial2=nodes[i+1];
    }
    scanf("%i",&nprob);
    
    gets(prob)
    
    for(i=0;i<30;i++)
    {
        if(prob[i]=='|')
        {
            if(prob[i+1]=='+')
            {
                
            } 
        }
    }
    
    printf("%c %c",initial1,initial2);*/
    
    return 0;
}
