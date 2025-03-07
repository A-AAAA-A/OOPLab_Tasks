#include<iostream>
using namespace std;

class Person {
protected:
    string fullName;
    int age;

public:
    Person(string name, int age) : fullName(name), age(age) {}

    void displayDetails() const {
        cout << "Name: " << fullName << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : public Person {
protected:
    string subjectSpecialty;

public:
    Teacher(string name, int age, string subject) : Person(name, age), subjectSpecialty(subject) {}

    void displayDetails() const {
        Person::displayDetails();
        cout << "Subject: " << subjectSpecialty << endl;
    }
};

class Researcher : public Teacher {
protected:
    string fieldOfResearch;

public:
    Researcher(string name, int age, string subject, string research) : Teacher(name, age, subject), fieldOfResearch(research) {}

    void displayDetails() const {
        Teacher::displayDetails();
        cout << "Research Area: " << fieldOfResearch << endl;
    }
};

class Professor : public Researcher {
private:
    int numberOfPublications;

public:
    Professor(string name, int age, string subject, string research, int publications) : Researcher(name, age, subject, research), numberOfPublications(publications) {}

    void displayDetails() const {
        Researcher::displayDetails();
        cout << "Publications: " << numberOfPublications << endl;
    }
};

int main() {
    Professor professor("Dr. Abdul Qadir", 50, "Astro Physics", "Higs Boson", 110);
    professor.displayDetails();

    return 0;
}
