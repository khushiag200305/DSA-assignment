#include <iostream>
#include <vector>
using namespace std;

class MaxPQ {
    vector<int> heap;

    void heapifyUp(int i){
        while(i > 0 && heap[(i-1)/2] < heap[i]){
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void heapifyDown(int i){
        int n = heap.size();
        while(true){
            int largest = i;
            int l = 2*i + 1;
            int r = 2*i + 2;

            if(l < n && heap[l] > heap[largest]) largest = l;
            if(r < n && heap[r] > heap[largest]) largest = r;

            if(largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void push(int val){
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop(){
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top(){
        return heap.empty() ? -1 : heap[0];
    }

    bool empty(){
        return heap.empty();
    }
};

int main(){
    MaxPQ pq;
    pq.push(40);
    pq.push(10);
    pq.push(50);
    pq.push(30);

    cout << "Top: " << pq.top() << endl;

    pq.pop();
    cout << "Top after pop: " << pq.top() << endl;
}
