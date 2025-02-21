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
            cout << "Enter the number of days you want to rent the car for: ";
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
};

int main() {
    Vehicle v1("Toyota", "Corolla 1.6", 10000, true);
    v1.displayInfo();
    v1.applyDiscount();
    cout << "Is the vehicle available? " << (v1.checkAvailability() ? "Yes" : "No") << endl;
    v1.rentVehicle();
    cout << "Is the vehicle available? " << (v1.checkAvailability() ? "Yes" : "No") << endl;
    v1.displayInfo();

    return 0;
}
