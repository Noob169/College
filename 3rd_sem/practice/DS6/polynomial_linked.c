#include <stdio.h>
#include <stdlib.h>

void display();
void equate(int );

typedef struct polynomial
{
    int pow;//stores the power or the degree of the variable
    signed int cof;//stores the coefficient of the variable
    struct polynomial *adr;
}Node;

Node *head=NULL, *temp;
char var;

Node* create(int deg)
{
    Node *f = (Node*)malloc(sizeof(Node));
    f->pow = deg;
    printf("\nEnter the coeffcicient of the variable:-\t");
    scanf("%d", &f->cof);
    //printf("%d", f->pow);
    f->adr = NULL;
    return(f);
}

int main()
{ 
    int deg;//stores the degree of the polynomial;
    head = (Node*)malloc(sizeof(Node));//head pointer now pointing to newly created memory block
    head->pow=0;//the head node has nothing stored inside it
    head->cof=0;
    head->adr=NULL;
    temp = head;
    printf("\nEnter the variable (x,y):-\t");
    scanf(" %c", &var);
    fflush(stdin);
    printf("\nEnter the degree of the polynomial:-\t");
    scanf("%d",&deg);
    equate(deg);
    return 0;
}

void equate(int deg)
{
    int ch=0, i=deg;
    Node *f;
    while(i>=0)
    {
        printf("\nEnter the term of the polynomial where the degree of the variable is %d.\nIf you want to skip this term, press 0, else press 1:\t", i);
        scanf("%d", &ch);
        if(ch!=0)
        {   
            f = create(i);
            temp->adr = f;
            temp = f;
        }
        i--;
    }
    display();
}

void display()
{
    temp = head->adr;
    printf("\nThe polynomial is:\t");
    while(temp!=NULL)
    {
        if(temp->pow==0)
        printf("%d", temp->cof);
        else if(temp->adr==NULL)
        printf("%d%c^%d", temp->cof, var, temp->pow);
        else
        printf("%d%c^%d + ", temp->cof, var, temp->pow);
        temp = temp->adr;
    }
}
