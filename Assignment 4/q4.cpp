#include <iostream>
using namespace std;

void firstNonRepeating(char str[], int n) {
    int freq[256] = {0};
    char queue[100];
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        char ch = str[i];
        freq[ch]++;
        queue[++rear] = ch;

        while (front <= rear && freq[queue[front]] > 1) {
            front++;
        }

        if (front > rear) cout << -1 << " ";
        else cout << queue[front] << " ";
    }
}

int main() {
    char str[] = {'a','a','b','c'};
    int n = 4;
    firstNonRepeating(str, n);
    return 0;
}
