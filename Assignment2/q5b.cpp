#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of matrix";
    cin>>n;
    int A[100][3];
    int k=0; int ele;
    cout<<"Tri-diagonal Matrix\n";
    for(int i=0;i<n;i++)
    {   for(int j=max(0,i-1);j<=min(n-1,i+1);j++){
        cout<<"enter element";
        cin>>ele;
         if(ele!=0)
        {
            A[k][0]=i;
            A[k][1]=j;
            A[k][2]=ele;
            k++;
        }}}
     cout<<"Row\tColumn\tValue\n";
    for(int i=0;i<k;i++)
    {        

        {
            cout<<A[i][0]<<"\t"<<A[i][1]<<"\t"<<A[i][2];
        }
        cout<<'\n';
    }}
    

    
    
