#include <stdio.h>

int main()
{
    int n, k=0;
    int *p;//creating a pointer
    printf("**Please specify the size of the array**\n");
    scanf("%d", &n);
    int a[n];
    printf("**Please enter the data for the aray**\n");
    for(int i=0;i<n;i++)
    {
        p = &a[i];//referencing the array adress to the pointer
        scanf("%d", &*p);
        *p+=5;
    }
    for (int j=0;j<n;j++)
    {
        if(*(a+j)==25)//using array as a pointer
        k=1;
    }
    if (k==1)
    {
        printf("\nThe array contains 25");
    }
    else
    {
        printf("\nThe array does not contain 25");
    }
    return 0;
}    
    
    
