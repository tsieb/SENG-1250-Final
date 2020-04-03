#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Hospital.h"
#include "Patient.h"
using namespace std;

void Patient::set_Age(int age)
{
    this->age = age;
}
int Patient::get_Age()
{
    return age;
}
void Patient::set_Weight(double weight)
{
    this->weight = weight;
}
double Patient::get_Weight()
{
    return weight;
}
void Patient::set_Height(double height)
{
    this->height = height;
}
double Patient::get_Height()
{
    return height;
}
bool check_In_Patient()
{
    fstream patientFile;
    patientFile.open("patients.dat", ios::app);
    if (space_Available())
    {
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter Age: ";
        cin>>age;
        cout<<"Enter Height: ";
        cin>>height;
        cout<<"Enter Weight: ";
        cin>>weight;
        cout<<"Enter ID: ";
        cin>>id;
        cout<<"Enter Blood Type: ";
        cin>>blood_type;
        patientFile<<name<<" "<<age<<" "<<height<<" "<<weight<<" "<<id<<" "<<blood_type;
        patientFile.close();
        return true;
    }
    patientFile.close();
    return false;
}
