#include "Supplier.h"
#include "Hospital.h"
#include <string>
#include <fstream>
using namespace std;

Supplier::getSupplyList()
{
  supplies.open("Supplies.dat", ios::in | ios::binary);
  while(getline(supplies, supply))
  {
    supplies>>id>>supply>>stock;
    cout<<supply<<" "
  }
}

Supplier::depositSupplies()
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

Supplier::withdrawSupplies()
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

Supplier::outputStock()
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
