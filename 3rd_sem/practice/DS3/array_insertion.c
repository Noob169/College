#include <stdio.h>

int main()
{
    int n, i, k, e;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int a[100];
    printf("Enter the elements of the array");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    
    printf("\nEnter the position at which you want to enter an element, followed by the number");
    scanf("%d%d", &k, &e);
    n++;
    for(i=n;i>k-1;i--)
    {
        a[i] = a[i-1];
    }
    a[k-1] = e;
    
    printf("The new array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
}
