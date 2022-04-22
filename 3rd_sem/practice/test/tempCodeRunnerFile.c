#include <stdio.h>
void swap_point();
void swap_var();

void main()
{
    int a,b;
    printf("Enter two numbers that you want to swap\n");
    scanf("%d", &a);
    scanf("%d", &b);
    int *x = &a;
    int *y = &b;
    printf("\nBefore swapping, a is %d, b is %d", a,b);
    swap_var(a,b);//call by value
    swap_point(x,y);//call by reference
    printf("\nAfter swapping using call by reference, a is %d, b is %d", a,b);
}

void swap_var(int a, int b)
{
    int t;
    t=a;
    a=b;
    b=t;
    printf("\nAfter swapping using call by value, a is %d, b is %d", a,b);
}

void swap_point(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

