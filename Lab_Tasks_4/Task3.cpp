#include<iostream>
using namespace std;

class Vehicle {
    private:
        string vehicleBrand;
        string vehicleModel;
        float rentalRate;
        bool isAvailable;
        float totalPrice = 0;
    public:
        Vehicle() {
            vehicleBrand = "Unknown";
            vehicleModel = "Generic";
            rentalRate = 0.0;
            isAvailable = true;
        }

        Vehicle(string brand, string model, float rate, bool availability) {
            vehicleBrand = brand;
            vehicleModel = model;
            rentalRate = rate;
            isAvailable = availability;
        }

        void applyDiscount() {
            int rentalDays = 0;
            cout << "Enter the number of days you want to rent the vehicle for: ";
            cin >> rentalDays;
            float discount = 0;
            if (rentalDays > 10) {
                discount = 0.10;
            } else if (rentalDays > 5) {
                discount = 0.05;
            }

            totalPrice = rentalRate * rentalDays * (1 - discount);
        }

        bool checkAvailability() {
            return isAvailable;
        }

        void rentVehicle() {
            if (isAvailable) {
                isAvailable = false;
                cout << "Vehicle rented successfully!" << endl;
            } else {
                cout << "Sorry, the vehicle is not available." << endl;
            }
        }

        void returnVehicle() {
            isAvailable = true;
            cout << "Vehicle returned successfully." << endl;
        }

        void displayInfo() {
            cout << "Brand: " << vehicleBrand << endl;
            cout << "Model: " << vehicleModel << endl;
            cout << "Rental Rate: " << rentalRate << endl;
            cout << "Total Price after discount: " << totalPrice << endl;
        }

        Vehicle(const Vehicle &obj) {
            vehicleBrand = obj.vehicleBrand;
            vehicleModel = obj.vehicleModel;
            rentalRate = obj.rentalRate;
            isAvailable = obj.isAvailable;
            totalPrice = obj.totalPrice;
        }

        ~Vehicle() {
            cout << "Vehicle object is destroyed." << endl;
        }
};

int main() {
    Vehicle v1("Honda", "Civic 1.8", 12000, true);
    Vehicle v2(v1); 
    
    v1.displayInfo();
    v2.displayInfo();
    
    v1.applyDiscount();
    cout << "\nAfter applying discount to v1:\n";
    v1.displayInfo();
    v2.displayInfo(); 
    return 0;
}
