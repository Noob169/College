#include <stdio.h>
#include <stdlib.h>

void display();
void insert();

typedef struct list
{
    int data;
    struct list *adr;
}Node;

Node *temp, *head=NULL;//start or head pointer initialized to null; i.e pointing nowhere



int main()
{
    head = (Node*)malloc(sizeof(Node));//head pointer now pointing to newly created memory block
    head->data=0;//the head node has nothing stored inside it
    head->adr=NULL;
    temp = head;

    int ch;
    printf("Enter the number of nodes:\t");
    scanf("%d", &ch);
    insert(ch);
    display();

}

Node* create()
{
    Node *f = (Node*)malloc(sizeof(Node));
    printf("Enter the value:\t");
    scanf("%d", &f->data);
    f->adr = NULL;
    return(f);
}

void insert(int n)
{
    Node *f;
    int i=0;

    while(i<n)
    {
        i++;
        f = create();
        temp->adr = f;//new nodes added to the head/precedent nodes
        temp = f;
    }
}

void display()
{
    temp = head->adr;//printing will start after the head node as the head node is empty
    printf("\nThe header linked list:\n");
    while(temp!=NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->adr;
    }
}
