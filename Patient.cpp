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
void Patient::add_Symptom(string symptom)
{
    //TODO add symptom to symptoms
}
void Patient::add_Illness(string illness)
{
    //TODO add illness to illnesses
}
void Patient::add_Allergy(string allergy)
{
    //TODO add allergy to allergies
}
