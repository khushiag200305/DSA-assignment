#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
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

// (a) Search Recursive
bool searchRec(Node* root, int key){
    if(root == NULL) return false;
    if(root->data == key) return true;
    return key < root->data ? searchRec(root->left, key) : searchRec(root->right, key);
}

// (a) Search Non-Recursive
bool searchIter(Node* root, int key){
    while(root != NULL){
        if(root->data == key) return true;
        if(key < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

// (b) Maximum
Node* maxNode(Node* root){
    while(root->right != NULL)
        root = root->right;
    return root;
}

// (c) Minimum
Node* minNode(Node* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

// (d) Inorder Successor
Node* inorderSuccessor(Node* root, int key){
    Node* successor = NULL;
    while(root != NULL){
        if(key < root->data){
            successor = root;
            root = root->left;
        }
        else root = root->right;
    }
    return successor;
}

// (e) Inorder Predecessor
Node* inorderPredecessor(Node* root, int key){
    Node* predecessor = NULL;
    while(root != NULL){
        if(key > root->data){
            predecessor = root;
            root = root->right;
        }
        else root = root->left;
    }
    return predecessor;
}
