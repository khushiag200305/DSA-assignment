#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = 6;

    unordered_map<int, int> mp;

    for(int x : arr)
        mp[x]++;

    for(int i = 0; i < n; i++) {
        if(mp[arr[i]] == 1) {
            cout << arr[i];
            return 0;
        }
    }
    cout << "No non-repeating element";
}
