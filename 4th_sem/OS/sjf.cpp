#include <iostream>
using namespace std;
void find_min(int *at, int *bt, int *pc, int n)
{
    int i, j, min=at[i];
    for(i=0;i<n;i++)
    {
        if(at[i]<min)
        {
            min=i;
        }
    }
    swap(&at[0],&at[i]);
    swap(&bt[0],&bt[i]);
    swap(&pc[0],&pc[i]);
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void sort(int bt[], int at[], int pc[],int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        {
            if (bt[j] <= bt[min_idx])
            {
                if(bt[j]==bt[min_idx])
                min_idx=at[j]<at[min_idx]?j:min_idx;
                else
                min_idx = j;
            }  
        }
        swap(&bt[min_idx], &bt[i]); 
        swap(&at[min_idx],&at[i]);
        swap(&pc[min_idx],&pc[i]);
    } 
} 
void execute(int idle, int *at,int *bt, int *ct, int *tat, int *wt, int *rt, int *pc,int n)
{
    sort(bt,at,pc,n);
    int i,c=idle;
    for(i=1;i<n;i++)
    {
        ct[i]=c+bt[i];
        c=ct[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
}
int main()
{
    int n,i,c=0,idle;
    cout<<"Enter the number of programs:"<<endl;
    cin >> n;
    int at[n]={0},bt[n]={0},ct[n]={0},tat[n]={0},wt[n]={0},rt[n]={0},pc[n]={0};
    for(i=0;i<n;i++)
    {
        cout<<"Enter AT of program no: "<<i+1<<endl;
        cin>>at[i];
        cout<<"Enter BT of program no: "<<i+1<<endl;
        cin>>bt[i];
        pc[i]=i+1;
    }
    find_min(at,bt,pc,n);
    c=at[0];
    ct[0]=at[0]+bt[0];
    idle=c-0;
    execute(c,at,bt,ct,tat,wt,rt,pc,n);
}

