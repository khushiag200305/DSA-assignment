#include <iostream>
using namespace std;

class Queue {
public:
    int arr[100], front, rear, size;
    Queue() { front = 0; rear = -1; size = 0; }
    void push(int x) { arr[++rear] = x; size++; }
    void pop() { front++; size--; }
    int Front() { return arr[front]; }
    bool empty() { return size == 0; }
    int getSize() { return size; }
};

class StackOneQ {
    Queue q;
public:
    void push(int x) {
        q.push(x);
        int sz = q.getSize();
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.Front());
            q.pop();
        }
    }
    void pop() {
        if (!q.empty()) q.pop();
    }
    int top() {
        if (q.empty()) return -1;
        return q.Front();
    }
};

int main() {
    StackOneQ st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.top() << endl; // 30
    st.pop();
    cout << st.top() << endl; // 20
}
