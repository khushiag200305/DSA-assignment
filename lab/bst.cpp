#include <iostream>
using namespace std;


void preorder(int arr[], int n, int index) {
    if(index >= n) return;

    cout << arr[index] << " ";
    preorder(arr, n, 2*index + 1);
    preorder(arr, n, 2*index + 2);
}


void inorder(int arr[], int n, int index) {
    if(index >= n) return;

    inorder(arr, n, 2*index + 1);
    cout << arr[index] << " ";
    inorder(arr, n, 2*index + 2);
}


void postorder(int arr[], int n, int index) {
    if(index >= n) return;

    postorder(arr, n, 2*index + 1);
    postorder(arr, n, 2*index + 2);
    cout << arr[index] << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Preorder: ";
    preorder(arr, n, 0);

    cout << "\nInorder: ";
    inorder(arr, n, 0);

    cout << "\nPostorder: ";
    postorder(arr, n, 0);

    return 0;
}
