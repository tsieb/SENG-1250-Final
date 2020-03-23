#include "Hospital.h"
#include <fstream>
#include <string>
using namespace std;

class Supplier : public Hospital
{
  public:
    fstream supplies;
    int id, stock, in, amount;
    std::string supply;

    void getSupplyList();
    void depositSupplies();
    void withdrawSupplies()
    int returnStock();
};
