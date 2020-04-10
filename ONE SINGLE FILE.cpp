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

    Hospital()
    {
        fstream hospitalFile;
        string line;
        hospitalFile.open("hospital.txt", ios::in);
        getline(hospitalFile, line);
        if (line != "")
        {
            address = line;
            hospitalFile>>number_of_beds;
            hospitalFile>>number_of_nurses;
            hospitalFile>>number_of_doctors;
            hospitalFile.close();
        }
        else
        {
            cout<<"Enter the address: ";
            cin.ignore();
            getline(cin, address);
            cout<<"Enter the number of beds: ";
            cin>>number_of_beds;
            cout<<"Enter the number of nurses: ";
            cin>>number_of_nurses;
            cout<<"Enter the number of doctors: ";
            cin>>number_of_doctors;
            hospitalFile.close();
            hospitalFile.open("hospital.txt", ios::out);
            hospitalFile<<address<<endl<<number_of_beds<<endl<<number_of_nurses<<endl<<number_of_doctors;
            hospitalFile.close();
        }
    }

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
public:
    std::string name;
    int age;
    string blood_type;
    double height;
    double weight;
    int id, ID;

    void set_Name(string name)
    {
        this->name = name;
    }
    int get_Name(int id)
    {
        ifstream patientFile1;
        ifstream patientFile2;
        string line;
        patientFile1.open("patients.dat");
        patientFile2.open("patients.dat");
        {
            string name;
            int person = 0;
            int count_word = 1;
            while(getline(patientFile1, line))
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
                    patientFile2 >>ID;
                    if(j == 5)
                    {
                    if(ID == id)
                    person++;
                    }
                }
            }


        cout<<"The name of the person with this id is: ";
        return person;
        }
        patientFile1.close();
        patientFile2.close();
    }
    void set_Age(int age)
    {
        this->age = age;
    }
    int get_Age(int n)
    {
        return age;
    }
    void set_Height(double height)
    {
        this->height = height;
    }
    double get_Height(int n)
    {
        return height;
    }
    void set_Weight(double weight)
    {
        this->weight = weight;
    }
    double get_Weight(int n)
    {
        return weight;
    }
     void set_BloodType(string blood_type)
    {
        this->blood_type = blood_type;
    }
    string get_BloodType(int n)
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
    void check_Out_Patient(int id)
    {
        //TODO
    }

};

class Supplier : public Hospital
{
  public:
    fstream supplies;
    int id, stock, in, amount;
    std::string supply;

    void addSupply()
    {
      int tempID, check=1, tempStock;
      string tempSupply;
      cout<<"Enter the id, name and stock of the supply you want to add: ";
      cin>>tempID>>tempSupply>>tempStock;

      supplies.open("Supplies.dat", ios::in | ios::binary);
      while(supplies)
      {
		supplies>>id>>supply>>stock;
        if(id==tempID)
        {
          cout<<"An item already exists with this id.";
          check=0;
          break;
        }
      }
      supplies.close();
      if(check==1)
      {
		while(supplies)
		{
			supplies<<endl;
		}
		supplies.open("Supplies.dat", ios::app | ios::binary);
		supplies<<tempID<<" "<<tempSupply<<" "<<tempStock<<endl;
		cout<<endl;
		supplies.close();
	  }
    }

    void getSupplyList()
    {
      supplies.open("Supplies.dat", ios::in | ios::binary);
      while(getline(supplies, supply))
      {
        supplies>>id>>supply>>stock;
        cout<<supply<<" ";
      }
      supplies.close();
    }

    void depositSupplies()
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
          supplies.close();
          break;
        }
        else
        {
          cout<<"There is no supply with this ID.";
        }
      }
    }

    void withdrawSupplies()
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
          supplies.close();
          break;
        }
        else
        {
          cout<<"There is no supply with this ID.";
        }
      }
    }

    void outputStock()
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
          supplies.close();
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
    cout<<"     Initialization Complete"<<endl<<endl;
}

void line()
{
    cout<<      "-----------------------------------------"<<endl;
}

