#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

class CLL {
public:
    Node* head;

    CLL() { head = NULL; }

    void insert(int val) {
        Node* n = new Node(val);
        if(!head) {
            head = n;
            n->next = n;
            return;
        }
        Node* temp = head;
        while(temp->next != head) temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void displayRepeatHead() {
        if(!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);
        cout << head->data; // repeat head
    }
};

int main() {
    CLL list;
    list.insert(20);
    list.insert(100);
    list.insert(40);
    list.insert(80);
    list.insert(60);

    list.displayRepeatHead();
}
