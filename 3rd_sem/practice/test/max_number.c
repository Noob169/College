#include <stdio.h>

void main()
{
    int n, i;
    printf("Enter the number of elements \n");
    scanf("%d", &n);
    int a[n], max=0, k=0;
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    scanf("\n%d", &a[i]);
    max = a[0];
    i=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        max = a[i];
    }
    printf("The greatest number is: %d", max);
}