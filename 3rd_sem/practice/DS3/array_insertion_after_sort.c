#include <stdio.h>

void insert();
int main()
{
    int n, i, j, k, e, t=0;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int a[n];
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
    
    //sorting the array using bubble sort technique

    for (i = 0; i < n-1; i++)     
      {
            for (j = 0; j < n-i-1; j++) 
            {
                if (a[j] > a[j+1]) 
                {
                    t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                }
            }
      }
    
    printf("The new array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
}
    