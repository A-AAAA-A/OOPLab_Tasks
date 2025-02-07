#include<iostream>
using namespace std;

void showArray(int *array, int size) {
    cout << "Array elements: ";
    for(int i = 0; i < size; i++) {
        cout << *(array + i) << " ";
    }
    cout << endl;
}

void calculateSum(int *array, int size) {
    int total = 0;
    for(int i = 0; i < size; i++) {
        total += *(array + i);
    }
    cout << "Sum of Array: " << total << endl;
}

int main() {
    int numElements;
    cout << "Enter the number of elements you want to input: ";
    cin >> numElements;

    int *array = new int[numElements];

    for(int i = 0; i < numElements; i++) {
        cout << "array[" << i + 1 << "]: ";
        cin >> *(array + i);
    }

    showArray(array, numElements);
    calculateSum(array, numElements);

    delete[] array;
}
