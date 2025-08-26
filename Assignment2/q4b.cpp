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
    for(int i=0,j=n-1;i<=j;i++,j--)
    {
        char temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    cout<<A;
}