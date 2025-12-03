#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = 4;

    unordered_set<int> st;

    for(int i = 0; i < n; i++) {
        if(st.count(nums[i])) {
            cout << "true";
            return 0;
        }
        st.insert(nums[i]);
    }

    cout << "false";
}
