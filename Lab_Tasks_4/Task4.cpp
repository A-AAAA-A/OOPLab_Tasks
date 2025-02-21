#include<iostream>
using namespace std;

class Vehicle {
    private:
        string vehicleBrand;
        string vehicleModel;
        float rentalRate;
        bool isAvailable;
        float totalRevenue;
    public:
        Vehicle() {
            vehicleBrand = "Unknown";
            vehicleModel = "Generic";
            rentalRate = 0.0;
            isAvailable = true;
            totalRevenue = 0.0;
        }

        Vehicle(string brand, string model, float rate, bool availability, float revenue) {
            vehicleBrand = brand;
            vehicleModel = model;
            rentalRate = rate;
            isAvailable = availability;
            totalRevenue = revenue;
        }

        void rentVehicle(int rentalDays) {
            if (!isAvailable) {
                cout << "Vehicle is not available." << endl;
                return;
            }

            float discount = 0;
            if (rentalDays > 10) {
                discount = 0.10;
            } else if (rentalDays > 5) {
                discount = 0.05;
            }

            float finalPrice = rentalRate * rentalDays * (1 - discount);

            this->totalRevenue += finalPrice;
            this->isAvailable = false;
            cout << "Vehicle rented for " << rentalDays << " days. Final price after discount: " << finalPrice << endl;
        }

        void returnVehicle() {
            isAvailable = true;
            cout << "Vehicle returned successfully." << endl;
        }

        bool checkAvailability() {
            return isAvailable;
        }

        void displayInfo() {
            cout << "Brand: " << vehicleBrand << endl;
            cout << "Model: " << vehicleModel << endl;
            cout << "Rental Rate: " << rentalRate << endl;
            cout << "Total Revenue: " << totalRevenue << endl;
        }

        Vehicle(const Vehicle &obj) {
            vehicleBrand = obj.vehicleBrand;
            vehicleModel = obj.vehicleModel;
            rentalRate = obj.rentalRate;
            isAvailable = obj.isAvailable;
            totalRevenue = obj.totalRevenue;
        }

        ~Vehicle() {
            cout << "Vehicle object destroyed." << endl;
        }
};

int main() {
    Vehicle v1("Toyota", "Corolla 1.6", 10000, true, 0);
    v1.displayInfo();
    v1.rentVehicle(10);
    v1.displayInfo();
    
    return 0;
}
