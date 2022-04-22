#include <stdio.h>

int recur();

void main()
{
    int m,n;
    printf("Enter the number 'm' which is to be raised to the power 'n'\n");
    scanf("%d", &m);
    scanf("%d", &n);
    int p = recur(m,n);
    printf("\nThe solution is %d", p);
}

int recur(int m, int n)
{
    if(n==0)
    return 1;
    else
    return (m*recur(m,n-1));
}