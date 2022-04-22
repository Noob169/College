

#include <iostream>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void sort(int at[], int bt[], int pc[],int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        {
            if (at[j] < at[min_idx]) 
            min_idx = j; 
        }
   
        swap(&at[min_idx], &at[i]); 
        swap(&bt[min_idx],&bt[i]);
        swap(&pc[min_idx],&pc[i]);
    } 
} 

void printArray(int at[],int bt[],int ct[],int tat[],int pc[],int idle,int n)
{
    cout<<"Completion time/Burst time:"<<endl;
    for(int i = 0;i<n;i++)
    cout<<"AT OF P["<<pc[i]<<"]: "<<at[i]<<"\tBurst time: "<<bt[i]<<"\tCompletion time: "<<ct[i]<<"\tTurn around time: "<<tat[i]<<endl;
    cout<<"CPU idle time:"<<idle;
}

int main()
{
    int n,i,c=0,t=0,t2=0;
    int a_t,b_t,id=0;
    cout<<"Enter the no. of programs:\n";
    cin>>n;
    int at[n]={0},bt[n]={0},ct[n]={0},tat[n]={0},pc[n]={0};
    for(i=0;i<n;i++)
    {
        cout<<"Enter AT of program no: "<<i+1<<endl;
        cin>>at[i];
        cout<<"Enter BT of program no: "<<i+1<<endl;
        cin>>bt[i];
        pc[i]=i+1;
    }
    sort(at,bt,pc,n);
    c=at[0];i=0;
    while(t<n)
    {
        while(i<n)
        {
            if(c==at[i]||c>at[i])
            break;
            else if (at[i]>c)
            {
                c++;
                id++;
            }
            else
            i++;
        }
        t2=i;
        ct[i]=c+bt[i];
        tat[i]=ct[i]-at[i];
        c=ct[i];
        t++;
        i=t2+1;
    }
    printArray(at,bt,ct,tat,pc,id,n);
}