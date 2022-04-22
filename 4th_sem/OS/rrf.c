#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int at[2],bt[2],tat,ct,wt;
    char a;
    struct process *adr;
}process;

process *fp, *tp;            //fp->front pointer, tp->rear pointer, enq happens at tp, deq at fp

process* create()           //CREATES A NEW PROCESS
{
    int at,bt;
    char c;
    printf("Enter process id, at, bt: ");
    scanf(" %c %d %d",&c,&at,&bt);
    process *temp=(process*)malloc(sizeof(process));
    temp->at[0]=at; 
    temp->at[1]=at;
    temp->bt[0]=bt;
    temp->bt[1]=bt;
    temp->wt=0;
    temp->tat=0;
    temp->ct=0;
    temp->a=c;
    temp->adr=NULL;
    return temp;
}

void dequeue()          //dequeues a process at fp
{
    if(fp==NULL)
    return;
    fp=fp->adr;
    if(fp==NULL)
    tp=NULL;
}

void enqueue(process *temp)     //enqueues a process whose address is received at tp
{
    if(tp==NULL)
    {
        tp=temp;
        fp=tp;
    }
    else
    {
        tp->adr=temp;
        tp=temp;
    }
}

void swap(process *i, process *temp)
{
    int t_at,t_bt;
    char t_a;
    t_at=i->at[0];
    t_bt=i->bt[0];
    t_a=i->a;
    i->at[0]=temp->at[0];
    i->bt[0]=temp->bt[0];
    i->a=temp->a;
    temp->a=t_a;
    temp->at[0]=t_at;
    temp->bt[0]=t_bt;
    i->at[1]=i->at[0];
    temp->bt[1]=temp->bt[0];
}

void QSort()
{
    process *i=fp, *j=NULL, *temp=NULL;
    int min=0;
    while(i!=tp)
    {
        min=i->at[0];
        j=i->adr;
        while(j!=NULL)
        {
            if(j->at[0]<i->at[0])
            {
                min=j->at[0];
                temp=j;
            }
            j=j->adr;
        }
        swap(i,temp);
        i=i->adr;
    }
}

void cal(int number_of_programs)
{
    int tq,time_used=0;
    int cp=0;
    int total_tat=0,total_wt=0;
    process *temp=fp;
    printf("Enter the time quantum of the system: ");
    scanf("%d",&tq);
    printf("**SCHEDULER STARTS**\n");
    while(fp!=NULL)
    {
       if(temp->at[1]>cp)              //it is impossible that a process->at after the process at fp will match cp(as process array is sorted)
       {
           printf("CPU idle for %d to %d units of time\n",cp,cp+1);
           cp++;
           continue;                //Thus cp gets incremented and search continues
       }
        
        //if process' at<=cp:
        dequeue();
        temp->adr=NULL;      
        time_used=temp->bt[1]>tq?tq:temp->bt[1];
        temp->bt[1]-=time_used;
        cp+=time_used;
        temp->at[1]=cp;
        if(temp->bt[1]>0)
           enqueue(temp);
        else
        {
            temp->ct=cp;
            temp->tat=temp->ct-temp->at[0];
            temp->wt=temp->tat-temp->bt[0];
            total_tat+=temp->tat;
            total_wt+=temp->wt;
            printf("Process id:%c\tAT:%d\tBT:%d\tCT:%d\tTAT:%d\tWT:%d\n",temp->a,temp->bt[0],temp->at[0],temp->ct,temp->tat,temp->wt);
        }
        temp=fp;
    }
    double avg_waiting_time=total_wt/number_of_programs;
    double average_tat=total_tat/number_of_programs;
    printf("**SCHEDULER ENDS**\nAverage turnaround time=%lf\nAverage waiting time=%lf",average_tat,avg_waiting_time);
}

int main()
{
    int np,number_of_programs;
    printf("Enter the number of programs\n");
    scanf("%d",&np);
    number_of_programs=np;
    while(np--)
    enqueue(create());
    cal(number_of_programs);
    return 0;
}