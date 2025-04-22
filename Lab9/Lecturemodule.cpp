#include "LectureModule.h"

LectureModule::LectureModule(string courseID, int creditHours) { 
    this->courseID = courseID;
    this->creditHours = creditHours;
}

void LectureModule::calculateFinalGrade()
{
    int score;
    cout << "Enter marks for Lecture Module " << courseID << ": ";
    cin >> score;
    cout << "Your final grade is: ";
    if (score >= 90)
        cout << "Grade: A" << endl;
    else if (score >= 80)
        cout << "Grade: B" << endl;
    else if (score >= 70)
        cout << "Grade: C" << endl;
    else if (score >= 60)
        cout << "Grade: D" << endl;
    else
        cout << "Grade: F" << endl;
}

void LectureModule::showCourseDetails()
{
    cout << "Course ID: " << courseID << endl;
    cout << "Credits: " << creditHours << endl;
    cout << "Course Type: Lecture" << endl;
}
