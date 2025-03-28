#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    string contactNumber;
    string address;
    
public:
    Person(string n, int a, string c, string ad)
    {
        name = n;
        age = a;
        contactNumber = c;
        address = ad;
    }
    
    virtual void displayInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "Address: " << address << endl;
    }

    virtual void updateInfo(const string &n, int a, const string &c, const string &ad)
    {
        name = n;
        age = a;
        contactNumber = c;
        address = ad;
    }
};

class Patient : public Person
{
    string patientID;
    string doctorAssigned;
    string medicalHistory;
    
public:
    Patient(string n, int a, string c, string ad, string id, string doc, string med) 
    : Person(n, a, c, ad), patientID(id), doctorAssigned(doc), medicalHistory(med)
    {}

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
        cout << "Medical History: " << medicalHistory << endl;
    }

    void updateInfo(const string &n, int a, const string &c, const string &ad, const string &id, const string &doc, const string &med)
    {
        Person::updateInfo(n, a, c, ad);
        patientID = id;
        doctorAssigned = doc;
        medicalHistory = med;
    }
};

class Doctor : public Person
{
    string specialization;
    float consultationFee;
    string patientList[5];
    
public:
    Doctor(string n, int a, string c, string ad, string spec, float fee)
    : Person(n, a, c, ad), specialization(spec), consultationFee(fee)
    {
        for (int i = 0; i < 5; ++i)
            patientList[i] = "";
    }

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: " << consultationFee << endl;
        cout << "Patient List: " << endl;
        for (const auto& patient : patientList)
        {
            if (!patient.empty()) 
                cout << patient << endl;
        }
    }

    void addPatient(const string &patientName)
    {
        for (int i = 0; i < 5; ++i)
        {
            if (patientList[i].empty())
            {
                patientList[i] = patientName;
                break;
            }
        }
    }

    void removePatient(const string &patientName)
    {
        for (int i = 0; i < 5; ++i)
        {
            if (patientList[i] == patientName)
            {
                patientList[i] = "";
                break;
            }
        }
    }
};

class Nurse : public Person
{
    string assignedWard;
    string shiftTiming;
    
public:
    Nurse(string n, int a, string c, string ad, string ward, string shift)
    : Person(n, a, c, ad), assignedWard(ward), shiftTiming(shift)
    {}

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timing: " << shiftTiming << endl;
    }
};

class Administrator : public Person
{
    string department;
    float salary;
    
public:
    Administrator(string n, int a, string c, string ad, string dept, float sal)
    : Person(n, a, c, ad), department(dept), salary(sal)
    {}

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }

    void updateInfo(const string &n, int a, const string &c, const string &ad, const string &dept, float sal)
    {
        Person::updateInfo(n, a, c, ad);
        department = dept;
        salary = sal;
    }
};

int main()
{
    Patient p("James", 29, "03214567890", "Flat 34, Block C, Karachi", "P1001", "Dr. Emily", "Diabetes");
    Doctor d("Dr. Emily", 42, "03214567890", "Flat 34, Block C, Karachi", "Endocrinologist", 7000);
    Nurse n("Megan", 33, "03214567890", "Flat 34, Block C, Karachi", "Ward 3", "Afternoon");
    Administrator a("Sarah", 37, "03214567890", "Flat 34, Block C, Karachi", "Finance", 12000);

    cout << "Patient Details:" << endl;
    p.displayInfo();
    cout << endl;

    cout << "Doctor Details:" << endl;
    d.displayInfo();
    cout << endl;

    cout << "Nurse Details:" << endl;
    n.displayInfo();
    cout << endl;

    cout << "Administrator Details:" << endl;
    a.displayInfo();
    cout << endl;

    cout << "Updating Patient Information:" << endl;
    p.updateInfo("James", 29, "03214567890", "Flat 34, Block C, Karachi", "P1001", "Dr. Emily", "Type 2 Diabetes");
    p.displayInfo();
    cout << endl;

    cout << "Updating Administrator Information:" << endl;
    a.updateInfo("Sarah", 37, "03214567890", "Flat 34, Block C, Karachi", "Operations", 13000);
    a.displayInfo();
    cout << endl;

    cout << "Adding Patient to Doctor's List:" << endl;
    d.addPatient("James");
    d.displayInfo();
    cout << endl;

    cout << "Removing Patient from Doctor's List:" << endl;
    d.removePatient("James");
    d.displayInfo();
    cout << endl;

    return 0;
}
