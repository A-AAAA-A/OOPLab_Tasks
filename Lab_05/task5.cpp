#include<iostream>
using namespace std;

class Doctor {
private:
    string doctorName;
    string doctorSpecialization;
    string yearsOfExperience;

public:
    Doctor() {}
    Doctor(string name, string specialization, string experience)
        : doctorName(name), doctorSpecialization(specialization), yearsOfExperience(experience) {}

    void showDetails() const {
        cout << "Doctor Name: " << doctorName << endl;
        cout << "Specialization: " << doctorSpecialization << endl;
        cout << "Experience: " << yearsOfExperience << endl;
    }
};

class Hospital {
private:
    string hospitalName;
    Doctor* doctorList;
    int totalDoctors;

public:
    Hospital(string name)
        : hospitalName(name), totalDoctors(0), doctorList(new Doctor[10]) {}

    ~Hospital() {
        delete[] doctorList;
    }

    void assignDoctor(const Doctor& doctor) {
        doctorList[totalDoctors++] = doctor;
    }

    void showHospitalDetails() const {
        cout << "Hospital Name: " << hospitalName << endl;
        cout << "Currently Working Doctors: " << endl;
        for (int i = 0; i < totalDoctors; i++) {
            doctorList[i].showDetails();
        }
    }
};

int main() {
    Doctor doctor1("Dr. Hasa", "Neurologist", "3 months");
    Doctor doctor2("Dr. Jamal", "Orthopedic", "5 hours");

    Hospital hospital1("IO Hospital");
    hospital1.assignDoctor(doctor1);
    hospital1.assignDoctor(doctor2);

    hospital1.showHospitalDetails();

    return 0;
}
