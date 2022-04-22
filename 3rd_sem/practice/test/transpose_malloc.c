#include <stdio.h>
#include <stdlib.h>

void main()
{
    int r,c,i,j,t=0,m=0;
    printf("Enter the rows and columns\n");
    scanf("%d", &r);
    scanf("%d", &c);
    int *a[r];
    int *k[c];/*creating a array of pointers, each of which will point(store the adress)
    to a dynamically allocated heap*/
    
    for(i=0;i<r;i++)
    {
        a[i] = (int*)malloc(c*sizeof(int));
    }
    for(i=0;i<c;i++)
    {
        k[i] = (int*)malloc(r*sizeof(int));
    }
    printf("Enter the elements of the array");
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d", (*(a+i)+j));
        }
    }
    printf("The original array:\n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("The transposed array:\n");
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {   
            k[j][i] = a[i][j];
        }
    }

    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d\t", k[i][j]);
        }
        printf("\n");
    }

}