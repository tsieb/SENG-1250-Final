#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Hospital.h"
#include "Patient.h"
using namespace std;

class Patient : public Hospital
{
    std::string name;
    int age;
    string blood_type;
    double height;
    double weight;
    int id;

    void set_Age(int);
    int get_Age();
    void set_Weight(double);
    double get_Weight();
    void set_Height(double);
    double get_Height();
    
    bool check_In_Patient();

};
