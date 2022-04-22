#include <stdio.h>
#include <string.h>

void getBooks(int a);
void printData(int a, int b);

typedef struct books
{
    int id;
    char bname[50];
}B;

typedef struct students
{
    char name[50];
    char sec;
    int roll;
    int nbo;
    B *issue[10];
}S;

S sr[50];
B br[50];


int main()
{
    int n, k, bid=0,c=0, i=0, m=0, nb=0,l=0;
    printf("Enter the number of students whose info is to be stored\n");
    scanf("%d", &n);
    printf("\nEnter the number of books whose information is to be stored:-\t");
    scanf("%d", &k);
    
    getBooks(k);
   
    printf("\nEnter the student details...");
    while(i<n)
    {
        printf("\nEnter the name of the student:-\t");
        fflush(stdin);
        gets(sr[i].name);
        printf("\nEnter the roll no.:-\t");
        scanf("%d", &(sr[i].roll));
        printf("\nEnter the sec of the student:-\t");
        scanf(" %c", &(sr[i].sec));
        printf("\nEnter the number of books which has been issued to the student:-\t");
        fflush(stdin);
        scanf("%d", &nb);
        sr[i].nbo=nb;
        while(l<nb)
        {
             printf("Enter the book ID which the student has borrowed:-\t");
             fflush(stdin);
             scanf("%d", &bid);
                for(int j=0;j<k;j++)
                {
                     if(bid==br[j].id)
                        {
                            sr[i].issue[l] = &br[j];
                            c=1;
                        }
                }
            if(c==0)
            {
                printf("\nBook ID does not match, try again");
                l--;
            }
            c=0;
            l++;
        }
        l=0;
       
        i++;
    }
    printData(n,k);

    
}

void getBooks(int n)
{
   printf("\nEnter the book details....");
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the book id:-\t");
        scanf("%d", &br[i].id);
        printf("\nEnter the book name:-\t");
        fflush(stdin);
        gets(br[i].bname);
    }
}

void printData(int s, int b)
{
    int n,c=0,nb=0;
    printf("\nEnter the roll of the student whose details you want to verify:-\t");
    scanf("%d", &n);
    for(int i=0;i<s;i++)
    {
        if(sr[i].roll==n)
        {
            printf("\nThe name of the student is:-\t%s", sr[i].name);
            printf("\nThe roll no:-\t%d", sr[i].roll);
            printf("\nThe sec:-\t%c", sr[i].sec);
            nb = sr[i].nbo;
            for(int j=0;j<nb;j++)
            {
                printf("\nThe ID of the book which the student borrowed:-\t%d", sr[i].issue[j]->id);
                printf("\nThe name of the book which the student borrowed:-\t%s", sr[i].issue[j]->bname);
            }
            
            c=1;
        }
    }
    if(c==0)
    printf("\nNo such records found, try again.");
    return;
}