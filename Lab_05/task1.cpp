#include<iostream>
using namespace std;

class Apartment {
private:
    int apartmentID;
    string address;
    string* ownerName;

public:
    Apartment(int id, string addr, string name)
        : apartmentID(id), address(addr), ownerName(new string(name)) {}

    Apartment(const Apartment& other) {
        apartmentID = other.apartmentID;
        address = other.address;
        ownerName = new string(*(other.ownerName));
    }

    ~Apartment() {
        delete ownerName;
    }

    void displayDetails() const {
        cout << "Apartment ID: " << apartmentID << endl;
        cout << "Address: " << address << endl;
        cout << "Owner's Name: " << *ownerName << endl;
    }
};

int main() {
    Apartment apartment1(68, "Saddar, Karachi", "Suresh");
    apartment1.displayDetails();

    Apartment apartment2 = apartment1;
    cout << "\nCopied Apartment Details:\n";
    apartment2.displayDetails();

    return 0;
}
