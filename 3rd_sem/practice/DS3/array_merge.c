#include <stdio.h>

int main()
{
    int n1,n2,i,j;
    printf("Enter the no. of elements of array 1 and array 2\n");
    scanf("%d%d", &n1, &n2);
    int a1[n1], a2[n2];
    
    printf("Enter the elements of the first array:\n");
    for(i=0;i<n1;i++)
    scanf("%d", &a1[i]);

    printf("Enter the elements of the second array:\n");
    for(i=0;i<n2;i++)
    scanf("%d", &a2[i]);

    int a3[n1+n2];  //creating the array that will merge the two arrays
    for(i=0;i<(n1+n2);i++)
    {
        if(i<n1)    //storing the first array
        {
            a3[i] = a1[i];
        
        }
        else       //storing the second array
        {    
            a3[i] = a2[i-(n2-1)];
            
        }
    }

    printf("The new array\n");
    for(i=0;i<(n1+n2);i++)
    {
        printf("%d\t", a3[i]);
    }    
}