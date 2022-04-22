#include <iostream>
#include <cstring>
using namespace std;

class item
{
    public:
    int profit,weight;
    char name;

    public:
    item()
    {
        this->profit=0;
        this->name='\0';
        this->weight=0;
    }
};

void sort(item items[], int n)
{
    int min=items[0].weight,i,j;
    item temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(items[j].weight<items[min].weight)
            min=j;
        }
        temp=items[i];
        items[i]=items[min];
        items[min]=temp;
    }
}
void putInBag(item items[],int n, int bag_wt)
{
    int table[n][bag_wt+1]={0},i,j,temp=0,max=0,max_i,max_j;
    std::memset(table,0,sizeof(table));
    for(i=0;i<n;i++)
    {
        for(j=0;j<=bag_wt;j++)
        {
            if(items[i].weight>j)
            {
                if(i==0)
                table[i][j]=0;
                else
                table[i][j]=table[i-1][j];
            }
            else
            {
                if(i==0)
                table[i][j]=items[i].profit;
                else   
                {
                    temp=items[i].profit+table[i-1][j-items[i].weight];
                    table[i][j]=temp>table[i-1][j]?temp:table[i-1][j];
                }
            }
        }
    }
    max=table[i-1][j-1];
    cout<<"Total profit is= "<<max<<endl;
    cout<<"Items selected are: "<<endl;
    max_i=i-1;max_j=j-1;
    while(max_i>=0)
    {
        if(max==0)
        cout<<items[max_i].name<<" is not taken"<<endl;
        else if(max==table[max_i-1][max_j])
        cout<<items[max_i].name<<" is not taken"<<endl;
        else
        {
            cout<<items[max_i].name<<" is taken"<<endl;
            max_j=max_j-items[max_i].weight;
        }
        max_i-=1;
        max=table[max_i][max_j];
    }
}

int main()
{
    int number_of_items,bag_weight,i;
    cout<<"Enter the number of items and the weight of the bag:"<<endl;
    cin>>number_of_items>>bag_weight;
    item items[number_of_items];
    cout<<"Enter the item's name, profit, weight:"<<endl;
    for (i = 0; i < number_of_items; i++)
    cin>>items[i].name>>items[i].profit>>items[i].weight;
    sort(items,number_of_items);
    putInBag(items,number_of_items,bag_weight);
}