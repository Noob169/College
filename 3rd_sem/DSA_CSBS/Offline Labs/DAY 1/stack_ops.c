#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int d;
    struct node *a;
}Node;

Node *temp, *head;
int nc=0,MAX;
char s[100];
Node* create(int n)
{
    Node *t= (Node*)malloc(sizeof(Node));
    t->d=n;
    t->a=NULL;
    return t;
}

int pop()
{
    int c = temp->d;
    temp = temp->a;
    head=temp;
    nc--;
    return c;
}

void push(int n)
{
    Node *t=create(n);
    t->a=head;
    head=t;
    temp=head;
    nc++;
}

void stack_ops()
{
    int ch=0;
    int c;
    printf("\nEnter max number of stacks: ");
    scanf("%d",&MAX);
    printf("\nEnter 1 to insert: ");
    scanf("%d",&ch);
    while(ch!=0)
    {
       if(ch==1)
       {
           if(nc==MAX)
           printf("Overflow!");
           else
           {
               printf("\nEnter the character: ");
               scanf("%d",&c);
               push(c);
           }
       }
       else 
       {
           if(nc==0)
           printf("UNDERFLOW");
           else
           printf("Element popped: %d",pop());
       }
       printf("\nEnter 1 to push, Enter 2 to pop: ");
       scanf("%d",&ch);
    }
}

int main()
{
    stack_ops();
    return 1;
}

