#include<iostream>
using namespace std;

class Employee {
protected:
    string employeeName;
    float employeeSalary;

public:
    Employee(string name, float salary) : employeeName(name), employeeSalary(salary) {}

    void showDetails() const {
        cout << "Name: " << employeeName << endl;
        cout << "Salary: " << employeeSalary << endl;
    }
};

class Manager : public Employee {
private:
    float managerBonus;

public:
    Manager(string name, float salary, float bonus) : Employee(name, salary), managerBonus(bonus) {}

    void showDetails() const {
        Employee::showDetails();
        cout << "Bonus: " << managerBonus << endl;
    }
};

int main() {
    Manager manager1("Ahsan", 5000, 80000);

    manager1.showDetails();

    return 0;
}
