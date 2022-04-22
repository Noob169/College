#include <stdio.h>

void main()
{
    int a,b,c, i=1;
    a=0;
    b=1;
    c=a+b;
    printf("The series:\n");
    printf("%d\t%d\t%d\t",a,b,c);
    while(i<=12)
    {
        a=b;
        b=c;
        c=a+b;
        printf("%d\t", c);
        i++;
    }
}