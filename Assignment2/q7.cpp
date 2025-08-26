#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of elements";
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
       cout<<"enter element";
       cin>>A[i];
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[i]>A[j])
            {c++;}
        }
    }
    cout<<"\nNumber of inversions:"<<c;
}