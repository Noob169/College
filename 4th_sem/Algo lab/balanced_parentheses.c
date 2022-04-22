#include "stack.h"
#include <stdio.h>
#include <string.h>

int check();
char paircheck(char );

char paircheck(char ch)
{
    if(ch=='(')
    return ')';
    else if(ch=='{')
    return '}';
    else
    return ']';
}

int check(char s[])
{
    int i=0;char t;
    while(i<strlen(s))
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        push(s[i]);
        else if(s[i]==')'||s[i]=='}'||s[i]==']')
        {
            if(paircheck(peek())==s[i])
            t=pop();
            else
            return peek();
            
        }
        i++;
    }
    //k=isEmpty();
    if(!(isEmpty()))
    return peek();
    else
    return 1;
}

int main()
{
   MAX=999;c=0;int r=0;
   printf("\nEnter the expression:\n ");
   char s[MAX];
   fgets(s,MAX,stdin);
   r=check(s);
   if(r==1)
   printf("\nBalanced expression!");
   else
   printf("\n%c has not been closed",r);
}
