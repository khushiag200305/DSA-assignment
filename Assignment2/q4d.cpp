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
    for(int j=0;j<n-i-1;j++)
    {
        if( A[j]>  A[j+1])
        {
            char temp=A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
        }
    }
   }
   cout<<A;

}