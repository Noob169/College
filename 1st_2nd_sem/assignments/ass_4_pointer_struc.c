#include <stdio.h>
#include <stdlib.h>

void book(int );
void print(int );

typedef struct student
{
    int roll;
    char name[20];
    char sec;
    struct student *p;
}S;

typedef struct books
{
    int id;
    char bname[20];
}B;

int main()
{
    printf("\nEnter the number of students:\t");
    scanf("%d", ns);
    printf("\nEnter the number of books:\t");
    scanf("%d", nb);
    S *st = (S*)malloc(ns*sizeof(S));
    B *bo = (B*)malloc(nb*sizeof(B));
    //Data entry for students

}
