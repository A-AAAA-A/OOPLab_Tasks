#include<iostream>
using namespace std;

int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void inputMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element at matrix[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void showMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrices(int **mat1, int **mat2, int rows1, int cols1, int rows2, int cols2) {
    cout << "Result of Matrix Multiplication: " << endl;
    int tempSum = 0;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                tempSum += mat1[i][k] * mat2[k][j];
            }
            cout << tempSum << " ";
            tempSum = 0;
        }
        cout << endl;
    }
}

void freeMemory(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    cout << "Enter the number of rows for Matrix A: ";
    cin >> rowsA;
    cout << "Enter the number of columns for Matrix A: ";
    cin >> colsA;

    cout << "Enter the number of rows for Matrix B: ";
    cin >> rowsB;
    cout << "Enter the number of columns for Matrix B: ";
    cin >> colsB;

    if (colsA == rowsB) {
        int **matrixA = createMatrix(rowsA, colsA);
        int **matrixB = createMatrix(rowsB, colsB);

        cout << "Enter elements of Matrix A:" << endl;
        inputMatrix(matrixA, rowsA, colsA);

        cout << "Enter elements of Matrix B:" << endl;
        inputMatrix(matrixB, rowsB, colsB);

        cout << "Matrix A:" << endl;
        showMatrix(matrixA, rowsA, colsA);

        cout << "Matrix B:" << endl;
        showMatrix(matrixB, rowsB, colsB);

        multiplyMatrices(matrixA, matrixB, rowsA, colsA, rowsB, colsB);

        freeMemory(matrixA, rowsA);
        freeMemory(matrixB, rowsB);
    } else {
        cout << "Matrix multiplication not possible. The number of columns in Matrix A must equal the number of rows in Matrix B." << endl;
    }

    return 0;
}
