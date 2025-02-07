#include<iostream>
using namespace std;

int* createArray(int size) {
    return new int[size];
}

void inputArray(int *array, int size) {
    for(int i = 0; i < size; i++) {
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> array[i];
    }
}

void displayArray(int *array, int size) {
    cout << "The elements of the array are: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void deallocateArray(int *array) {
    delete[] array;
}

int main() {
    int length;
    cout << "Please enter the size of the array: ";
    cin >> length;

    int *dynamicArray = createArray(length);

    inputArray(dynamicArray, length);
    displayArray(dynamicArray, length);
    deallocateArray(dynamicArray);

    return 0;
}
