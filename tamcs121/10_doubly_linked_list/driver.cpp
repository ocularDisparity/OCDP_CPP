#include <iostream>
#include "Node.h"
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
  DoublyLinkedList<int> something = DoublyLinkedList<int>(1);
  something.push_back(2);
  something.push_back(3);
  something.push_back(4);
  something.push_back(5);
  
  something.insert(3, 3);
  
  something.to_str();
  
  return 0;
}