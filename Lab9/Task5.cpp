#include <iostream>
using namespace std;

class Shipment
{
protected:
    string trackingID;
    double shipmentWeight;

public:
    Shipment(string trackingID, double shipmentWeight) : trackingID(trackingID), shipmentWeight(shipmentWeight) {}
    virtual void calculateDeliveryTime() = 0;
    virtual void displayInfo() = 0;
};

class AirCargo : public Shipment
{
public:
    AirCargo(string trackingID, double shipmentWeight) : Shipment(trackingID, shipmentWeight) {}

    void calculateDeliveryTime()
    {
        cout << "Estimated delivery time for Air Cargo: 2-3 days" << endl;
    }

    void displayInfo()
    {
        cout << "Air Cargo Shipment Information:" << endl;
        cout << "Tracking ID: " << trackingID << endl;
        cout << "Weight: " << shipmentWeight << " kg" << endl;
    }
};

class GroundCargo : public Shipment
{
public:
    GroundCargo(string trackingID, double shipmentWeight) : Shipment(trackingID, shipmentWeight) {}

    void calculateDeliveryTime()
    {
        cout << "Estimated delivery time for Ground Cargo: 5-7 days" << endl;
    }

    void displayInfo()
    {
        cout << "Ground Cargo Shipment Information:" << endl;
        cout << "Tracking ID: " << trackingID << endl;
        cout << "Weight: " << shipmentWeight << " kg" << endl;
    }
};

int main()
{
    Shipment *shipment1 = new AirCargo("AC98765", 15.3);
    Shipment *shipment2 = new GroundCargo("GC54321", 25.0);

    shipment1->calculateDeliveryTime();
    shipment1->displayInfo();

    shipment2->calculateDeliveryTime();
    shipment2->displayInfo();

    delete shipment1;
    delete shipment2;

    return 0;
}
