#include<iostream>
using namespace std;

class Vehicle {
protected:
    string vehicleBrand;
    int vehicleSpeed;

public:
    Vehicle(string brand, int speed) : vehicleBrand(brand), vehicleSpeed(speed) {}

    void showDetails() const {
        cout << "Brand: " << vehicleBrand << endl;
        cout << "Speed: " << vehicleSpeed << " km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
    int carSeats;

public:
    Car(string brand, int speed, int seats) : Vehicle(brand, speed), carSeats(seats) {}

    void showDetails() const {
        Vehicle::showDetails();
        cout << "Seats: " << carSeats << endl;
    }
};

class ElectricCar : public Car {
private:
    int electricBatteryLife;

public:
    ElectricCar(string brand, int speed, int seats, int batteryLife)
        : Car(brand, speed, seats), electricBatteryLife(batteryLife) {}

    void showDetails() const {
        Car::showDetails();
        cout << "Battery Life: " << electricBatteryLife << " km" << endl;
    }
};

int main() {
    ElectricCar myElectricCar("Hyundai", 300, 2, 300);
    myElectricCar.showDetails();
    return 0;
}
