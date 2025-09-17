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

    int countAndDeleteOccurrences(int key) {
        int count = 0;
        while (head && head->data == key) {
            Node* del = head;
            head = head->next;
            delete del;
            count++;
        }
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->next->data == key) {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
                count++;
            } else temp = temp->next;
        }
        return count;
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
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    cout << "Original List: "; list.display();

    int key = 1;
    int cnt = list.countAndDeleteOccurrences(key);

    cout << "Count: " << cnt << endl;
    cout << "Updated List: "; list.display();
}
