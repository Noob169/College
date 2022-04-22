#include <stdio.h>
#include <stdlib.h>
void q();
int check();
int length();

int main()
{

char a[50];
printf("Enter the string:\n");
gets(a);
q(a);

}

void q(char a[])
{
    int p, i=0,o=0, m=0;
    char k[50], b[50];
    printf("Enter the word to be searched\n ");
    gets(b);
   
    while (a[i])
    {
        if(a[i]!=' ')
        {
            k[m] = a[i];
            m++;
        }
        else
        {
            k[m]='\0';
            o = check(k,b);
            if(o==1)
            break;
            else
            m=0;
        }
        i++;
    }
    if(o==1)
    printf("The word is present");
    else
    printf("The word is not present");
}

int check(char a[],char b[])
{
    int i=0,c=0;
    char e=' ',d=' ';
    int l1 = length(a);
    int l2 = length(b);
    if(l1==l2)
    {
        while(i<l1)
        {
            e=a[i];
            d=b[i];
            if(e!=d)
            {
                c=0;
                break;
            }
            else
            c=1;
            i++;
        }
    }

    return c;
}

int length(char a[])
{
    int i=0;
    while(a[i])
    i++;
    return(i);
}


    