#include<iostream>
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
   
   
    for(int i=0;i<n;i++)
    {  int sr=0;
        for (int j=0;j<n;j++)
        {
            sr=sr+A[i][j];
           
        }
        cout<<"Sum of "<<i+1<<" Row ="<<sr<<"\n";
    }
    for(int i=0;i<n;i++)
    { int sc=0;
        for(int j=0;j<n;j++)
        {
            sc=sc+A[j][i];
        }
        cout<<"Sum of "<<i+1<<" Column="<<sc<<"\n";
    }
    return 0;


}