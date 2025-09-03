#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    stack<char> st;
    for (char c : str) {
        st.push(c);
    }
    cout << "Reversed string: ";
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;
    return 0;
}