#include<iostream>
using namespace std;

class Account {
protected:
    int accountID;
    float accountBalance;

public:
    Account(int id, float balance) : accountID(id), accountBalance(balance) {}

    void displayDetails() const {
        cout << "Account Number: " << accountID << endl;
        cout << "Balance: " << accountBalance << endl;
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(int id, float balance, float rate) : Account(id, balance), interestRate(rate) {}

    void displayDetails() const {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(int id, float balance, float limit) : Account(id, balance), overdraftLimit(limit) {}

    void displayDetails() const {
        Account::displayDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount savings(303, 200.0, 4.6);
    CheckingAccount checking(201, 3500.0, 1600.0);

    cout << "Savings Account Details" << endl;
    savings.displayDetails();
    cout << "------------------------" << endl;

    cout << "Checking Account Details" << endl;
    checking.displayDetails();

    return 0;
}
