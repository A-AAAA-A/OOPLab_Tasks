#include<iostream>
using namespace std;

class Student {
private:
    int studentID;
    string studentName;
    int* examScores;
    int numScores;

public:
    Student(int id, string name, int scores[], int num) 
        : studentID(id), studentName(name), numScores(num) {
        examScores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            examScores[i] = scores[i];
        }
    }

    Student(const Student& other) {
        studentID = other.studentID;
        studentName = other.studentName;
        numScores = other.numScores;
        examScores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            examScores[i] = other.examScores[i];
        }
    }

    ~Student() {
        delete[] examScores;
    }

    void displayDetails() const {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << studentName << endl;
        cout << "Exam Scores: " << endl;
        for (int i = 0; i < numScores; i++) {
            cout << "Score " << i + 1 << ": " << examScores[i] << endl;
        }
    }
};

int main() {
    int scores[] = {78, 87, 78, 79};
    Student student1(007, "Iron Man", scores, 4);
    student1.displayDetails();

    Student student2(student1);  
    student2.displayDetails();

    return 0;
}
