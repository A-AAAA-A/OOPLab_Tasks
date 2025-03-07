#include<iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;

public:
    Device() {}
    Device(int id, bool st) : deviceID(id), status(st) {}

    void displayDetails() const {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "Active" : "Inactive") << endl;
    }
};

class SmartPhone : virtual public Device {
protected:
    float displaySize;

public:
    SmartPhone(int id, bool st, float size) : Device(id, st), displaySize(size) {}
};

class SmartWatch : virtual public Device {
protected:
    bool hasHeartRateMonitor;

public:
    SmartWatch(int id, bool st, bool monitor) : Device(id, st), hasHeartRateMonitor(monitor) {}
};

class SmartWearable : public SmartPhone, public SmartWatch {
protected:
    int stepCounter;

public:
    SmartWearable(int id, bool st, float size, bool monitor, int steps) 
        : Device(id, st), SmartPhone(id, st, size), SmartWatch(id, st, monitor), stepCounter(steps) {}

    void displayDetails() const {
        Device::displayDetails();
        cout << "Screen Size: " << displaySize << " inches" << endl;
        cout << "Heart Rate Monitor: " << (hasHeartRateMonitor ? "Enabled" : "Disabled") << endl;
        cout << "Step Count: " << stepCounter << endl;
    }
};

int main() {
    SmartWearable wearable(114, true, 7.4, true, 3600);
    wearable.displayDetails();

    return 0;
}
