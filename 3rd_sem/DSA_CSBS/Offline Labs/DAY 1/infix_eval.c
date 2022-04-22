#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int d;
    struct node *a;
}Node;

Node *temp, *head;
int nc=0;
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
    return c;
}

void push(int n)
{
    Node *t=create(n);
    t->a=head;
    head=t;
    temp=head;
}

void operate(char ch, int ch1, int ch2)
{
    int n=0;
    if(ch=='+')
    n=ch1+ch2;
    else if(ch=='-')
    n=ch1-ch2;
    else if(ch=='*')
    n=ch1*ch2;
    else
    n=ch1/ch2;
    push(n);
}

void eval()
{
    int i=0,ch1,ch2;
    char ch;
    while(s[i]!='\0')
    {
        ch=s[i];
        if(ch>=48&&ch<=57)
        push(ch-48);
        else 
        {
            ch2=pop();
            ch1=pop();
            operate(ch,ch1,ch2);
        }
        i++;
    }
    printf("The postfix expression evaluated = %d",pop());
}

int main()
{
    printf("Enter the string: ");
    scanf("%s",s);
    eval();
    return 1;
}