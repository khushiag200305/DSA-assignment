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
    char B[50];int j=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='A'||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U'||A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u')
        continue;
        else{
            B[j]=A[i];
            j++;

        }
    }
    B[j]='\0';
    cout<<B;
}