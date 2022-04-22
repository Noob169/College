#include <iostream>
using namespace std;

class job{
    public:

    char name;
    int profit;
    int deadline;

    public:
    job()
    {
        name='\0';
        profit=0;
        deadline=-1;
    }

    void createJob(char a, int b, int c)
    {
        this->name=a;
        this->profit=b;
        this->deadline=c;
    }
};

void merge(job a[], int p, int q, int r)
{
    int n1,n2,i,j,k;
    n1 = q-p+1;
    n2 = r-q;
    job L[n1+1],R[n2+1];
    
    for(i=0;i<n1;i++)
    L[i]= a[p+i];
    for(j=0;j<n2;j++)
    R[j] = a[q+j+1];
    L[i].profit=-10000000;
    R[j].profit=-1000000;
    i=0;j=0;

    for(k=p;k<=r;k++)
    {
        if(L[i].profit>R[j].profit)
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }

}

void merge_sort(job a[], int p, int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}

int slot_is_full(job slots[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(slots[i].deadline==-1)
        return 0;
    }
    return 1;
}

int find_max_deadline(job a[],int n)
{
    int max=a[0].deadline;
    for(int i=0;i<n;i++)
    {
        if(a[i].deadline>max)
        max=a[i].deadline;
    }
    return max;
}

int main()
{
    int number_of_jobs,i=0,temp_deadline=0,total_profit=0;
    cout<<"Enter the number of jobs:"<<endl;
    cin>>number_of_jobs;
    job jobs[number_of_jobs];
    cout<<"Enter the job description in the form of: Job_name, profit, deadline"<<endl;
    for(i=0;i<number_of_jobs;i++)
    cin>>jobs[i].name>>jobs[i].profit>>jobs[i].deadline;
    
    merge_sort(jobs,0,number_of_jobs);
    int max=find_max_deadline(jobs,number_of_jobs);
    int t=0;
    job slots[max];
    int j=0;
    while(slot_is_full(slots,max)==0||j<number_of_jobs)
    {
        
        temp_deadline=jobs[j].deadline;
        int counter_slots=temp_deadline-1;
        while(counter_slots>=0)
        {
            if(slots[counter_slots].deadline==-1)
            {
                slots[counter_slots]=jobs[j];
                break;
            }
            counter_slots--;
        }
        counter_slots=0;
        j++;
    }
    cout<<endl<<"SLOT NO:\t"<<"PROFITS\t"<<"DEADLINE"<<endl;
    for(i=0;i<max;i++)
    {
        cout<<"Slot "<<i+1<<" "<<slots[i].name<<"\t"<<slots[i].profit<<"\t"<<slots[i].deadline<<endl;
        total_profit+=slots[i].profit;
    }
    cout<<"TOTAL PROFIT: "<<total_profit;
}
