#include "functions.h"

bool is_valid_range(int a, int b) {
  if ( (a > b) || (a <= 0) || (b > 10000) ) {
    return false;
    
  } else {
    return true;
    
  }
}

int count_digit_occurrences(int n, int digit) {
  int numberCopy = n;
  int currentDigit;
  int counter = 0;
	
  while (numberCopy > 0) {
    currentDigit = numberCopy % 10;
    
    if (currentDigit == digit) {
      counter += 1;
    }
    numberCopy = (numberCopy - currentDigit)/10;
  }
  return counter;
}

bool has_repeated_digits(int number) {
  bool validity = false;
  int currentCount;
  
  for (int i = 0; i < 10; i++) {
    currentCount = count_digit_occurrences(number, i);
    
    if (currentCount > 1) {
      validity = true;
    }
  }
  
  return validity;
  
}

int count_valid_numbers(int a, int b) {
  int counter = 0;
  
  for (int i = a; i <= b; i++) {
    if (!has_repeated_digits(i)) {
      counter += 1;
	}
  }
  
  return counter;
}