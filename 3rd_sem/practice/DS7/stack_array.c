//LIFO stack implementation using stack
#include <stdio.h>

int n=0,k=0;
int s[100];

void push();
void peek();
void pop();
void display();

void main()
{
    int ch;
    printf("Enter the maximum number of elements\t");
    scanf("%d", &n);
    
    for(;;)
    {
        printf("\nMENU:\nPress 1 to push, Press 2 to pop, 3 to peek, 4 to display 0 to end:\t");
        scanf("%d", &ch);
        if(ch==0)
        break;
        switch(ch)
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
            printf("\nEnter the correct input");
            break;
        }
    }
}

void push()
{
    int d;
    if(k==n)
    printf("\nOVERFLOW!");
    else
    {
        printf("\nEnter the data to be pushed:\t");
        scanf("%d", &d);
        s[k] = d;
        k++;
    }
}

void pop()
{
    if(k!=0)
    {
        printf("Data popped is %d", s[k-1]);
        s[k-1]=0;
        k--;
    }
    else
    {
        printf("\nUNDERFLOW!");
    }
}

void peek()
{
    printf("\nData to be peeked is %d", s[k-1]);
}

void display()
{
    int i=0;
    if(k==0)
    printf("Stack is empty!");
    else
    {
        while(i<k)
        {
            printf("%d\t", s[i]);
            i++;
        }
    }
}