#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() { head = nullptr; }

    
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

   
    void insertAfter(int key, int val) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    
    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        do {
            if (temp->next->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

   
    void deleteNode(int key) {
        if (!head) return;

       
        if (head->data == key) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = head->next;
            Node* delNode = head;
            head = head->next;
            delete delNode;
            return;
        }

        Node* temp = head;
        do {
            if (temp->next->data == key) {
                Node* delNode = temp->next;
                temp->next = delNode->next;
                delete delNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

  
    bool search(int key) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == key) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

   
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, val, key;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After\n";
        cout << "4. Insert Before\n";
        cout << "5. Delete Node\n";
        cout << "6. Search Node\n";
        cout << "7. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                cll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                cll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter key and value: ";
                cin >> key >> val;
                cll.insertAfter(key, val);
                break;
            case 4:
                cout << "Enter key and value: ";
                cin >> key >> val;
                cll.insertBefore(key, val);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                cll.deleteNode(key);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                cout << (cll.search(key) ? "Found\n" : "Not Found\n");
                break;
            case 7:
                cll.display();
                break;
        }
    } while (choice != 0);

    return 0;
}
