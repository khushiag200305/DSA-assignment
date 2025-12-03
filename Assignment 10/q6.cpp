#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool checkDuplicates(Node* root, unordered_set<int> &st) {
    if(root == NULL) return false;

    if(st.count(root->data))
        return true;

    st.insert(root->data);

    return checkDuplicates(root->left, st) ||
           checkDuplicates(root->right, st);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(3); // duplicate

    unordered_set<int> st;

    if(checkDuplicates(root, st))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";
}
