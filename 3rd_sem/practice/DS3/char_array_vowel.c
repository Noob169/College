#include <stdio.h>

int main()
{
    int n,i,c=0;
    printf("Enter the number of characters you want to enter:\n");
    scanf("%d", &n);
    char a[n];
    char delta[n];
    
    printf("Enter the characters, in LOWERCASE ONLY:\n");
    for(i=0;i<n;i++)
    scanf(" %c", &a[i]);

    printf("The original array:\n");
    for(i=0;i<n;i++)
    printf(" %c\t", a[i]);

    for(i=0;i<n;i++)
    {
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
        continue;
        else
        {
            delta[c]=a[i];
            c++;
        }
        
    }

    printf("\nThe non-vowel array 'DELTA'\n");
    if(c==0)
    printf("Sorry, only vowels were present!\n");
    else
    {
        for(i=0;i<c;i++)
        printf("%c\t", delta[i]);
    }
}   