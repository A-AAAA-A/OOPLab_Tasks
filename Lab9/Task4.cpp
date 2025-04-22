#include <iostream>
using namespace std;

class WeatherSensor
{
public:
    virtual void gatherData() = 0;
    virtual void generateReport() = 0;
};

class Thermometer : public WeatherSensor
{
public:
    void gatherData()
    {
        cout << "Gathering temperature data..." << endl;
    }

    void generateReport()
    {
        cout << "Temperature report has been generated." << endl;
    }
};

class Barometer : public WeatherSensor
{
public:
    void gatherData()
    {
        cout << "Gathering atmospheric pressure data..." << endl;
    }

    void generateReport()
    {
        cout << "Pressure report has been generated." << endl;
    }
};

int main()
{
    WeatherSensor *sensor1 = new Thermometer();
    WeatherSensor *sensor2 = new Barometer();

    sensor1->gatherData();
    sensor1->generateReport();

    sensor2->gatherData();
    sensor2->generateReport();

    delete sensor1;
    delete sensor2;

    return 0;
}
