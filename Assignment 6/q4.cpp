#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
    Node(char c){ data=c; prev=next=NULL; }
};

class DLL {
public:
    Node* head=NULL;

    void insert(char c){
        Node* n=new Node(c);
        if(!head){ head=n; return; }
        Node* t=head;
        while(t->next) t=t->next;
        t->next=n;
        n->prev=t;
    }

    bool isPalindrome() {
        if(!head) return true;

        Node* left = head;
        Node* right = head;

        while(right->next) right = right->next;

        while(left != right && right->next != left){
            if(left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main(){
    DLL d;
    d.insert('r');
    d.insert('a');
    d.insert('d');
    d.insert('a');
    d.insert('r');

    cout << (d.isPalindrome() ? "True" : "False");
}
