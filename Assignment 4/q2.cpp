#include<iostream>
using namespace std;
#define MAX 100
class Circular_Queue{
    public:
    int A[MAX];
    int front;
    int rear;
    int max_size;
    void set(int size){
        max_size=size;
        front=0;
        rear=0;

    }
    bool isempty(){
        return (front ==rear);
    }
    bool isFull(){
        return((rear+1)%max_size)==front;
    }
    void enqueue(int item){
        if(isFull()){
            cout<<"queue is full"<<endl;
            return;
        }
        rear=(rear+1)%max_size;
        A[rear]=item;
        cout<<" Enqueued:"<<item<<endl;
      
    }
    void dequeue()
    {
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
         front=(front+1)%max_size;
         cout<<"Dequeued: "<<A[front]<<endl;
    }
    void peek()
    {
        if(isempty())
        {
            cout<<"queue is empty"<<endl;
            return;
        }
       
       cout<<"Front element:"<<A[(front+1)%max_size]<<endl;
    
    }
    void display()
    {
        if(isempty()){
            cout<<"queue is empty"<<endl;
            return;

        }
        cout<<"queue elements:";
       int i=(front +1)%max_size;
       while(i!=(rear+1)%max_size){
        cout<<A[i]<<" ";
        i=(i+1)%max_size;
       }
       cout<<endl;

    }

};
int main(){
    int size,choice,item;
    Circular_Queue q;
    cout<<"enter size of circular queue:";
    cin>>size;
    q.set(size);
    while(choice!=7)
    {
        cout<<"\n1.Enqueue\n2.Dequeue\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n7.Exit\n";
        cout<<"enter your choice";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"enter element to enqueue";
            cin>>item;
            q.enqueue(item);
            break;
            case 2:
            q.dequeue();
            break;
            case 3:
            cout<<(q.isempty()?"Queue is empty!":"Queue is not empty")<<endl;
            break;
            case 4:
            cout<<(q.isFull()?"Queue is full":"queue is not full")<<endl;
            break;
            case 5:
            q.display();
            break;
            case 6:
            q.peek();
            break;
            case 7:
            cout<<"Exiting program"<<endl;
            break;
            default:
            cout<<"invalid choice";
        }
    }
}