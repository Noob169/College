#include <iostream>
#include <string.h>

using namespace std;
class Table
{
public:
    int mul;
    int k;

public:
    Table()
    {
        this->mul = 0;
        this->k = 0;
    }
};


void makeTable(int *indices,int n,int req_i,int req_j)
{
    int k=1,i,j,temp=0,split_value=0,min=0;
    Table tables[n][n];
    memset(tables,0,sizeof(tables));
    while(k<n)
    {
        for(i=0;i<n-k;i++)
        {
            split_value=0;min=0;
            for(j=i;j<i+k;j++)
            {
                temp=(tables[i][j]).mul+(tables[j+1][i+k]).mul+indices[i]*indices[j+1]*indices[i+k+1];
                if(min==0)
                {
                    min=temp;
                    continue;
                }
                if(temp<min)
                {
                    min = temp;
                    split_value = j;
                }
            }
            (tables[i][i+k]).mul=min;
            (tables[i][i+k]).k=split_value;
        }
        k++;
    }
    cout<<"The table generated:="<<endl<<"To be read in [mul,k]\n";

    for(i=0;i<n;i++)
    {
        cout<<"["<<i<<"]"<<endl;
        for(j=0;j<n;j++)
            cout<<"["<<(tables[i][j]).mul<<","<<(tables[i][j]).k<<"]"<<"\t\t";
        cout<<endl;
    }
    cout<<"The minimum number of matrix multiplications required will be: "<<(tables[req_i][req_j]).mul<<" with splitting performed between matrix M"<<(tables[req_i][req_j]).k<<" and M"<<((tables[req_i][req_j]).k)+1;
}

int main()
{
    int number_of_matrices,req_i,req_j;
    cout<<"Enter the number of matrices: ";
    cin>>number_of_matrices;
    int indices[number_of_matrices+1]={0};
    cout<<"Enter the indices of each matrix in space-separated format:"<<endl;
    for(int i=0;i<number_of_matrices+1;i++)
        cin>>indices[i];
    cout<<"Enter the required indices in i <space> j format:"<<endl;
    cin>>req_i>>req_j;
    makeTable(indices,number_of_matrices,req_i,req_j);
    return 0;
}
