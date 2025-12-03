#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v){ data=v; next=NULL; }
};

class LinkedList {
public:
    Node* head=NULL;

    void insert(int v){
        Node* n=new Node(v);
        if(!head){ head=n; return; }
        Node* t=head;
        while(t->next) t=t->next;
        t->next=n;
    }

    bool isCircular(){
        if(!head) return false;

        Node* slow=head;
        Node* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast) return true;
        }
        return false;
    }
};

int main(){
    LinkedList l;
    l.insert(2);
    l.insert(4);
    l.insert(6);
    l.insert(7);
    l.insert(5);

    // make circular
    l.head->next->next->next->next->next = l.head;

    cout << (l.isCircular() ? "True" : "False");
}
