#ifndef HOSPITAL_H
#DEFINE HOSPITAL_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

class Hospital
{
public:
    int number_of_patients;
    int number_of_beds;
    int number_of_doctors;
    int number_of_nurses;
    string address;

    void set_Number_Of_Patients(int);
    int get_Number_Of_Patients();
    void set_Number_Of_Beds(int);
    int get_Number_Of_Beds();
    void set_Number_Of_Doctors(int);
    int get_Number_Of_Doctors();
    void set_Number_Of_Nurses(int);
    int get_Number_Of_Nurses();
    void set_Address(string);
    std::string get_Address();
    void newOrder();
    
};
#endif
