#include <stdio.h>
#include <stdlib.h>

void display();
void init_list();
void create();
void check();
void display_rev();
void insert();
void search();
void del();
void sort_list();
void dup();
void rev_list();

int c=0;

typedef struct link_list
{
    int data;
    struct link_list *adr;

}Node;

Node *head,*temp, *f,*l, *t;

Node* allocate_node()
{
    Node *temp = (Node*)malloc(sizeof(Node));
    printf("Enter the value of the node\t");
    scanf("%d", &temp->data);
    temp->adr = NULL;
    return(temp);
}

int main()
{
    int ch;
    for(;;)
    {
        printf("\n\nPress 1 to check if the list has nodes\nPress 2 to create a node for the first time\nPress 3 to insert a node at the begining\n");
        printf("Press 4 to insert a node at the end\nPress 5 to display the entire list\nPress 6 to display the list in reverse\nPress 7 to search a specific node\n");
        printf("Press 8 to delete the last node\nPress 9 to sort the quiz\nPress 10 to remove all duplicate elements\nPress 11 to reverse the list\nPress 0 to end\n\n");    
        printf("Enter your choice:\t");
        scanf("%d", &ch);
        if(ch==0)
        break;
        else
        {
            switch(ch)
            {
                case 1:check();break;
    
                case 2:init_list();break;

                case 3:insert();break;

                case 4:create();break;

                case 5:display();break;

                case 6:display_rev(head);break;

                case 7:search();break;

                case 8:del();break;

                case 9:sort_list();break;

                case 10:dup();break;

                case 11:rev_list();break;

                default:printf("Enter a valid option, try again!\n");break;
            }
        }
    }
}

void init_list()
{
    c = 1;
    head = allocate_node();
    temp = head;
}

void check()
{
    if(c>=1)
    printf("The linked list is not empty\n");
    else
    printf("The list is empty\n");
}

void create()
{
    if(c==0)
    printf("First create the first node\n");
    else
    {
        f = allocate_node();    
        temp->adr = f;
        temp = f;
    }
    c++;
}

void display()
{
    if(c==0)
    printf("No nodes are created\n");
    else
    {   
        printf("The current list:\n");
        temp = head;
        while(temp!=NULL)
        {
            if(temp->data!=0)
            printf("%d\t", temp->data);
            temp = temp->adr;
        }
    }
}

void display_rev(Node *t)
{
    if(t==NULL)
    return;
    else
    {
        display_rev(t->adr);
        printf("%d\t", t->data);
    }
}

void insert()
{
    f = allocate_node();
    f->adr = head;
    head = f;
}

void search()
{
   int n,k=0,i=1;
   printf("\nEnter the number you want to search for\t");
   scanf("%d",&n);
   f = temp;
   temp = head;
   while(temp!=NULL)
   {
       if(temp->data==n)
        {
            k=1;
            break;
        }
       temp = temp->adr;
       i++;
   }
   temp = f;
   if(k==1)
   printf("The data is present at node# %d", i);
   else
   printf("The data is not present");
}

void del()
{ 
    temp = head;
    while((temp->adr)!=NULL)
    {   
        f = temp;
        temp = temp->adr;
    }
    temp = f;
    temp->adr = NULL;
    f = temp;
}

void sort_list()
{
    int min = 0;
    f = head;
    l = temp;
    while(f!=NULL)
    {
        temp = f;
        min = temp->data;
        while(temp!=NULL)
        {
            if((temp->data)<min)
            {
                min = temp->data;
                t = temp;
            }
            temp = temp->adr;
        }
        t->data = f->data;
        f->data = min;
        f = f->adr;
    }
    temp = l;
}

void dup()
{
    int n=0;
    l = temp;
    temp = head;
    while(temp!=NULL)
    {
        n = temp->data;
        t = temp->adr;
        while(t!=NULL)
        {
            if(n==(t->data))
            t->data = 0;
            t = t->adr;
        }
        temp = temp->adr;
    }
    temp = l;
}

void rev_list()
{
    Node  *pt, *pt2, *pt3=NULL; //pt = stores the previous node, pt2 = temporary node pointer, pt3 = traversing the node
    pt = head;
    pt2 = head->adr;
    pt->adr = NULL;
    for(int i=1;i<c;i++)
    {
        pt3 = pt2;
        pt2 = pt2->adr;
        pt3->adr=pt;
        pt=pt3;
    }
    head=pt;
    display();
}