#include <stdio.h>

typedef struct process
{
    int at,bt,ct,tat,wt;
    char id;
}process;


int main()
{
    int number_of_process,i;
    printf("Enter the number of processes: ");
    scanf("%d",&number_of_process);
    process list[number_of_process];
    for(i=0;i<number_of_process;i++)
    {
        printf("\nEnter ID,AT,BT of process: %d",i);
        scanf("%c%d%d",&list[0].id,&list[0].at,&list[0].bt);
    }
    
}