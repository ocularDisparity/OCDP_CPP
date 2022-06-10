#include <iostream>
using std::cin; using std::cout; using std::endl;

/*	README:
 *	This program will calculate the minimum amount of coins necessary to fulfill the amount provided by the user.
 *	For example, $2.16 will result in 8 quarters, 1 dime, 1 nickel, and 1 penny, for a grand total of 11 coins.
 */

int main() {
	// variable declarations
	int dollars = 0, cents = 0;
	
	int pennies = 0, nickels = 0, dimes = 0, quarters = 0;
	
	int totalCents = 0;
	
	// user input
	cout << "Enter dollars: ";
	cin >> dollars;
	cout << "Enter cents: ";
	cin >> cents;
	
	// calculation
	totalCents = (dollars * 100) + cents;
	
	if (totalCents >= 25) {
		quarters = totalCents / 25;
		totalCents = totalCents % 25;
	}
	
	if (totalCents >= 10) {
		dimes = totalCents / 10;
		totalCents = totalCents % 10;
	}
	
	if (totalCents >= 5) {
		nickels = totalCents / 5;
		totalCents = totalCents % 5;
	}
	
	if (totalCents >= 1) {
		pennies = totalCents;
	}
	
	// outputs
	cout << "Pennies: " << pennies << endl;
	cout << "Nickels: " << nickels << endl;
	cout << "Dimes: " << dimes << endl;
	cout << "Quarters: " << quarters << endl << endl;
	
	cout << "Total coins used: " << pennies + nickels + dimes + quarters << endl;
	
	return 0;
}