#include <iostream>
using namespace std;

void insertionSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) cin >> a[i];

    insertionSort(a, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
