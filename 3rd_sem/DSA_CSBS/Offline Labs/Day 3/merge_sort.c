#include <stdio.h>

void merge();
void merge_sort();

void merge(int a[], int p, int q, int r)
{
    int n1,n2,i,j,k;
    n1 = q-p+1;
    n2 = r-q;
    int L[n1+1],R[n2+1];
    
    for(i=0;i<n1;i++)
    L[i]= a[p+i];
    for(j=0;j<n2;j++)
    R[j] = a[q+j+1];
    L[i]=99999;
    R[j]=99999;
    i=0;j=0;

    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }

}

void merge_sort(int a[], int p, int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}

int main()
{
    int n,i;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    merge_sort(a,0,n-1);
    printf("The sorted array:\n");
    for(int i=0;i<n;i++)
    printf("%d\t",a[i]);
    return 0;
}