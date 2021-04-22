// planet_enums.cpp -- asks the user to enter his or her weight and the name of a planet then calculates the user's weight as if he or she were on the chosen planet. 
// CSIS 111-001
// Public domain source code used with my instructor's permission

// include statements
#include <iostream>
#include <string>
#include <locale>
#include "resource.h"

using namespace std;

//default must be last, directly after none
enum Planets { MERCURY, VENUS, EARTH, MOON, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO, DEFAULT, NONE };
const string PLANETSTRINGS[] = {"MERCURY","VENUS", "EARTH", "MOON", "MARS", "JUPITER", "SATURN", "URANUS", "NEPTUNE", "PLUTO", "","NONE"};

// function prototypes
Planets stp(string);
double getInput();

// program starts here
int main() {

	// print out name in accordance with lab submission instructions
	cout << "Sean DeBarr -- Lab 5" << endl << endl;

	// display opening message
	cout << "************************************" << endl;
	cout << "      Welcome to Planet Enums" << endl;
	cout << "************************************" << endl;

	// local variable declarations
	Planets planet;
	string planetName = "";
	double factor;
	double weight = getInput();

	// gets a valid planet name from user
	for(planet = DEFAULT; planet >= DEFAULT; planet = stp(planetName)) {

		// check to make sure planet name is valid
		if(planet != DEFAULT) {
			cout << "\nINVALID. " << planetName << " is not a planet.\n";
			cout << "Valid planets are: ";
			for(int i = MERCURY; i <= PLUTO; i++) {
				cout << PLANETSTRINGS[i];
				if(i != PLUTO) {
					cout << ", ";
				}
			}
			cout << endl;
		}
		cout << "\nPlease enter the name of a planet: ";
		getline(cin, planetName);

		// uppercases the string
		std::use_facet<std::ctype<char>>(std::locale()).toupper(&planetName[0], &planetName[0] + planetName.size());
	}

	// set gravity factor based on planet selected
	switch(planet) {
		case MERCURY:
			factor = 0.4155;
			break;
		case VENUS:
			factor = 1.8975;
			break;
		case EARTH:
			factor = 1.0;
			break;
		case MOON:
			factor = 0.166;
			break;
		case MARS:
			factor = 0.3507;
			break;
		case JUPITER:
			factor = 2.5374;
			break;
		case SATURN:
			factor = 1.0677;
			break;
		case URANUS:
			factor = 0.8947;
			break;
		case NEPTUNE:
			factor = 1.1794;
			break;
		case PLUTO:
			factor = 0.0899;
			break;
		default:
			abort();
	}

	// display weight on selected planet
	weight = weight * factor;
	cout << "\nYour weight on " << planetName << " is: " << weight << endl << endl;

	cout << "*** Thank you for using Planet Enums ***" << endl << endl;

	// pause system for user to see results
	cout << "Press enter to continue...";
	cin.get();
	return 0;
}

// takes a string and returns the Planet enum
Planets stp(string a) {

	int i;
	for(i = MERCURY; i < NONE - MERCURY && PLANETSTRINGS[i] != a; i++);
	return (Planets)i;
}

// gets a positive numerical value from user
double getInput() {

	// declare local variables
	string userInput;
	double number;
	bool valid = false;

	// asks user for input and continues to ask till valid
	while(!valid) {

		// asks user for a positive integer
		cout << "\nPlease enter your weight: ";
		getline(cin, userInput);

		// sanitizes user input
		try {
			number = stod(userInput);
			if(number >= 0) {
				valid = true;
			} else {
				cout << "\nWeight must be positive. Try again.\n\n";
				valid = false;
			}
		} catch(const std::exception&) {
			cout << "\nInvalid input detected.\n\n";
		}
	}

	// returns the positive integer
	return number;
}