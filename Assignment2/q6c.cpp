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
    if(c1==r2) {
        cout << "\nMultiplication Result (normal matrix form):\n";
        int res[r1][c2];
        for(int i=0;i<r1;i++)
            for(int j=0;j<c2;j++)
                res[i][j]=0;

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(mat1[i][1]==mat2[j][0]){
                    res[mat1[i][0]][mat2[j][1]] += mat1[i][2]*mat2[j][2];
                }
            }
        }

        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++)
                cout<<res[i][j]<<" ";
            cout<<endl;
        }
    }
    else cout<<"Multiplication not possible\n";

    return 0;
}