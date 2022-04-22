#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list
{
	int data;
	struct linked_list *link; 
}node;
node* Allocate_node(int i)
{
	node *temp;
	int data;
	temp=(node*)malloc(sizeof(node));
	printf("Enter [%d] Data= ",i+1);
	scanf("%d",&data);
	temp->data=data;
	temp->link=NULL;
	return temp;
}
node *head1,*head2;
void Display(node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
void Merge(int n)
{
    int i=0;
    node *temp1 = head1,*temp2 = head2,*temp3 = NULL;
    while(i<2*n)
    {
        if(i%2==0)
        {
            temp3 = temp1->link;
            temp1->link = temp2;
            temp2 = temp2->link;
            temp1->link->link = temp3;
        }
        temp1 = temp1->link;
        i++;
    }

}
void Insert(node *temp,int n)
{
    node *f, *s;
    int c=0;
    while(temp!=NULL)
    {
        c++;
        if(c==n)
        {
            s = temp->link;
            break;
        }
        temp = temp->link;
    }
    f = Allocate_node(n);
    temp->link = f;
    temp = f;
    temp->link = s;
}
int main()
{
    node *f,*temp;
	int i=0,n,in;
    char ch;
    printf("\nEnter the number of nodes for 1st list you want to create: ");
    scanf("%d",&n);
    while(i<n)
	{
		
		f = Allocate_node(i);
        if(i==0)
        {
            head1 = f;
            temp = head1;
        }
        else
        {
            temp->link = f;
            temp = f;
        }
        i++;
    }
    i=0;
    printf("\nThe no. of nodes for 2nd list is %d, enter the data.\n",n);
    while(i<n)
	{
		
		f = Allocate_node(i);
        if(i==0)
        {
            head2 = f;
            temp = head2;
        }
        else
        {
            temp->link = f;
            temp = f;
        }
        i++;
    }
    printf("\nThe 1st linked list: ");
    Display(head1);
    printf("\nThe 2nd linked list: ");
    Display(head2);
    Merge(n);
    printf("\nThe Merged linked list: ");
    Display(head1);
    printf("\nDo you want to insert a node? (type 'y' for yes and 'n' for no)= ");
    scanf(" %c",&ch);
    if(ch=='y' || ch=='Y')
    {
        printf("\nEnter the position of the node after which you want to insert: ");
        scanf("%d",&in);
        Insert(head1,in);
        printf("\nThe new list: ");
        Display(head1);
    }
    return 0;
}
