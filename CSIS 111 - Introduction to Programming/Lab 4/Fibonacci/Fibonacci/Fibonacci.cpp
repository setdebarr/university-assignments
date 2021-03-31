// Fibonacci.cpp -- this program asks the user for a positive integer and returns the fibonacci sequence up to that number
// then displays average to console
// CSIS 111-001
// Public domain source code used with my instructor's permission

// include statements
#include <iostream>
#include <string>

using namespace std;

// function prototypes
int fib (int);
int getInput ();

// program starts here
int main () {

	// print out name in accordance with lab submission instructions
	cout << "Sean DeBarr -- Lab 4" << endl << endl;

	// display opening message
	cout << "************************************" << endl;
	cout << " Welcome to the Fibonacci Generator" << endl;
	cout << "************************************" << endl;

	// stores the number the user specifies
	int fibNum;

	// get integer from user
	fibNum = getInput ();
	cout << endl;

	// displays the fibonacci sequence up to that number
	cout << "The fibonacci sequence to " << fibNum << " is: ";
	for (int i = 0; i <= fibNum; i++)
		cout << fib (i) << " ";
	cout << endl << endl;
	cout << "********** end of program **********" << endl;

	// pause system for user to see results
	system ("pause");
	return 0;
}

// calculates fibonacci sequence number using recursion
int fib (int n) {
	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	return fib (n - 1) + fib (n - 2);
}

// gets a positive numerical value from user
int getInput () {

	// declare local variables
	string userInput;
	int number;
	bool valid = false;

	// asks user for input and continues to ask till valid
	while (!valid) {

		// asks user for a positive integer
		cout << "Enter a positive integer: ";
		cin >> userInput;

		// sanitizes user input
		try {
			number = stod (userInput);
			if (number >= 0) {
				valid = true;
			} else {
				cout << "\nInteger must be positive... Try again...\n\n";
				valid = false;
			}
		} catch (const std::exception&) {
			cout << "\nInvalid input detected...\n\n";
		}
	}

	// returns the positive integer
	return number;
}