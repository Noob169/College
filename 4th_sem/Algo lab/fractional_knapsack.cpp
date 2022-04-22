#include <iostream>
using namespace std;

//SORT
typedef struct items
{
    int profit;
    int weight;
    double ratio;
    char marker;
    items()
    {
        this->profit = 0;
        this->weight=0;
        this->ratio=0;
        this->marker='\0';
    }
}items;




void merge(items a[], int p, int q, int r)
{
    int n1,n2,i,j,k;
    n1 = q-p+1;
    n2 = r-q;
    items L[n1+1],R[n2+1];
    for(i=0;i<n1;i++)
    {
        L[i]= a[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j] = a[q+j+1];
    }
    L[i].ratio=-1;
    R[j].ratio=-1;
    i=0;j=0;

    for(k=p;k<=r;k++)
    {
        if(L[i].ratio>=R[j].ratio)
        {
            if(L[i].ratio==R[j].ratio)
            {
                if(L[i].weight<R[i].weight)
                {
                    a[k]=L[i];
                    i++;
                }
            }
            else
            {
            a[k]=L[i];
            i++;
            }
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }

}

void merge_sort(items *a, int l, int u)
{
    if(u>l)
    {
        int mid=(l+u)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,u);
        merge(a,l,mid,u);
    }
}

int main()
{
    int n,bag,i,total_profit=0;
    double frac=0;
    char s;
    cout<<"Enter number of items: ";
    cin>>n;
    cout<<"Max bag capacity: ";
    cin>>bag;
    items array[n];
    cout<<"Enter items in form: profit weight marker"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>array[i].profit>>array[i].weight>>array[i].marker;
        array[i].ratio=array[i].profit/array[i].weight;
    }
    merge_sort(array,0,n);
    cout<<"ITEMS\tQUANTITY"<<endl;
    i=0;
    while(i<n)
    {
        frac=array[i].weight<bag?1:((double)bag/(double)array[i].weight);
        bag-=frac*array[i].weight;
        total_profit+=frac*array[i].profit;
        cout<<array[i].marker<<"\t"<<frac<<endl;
        i++;
    }
    cout<<"MAX PROFIT: "<<total_profit;
}
