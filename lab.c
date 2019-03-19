#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    float t,f;
}s1,s2;

struct node1
{
    float t,f
}rq[2],r2[2];

struct node2
{
    float t,f;
}q1[4],q2[4];

int main()
{
    char nodes[20],prob[30],initial1,initial2;
    int i,nprob;
    gets(nodes);
    
    initial1=nodes[0];
    
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
    
    printf("%c %c",initial1,initial2);
    
    return 0;
}
