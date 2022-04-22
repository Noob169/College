//LIFO STACK implemented using linked list

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void peek();
void display();

typedef struct stack
{
    int data;
    struct stack *adr;
}sNode;

sNode *temp, *head;
int c=0, n=0;

int main()
{
    int k;   
    printf("Enter the maximum number of data to be entered:\t");
    scanf("%d", &n);
    for(;;)
    {
        printf("\nMENU:-\n\nPress 1 to push, Press 2 to pop, Press 3 to peek, Press 4 to display,Press 0 to end\nEnter your choice:\t");
        scanf("%d",&k);
        if(k==0)
        break;
        switch(k)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            default:
            printf("Wrong choice, try again\n");
            break;
        }

    }

}

sNode* create()
{
    sNode *f = (sNode*)malloc(sizeof(sNode));
    printf("Enter the data:\t");
    scanf("%d", &f->data);
    f->adr = NULL;
    return(f);
}

void push()
{
    sNode *f = create();
    if(c==0)
    {
        head = f;
        temp = head;
        c++;
    }
    else if(c==n)
    printf("OVERFLOW!");
    else 
    {
       f->adr = temp;
       temp = f;
       head= temp;
       c++;
    }
    
}

void pop()
{
    sNode *f;
    if(c>1)
    {
        printf("Node containing data %d popped out\n", temp->data);
        temp = temp->adr;
        head->adr = NULL;
        head = temp;
        c--;
    }
    else if(c==0)
    printf("UNDERFLOW!\n");
    else
    {
        printf("Node containing data %d popped out\n", temp->data);
        head = NULL;
        temp = NULL;
        c--;
    }
}

void peek()
{
    if(c!=0)
    {
        printf("The element in the node is:\t%d", temp->data);
    }
    else
    printf("No element is presnt in the stack!");
}

void display()
{
    if(c==0)
    printf("\nStack is empty!");
    else
    {
        printf("\nThe stack:\n");
        while(temp!=NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->adr;
        }
        temp = head;
    }
}

