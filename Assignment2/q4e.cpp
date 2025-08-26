#include<iostream>
using namespace std;
int main()
{
   char A[50];
   cout<<"enter string";
   cin>>A;
   int n=0;
   while(A[n]!='\0')
   {
    n++;
   }
   for(int i=0;i<n;i++)
   {
    if((int)A[i]>=65 && (int)A[i]<=90)
    {
        A[i]=A[i]+32;
    }
    else if(A[i]>=97 && A[i]<=122)
    {
        A[i]=A[i]-32;
    }
   }
   cout<<A;


}