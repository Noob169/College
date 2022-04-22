//QUEUE IMPLEMENTATION USING LIFO PRINCIPLE

#include <stdio.h>
#include <stdlib.h>

void dequeue();
void enqueue();
void display();

typedef struct queue
{
    int data;
    struct queue *adr;
}Q;

Q *top, *rear;
int c=0;

Q* create()
{
    Q *f = (Q*)malloc(sizeof(Q));
    printf("Enter the data:\t");
    scanf("%d", &f->data);
    f->adr = NULL;
    return(f);
}

void main()
{
    int ch;
    for(;;)
    {
        printf("\nMENU:\nPRESS 1 TO FOR ENQUEUE FUNCTION\nPRESS 2 FOR DEQUEUE FUNCTION\nPRESS 3 FOR DISPLAY FUNCTION\nPRESS 0 TO END\nEnter your choice:\t");
        scanf("%d", &ch);
        if(ch!=0)
        {
            switch(ch)
            {
                case 1:
                enqueue();
                break;

                case 2:
                dequeue();
                break;

                case 3:
                display();
                break;

                default:
                printf("\nEnter the right choice!");
                break;
            }
        }
            else
            break;
    }

}

void enqueue()
{
    Q *f = create();
    if(c==0)
    {
        top = f;
        rear = f;    
    }
    else
    {
        rear->adr = f;
        rear = f;
    }
    c++;
}

void dequeue()
{
    Q *f;
    f = top;
    top = top->adr;
    top->adr = NULL;
    c--;
}

void display()
{
    if(c!=0)
    {
        printf("\nThe QUEUE:\n");
        rear = top;
        while(rear!=NULL)
        {
            printf("%d\t", rear->data);
            rear = rear->adr;
        }
    }
    else
    printf("\nThe queue is EMPTY!");

}