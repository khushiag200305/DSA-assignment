#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL) return new Node(val);
    if(val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* minNode(Node* root){
    while(root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root == NULL) return root;

    if(key < root->data) root->left = deleteNode(root->left, key);
    else if(key > root->data) root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;

        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root){
    if(root == NULL) return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main(){
    Node* root = NULL;

    int arr[] = {20, 10, 30, 5, 15, 25, 35};
    for(int x : arr) root = insert(root, x);

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    root = deleteNode(root, 10);
    cout << "After deletion, Max Depth: " << maxDepth(root) << endl;
}
