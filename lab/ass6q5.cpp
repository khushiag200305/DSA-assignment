#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }

};
class CircularList{
    private:
    Node* head;
    public:

    CircularList(){
        head=NULL;
    }

     void insert(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            
            return;
        }

        Node* temp = head;
        while (temp->next !=NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        
    }
    void makecircular()
    {
        if(head==NULL)
        return;
        Node* temp=head;
        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
    }

    bool isCircular()
    {
        if(head==NULL)
        return true;
        Node* current=head->next;
        while(current != NULL && current!=head){
            current=current->next;
        }
        return (current==head);
    }

};
int main()
{
    CircularList cl;
    cl.insert(10);
    cl.insert(20);
    cl.insert(40);
    cl.makecircular();
    if(cl.isCircular())
    {
        cout<<" Linkedlist is circular";

    }
    else
    {
        cout<<"Not circular";
    }
    return 0;
    
}
