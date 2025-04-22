#include "LabModule.h"
#include "LectureModule.h"

int main()
{
    Course* course1 = new LectureModule("MATH101", 4);
    Course* course2 = new LabModule("BIO102", 3);

    course1->showDetails();
    course1->computeGrade();
    
    course2->showDetails();
    course2->computeGrade();

    delete course1;
    delete course2;
}
