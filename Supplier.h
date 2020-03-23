#include "Hospital.h"
#include <fstream>
using namespace std;

class Supplier : public Hospital
{
  public:
    void getSupplyList();
    void depositSupplies();
    void returnStock();
};
