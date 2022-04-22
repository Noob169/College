#include <stdio.h>

int recursion(int n)
{
    if(n==1)
    return 1;
    else
    return(n*recursion(n-1));
}

int main()
{
    int n;
    printf("Enter the number whose factorial you want to print");
    scanf("%d", &n);
    printf("\nThe factorial is\t%d", recursion(n));
}