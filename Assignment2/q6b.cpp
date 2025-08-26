#include<iostream>
using namespace std;
int main()
{  int r1, c1, n1;
    cout << "Enter rows, cols and number of non-zero elements of Matrix1: ";
    cin >> r1 >> c1 >> n1;

    int mat1[n1][3]; 
    cout << "Enter row col value for Matrix1:\n";
    for(int i=0; i<n1; i++)
        cin >> mat1[i][0] >> mat1[i][1] >> mat1[i][2];

    int r2, c2, n2;
    cout << "\nEnter rows, cols and number of non-zero elements of Matrix2: ";
    cin >> r2 >> c2 >> n2;

    int mat2[n2][3];
    cout << "Enter row col value for Matrix2:\n";
    for(int i=0; i<n2; i++)
        cin >> mat2[i][0] >> mat2[i][1] >> mat2[i][2];

    if(r1==r2 && c1==c2) {
        cout << "\nAddition Result (triplet form):\n";
        int i=0, j=0;
        while(i<n1 && j<n2) {
            if(mat1[i][0]==mat2[j][0] && mat1[i][1]==mat2[j][1]) {
                cout << mat1[i][0] << " " << mat1[i][1] << " " << mat1[i][2]+mat2[j][2] << endl;
                i++; j++;
            }
            else if(mat1[i][0]<mat2[j][0] || (mat1[i][0]==mat2[j][0] && mat1[i][1]<mat2[j][1])) {
                cout << mat1[i][0] << " " << mat1[i][1] << " " << mat1[i][2] << endl;
                i++;
            }
            else {
                cout << mat2[j][0] << " " << mat2[j][1] << " " << mat2[j][2] << endl;
                j++;
            }
        }
        while(i<n1) {
            cout << mat1[i][0] << " " << mat1[i][1] << " " << mat1[i][2] << endl; i++;
        }
        while(j<n2) {
            cout << mat2[j][0] << " " << mat2[j][1] << " " << mat2[j][2] << endl; j++;
        }
    }
    else cout << "Addition not possible\n";}
