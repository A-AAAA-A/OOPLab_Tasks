#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream file("sensor_log.txt");

    if(!file.is_open())
    {
        cout << "Error" << endl;
        return 1;
    }

    file << "I am IronMan.\n";
    file << "I am dead.\n";

    size_t pos = file.tellp();
    cout << "Current position in file: " << pos << endl;

    file << "On yo left.\n";
    pos = file.tellp();
    cout << "Current position in file: " << pos << endl;

    file << "Once a rat, always a rat.\n";
    pos = file.tellp();
    cout << "Current position in file: " << pos << endl;

    file.close();

    return 0;


}
