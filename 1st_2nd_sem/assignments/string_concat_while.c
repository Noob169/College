#include <stdio.h>
int main()
{
    int i=0, k=0;
    char ar1[50], ar2[50];
    printf("Enter the two strings, 1  and 2, in order\n");
    gets(ar1);
    fflush(stdin);
    gets(ar2);
    while(ar1[i])
    i++;
    while(ar2[k])
    {
        ar1[i] = ar2[k];
        i++;k++;
    }
    ar1[i] = '\0';
     printf("\nConcatenated String\t%s", ar1);
     return 0;
}

