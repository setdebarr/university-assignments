// Temps_Output.cpp -- this program takes in user input and outputs them to file
// then displays average to console
// CSIS 111-001
// Public domain source code used with my instructor's permission

// include statements
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// sets how many inputs you want
const int Num_Of_Inputs = 12;

// function declarations
bool checkInput (double);
double getInput (int);
double calcAverage (double[]);

// checks to see if the input temperature is realistic in fahrenheit
bool checkInput (double n) {
	if (n < 134 && n > -128) {
		return true;
	} else {
		return false;
	}
}

// gets a numerical value from user
double getInput (int n) {

	// declare local variables
	string temperature;
	double temp;
	bool valid = false;

	// asks user for input and continues to ask till valid
	while (!valid) {

		// asks user for a temperature value
		cout << "Please enter temperture number " << n << ": ";
		cin >> temperature;

		// sanitizes user input
		try {
			temp = stod (temperature);
			if (checkInput (temp)) {
				valid = true;
			} else {
				cout << "\nInput temperature is not realistic...\n";
				cout << "Please try again...\n\n";
				valid = false;
			}
		} catch (const std::exception&) {
			cout << "\nInvalid input detected...\n\n";
		}
	}

	// returns the tempurature value
	return temp;
}

// function for calculating the average of all inputed temperatures
double calcAverage (double temp[]) {
	// declare local variables
	double sum = 0, avg;

	// loop through the temp array and sum up all elements
	for (int i = 0; i < Num_Of_Inputs; i++) {
		sum += temp[i];
	}

	// calculates average
	avg = sum / Num_Of_Inputs;

	// returns the average
	return avg;
}

// program starts here
int main () {

	// print out name in accordance with lab submission instructions
	cout << "Sean DeBarr -- Lab 3" << endl << endl;

	// declare array to store the specified number of temperatures
	double temperature[Num_Of_Inputs];

	// create tempdata.dat file for output
	ofstream outf ("tempdata.dat");

	// gets specified number of temperature inputs from user
	for (int i = 0; Num_Of_Inputs > i; i++) {
		temperature[i] = getInput (i + 1);

		// write temperature data to file
		outf << temperature[i] << "\t";

		// if i > 0 then compute difference
		if (i > 0) {
			double d = (temperature[i] - temperature[i - 1]);

			// write out difference to file
			outf << d;
		}
		outf << endl;
	}

	// displays average of temperatures
	cout << endl;
	cout << "The average temperature is: ";
	cout << calcAverage (temperature) << endl;
	outf.close ();
	cout << endl;

	// pause system for user to see results
	system ("pause");
	return 0;
}