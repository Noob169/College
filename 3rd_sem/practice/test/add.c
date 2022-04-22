#include <stdio.h>

void add();

void main()
{
    int a,b;
    printf("Enter two numbers to add them\n");
    scanf("%d", &a);
    scanf("%d", &b);
    int *x, *y;
    x = &a;
    y = &b;
    add(x,y);
}

void add(int *a, int *b)
{
    int s = *a+*b;
    printf("\nThe sum is %d", s);
}