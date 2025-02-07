#include<iostream>
using namespace std;

struct Pupil {
    string fullName;
    int id;
    float scores[3];
};

void calculateAverage(Pupil s) {
    float total = 0;
    for(int i = 0; i < 3; i++) {
        total += s.scores[i];
    }
    cout << "Average Marks: " << total / 3.0 << endl;
}

void inputRecords(Pupil *students, int count) {
    for(int i = 0; i < count; i++) {
        cout << "For student " << i + 1 << endl;
        cout << "Enter name: ";
        cin.ignore();  // Clears the input buffer
        getline(cin, students[i].fullName);
        cout << "Enter roll number: ";
        cin >> students[i].id;
        for(int j = 0; j < 3; j++) {
            cout << "Enter marks for subject " << j + 1 << ": ";
            cin >> students[i].scores[j];
        }
    }
}

void showRecords(Pupil *students, int count) {
    for(int i = 0; i < count; i++) {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << students[i].fullName << endl;
        cout << "Roll Number: " << students[i].id << endl;
        for(int j = 0; j < 3; j++) {
            cout << "Marks of subject " << j + 1 << ": " << students[i].scores[j] << endl;
        }
        calculateAverage(students[i]);
    }
}

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    Pupil *studentRecords = new Pupil[numStudents];
    
    inputRecords(studentRecords, numStudents);
    showRecords(studentRecords, numStudents);
    
    delete[] studentRecords;
}
