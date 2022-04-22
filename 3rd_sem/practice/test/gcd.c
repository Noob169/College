#include <stdio.h>

void main()
{
    int a,b,gcd=1,m,i;
    printf("Enter the two numbers whose gcd you want to find");
    scanf("\n%d", &a);
    scanf("\n%d", &b);
    if(a>b)
    m=a;
    else
    m=b;
    for(i=1;i<=m;i++)
    {
        if(a%i==0&&b%i==0)
        gcd = i;
    }
    printf("\nThe gcd of the given numbers is %d", gcd);
}