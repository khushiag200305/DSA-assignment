#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

node* Tree()
{
    int x;
    cout << "enter -1 if no node";
    cin >> x;

    if(x == -1)
        return NULL;

    node* root = new node(x);

    cout << "Enter left child " << x<<endl ;
    root->left = Tree();

    cout << "Enter right child" << x <<endl;
    root->right = Tree();

    return root;
}

void preorder(node* root)
{
    if(root == NULL) return;
    cout << root->data ;
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data ;
    inorder(root->right);
}

void postorder(node* root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data ;
}

int main()
{
    node* root = Tree();

    cout << "Preorder";
    preorder(root);
    cout << endl;

    cout << "Inorder";
    inorder(root);
    cout << endl;

    cout << "Postorder";
    postorder(root);
    cout << endl;

    return 0;
}
