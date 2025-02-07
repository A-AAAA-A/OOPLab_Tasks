#include<iostream>
using namespace std;

void getInput(int **mat1, int rowCount, int **mat2, int colCount) {
    cout << "Enter values for matrix 1:" << endl;
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            cout << "matrix1[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat1[i][j];
        }
    }

    cout << "Enter values for matrix 2:" << endl;
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            cout << "matrix2[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat2[i][j];
        }
    }
}

void showMatrix(int **mat, int rowCount, int colCount) {
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixAddition(int **mat1, int **mat2, int rowCount, int colCount) {
    cout << "Matrix addition result:" << endl;
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            cout << mat1[i][j] + mat2[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixSubtraction(int **mat1, int **mat2, int rowCount, int colCount) {
    cout << "Matrix subtraction result:" << endl;
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            cout << mat1[i][j] - mat2[i][j] << " ";
        }
        cout << endl;
    }
}

void releaseMemory(int **mat, int rowCount) {
    for(int i = 0; i < rowCount; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows for both matrices: ";
    cin >> rows;
    cout << "Enter the number of columns for both matrices: ";
    cin >> cols;

    int **matrix1 = new int*[rows];
    int **matrix2 = new int*[rows];
    
    for(int i = 0; i < rows; i++) {
        matrix1[i] = new int[cols];
        matrix2[i] = new int[cols];
    }

    getInput(matrix1, rows, matrix2, cols);
    
    cout << "Matrix 1:" << endl;
    showMatrix(matrix1, rows, cols);
    
    cout << "Matrix 2:" << endl;
    showMatrix(matrix2, rows, cols);
    
    matrixAddition(matrix1, matrix2, rows, cols);
    matrixSubtraction(matrix1, matrix2, rows, cols);
    
    releaseMemory(matrix1, rows);
    releaseMemory(matrix2, rows);

    return 0;
}
