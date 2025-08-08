// Reverse elements of array
#include <iostream>
using namespace std;
int main()
{
 int n; int A[50];
 cout<<"enter number of elements";
 cin>>n;
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
 for(int i=0,j=n-1;i<=j;i++,j--)
 {
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
 }
 for(int i=0;i<n;i++)
 {
    cout<<A[i]<<"\t";

 }
 cout<<"\n";
 return 0;
    
 

}