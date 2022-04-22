#include <stdio.h>
#include <stdlib.h>

void collision(int , int);
void search();
void sum();

typedef struct Node
{
    int d;
    struct Node *a;
}Node;

Node *arr[100];
int MAX;

int hf(int i)
{
    return(i%MAX);
}

Node* getNode(int n)
{
    Node *t=(Node*)malloc(sizeof(Node));
    t->d=n;
    t->a=NULL;
}
void hash(int *a, int n)
{
    int k=0;
    for(int i=0;i<n;i++)
    {
        k=hf(a[i]);
        collision(k,a[i]);
    }
}

void collision(int k,int n)
{
    Node *t=getNode(n);
    if(arr[k]==NULL)
    arr[k]=t;
    else
    {
        t->a=arr[k];
        arr[k]=t;
    }
}
void display()
{
    Node *t;
    for(int i=0;i<MAX;i++)
    {
        printf("\nKey:%d->  ",i);
        if(arr[i]!=NULL)
        {
           t=arr[i];
           while(t!=NULL)
           {
               printf("%d->",t->d);
               t=t->a;
           }
        }
    }
}
void search()
{
    int n,k;
    Node *t;
    printf("\nEnter the number to be searched: ");
    scanf("%d",&n);
    k = hf(n);
    if(arr[k]!=NULL)
    {
        t=arr[k];
        while(t!=NULL)
        {
            if(t->d==n)
            {
                printf("Number found at Key: %d",k);
                break;
            }
            t=t->a;
        }
    }
    if(t==NULL)
    printf("Number to be searched not found");
}
void sum()
{
    int sum=0;
    Node *t;
    for(int i=0;i<MAX;i++)
    {
        if(arr[i]!=NULL)
        {
           t=arr[i];
           while(t!=NULL)
           {
               sum+=t->d;
               t=t->a;
           }
        }
    }
    printf("\nThe sum of all the values in the hash table is: %d ",sum);
}
int main()
{
    int n,i,max,j,t;
    printf("Enter number of keys to be created: ");
    scanf("%d",&MAX);
    printf("Enter no. of values to be mapped to the keys: ");
    scanf("%d",&n);
    int a[10];
    for(i=0;i<n;i++)
    {
         printf("Enter element #%d: ",i+1);
         scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        max=i;
        for(j=i+1;j<n;j++)
        {
            if(a[max]<a[j])
            max=j;
        }
        t=a[i];
        a[i]=a[max];
        a[max]=t;
    }
    hash(a,n);
    display();
    search();
    sum();
}