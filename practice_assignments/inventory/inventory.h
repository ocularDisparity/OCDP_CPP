#ifndef INVENTORY.H
#define INVENTORY.H
#include <vector>
#include <string>

class item {
 private:
  string name;
  int itemNo;
  string description;
 
 public:
  //setters
  
  //getters
  string getname();
  int getnumber();
  string getdesc();
  
}

#endif
