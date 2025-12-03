#include <iostream>
using namespace std;

void bubbleSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) cin >> a[i];

    bubbleSort(a, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
