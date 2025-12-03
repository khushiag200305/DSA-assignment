#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

bool isBSTUtil(Node* root, int minV, int maxV){
    if(root == NULL) return true;

    if(root->data <= minV || root->data >= maxV)
        return false;

    return isBSTUtil(root->left, minV, root->data) &&
           isBSTUtil(root->right, root->data, maxV);
}

bool isBST(Node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(6); // makes it NOT BST

    if(isBST(root)) cout << "Tree is BST";
    else cout << "Tree is NOT BST";
}
