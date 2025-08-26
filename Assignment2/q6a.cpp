#include <iostream>
using namespace std;

int main() {
    int r1, c1, n1;
    cout << "Enter rows, cols and number of non-zero elements of Matrix1: ";
    cin >> r1 >> c1 >> n1;

    int mat1[n1][3]; 
    cout << "Enter row col value for Matrix1:\n";
    for(int i=0; i<n1; i++)
        cin >> mat1[i][0] >> mat1[i][1] >> mat1[i][2];

   
    cout << "\nTranspose of Matrix1 (triplet form):\n";
    for(int i=0; i<n1; i++)
        cout << mat1[i][1] << " " << mat1[i][0] << " " << mat1[i][2] << endl;
}