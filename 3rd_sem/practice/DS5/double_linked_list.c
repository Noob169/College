#include <stdio.h>
#include <stdlib.h>

void insertion(int );
void deletion(int );
void display();

typedef struct linked_list
{
    struct linked_list *prev;
    int data;
    struct linked_list *next;
}Node;

Node *head, *temp1, *temp2, *f;
int c=0;

Node* create()
{
    Node *k = (Node*)malloc(sizeof(Node));
    printf("\nEnter the data\t");
    scanf("%d", &k->data);
    k->prev = NULL;
    k->next = NULL;
    return(k);
}

int main()
{
    int ch;

    for(;;)
    {
        printf("\n\n***MENU***:\n\n");
        printf("\nPress 1 for insertion, 2 for deletion, 3 for display, 4 to end program\n");
        printf("------------------------------------------------------------------------\n\n");
        scanf("%d", &ch);
        if(ch!=4)
        {
            switch(ch)
            {
                case 1:
                printf("\nEnter 1 to insert at the begining, 2 to insert after a particular position, 3 to insert at end:-\t");
                scanf("%d", &ch);
                insertion(ch);
                break;

                case 2:
                printf("\nEnter 1 to delete at the begining, 2 to delete after a particular position, 3 to delete at end:-\t");
                scanf("%d", &ch);
                deletion(ch);
                break;

                case 3:
                display();
                break;

                default:
                printf("Wrong choice, try again!\n");
                break;
            }
        }
        else
        break;
    }

}

void insertion(int ch)
{
    int n, i=0;
    if(c==0)
    {
        head = create();
        temp1 = head;
        temp2 = head;
        c = 1;
    }
    else
    {
        switch(ch)
        {
            case 1:
            f = create();
            f->next = head;
            head->prev = f;
            head = f;
            break;

            case 2:
            printf("\nEnter the node number after which you want the node to be inserted:-\t");
            scanf("%d", &n);
            temp1 = head;
            while(temp1!=NULL)
            {
                i++;
                if(i==n)
                break;
                temp1 = temp1->next;
            }
            f = create();
            f->prev = temp1;
            f->next = temp1->next;
            (temp1->next)->prev = f;
            temp1->next = f;
            temp1 = temp2;
            break;

            case 3:
            f = create();
            temp1->next = f;
            temp1 = f;
            temp1->prev = temp2;
            temp2 = f;
            break;

            default:
            printf("Wrong choice!\n");
            break;
        }
        
    }
} 

void display()
{
    printf("\nThe linked list in order is:\n");
    temp1 = head;
    while(temp1!=NULL)
    {
        printf("%d\t", temp1->data);
        temp1 = temp1->next;
    }
    temp1 = temp2;
}

void deletion(int ch)
{   
    int n, i=0;
    switch(ch)
    {
        case 1:
        head = head->next;
        head->prev = NULL;
        break;

        case 2:
        printf("\nEnter the 'n'th position:-\t");
        scanf("%d", &n);
        temp1 = head;
        while(temp1!=NULL)
        {
            i++;
            if(i==n)
            break;
            temp1 = temp1->next;
        }
        (temp1->prev)->next = temp1->next;
        (temp1->next)->prev = temp1->prev;
        temp1 = temp2;
        break;

        case 3:
        (temp1->prev)->next = NULL;
        temp1 = temp1->prev;
        temp2 = temp1;
        break;

        default:
        printf("Wrong choice!\n");
        break;
    }

}