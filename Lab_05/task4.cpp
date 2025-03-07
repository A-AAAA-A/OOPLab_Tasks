#include<iostream>
using namespace std;

class AlarmSystem {
private:
    string securityLevel;

public:
    AlarmSystem(string level) : securityLevel(level) {}

    void updateSecurityLevel(string level) {
        securityLevel = level;
    }

    string getSecurityLevel() const {
        return securityLevel;
    }
};

class SmartHome {
private:
    int homeId;
    string location;
    AlarmSystem homeAlarm;

public:
    SmartHome(int id, string loc, string level)
        : homeId(id), location(loc), homeAlarm(level) {}

    void showDetails() const {
        cout << "Smart Home ID: " << homeId << endl;
        cout << "Location: " << location << endl;
        cout << "Alarm System Details:\n";
        cout << "Security Level: " << homeAlarm.getSecurityLevel() << endl;
    }
};

int main() {
    SmartHome home1(78, "Disco bakery, Golimaar", "Okay");
    home1.showDetails();
    return 0;
}
