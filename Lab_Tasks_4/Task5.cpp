#include<iostream>
using namespace std;

class Vehicle {
    private:
        string vehicleBrand;
        string vehicleModel;
        float rentalRate;
        bool isAvailable;
        string registrationID;
        int vehicleID;
        float totalRevenue;

    public:
        Vehicle() 
            : vehicleBrand("Unknown"), vehicleModel("Generic"), rentalRate(0.0), isAvailable(true), 
              registrationID("Unknown"), vehicleID(0), totalRevenue(0.0) {}

        Vehicle(string brand, string model, float rate, string regID, int id, bool availability)
            : vehicleBrand(brand), vehicleModel(model), rentalRate(rate), registrationID(regID), vehicleID(id), 
              isAvailable(availability), totalRevenue(0.0) {}

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
            cout << "Registration ID: " << registrationID << endl;
            cout << "Vehicle ID: " << vehicleID << endl;
            cout << "Rental Rate: " << rentalRate << endl;
            cout << "Total Revenue: " << totalRevenue << endl;
            cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
        }

        Vehicle(const Vehicle &obj) {
            vehicleBrand = obj.vehicleBrand;
            vehicleModel = obj.vehicleModel;
            rentalRate = obj.rentalRate;
            registrationID = obj.registrationID;
            vehicleID = obj.vehicleID;
            isAvailable = obj.isAvailable;
            totalRevenue = obj.totalRevenue;
        }

        ~Vehicle() {
            cout << "Vehicle object destroyed." << endl;
        }
};

int main() {
    Vehicle v1("Toyota", "Corolla 1.6", 10000, "ABC123", 1, true);
    Vehicle v2("Honda", "Civic", 15000, "XYZ789", 2, true);

    v1.displayInfo();
    v2.displayInfo();

    v1.rentVehicle(7);
    v1.displayInfo();

    v2.rentVehicle(12);
    v2.displayInfo();

    return 0;
}
