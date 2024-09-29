#include <bits/stdc++.h>
using namespace std;

int main() {
    int row1, col1, row2, col2;

    // Size matrix 1
    cout << "1/ Number of Rows and Columns: ";
    cin >> row1 >> col1;

    // Matrix 1
    int matrix1[row1][col1];
    cout << "Matrix_1:\n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> matrix1[i][j];
        }
    }

    // Similarly for the second one
    cout << "2/ Number of Rows and Columns: ";
    cin >> row2 >> col2;

    int matrix2[row2][col2];
    cout << "Matrix_2:\n";
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cin >> matrix2[i][j];
        }
    }

    // Check comditions
    if (row1 == row2 && col1 == col2) {
        // Ans
        int sum_matrix[row1][col1], diff_matrix[row1][col1], product_matrix[row1][col1];

        // Sum
        cout << "Sum:\n";
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
                cout << sum_matrix[i][j] << " ";
            }
            cout << endl;
        }

        // Subtraction
        cout << "Sub:\n";
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                diff_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
                cout << diff_matrix[i][j] << " ";
            }
            cout << endl;
        }

        // Multiplication
        cout << "Mul:\n";
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col2; j++) {
                product_matrix[i][j] = 0;
                for (int k = 0; k < col1; k++) {
                    product_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
                cout << product_matrix[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Different size matrices, cannot be performed!\n";
    }

    return 0;
}