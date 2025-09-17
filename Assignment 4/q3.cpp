#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear, size;
public:
    Queue() { front = 0; rear = -1; size = 0; }
    void push(int x) {
        if (rear == 99) return;
        arr[++rear] = x;
        size++;
    }
    void pop() {
        if (size == 0) return;
        front++;
        size--;
    }
    int Front() { return arr[front]; }
    bool empty() { return size == 0; }
    int getSize() { return size; }
};

void interleave(int arr[], int n) {
    int half = n / 2;
    int result[100];
    int k = 0;

    for (int i = 0; i < half; i++) {
        result[k++] = arr[i];       
        result[k++] = arr[half+i]; 
    }

    for (int i = 0; i < n; i++) cout << result[i] << " ";
}

int main() {
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    interleave(arr, n);
    return 0;
}
