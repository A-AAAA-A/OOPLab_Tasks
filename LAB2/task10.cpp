#include<iostream>
using namespace std;

int main() {
    int dimX, dimY, dimZ;
    cout << "For a 3D matrix [dimX][dimY][dimZ]" << endl;
    cout << "Enter dimension X: ";
    cin >> dimX;
    cout << "Enter dimension Y: ";
    cin >> dimY;
    cout << "Enter dimension Z: ";
    cin >> dimZ;

    // Dynamically allocate memory for the 3D array
    int ***matrix = new int**[dimX];
    for (int i = 0; i < dimX; i++) {
        matrix[i] = new int*[dimY];
        for (int j = 0; j < dimY; j++) {
            matrix[i][j] = new int[dimZ];
        }
    }

    // Input elements for the 3D array
    cout << "Enter the elements for the 3D array:" << endl;
    for (int i = 0; i < dimX; i++) {
        for (int j = 0; j < dimY; j++) {
            for (int k = 0; k < dimZ; k++) {
                cout << "Enter matrix[" << i + 1 << "][" << j + 1 << "][" << k + 1 << "]: ";
                cin >> matrix[i][j][k];
            }
        }
    }

    // Display the 3D array elements
    cout << "3D Array Elements:" << endl;
    for (int i = 0; i < dimX; i++) {
        for (int j = 0; j < dimY; j++) {
            for (int k = 0; k < dimZ; k++) {
                cout << matrix[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Deallocate memory for the 3D array
    for (int i = 0; i < dimX; i++) {
        for (int j = 0; j < dimY; j++) {
            delete[] matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
