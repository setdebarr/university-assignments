// main.cpp -- prompts user for rectangle dimensions until ctrlZ is entered
// CSIS 112-02
// <Sources if necessary>

// Include statements
#include <iostream>
#include <string>

#include "Rectangle.h"

// Global declarations: Constants and type definitions only -- NO variables
const std::string ALLOWED_CHARACTERS = ".0123456789";	// character array of allowed user input

// Function prototypes
bool EndOfInputStream(std::istream &);
void getInput(float&);

int main() {
	// In cout statement below substitute your name and lab number
	std::cout << "Sean DeBarr -- Lab 2" << std::endl << std::endl;

	// Variable declarations
	float num;
	Rectangle r;

	// Program logic

	// runs until user enters ctrlZ
	while(true) {
		std::cout << "Enter the Rectangle Length (Ctrl-Z to exit):  ";
		getInput(num);

		// break condition for if user entered ctrlZ
		if(num == -1) {
			break;
		}
		r.setLength(num);
		std::cout << "Enter the Rectangle Width (Ctrl-Z to exit):  ";
		getInput(num);

		// break condition for if user entered ctrlZ
		if(num == -1) {
			break;
		}
		r.setWidth(num);
		r.showData();
	}

	//Closing program statements
	std::cout << std::endl << "Press enter to exit...";
	std::cin.clear();
	std::cin.get();
	return 0;
}

//Function definitions

// checks if ctrlZ was entered
bool EndOfInputStream(std::istream &input) {
	bool endOfInput{false};
	if(input.eof()) {
		endOfInput = true;
	}
	return endOfInput;
}

// gets valid input from user
void getInput(float &value) {

	std::string temp;				// local string variable to temporarily store user input
	bool valid = false;				// check for if user entered vaild input

	getline(std::cin, temp);		// gets input from user

	// checks if user entered ctrlZ
	if(EndOfInputStream(std::cin)) {
		valid = true;
		value = -1;
	}

	// checks if the user entered allowed characters
	while(!valid) {
		if((temp.find_first_not_of(ALLOWED_CHARACTERS) != std::string::npos) | temp == "0") {
			std::cout << "You must enter an number, and that number must be positive and not 0.  Please try again. " << std::endl;
			std::cout << ">> ";
			getline(std::cin, temp);

			// checks if user entered ctrlZ
			if(EndOfInputStream(std::cin)) {
				valid = true;
				value = -1;
			}
		}
		else {
			// trys to convert to float, if the float is too big, stof throws std::out_of_range exception or unrealistic exception
			try {
				value = std::stof(temp);
				if(value > 1000000000000) {
					throw "That number was unrealistic.  Please enter a smaller number.";
					valid = false;
				}
				else {
					valid = true;
				}
			}
			// catches the unrealistic exception
			catch(const char* errorMsg) {
				std::cout << errorMsg << std::endl;
				std::cout << ">> ";
				getline(std::cin, temp);

				// checks if user entered ctrlZ
				if(EndOfInputStream(std::cin)) {
					valid = true;
					value = -1;
				}
			}
			// catches if the input cannot convert to float
			catch(const std::out_of_range&) {
				std::cout << "That number was too big.  Please try again." << std::endl;
				std::cout << ">> ";
				getline(std::cin, temp);

				// checks if user entered ctrlZ
				if(EndOfInputStream(std::cin)) {
					valid = true;
					value = -1;
				}
			}
		}
	}
}