#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
 
struct node     //The name of each node is saved in a structure
{
    char state[15]; //Example->"Test","Ill"
}nstate[10];

struct calc     //The name of some nodes are saved in a structure 
{               //Used for some calculation
    char cstate[15];    
}calState[15];

struct pstate   //The conditions are saved with their respective probability
{
    char pstate[30];    //Example-> "+Ill",0.01     "+Test,+Ill",0.0009
    double prob;        
}nodeState[25];

struct result
{
    float value;        //The results are saved in the same order in which
}nresult[15];           //the conditions were asked

struct num
{
    double valn;        //Probabilities related to the numerator
}vnum[15];              //for the enumeration operation

struct cnum
{
    char cond[30];      //Conditions related to the numerator
}numCon[15];            //for the enumeration operation

struct den
{
    double vald;        //Probabilities related to the denominator
}vden[15];              //for the enumeration operation

struct cden
{
    char cond[30];      //Conditions related to the denominator
}denCon[15];            //for the enumeration operation

int main ()
{
    const int dos=2;
    int a=0,i=0,k=0,m=0,n=0,l=0,o=0,p=0,q=0;    //Flags and counters
    int r=0,s=0,t=0,u=0,y=0,w=0,x=0,z=0;
    int sig=0,fract=0;
    int j,h,g;
    int n_states,n_prob,n_queries,n_node=0,lim=0,initial=0;
    int countC=0,countD=0,acum=0,counter=0;
    double prob,par=1,prob1=0,prob2=0;  //Variables for calculations
    double numerator=0,denomitor=0;
    char str1[75],str2[75],str3[50],str4[50],str5[50],str6[50]; //Strings
    char str7[50],str8[50],str9[50],str10[50],str11[50],str12[50],str13[50];
    char val[50],cant[50],por[50],var[50];
    char pot[50],vat[50],mat[50],mar[50],car[50];
    char complem[50];
    char *pch1,*pch2,*pch3,*pch4,*pch5,*pch6;       //Pointers
    char *pch7,*pch8,*pch9,*pch10,*pch11,*pch12;
    char *val1=val,*cant1=cant,*por1=por,*var1=var;
    char *pot1=pot,*vat1=vat,*mat1=mat,*mar1=mar,*car1=car;
    
    fflush(stdin);
    scanf("%s",&str1); //First string asked, the name of all nodes

    pch1=strtok(str1," ,"); //In this part the string is divided by comas           
    while(pch1!=NULL)
    {
        strcpy(nstate[i].state,pch1);    //The name of each substring is saved
        pch1=strtok(NULL," ,");          //in a structure
        i++;
    }
        
    fflush(stdin);scanf("%i",&n_prob);	//Lecture of number of probabilities
    
    while(n_prob>0)             //Until all the probabilities are asked, 
    {                           //the cycle will continue
        fflush(stdin);
        scanf("%s",&str2);      //The probabilities are given
        
        countC=0;countD=0;
        for(j=0;j<75;j++)       //Counts the coma and dashes for more
        {                       //control of the nodes
            if(str2[j]==',')
                countC++;
            if(str2[j]=='|')
                countD++;
        }
        if(countC==0 && countD==0)      //If the is only one state 
        {                               //for example: +Ill=0.01
            pch2=strtok(str2," =");     
            while(pch2!=NULL)
            {
                strcpy(val1,pch2);      //The substring befor the '=' is saved
                if(k==0)
                {
                    for(j=0;j<i;j++)
                    {
                        if(strstr(val1,nstate[j].state))
                        {
                            strcpy(nodeState[m].pstate,val1);   //The condition
                            j=5;                                //is saved in a
                            k++;                                //structure
                        }
                    }
                }
                else
                    if(k==1)
                    {
                        prob=atof(val1);        
                        nodeState[m].prob=prob;     //The probability is saved
                        k=0;                        //in a structure
                    }
                pch2=strtok(NULL," ="); 
            }
            m++;
            strcpy(complem,nodeState[m-1].pstate);  //The complement of the 
            complem[0]='-';                         //of the condition is
            strcpy(nodeState[m].pstate,complem);    //calculated
            nodeState[m].prob=(1-nodeState[m-1].prob);  //and saved in a
            m++;                                    //in a structure
            n_prob--;
            initial++;  //Initial counts the number of single nodes received
        }               //at the beginning
        else
            if(countD>0)
            {
                if(lim==0)
                {
                    lim=pow(dos,countC+1);    //Number of conditions needed
                }
                par=1;
                strcpy(str6,str2);      //The string is saved in another one
                pch3=strtok(str2," |=");
                while(pch3!=NULL)
                {
                    strcpy(val1,pch3);      //The substring between the dash
                    if(q==1)                //and '=' are saved in a different
                    {                       //string
                        strcpy(str13,val1);
                    }
                    q++;
                    pch3=strtok(NULL," |=");
                }
                q=0;
                
                pch12=strtok(str13," ,");
                while(pch12!=NULL)
                {
                    strcpy(car1,pch12);     //The previous substring is divided
                    strcpy(calState[a].cstate,car1);    //by comas to be saved
                    a++;                        //in a structure for later
                    pch12=strtok(NULL," ,");    //calculations
                }
                if(initial>1)   //If we received more than one single condition
                {               //at the beginning
                    for(j=0;j<m;j++)
                    {
                        for(g=0;g<a;g++)
                        {
                            if(strcmp(nodeState[j].pstate,calState[g].cstate)==0)
                                par=par*nodeState[j].prob;  //The probability               
                        }                   //is acumulated by multiplying each
                    }                       //other since they are cond indep
                }
                else
                {
                    for(j=0;j<m;j++)
                    {
                        for(g=0;g<a;g++)
                        {
                            if(a==1&&strcmp(nodeState[j].pstate,calState[g].cstate)==0)
                            {
                                par=nodeState[j].prob;  //If the condition 
                                j=m;        //already exists in the structure
                                g=a;        //its probability will be saved
                            }               //in a variable
                            else
                                if(a!=1&&strstr(nodeState[j].pstate,calState[g].cstate))
                                    counter++;      //When there are more
                                                    //conditions and they are
                            if(counter==a)          //all in one condition of the 
                                par=nodeState[j].prob;  //structure, its condition
                        }                           //is saved
                        counter=0;
                    }
                }
                pch6=strtok(str6," =");
                while(pch6!=NULL)
                {
                    strcpy(cant1,pch6); //The saved previously will be divided
                    if(k==0)            //by the '=' to get what is before it
                    {
                        strcpy(complem,cant1);
                        for(n=0;n<50;n++)       //The substring is saved so 
                        {                       //its dashes can become comas
                            if(complem[n]=='|') 
                                complem[n]=',';
                        }
                        strcpy(nodeState[m].pstate,complem);    //Then the
                        k++;                    //condition is saved in a 
                    }                           //structure
                    else
                        if(k==1)
                        {
                            prob=atof(cant1);   //The probability is saved in a
                            nodeState[m].prob=prob*par; //variable to be then
                            k=0;                //saved in the its structure
                        }                       //with its condition
                    pch6=strtok(NULL," =");
                }
                //printf("%s\t%f\n",nodeState[m].pstate,nodeState[m].prob);
                m++;
                strcpy(complem,nodeState[m-1].pstate);  //Here the complements
                complem[0]='-';                         //are calculated
                strcpy(nodeState[m].pstate,complem);    //and saved
                nodeState[m].prob=(1-prob)*par;
                //printf("%s\t%f\n",nodeState[m].pstate,nodeState[m].prob);
                m++;
                n_prob--;
                lim--;
                a=0;
                
                if(lim==0)  //When the limit has been reached, the program
                {           //will calculate a total condition
                    strcpy(str8,nodeState[m-1].pstate); 
                    pch8=strtok(str8," ,");     //The previous condition saved
                    while(pch8!=NULL)           //will be divided by comas
                    {
                        strcpy(por1,pch8);
                        if(s==0)
                        {
                            strcpy(nodeState[m].pstate,por1); //If the first
                            for(j=0;j<m;j++)        //condition saved by the
                            {                       //coma is in any condition
                                if(strstr(nodeState[j].pstate,por1))    //of the
                                    prob1=prob1+nodeState[j].prob;  //structure,
                            }                       //its probability will be
                            s++;                    //acumulated
                        }
                        pch8=strtok(NULL," ,");
                    }
                    s=0;
                    nodeState[m].prob=prob1;    //The total of the probability
                    prob1=0;                    //is saved in the structure
                    //printf("%s\t%f\n",nodeState[m].pstate,nodeState[m].prob);
                    strcpy(str9,nodeState[m-2].pstate);
                    pch9=strtok(str9," ,");     //The same process like the last
                    while(pch9!=NULL)           //cycle but this time is for
                    {                           //the complement of the total
                        strcpy(var1,pch9);      //saved
                        if(s==0)
                        {
                            strcpy(nodeState[m+1].pstate,var1);
                            for(j=0;j<m;j++)
                            {
                                if(strstr(nodeState[j].pstate,var1))
                                    prob1=prob1+nodeState[j].prob;
                            }
                            s++;
                        }
                        pch9=strtok(NULL," ,");
                    }
                    s=0;
                    nodeState[m+1].prob=prob1;
                    prob1=0;
                    //printf("%s\t%f\n",nodeState[m+1].pstate,nodeState[m+1].prob);
                    m=m+2;
                    initial=0;
                }
            }
    }
    
    scanf("%i",&n_queries); //Enter the number of queries
    
    while(n_queries>0)      //Until the number of queries are searched,
    {                       //the cycle will continue
        fflush(stdin);
        scanf("%s",&str3);  //Enter the condition to search
        
        for(j=0;j<m;j++)
        {
            if(strcmp(nodeState[j].pstate,str3)==0) //The program searches
            {                                       //in the structure
                nresult[r].value=nodeState[j].prob; //with all the conditions
                r++;                    //saved, if it is already there it
                n_queries--;            //will be saved in the structure of
                sig=0;                  //of results
                j=m;
            }
            else
            {
                sig=1;  //If there is none, a flag is activated
            }
        }

        if(sig==1)  //If the flag is activated, the enumeration function
        {           //will be calculated
            strcpy(str12,str3);
            pch4=strtok(str3," |=");    //The substring between the dash and '='
            while(pch4!=NULL)           //is extracted
            {
                strcpy(pot1,pch4);
                if(t==1)
                {
                    strcpy(str4,pot1);
                }
                t++;
                pch4=strtok(NULL," |=");
            }
            t=0;
            
            pch10=strtok(str4," ,");
            while(pch10!=NULL)          //The previous substring is divided now
            {                           //by the comas, each condition is saved
                strcpy(vat1,pch10);     //in the structure of denominators
                strcpy(denCon[y].cond,vat1);
                y++;
                pch10=strtok(NULL," ,");
            }
            
            pch5=strtok(str12," =");
            while(pch5!=NULL)       //Now the substring we need is the one
            {                       //before the '='
                strcpy(mat1,pch5);
                if(u==0)
                {
                    strcpy(str11,mat1);
                    u++;
                }
                pch5=strtok(NULL," =");
            }
            u=0;
            
            pch11=strtok(str11," |,");
            while(pch11!=NULL)          //The previous substring is divided
            {                           //by the dash and comas so the
                strcpy(mar1,pch11);     //conditions are saved in the structure
                strcpy(numCon[l].cond,mar1);    //of numerators
                l++;
                pch11=strtok(NULL," |,");
            }
            
            for(j=0;j<m;j++)
            {
                for(g=0;g<y;g++)
                {
                    if(strcmp(nodeState[j].pstate,denCon[g].cond)==0)
                    {               //Now if the denominator is a condition 
                        vden[x].vald=nodeState[j].prob; //already saved in the
                        x++;        //structure of conditions, it will be
                    }               //added to the structure of values of the
                    else            //denominator
                        if(strstr(nodeState[j].pstate,denCon[g].cond))
                            acum++;     //If all the conditions are accomplished
                                        //the prob is saved in the structure of
                    if(acum==n)         //values of the denominator
                    {
                        vden[x].vald=nodeState[j].prob;
                        x++;
                    }
                }
                acum=0;
            }
            
            for(j=0;j<m;j++)
            {
                for(g=0;g<l;g++)
                {
                    if(strstr(nodeState[j].pstate,numCon[g].cond))
                        acum++;     //The same logic as the one of denominator
                                    //but the data is saved in the structure
                    if(acum==l)     //of values of the numerator
                    {
                        vnum[z].valn=nodeState[j].prob;
                        z++;
                    }
                    
                }
                acum=0;
            }

            for(j=0;j<z;j++)        //All the conditions saved in the structure
                numerator=numerator+vnum[j].valn;   //of numerators is summed
            
            for(j=0;j<x;j++)        //All the conditions saved in the structure
                denomitor=denomitor+vden[j].vald;   //of denominators is summed
                
            nresult[r].value=numerator/denomitor;   //Finally the division is 
            r++;                                    //made
            n_queries--;    //Number of queries is reduced
            l=0;            //Some variables are reseted to work again
            y=0;
            x=0;
            z=0;
            numerator=0;
            denomitor=0;
            sig=0;
        }
    }
    
    for(j=0;j<r;j++)    //In the end all the values saved in the structure of
        printf("%.7f\n",nresult[j].value);    //results is given in order
    
    return 0;   //End
}