int main(int argc, char const *argv[])
{
    int choice, number;
    string address_string, patient_string;
    startUp();
    while (1)
    {
      line();
      cout<<"1 - Hospital"<<endl;
      cout<<"2 - Patient"<<endl;
      cout<<"3 - Supplies"<<endl;
      cout<<"Choice: ";
      cin>>choice;
      if (choice == 1)
      {
          Hospital h1;
          line();
          cout<<"1 - Configure Resources"<<endl;
          cout<<"2 - Check Resources"<<endl;
          cout<<"Choice: ";
          cin>>choice;
          switch (choice)
          {
              case 1:
                  line();
                  cout<<"1 - Set Doctors"<<endl;
                  cout<<"2 - Set Nurses"<<endl;
                  cout<<"3 - Set Beds"<<endl;
                  cout<<"4 - Set Address"<<endl;
                  cin>>choice;
                  switch (choice)
                  {
                      case 1:
                          cout<<"Enter Number: ";
                          cin>>number;
                          h1.set_Number_Of_Doctors(number);
                          break;
                      case 2:
                          cout<<"Enter Number: ";
                          cin>>number;
                          h1.set_Number_Of_Nurses(number);
                          break;
                      case 3:
                          cout<<"Enter Number: ";
                          cin>>number;
                          h1.set_Number_Of_Beds(number);
                          break;
                      case 4:
                          cout<<"Enter Address: ";
                          getline(cin, address_string);
                          h1.set_Number_Of_Beds(number);
                          break;
                      default :
                          cout<<"Invalid Entry"<<endl;
                          break;
                  }
                  break;
              case 2:
                  line();
                  cout<<"1 - Check Number of Doctors"<<endl;
                  cout<<"2 - Check Number of Nurses"<<endl;
                  cout<<"3 - Check Number of Beds"<<endl;
                  cout<<"4 - Check Address"<<endl;
                  cin>>choice;
                  switch (choice)
                  {
                      case 1:
                          cout<<"Number of Doctors: "<<h1.get_Number_Of_Doctors()<<endl;
                          break;
                      case 2:
                          cout<<"Number of Nurses: "<<h1.get_Number_Of_Nurses()<<endl;
                          break;
                      case 3:
                          cout<<"Number of Beds: "<<h1.get_Number_Of_Beds()<<endl;
                          break;
                      case 4:
                          cout<<"Address: "<<h1.get_Address()<<endl;
                          break;
                      default :
                          cout<<"Invalid Entry"<<endl;
                          break;
                  }
                  break;
              default :
                  cout<<"Invalid Entry"<<endl;
                  break;
          }
    }
    else if (choice == 2)
    {
          Patient p1;
          line();
          cout<<"1 - Check-In Patient"<<endl;
          cout<<"2 - Check-Out Patient"<<endl;
          cout<<"3 - View Patient Information"<<endl;
          cout<<"Choice: ";
          cin>>choice;
          switch (choice)
          {
              case 1:
                  if(p1.check_In_Patient())
                  {
                      cout<<"Check-in Successful"<<endl;
                      break;
                  }
                  cout<<"Unable to add patient - No space available"<<endl;
                  break;
              case 2:
                  cout<<"Enter patient ID: ";
                  cin>>number;
                  p1.check_Out_Patient(number);
                  break;
              case 3:
                  line();
                  cout<<"1 - Get patient name"<<endl;
                  cout<<"2 - Get patient age"<<endl;
                  cout<<"3 - Get patient weight"<<endl;
                  cout<<"4 - Get patient height"<<endl;
                  cout<<"5 - Get patient blood type"<<endl;
                  cout<<"Choice: ";
                  cin>>choice;
                  switch (choice)
                  {
                      case 1:
                          cout<<"Enter patient ID: ";
                          cin>>number;
                          p1.get_Name(number);
                          break;
                      case 2:
                          cout<<"Enter patient ID: ";
                          cin>>number;
                          p1.get_Age(number);
                          break;
                      case 3:
                          cout<<"Enter patient ID: ";
                          cin>>number;
                          p1.get_Weight(number);
                          break;
                      case 4:
                          cout<<"Enter patient ID: ";
                          cin>>number;
                          p1.get_Height(number);
                          break;
                      case 5:
                          cout<<"Enter patient ID: ";
                          cin>>number;
                          p1.get_BloodType(number);
                          break;
                      default :
                          cout<<"Invalid Entry"<<endl;
                          break;
                  }
                  break;
          }
      }
      else if (choice == 3)
      {
          Supplier s1;
          line();
          cout<<"1 - Check Supply"<<endl;
          cout<<"2 - List Supplies"<<endl;
          cout<<"3 - Withdraw Supplies"<<endl;
          cout<<"4 - Deposit Supplies"<<endl;
          cout<<"5 - Add New Supply"<<endl;
          cout<<"Choice: ";
          cin>>choice;
          switch (choice)
          {
              case 1:
                  s1.outputStock();
                  break;
              case 2:
                  s1.getSupplyList();
                  break;
              case 3:
                  s1.withdrawSupplies();
                  break;
              case 4:
                  s1.depositSupplies();
                  break;
              case 5:
                  s1.addSupply();
                  break;
              default :
                  cout<<"Invalid Entry"<<endl;
                  break;
          }
      }
      else
      {
          cout<<"Invalid Entry"<<endl;
      }
      return 0;
    }
}
