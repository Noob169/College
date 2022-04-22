#include <stdio.h>

int recur();
void main()
{
    printf("Enter the number whose factorial you want:\n");
    int n;
    scanf("%d", &n);
    int f = recur(n);
    printf("The factorial is: %d", f);
}

int recur(int n)
{
    if(n==1)
    return 1;
    else
    return(n*recur(n-1));
}