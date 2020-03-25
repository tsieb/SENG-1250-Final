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

    int get_Number_Of_Patients()
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
    void set_Number_Of_Beds(int number_of_beds)
    {
        this->number_of_beds = number_of_beds;
    }
    int get_Number_Of_Beds()
    {
        return number_of_beds;
    }
    void set_Number_Of_Doctors(int)
    {
        this->number_of_doctors = number_of_doctors;
    }
    int get_Number_Of_Doctors()
    {
        return number_of_doctors;
    }
    void set_Number_Of_Nurses(int)
    {
        this->number_of_nurses = number_of_nurses;
    }
    int get_Number_Of_Nurses()
    {
        return number_of_nurses;
    }
    void set_Address(string)
    {
        this->address = address;
    }
    std::string get_Address()
    {
        return address;
    }
    void newOrder(string* order, int l)
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

};

class Patient : public Hospital
{
    std::string symptoms[10];
    std::string illnesses[10];
    std::string allergies[10];
    std::string name;
    int age;
    string blood_type;
    double height;
    double weight;
    int id;

    void set_Age(int age)
    {
        this->age = age;
    }
    int get_Age()
    {
        return age;
    }
    void set_Weight(double weight)
    {
        this->weight = weight;
    }
    double get_Weight()
    {
        return weight;
    }
    void set_Height(double height)
    {
        this->height = height;
    }
    double get_Height()
    {
        return height;
    }
    void add_Symptom(string symptom)
    {
        //TODO add symptom to symptoms
    }
    void add_Illness(string illness)
    {
        //TODO add illness to illnesses
    }
    void add_Allergy(string allergy)
    {
        //TODO add allergy to allergies
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

};

class Supplier : public Hospital
{
  public:
    fstream supplies;
    int id, stock, in, amount;
    std::string supply;

    addSupply()
    {
      int temp;
      cout<<"Enter the id, name and stock of the supply you want to add: ";
      cin>>id>>supply>>stock;
      temp=id;
      supplies.open("Supplies.dat", ios::app | ios::binary);
      while(getline(supplies, supply))
      {
        if(id==temp;)
        {
          cout<<"An item already exists with this id.";
          break;
        }
      }
    }

    getSupplyList()
    {
      supplies.open("Supplies.dat", ios::in | ios::binary);
      while(getline(supplies, supply))
      {
        supplies>>id>>supply>>stock;
        cout<<supply<<" "
      }
    }

    depositSupplies()
    {
      cout<<"Enter the ID of the supply you wish to deposit to, and the amount to deposit: ";
      cin>>in>>amount;
      supplies.open("Supplies.dat", ios::app | ios::binary);
      while(getline(supplies, supply))
      {
        supplies>>id>>supply>>stock;
        if(id==in)
        {
          cout<<id<<" "<<supply<<" "<<stock;
          supplies.close;
          break;
        }
        else
        {
          cout<<"There is no supply with this ID.";
        }
      }
    }

    withdrawSupplies()
    {
      cout<<"Enter the ID of the supply you wish to withdraw from, and the amount to withdraw: ";
      cin>>in>>amount;
      supplies.open("Supplies.dat", ios::app | ios::binary);
      while(getline(supplies, supply))
      {
        supplies>>id>>supply>>stock;
        if(id==in)
        {
          cout<<id<<" "<<supply<<" "<<stock;
          supplies.close;
          break;
        }
        else
        {
          cout<<"There is no supply with this ID.";
        }
      }
    }

    outputStock()
    {
      cout<<"Enter the ID of the supply you wish to check the stock of: ";
      cin>>in;
      supplies.open("Supplies.dat", ios::in | ios::binary);
      while(getline(supplies, supply))
      {
        supplies>>id>>supply>>stock;
        if(id==in)
        {
          cout<<stock;
          supplies.close;
          break;
        }
        else
        {
          cout<<"There is no supply with this ID.";
        }
      }
    }
};

void startUp()
{
    cout<<"Medicare 2020 - Booting"<<endl;
    cout<<"                Booting."<<endl;
    cout<<"                Booting.."<<endl;
    cout<<"                Booting..."<<endl<<endl;
    cout<<"/tInitialization Complete"<<endl<<endl;
}


int int main(int argc, char const *argv[])
{
    startUp();
    cout<<"List of options"<<endl;
    return 0;
}
