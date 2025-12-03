#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};
    int n1 = 4, n2 = 4;

    unordered_set<int> st(A, A + n1);

    cout << "Common elements: ";
    for(int i = 0; i < n2; i++) {
        if(st.count(B[i]))
            cout << B[i] << " ";
    }
}
