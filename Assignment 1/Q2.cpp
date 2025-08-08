// Remove duplicate elements
#include<iostream>
using namespace std;
int main()
{
   int n;
   cout<<"enter number of elements";
   cin>>n;
   int A[50];
   for(int i=0;i<n;i++)
   {
    cout<<"enter element";
    cin>>A[i];
   }
   for(int i=0;i<n;i++)
   {
    cout<<A[i]<<"\t";
   }
   cout<<"\n";
   for(int i=0;i<n;i++)
   {
    for(int j=i+1;j<n;j++)
    {
        if(A[i]==A[j])
        {
            for(int k=j;k<n;k++)
            {
                A[k]=A[k+1];
            }
            n--;
            j--;
        }
    }
   }
   for(int i=0;i<n;i++)
   {
    cout<<A[i]<<"\t";
   }
   return 0;

}