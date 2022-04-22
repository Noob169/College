#include <stdio.h>
#include <stdlib.h>
 
int MAX;
 
void sort(int a[], int l, int h)
{
    if(l<h)
    {
        int p = partition(a,l,h);
        sort(a,l,p-1);
        sort(a,p+1,h);
    }
}
 
int partition(int a[], int l, int h)
{
   int i,j,p;
   p=a[h];
   i=l-1;
   for(j=l;j<=h-1;j++)
   {
       if(a[j]<p)
       {
           i++;
           swap(a,i,j);
        }
    }
    swap(a,i+1,h);
    return i+1;
}
 
void swap(int arr[], int a, int b)
{
    int t=arr[a];
    arr[a]=arr[b];
    arr[b]=t;
}
 
int main()
{
    int a[100];
    printf("Enter the MAXIMUM no. of elements: ");
    scanf("%d",&MAX);
    printf("\nEnter the elements");
    for(int i=0;i<MAX;i++)
    scanf("%d",&a[i]);
    sort(a,0,MAX-1);
    printf("\nThe sorted elements: ");
    for(int i=0;i<MAX;i++)
    printf("%d ",a[i]);
}
