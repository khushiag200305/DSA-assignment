#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of array";
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter element";
        cin>>A[i];
    }
    int beg=0,end=n-1; 
    int ele;
    cout<<"enter element yoy want to search";
    cin>>ele;
    while(beg<=end)
    {
       int mid=(beg+end)/2;
       if(A[mid]==ele)
       {
         cout<< "element found at index "<<mid;
         break;
       }
       else if(ele>A[mid])
       {
        beg=mid+1;
       }
       else{
        end=mid-1;
       }

    }
   
}