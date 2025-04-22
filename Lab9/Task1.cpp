#include <iostream>
using namespace std;

class PatientBase
{
protected:
    string patientName;
    int patientID;

public:
    PatientBase(string patientName, int patientID) : patientName(patientName), patientID(patientID) {}
    virtual void showTreatment() = 0;
    virtual int computeCost() = 0;
};

class InHospitalPatient : public PatientBase
{
public:
    InHospitalPatient(string patientName, int patientID) : PatientBase(patientName, patientID) {}
    
    void showTreatment()
    {
        cout << "Treatment for inpatient: " << patientName << endl;
    }
    
    int computeCost()
    {
        return 1200;  
    }
};

class OutHospitalPatient : public PatientBase
{
public:
    OutHospitalPatient(string patientName, int patientID) : PatientBase(patientName, patientID) {}
    
    void showTreatment()
    {
        cout << "Treatment for outpatient: " << patientName << endl;
    }
    
    int computeCost()
    {
        return 600;  
    }
};

int main()
{
    PatientBase *patient1 = new InHospitalPatient("Alice Cooper", 101);
    PatientBase *patient2 = new OutHospitalPatient("Bob Johnson", 102);

    patient1->showTreatment();
    cout << "Total Cost: $" << patient1->computeCost() << endl;

    patient2->showTreatment();
    cout << "Total Cost: $" << patient2->computeCost() << endl;

    delete patient1;
    delete patient2;
    
    return 0;
}
