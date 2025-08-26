#include<iostream>
using namespace std;
int main()
{
  int n;
  cout<<"enter n";
  cin>>n;
  int A[n];
  for(int i=0;i<n-1;i++)
  {
    cout<<"enter element";
    cin>>A[i];
  }
  int x;
  int beg=0;
  int end=n-2;
  while(beg<=end)
  {
    int mid=(beg+end)/2;
    if(A[mid]==mid+1)
    beg=mid+1;
   else
    end=mid-1;
    

  }
 cout<< beg+1;
}