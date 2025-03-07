#include<iostream>
using namespace std;

class Employee {
private:
    string employeeName;
    string jobTitle;

public:
    Employee() {}
    Employee(string name, string title) : employeeName(name), jobTitle(title) {}

    void showDetails() const {
        cout << "Name: " << employeeName << endl;
        cout << "Designation: " << jobTitle << endl;
    }
};

class Project {
private:
    string projectName;
    string projectDeadline;
    Employee *assignedEmployees;
    int totalEmployees = 0;

public:
    Project(string name, string deadline) : projectName(name), projectDeadline(deadline) {
        assignedEmployees = new Employee[5]; 
    }

    void assignEmployee(const Employee &e) {
        assignedEmployees[totalEmployees++] = e;
    }

    void showProjectDetails() const {
        cout << "Project Name: " << projectName << endl;
        cout << "Deadline: " << projectDeadline << endl;
        cout << "Assigned Employees: " << endl;
        for (int i = 0; i < totalEmployees; i++) {
            assignedEmployees[i].showDetails();
        }
    }

    ~Project() {
        delete[] assignedEmployees; 
    }
};

int main() {
    Employee emp1("Lavaris", "Project lead");
    Employee emp2("Barirah", "Developer");
    Employee emp3("Danish", "Designer");

    Project projectA("Game Development", "15th May 2026");
    Project projectB("App Design", "1st June 2026");

    projectA.assignEmployee(emp1);
    projectA.assignEmployee(emp3);
    projectB.assignEmployee(emp2);
    projectB.assignEmployee(emp1);
    projectB.assignEmployee(emp3);

    cout << "Details of Project A:" << endl;
    projectA.showProjectDetails();
    cout << "\nDetails of Project B:" << endl;
    projectB.showProjectDetails();

    return 0;
}
