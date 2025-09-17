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

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertBeforeValue(int val, int newVal) {
        if (!head) return;
        if (head->data == val) { insertAtBeginning(newVal); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != val) temp = temp->next;
        if (temp->next) {
            Node* newNode = new Node(newVal);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void insertAfterValue(int val, int newVal) {
        Node* temp = head;
        while (temp && temp->data != val) temp = temp->next;
        if (temp) {
            Node* newNode = new Node(newVal);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteAtBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteValue(int val) {
        if (!head) return;
        if (head->data == val) { deleteAtBeginning(); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != val) temp = temp->next;
        if (temp->next) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }

    int search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) return pos;
            temp = temp->next; pos++;
        }
        return -1;
    }

    void display() {
        Node* temp = head;
        while (temp) { cout << temp->data << " -> "; temp = temp->next; }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, newVal;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before Value\n4. Insert After Value\n";
        cout << "5. Delete at Beginning\n6. Delete at End\n7. Delete a Value\n8. Search\n9. Display\n0. Exit\n";
        cout << "Enter your choice: "; cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; list.insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
            case 3: cout << "Insert before value: "; cin >> val; cout << "New value: "; cin >> newVal; list.insertBeforeValue(val, newVal); break;
            case 4: cout << "Insert after value: "; cin >> val; cout << "New value: "; cin >> newVal; list.insertAfterValue(val, newVal); break;
            case 5: list.deleteAtBeginning(); break;
            case 6: list.deleteAtEnd(); break;
            case 7: cout << "Enter value to delete: "; cin >> val; list.deleteValue(val); break;
            case 8: cout << "Enter value to search: "; cin >> val; { int pos = list.search(val); if (pos != -1) cout << "Found at position " << pos << endl; else cout << "Not found\n"; } break;
            case 9: list.display(); break;
        }
    } while (choice != 0);
}
