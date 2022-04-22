
#include <stdio.h>
#include <stdlib.h>

typedef struct process{
    char id;
    int priority,at,bt,ct,tat,wt;
    bool status;
    struct process *next;
}process;

bool noMoreProcess(process *list, int n)
{
    bool t=false;
    for(int i=0;i<n;i++)
    {
        if(list[i].status==false)
        return false;
    }
    return true;
}

int getMax(int fp,int rp, process *list)
{
    int max=0;
    int index=0;
    for(int i=fp;i<rp;i++)
    {
        if(list[i].status==false && (max<list[i].priority))
        {
            max=list[i].priority;
            index=i;
        }
    }
return index;
}

void sort(process *list, int n)
{
    int i,j, min_at=list[0].at;
    process temp;
    for(i=0;i<n-1;i++)
    {
        min_at=i;
        for(j=i+1;j<n;j++)
        {
            if(list[min_at].at>list[j].at)
            min_at=j;
        }
        temp=list[i];
        list[i]=list[min_at];
        list[min_at]=temp;
    }
}

void scheduler(process *list, int n)
{
    int i=0,j,cp=0;
    double avg_tat=0,avg_wt=0;
    int max_priority_process;
    process temp;
    while (!noMoreProcess(list,n))
    {
        while(cp<list[i].at)
        cp++;
        j=i;
        while(list[j].at<=cp&&j<n)
        j++;
        max_priority_process=getMax(i,j,list);
        temp = list[max_priority_process];
        temp.ct=cp+temp.bt;
        cp=temp.ct;
        temp.tat=temp.ct-temp.at;
        temp.wt=temp.tat-temp.bt;
        temp.status=true;
        list[max_priority_process]=temp;
    }
    printf("**SCHEDULER STARTS**\nProcess id:\tPriority\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%c\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n",list[i].id,list[i].priority,list[i].at,list[i].bt,list[i].ct,list[i].tat,list[i].wt);
        avg_tat+=list[i].tat;
        avg_wt+=list[i].wt;
    }
    avg_tat=avg_tat/n;
    avg_wt=avg_wt/n;
    printf("**SCHEDULER ENDS**\nAverage turnaround time= %lf\nAverage waiting time= %lf",avg_tat,avg_wt);
}

int main()
{
    int number_of_process,i;
    printf("Enter the number of processes:\n");
    scanf("%d",&number_of_process);
    process list[number_of_process];
    printf("Enter the process id of process followed by priority,AT,BT:\n");
    fflush(stdin);
    for(i=0;i<number_of_process;i++)
    {
        scanf("%c %d %d %d",&list[i].id,&list[i].priority, &list[i].at, &list[i].bt);
        fflush(stdin);
        list[i].status=false;
    }
    sort(list,number_of_process);
    scheduler(list,number_of_process);
}


