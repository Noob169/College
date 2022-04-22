//STACK GETS PUSHED ON THE RIGHT
//INFIX->POSTFIX WORKS
//NORMAL STACK OPS WORK
//POSTFIX->INFIX WORKS
//DEBUGGING COMPLETE - FINAL VERSION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char ch[100];
    struct Node *ad;
}Node;

int nc,MAX;
Node *head, *temp;
char s[100];

Node* create(char c, int i)
{
    Node *t = (Node*)malloc(sizeof(Node));
    t->ch[i] = c;
    t->ch[i+1] = ' ';
    t->ad = NULL;
    return(t);
}

char peek()
{
	return(temp->ch[0]);
}

void push(char c, int i)
{
    Node *t;
    if(i==0)
    {
        t=create(c,i);
        if(nc==0)
        {
            head=t;
            temp=head;
        }
        else
        {
            temp->ad=t;
            temp=t;
        }
        nc++;
    }
    else
    {
        temp->ch[i]=c;
        temp->ch[i+1]=' ';
    }
}

char pop()
{
    char c;
    int i=0;
    Node *k=head;
	c = temp->ch[0];
    if(temp->ch[1]==' ')
    {
        if(k->ad!=NULL)
        {
            while(k->ad!=temp)
            k=k->ad;
            k->ad=NULL;
            free(temp);
            temp=k;

        }
        else
        free(head);
        nc--;
    }
    else{
    while(temp->ch[i]!=' ')
    {
        temp->ch[i]=temp->ch[i+1];
        i++;
    }
    }
    return(c);
}

int length()
{
    int i=0;
    while(temp->ch[i]!=' ')
    i++;
    return(i);
}

int prec(char ch)       //returns the precedence of the given operator
{
	int c=0;
    char pr[8]="|&-+%/*^";  //array storing operators in ascending orders of precedence
    if(ch=='('||ch==')')    //() have the highest precedence, but we need to push an operator if they are present, hence in this particular
                            //program they have the lowest precedence
    return 0;
    else{
    for(int i=0;i<8;i++)
    {
        if(ch==pr[i])
        return i+1;         //return the index of the character, which is their precedence value
    }
    }
}


void infix()
{
    Node *t;
    char ch;
    int i=0,l1=0,l2=0,j=0,k=0;
    while(k<MAX)
    {
        ch=s[k];
        if(ch>=48&&ch<=57)
        push(ch,0);
        else
        {
            //STR2

                l2=length();
                char s2[l2];
                for(j=0;j<l2;j++)
                s2[j]=pop();

            //STR1

                l1=length();
                char s1[l1];
                for(j=0;j<l1;j++)
                s1[j]=pop();

            //STR

                char str[l1+l2+3];j=0;str[j]='(';
                j++;i=0;
                while(i<l1)
                {
                    str[j]=s1[i];
                    j++;i++;
                }
                str[j]=ch;
                j++;i=0;
                while(i<l2)
                {
                    str[j]=s2[i];
                    j++;i++;
                }
                str[j]=')';
            //PUSH

            push('(',0);
            for(j=1;j<l1+l2+3;j++)
            push(str[j],j);
        }
        k++;
    }

}

void display()
{

    int l=length();
    char in[l];
    for(int i=0;i<l;i++)
    {
        in[i]=pop();
    }
    for(int i=0;i<l;i++)
    {
        int k = (int)in[i];
        if(k==40||k==41)
        continue;
        printf("%c",in[i]);
    }
}

void postfix()
{
   	int i=0,a;
   	char ch,ch2;
    push('(',0);          //pushes '(' into the stack first
    while(i<MAX)
    {
    	ch=s[i];
    	a=(int)ch;
    	if(a>=48&&a<=57)    //print if the scanned character is an operand
    	printf("%c",ch);
    	else if(ch=='(')    //push '(' into the stack if encountered
    	push(ch,0);
		else if(ch==')')
		{
			if(nc==0)       //push if stack is empty, else pop until stack is empty or '(' is encountered
            push(ch,0);
            else
            while(peek()!='('||nc==0)
            printf("%c",pop());
            ch = pop();
		}
    	else                //if an operator that is not '(' or ')' is encountered
    	{
    		while(prec(peek())>=prec(ch)&&nc!=0)    //pop until stack is empty or until the operator in the stack has a lower precedance
            printf("%c",pop());
            push(ch,0);                               //push the operator
		}
		i++;
	}
    while(nc>1)                                    //pop any remaining items until stack is empty
    printf("%c",pop());
}

int main()
{
    char ch;
    int i=0;
    printf("\nEnter the string: ");
    scanf("%s",s);
    while(s[i]!=',')
    i++;
    MAX=i;
    if(s[i+1]=='P')
    {
        printf("\nThe postfix expression is: ");
        postfix();
    }
    else if(s[i+1]=='I')
    {
        printf("\nThe infix expression is: ");
        infix();
        display();
    }
    else
    printf("\nEnter a correct choice");
    return 1;
}
