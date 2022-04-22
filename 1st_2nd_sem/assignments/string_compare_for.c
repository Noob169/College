#include <stdio.h>
int main()
{
    int i=0, k=0;
    char ar1[50], ar2[50];
    printf("Enter the two strings, 1  and 2, in order\n");
    gets(ar1);
    fflush(stdin);
    gets(ar2);
    for(i=0;ar1[i]!='\0';i++)
    {
        if(ar1[i]==ar2[i])
        k = 1;
        else
        {
            k=0;
            break;
        }
    }
    if (k==1)
    {
        printf("\nThe two strings are equal");
    }
    else
    {
        printf("\nThe strings are not equal");
    }
    
    
    
}
