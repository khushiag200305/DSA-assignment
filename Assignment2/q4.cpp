#include<iostream>
#include<string>
using namespace std;
int main()
{
   char A[50];
   char B[50];
   cout<<"enter first string";
   cin>>A;
   
   cout<<"enter second string";
   cin>>B;
  
   int i=0;
   while(A[i]!='\0')
   {  
    i++;}
    int j=0;
    while(B[j]!='\0')
    {
        A[i]=B[j];
        i++;
        j++;
    }
    cout<<A;
}