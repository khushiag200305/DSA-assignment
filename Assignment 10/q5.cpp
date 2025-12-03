#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

bool detectLoop(Node* head) {
    unordered_set<Node*> st;

    while(head != NULL) {
        if(st.count(head))
            return true;
        st.insert(head);
        head = head->next;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // create loop: 4 → 2
    head->next->next->next->next = head->next;

    if(detectLoop(head)) cout << "true";
    else cout << "false";
}
