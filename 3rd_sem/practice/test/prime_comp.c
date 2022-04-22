#include <stdio.h>

void main()
{

    int n,c=0,i;
    printf("Enter the number to be checked\n");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        c++;
    } 
    if(c==2)
    printf("\nThe number is prime!");
    else
    printf("\nThe number is composite!");
}