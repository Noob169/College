#include <stdio.h>
#include <stdlib.h>

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
        printf("\nKey: %d   ",i);
        if(arr[i]!=NULL)
        {
           t=arr[i];
           while(t!=NULL)
           {
               printf("%d\t",t->d);
               t=t->a;
           }
        }
    }
}
int main()
{
    int n;
    printf("Enter max number");
    scanf("%d",&MAX);
    printf("Enter no. of elements");
    scanf("%d",&n);
    int a[10];
    for(int i=0;i<n;i++)
    {
         printf("Enter element #%d",i+1);
         scanf("%d",&a[i]);
    }
    hash(a,n);
    display();
}
