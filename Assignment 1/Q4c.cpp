// Transpose of Matrix
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the size of matrix";
    cin>>n;
    int A[n][n]; 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"enter element";
            cin>>A[i][j];
    }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<A[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp= A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=temp;
        }
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<A[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
}
    