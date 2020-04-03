#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <string>
#include "Hospital.h"
#include "Patient.h"
using namespace std;

void Patient::set_Name(string name)
{
    this->name = name;
}
int Patient::get_Name(int id)
{
    ifstream patientFile1;
    ifstream patientFile2;
    input_stream1.open("patients.dat");
    input_stream2.open("patients.dat");
    {
	string name;
	int Person = 0;
	int count_word = 1;
	while(getline(input_stream1, line))
	{
		count_word = 1;
		if(line == "")
		break;
		cout<<line<<endl;
		
		for(int i =0; line[i] != '\0'; i++)
		{
			if(line[i]==' ')
			count_word++;
		}
		for (int j =0; j<count_word; j++)
		{
			input_stream2 >>ID;
			if(j == 5)
			{
			if(ID == id)
			Person++;
		}
		}

	}
	cout<<"The name of the person with this id is: "<<Person;
	
	input_stream1.close();
	input_stream2.close();
    }
    patientFile.close();
    return name;
}
void Patient::set_Age(int age)
{
    this->age = age;
}
int Patient::get_Age()
{
    return age;
}
void Patient::set_Height(double height)
{
    this->height = height;
}
double Patient::get_Height()
{
    return height;
}
void Patient::set_Weight(double weight)
{
    this->weight = weight;
}
double Patient::get_Weight()
{
    return weight;
}
void Patient::set_ID(int id)
{
    this->id = id;
}
int Patient::get_ID()
{
    return id;
}
void Patient::set_BloodType(string blood_type)
{
    this->blood_type = blood_type;
}
int Patient::get_BloddType()
{
    return blood_type;
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
