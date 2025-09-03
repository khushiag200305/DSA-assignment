#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;
    for (char c : expr) {
        if (isdigit(c)) {
            st.push(c - '0'); // convert char to int
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit operands): ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix) << endl;
    return 0;
}
