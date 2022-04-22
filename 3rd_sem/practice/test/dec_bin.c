#include <stdio.h>

int bin();
int mul();
void main()
{
    int n;
    printf("Enter the number you want to convert!\n");
    scanf("%d", &n);
    bin(n);
}

int bin(int n)
{
    int k=-1, s=n, c=0, o=0;
    while(s>0)
    {
        k++;
        s = n/mul(k); 
    }
    int a[k];
    o=n;
    while(n>0)
    {
        a[c]=n%2;
        n = n/2;
        c++;
    }
    printf("\nThe binary form of the number %d is:", o);
    while(c>=0)
    {
        printf("%d", a[c]);
        c--;
    }
}

int mul(int n)
{
    if(n==0)
    return 1;
    else
    return (2*mul(n-1));
}