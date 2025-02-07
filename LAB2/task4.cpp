#include<iostream>
#include<algorithm>
using namespace std;

void showStrings(string *array, int count) {
    for(int i = 0; i < count; i++) {
        cout << array[i] << endl;
    }
}

int main() {
    int numStrings;
    cout << "Enter the number of strings you wish to input: ";
    cin >> numStrings;
    cin.ignore();  // To clear the newline left by cin

    string *stringArray = new string[numStrings];
    
    for(int i = 0; i < numStrings; i++) {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, stringArray[i]);
    }

    cout << "Unsorted string array:" << endl;
    showStrings(stringArray, numStrings);

    sort(stringArray, stringArray + numStrings);
    
    cout << "Sorted string array:" << endl;
    showStrings(stringArray, numStrings);

    delete[] stringArray;
}
