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
    return t;
}

void disp()
{
    Node *t;
    for(int i=0;i<MAX;i++)
    {
        t=arr[i];
        if(t!=NULL)
        printf("\nKey#%d: %d",i,t->d);
    }
}
void probe(int *a, int n)
{
    int k,j,nt;
    Node *t;
    for(int i=0;i<n;i++)
    {
        k=hf(a[i]);
        nt=a[i];
        t=getNode(nt);
        if(arr[k]==NULL)
        arr[k]=t;
        else
        {
            j=i;
            while(arr[j]!=NULL)
            j++;
            arr[j]=t;
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
    if(MAX>=n)
    {
        for(int i=0;i<n;i++)
        {
         printf("Enter element #%d",i+1);
         scanf("%d",&a[i]);
        }
    probe(a,n);
    disp();
    }
    else
    printf("Hashing cannot be performed");
}
