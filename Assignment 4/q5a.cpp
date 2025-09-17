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

class StackTwoQ {
    Queue q1, q2;
public:
    void push(int x) {
        q1.push(x);
    }
    void pop() {
        if (q1.empty()) return;
        while (q1.getSize() > 1) {
            q2.push(q1.Front());
            q1.pop();
        }
        q1.pop();
        // swap queues
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int top() {
        if (q1.empty()) return -1;
        while (q1.getSize() > 1) {
            q2.push(q1.Front());
            q1.pop();
        }
        int val = q1.Front();
        q2.push(val);
        q1.pop();
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
        return val;
    }
};

int main() {
    StackTwoQ st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.top() << endl; 
    st.pop();
    cout << st.top() << endl; 
}
