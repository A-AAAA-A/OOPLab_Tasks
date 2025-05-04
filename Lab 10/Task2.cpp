#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    ifstream file("vehicle.txt");
    if(!file.is_open())
    {
        cout << "Error" << endl;
        return 1;
    }
    string line;
    stringstream ss;
    string type,id,name,year,Extra;

    while(getline(file, line))
    {
        ss.clear();
        ss.str(line); 

        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, year, ',');
        getline(ss, Extra); 

        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "Extra: " << Extra << endl;
    }
    file.close();
    return 0;
}
