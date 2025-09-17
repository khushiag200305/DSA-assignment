#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp) { cout << temp->data << " -> "; temp = temp->next; }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    cout << "Original List: "; list.display();

    list.reverse();

    cout << "Reversed List: "; list.display();
}
