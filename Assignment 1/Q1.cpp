#include <iostream>
using namespace std;
int main()
{
    int n;
    int A[50];
    cout<<" enter number of elements";
    cin>>n;
    for(int i =0;i<n; i++)
    {
        cout<<"enter element";
        cin>>A[i];
    }
    int m;
    cout<<" Enter 1 to create array \n Enter 2 to display array \n Enter 3 to insert element\n Enter 4 to delete element \n Enter 5 to linear search element \n Enter 6 to exit";
    cin>>m;
    switch (m){
        case 1:{
        int x;
        cout<< "enter no of elements ";
        int B[50];
        for(int i=0 ;i<x;i++)
        {
            cout<<"enter element ";
            cin>>B[i];
        }
        break;}
        case 2:{

        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<"\t";
        }
        break;
        }
        case 3:
        {
            int ele; int pos;
            cout<<"enter element to be inserted";
            cin>>ele;
            cout<<"enter position to be inserted";
            cin>>pos;
            int i=n-1;
            while(i>=pos)
            {
                A[i+1]=A[i];
                i--;
            }
            A[pos]=ele;
            for(int i=0;i<n+1;i++)
            {
                cout<<A[i]<<"\t";
            }
            break;
           
        }
        case 4:
        {
            int pos;
            cout<<" enter the position of element to be deleted";
            cin>>pos;
            for(int i=pos;i<n-1;i++)
            {
                A[i]=A[i+1];
            }
            for(int i=0;i<n-1;i++)
            {
                cout<<A[i];
            }
            break;

        }
        case 5:
        {
            int ele;
            cout<<"enter element you want to search\n";
            cin>>ele;
            int f=0;
            for(int i=0;i<n;i++)
            {
                if(A[i]==ele)
                
                {f=1;
                break;}
                
            }
            if (f==0)
            {
                cout<<"element not found";
            }
            else{
                cout<<"element found";
            }
            break;
           
        }
        case 6:
        {
            cout<<"Program ended";
            break;
           }   }
           return 0;
}
