#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the size of matrix";
    cin>>n;
    int A[n][n]; int C[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"enter element";
            cin>>A[i][j];
    }
    }
    int B[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"enter element";
            cin>>B[i][j];
    }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
             C[i][j]=0;
             for(int k=0;k<n;k++)
             {
                C[i][j]=C[i][j]+(A[i][k]*B[k][j]);
             }

        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<C[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
    
    
}

