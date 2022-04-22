#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n,i,k=3,max, pos=0;
    printf("Enter the number of elements \n");
    scanf("%d", &n);
    int *p = (int*)malloc(n*sizeof(int));
    printf("\nEnter the elements");
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    
    printf("\nThe elements are: ");
    for(i=0;i<n;i++)
    {
        printf("\n%d", p[i]);
    }
    
    while(k>0)
    {
        max=0;
        for(i=0;i<n;i++)
        {
            if(p[i]>max)
            {
                max = p[i];
                pos = i;
            }
        }
        printf("\nGreatest number # %d is %d", k, max);
        k--;
        p[pos]=0;
    }
}