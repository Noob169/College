#include <stdio.h>
#include <stdlib.h>
void q();
//int length();

int main()
{

char a[50];
printf("Enter the string:\n");
gets(a);
q(a);

}

void q(char a[])
{
    int i=0, m=0, v=0, n[26];
    int k;
    char c[26];
    while (a[i])
    {
        if((int)a[i]>=65&&(int)a[i]<=90)
        a[i] = (char)((int)a[i]+32);
        i++;
    }
    i=0;
    /*while(a[i]) 
    {
        //if(n[i]!=0)
        printf(" %c\n", a[i]);i++;
    } */ 
    i=0;
    while(a[i])
    {
       
       k = (int)a[i];
       if(k>=97&&k<=122)
       {
          while(a[v])
          {
           if((int)a[v]==k)
            {
                c[m]=a[v];
                n[m]++;
                a[v]='A';
            }
            v++;
          }
         m++;
       }
       
        i++;
        v=0;

    }
    //printf("\nThe number of consonants:\t%d\nThe number of vowels:\t%d",c,v);
    i=0;
    //n[0]--;
    while(c[i]) 
    {
        if(n[i]!=0)
        {
           
            printf("%c:-%d\n", c[i],n[i]);
        }
        i++;
    }  
}

/*int length(char a[])
{
    int i=0;
    while(a[i])
    i++;
    return(i);
}*/