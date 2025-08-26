#include<iostream>
using namespace std;
int main()
{
  int n;
  cout<<"enter n";
  cin>>n;
  int A[n]; int x;
  for(int i=0;i<n-1;i++)
  {
    cout<<"enter element";
    cin>>A[i];
  }
  int i;
  for( i=0;i<n-2;i++)
  {
    if(A[i]!=i+1)
    {
        break;
     }
  }
  cout<<i+1;
  }