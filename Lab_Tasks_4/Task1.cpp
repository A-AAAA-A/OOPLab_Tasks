#include<iostream>
using namespace std;

class Vehicle {
    private:
        string carBrand;
        string carModel;
        float rentalFee;
        bool isAvailable;
    public:
        Vehicle(){
            carBrand = "Unknown";
            carModel = "Generic";
            rentalFee = 0.0;
            isAvailable = true;
        }

        bool checkAvailability() {
            return isAvailable;
        }

        void rentCar() {
            if(isAvailable) {
                isAvailable = false;
            } else {
                cout << "Sorry, the car is not available for rent." << endl;
            }
        }
};

int main() {
    Vehicle v1;
    v1.checkAvailability();
    v1.rentCar();
    v1.checkAvailability();
    v1.rentCar();
    return 0;
}
