#include <iostream>
using namespace std;

void selectionSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[minIndex])
                minIndex = j;
        }
        swap(a[i], a[minIndex]);
    }
}

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) cin >> a[i];

    selectionSort(a, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
