#include "Labcourse.h"

LabModule::LabModule(string courseID, int creditHours) { 
    this->courseID = courseID;
    this->creditHours = creditHours;
}

void LabModule::calculateFinalGrade()
{
    int score;
    cout << "Enter marks for Lab Module " << courseID << ": ";
    cin >> score;
    cout << "Your final grade is: ";
    if (score >= 90)
        cout << "Grade: A+" << endl;
    else if (score >= 80)
        cout << "Grade: A" << endl;
    else if (score >= 70)
        cout << "Grade: B" << endl;
    else if (score >= 60)
        cout << "Grade: C" << endl;
    else
        cout << "Grade: D" << endl;
}

void LabModule::showCourseDetails()
{
    cout << "Course ID: " << courseID << endl;
    cout << "Credits: " << creditHours << endl;
    cout << "Course Type: Lab" << endl;
}
