#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Hospital.h"
using namespace std;

int Hospital::get_Number_Of_Patients()
{
    fstream patientFile;
    std::string patient;
    patientFile.open("patients.dat", ios::in);
    while(getline(patientFile, patient))
    {
        if (patient == "")
        {
            patientFile.close();
            return number_of_patients;
        }
        number_of_patients++;
    }
    patientFile.close();
    return number_of_patients;
}
void Hospital::set_Number_Of_Beds(int number_of_beds)
{
    this->number_of_beds = number_of_beds;
}
int Hospital::get_Number_Of_Beds()
{
    return number_of_beds;
}
void Hospital::set_Number_Of_Doctors(int)
{
    this->number_of_doctors = number_of_doctors;
}
int Hospital::get_Number_Of_Doctors()
{
    return number_of_doctors;
}
void Hospital::set_Number_Of_Nurses(int)
{
    this->number_of_nurses = number_of_nurses;
}
int Hospital::get_Number_Of_Nurses()
{
    return number_of_nurses;
}
void Hospital::set_Address(string)
{
    this->address = address;
}
std::string Hospital::get_Address()
{
    return address;
}
void Hospital::newOrder(string* order, int l)
{
    fstream orderFile;
    orderFile.open("orders.dat", ios::app);
    for(int i = 0; i <= l, i+=2)
    {
        orderFile<< *(order + i)<<" "<< *(order + (i + 1));
    }
    orderFile.close();
}
bool space_Available()
{
    if (get_Number_Of_Patients() >= number_of_beds)
    {
        return false;
    }
    return true;
}
