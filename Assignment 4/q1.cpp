#include<iostream>
using namespace std;
#define MAX 100
class Queue{
    public:
    int A[MAX];
    int front;
    int rear;
    int max_size;
    void set(int size){
        max_size=size;
        front=-1;
        rear=-1;

    }
    bool isempty(){
        return (front ==-1 || front >rear);
    }
    bool isFull(){
        return(rear == max_size-1);
    }
    void enqueue(int item){
        if(isFull()){
            cout<<"queue is full"<<endl;
            return;
        }
        if(isempty()){
            front =0;
        }
        A[++rear]=item;
        cout<<"enqueued:"<<item<<endl;
    }
    void dequeue()
    {
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"dequeued:"<<A[front++]<<endl;
    }
    void peek()
    {
        if(isempty())
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        cout<<"first element:"<<A[front]<<endl;
    
    }
    void display()
    {
        if(isempty()){
            cout<<"queue is empty"<<endl;
            return;

        }
        cout<<"queue elements:";
        for(int i=front;i<=rear;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;

    }

};
int main(){
    int size,choice,item;
    Queue q;
    cout<<"enter size of queue:";
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