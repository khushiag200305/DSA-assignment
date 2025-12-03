#include <iostream>
using namespace std;

// ---------------- DLL NODE ----------------
class DLLNode {
public:
    int data;
    DLLNode* prev;
    DLLNode* next;

    DLLNode(int val) {
        data = val;
        prev = next = NULL;
    }
};

// ---------------- CLL NODE ----------------
class CLLNode {
public:
    int data;
    CLLNode* next;

    CLLNode(int val) {
        data = val;
        next = NULL;
    }
};

// ---------------- DOUBLY LINKED LIST CLASS ----------------
class DoublyLinkedList {
public:
    DLLNode* head;

    DoublyLinkedList() { head = NULL; }

    void insertFirst(int val) {
        DLLNode* n = new DLLNode(val);
        if(head) {
            n->next = head;
            head->prev = n;
        }
        head = n;
    }

    void insertLast(int val) {
        DLLNode* n = new DLLNode(val);
        if(!head) {
            head = n;
            return;
        }
        DLLNode* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void insertAfter(int key, int val) {
        DLLNode* temp = head;
        while(temp && temp->data != key) temp = temp->next;
        if(!temp) return;

        DLLNode* n = new DLLNode(val);
        n->next = temp->next;
        n->prev = temp;
        if(temp->next) temp->next->prev = n;
        temp->next = n;
    }

    void deleteNode(int key) {
        DLLNode* temp = head;
        while(temp && temp->data != key) temp = temp->next;
        if(!temp) return;

        if(temp->prev) temp->prev->next = temp->next;
        else head = temp->next;

        if(temp->next) temp->next->prev = temp->prev;

        delete temp;
    }

    bool search(int key) {
        DLLNode* temp = head;
        while(temp) {
            if(temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        DLLNode* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ---------------- CIRCULAR LINKED LIST CLASS ----------------
class CircularLinkedList {
public:
    CLLNode* head;

    CircularLinkedList() { head = NULL; }

    void insertLast(int val) {
        CLLNode* n = new CLLNode(val);

        if(!head) {
            head = n;
            n->next = n;
            return;
        }

        CLLNode* temp = head;
        while(temp->next != head) temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    void display() {
        if(!head) return;
        CLLNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);
        cout << endl;
    }

    void deleteNode(int key) {
        if(!head) return;

        CLLNode *curr = head, *prev = NULL;

        do {
            if(curr->data == key) {
                if(curr == head) {
                    CLLNode* temp = head;
                    while(temp->next != head) temp = temp->next;
                    head = head->next;
                    temp->next = head;
                }
                else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while(curr != head);
    }

    bool search(int key) {
        if(!head) return false;
        CLLNode* temp = head;
        do {
            if(temp->data == key) return true;
            temp = temp->next;
        } while(temp != head);
        return false;
    }
};

// ---------------- MAIN MENU ----------------
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    int ch, val, key;

    while(true) {
        cout << "\n1. DLL Insert First\n2. DLL Insert Last\n3. DLL Insert After\n";
        cout << "4. DLL Delete\n5. DLL Search\n6. DLL Display\n";
        cout << "7. CLL Insert Last\n8. CLL Delete\n9. CLL Search\n10. CLL Display\n0. Exit\n";
        cin >> ch;

        switch(ch) {
            case 1: cin >> val; dll.insertFirst(val); break;
            case 2: cin >> val; dll.insertLast(val); break;
            case 3: cin >> key >> val; dll.insertAfter(key,val); break;
            case 4: cin >> key; dll.deleteNode(key); break;
            case 5: cin >> key; cout << (dll.search(key)?"Found\n":"Not Found\n"); break;
            case 6: dll.display(); break;

            case 7: cin >> val; cll.insertLast(val); break;
            case 8: cin >> key; cll.deleteNode(key); break;
            case 9: cin >> key; cout << (cll.search(key)?"Found\n":"Not Found\n"); break;
            case 10: cll.display(); break;

            case 0: return 0;
        }
    }
}
