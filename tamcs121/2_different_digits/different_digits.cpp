#include <iostream>
#include "functions.h"
using std::cout; using std::cin; using std::endl;

int main() {
  // Variable declaration
  int a;
  int b;
  
  int validCounter;
  
  // User input
  cout << "Enter numbers 0 < a <= b <= 10000: ";
  cin >> a;
  cout << " ";
  cin >> b;
  cout << endl;
  
  // Check for invalid inputs
  if ( !is_valid_range(a, b) ) {
    cout << "Invalid input" << endl;
	
    return -1;
  }

  // Run functions
  validCounter = count_valid_numbers(a, b);
  
  // Output
  cout << "There are " << validCounter << 
  " valid numbers between " << a << " and " << b << endl;
  
  return 0;
}