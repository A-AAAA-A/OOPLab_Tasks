#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    double fuelCapacity;
    double currentFuelLevel;

public:
    Car(string carBrand, string carModel, double capacity) {
        brand = carBrand;
        model = carModel;
        fuelCapacity = capacity;
        currentFuelLevel = capacity;
    }

    void drive(double distance) {
        double fuelConsumed = distance * 0.05;
        if (currentFuelLevel - fuelConsumed < 0) {
            cout << "Not enough fuel to drive. Please refuel the car." << endl;
        } else {
            currentFuelLevel -= fuelConsumed;
            cout << "You drove " << distance << " kilometers." << endl;
            cout << "Fuel consumed: " << fuelConsumed << " liters." << endl;
        }
    }

    void refuel(double fuelAmount) {
        if (currentFuelLevel + fuelAmount > fuelCapacity) {
            currentFuelLevel = fuelCapacity;
            cout << "The tank is full!" << endl;
        } else {
            currentFuelLevel += fuelAmount;
            cout << "Refueled " << fuelAmount << " liters." << endl;
        }
    }

    void checkFuelStatus() {
        cout << "Current fuel level: " << currentFuelLevel << " liters." << endl;
        if (currentFuelLevel <= fuelCapacity * 0.1) {
            cout << "Warning: Fuel is low!" << endl;
        }
    }

    void displayCarDetails() {
        cout << "Car Brand: " << brand << endl;
        cout << "Car Model: " << model << endl;
        cout << "Fuel Capacity: " << fuelCapacity << " liters" << endl;
        checkFuelStatus();
    }
};

int main() {
    Car myCar("Toyota", "Corolla", 50.0);

    myCar.displayCarDetails();

    myCar.drive(200);
    myCar.checkFuelStatus();

    myCar.refuel(10);
    myCar.checkFuelStatus();

    myCar.drive(300);
    myCar.checkFuelStatus();

    myCar.refuel(100);

    return 0;
}
