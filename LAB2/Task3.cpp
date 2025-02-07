#include<iostream>
using namespace std;

struct Worker
{
    string fullName;
    int workedHours;
    int ratePerHour;
};

void showEmployeeDetails(Worker emp) {
    cout << "Employee Name: " << emp.fullName << endl;
    cout << "Hours Worked: " << emp.workedHours << endl;
    cout << "Hourly Rate: " << emp.ratePerHour << endl;
}

void calculateSalary(Worker emp) {
    cout << "Total Salary: " << emp.workedHours * emp.ratePerHour << endl;
}

int main() {
    int totalEmployees;
    cout << "Enter the number of employees to register: ";
    cin >> totalEmployees;

    Worker *employeeList = new Worker[totalEmployees];
    
    for(int i = 0; i < totalEmployees; i++) {
        cout << "For Employee " << i + 1 << endl;
        cout << "Enter name: ";
        cin.ignore();  // To clear the input buffer
        getline(cin, employeeList[i].fullName);
        cout << "Enter hours worked: ";
        cin >> employeeList[i].workedHours;
        cout << "Enter hourly rate: ";
        cin >> employeeList[i].ratePerHour;
    }

    for(int i = 0; i < totalEmployees; i++) {
        showEmployeeDetails(employeeList[i]);
        calculateSalary(employeeList[i]);
    }

    delete[] employeeList;
}
