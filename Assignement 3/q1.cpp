#include<iostream>
using namespace std;
#define MAX 100
class Stack{
    int arr[MAX];
    int top;
    public:
    Stack()
    {
        top=-1;
    }
    bool push(int x)
    {
        if(isFull()){
            cout<<"Stack Overflow\n";
            return false;
        }
        arr[++top]=x;
        return true;
    }
    int pop()
    {
        if(isEmpty())
        
        {
            cout<<"Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
    bool isEmpty()
    {
        return(top==-1);
    }
    bool isFull()
    {
        return(top==MAX-1);
    }
    void display(){
        if(isEmpty())
        {
            cout<<"Stack is empty\n";
            return;
        }
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        
        }
        cout<<"\n";
    }
    int peek()

    {
        if(isEmpty()){
            cout<<"Stack is Empty";
            return -1;
        }
        return arr[top];
    }

};
int main()
{
    Stack S;
    int n,ele;
    while(1){
    
    cout<<"Enter 1 for push\n2 for pop\n3 for is empty\n4 for is full\n5 for display\n";
    cout<<"6 for peek\n7 for exit\n";
    cin>>n;
    
    switch(n){
        case 1:
        cout<<"enter element to push";
        cin>>ele;
        S.push(ele);
        break;
       
        case 2:
        S.pop();
        break;
       
        case 3:
       cout<<(S.isEmpty()?"Stack is Empty":"Stack is not empty")<<endl;
       break;
       
        case 4:
        cout<<(S.isFull()?"Stack is full":"Stack is not full")<<endl;
        break;
       
        case 5:
        S.display();
        break;
       
        case 6:
        S.peek();
        break;
       
        case 7:
        cout<<"Exiting program";
        return 0;

        default:
        cout<<"Invalid choice";

    }
    if(n==7)
    break;
    }
    return 0;
}