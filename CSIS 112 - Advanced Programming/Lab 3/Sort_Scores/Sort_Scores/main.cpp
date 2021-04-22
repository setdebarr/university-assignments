// main.cpp -- this program reads scores from file and displays the sorted scores and average to console
// CSIS 112-002
// <Sources if necessary>


// Include statements
#include <iostream>
#include <fstream>
#include <string>

#include "Scores.h"


// Global declarations: Constants and type definitions only -- NO variables
const std::string ALLOWED_CHARACTERS_F = "-.0123456789";	// allowed characters for floats
const std::string ALLOWED_CHARACTERS_I = "-0123456789";		// allowed characters for ints

// Function prototypes
void openFile(std::ifstream&);
bool getLineFromFile(std::ifstream&, float&);
bool getLineFromFile(std::ifstream&, int&);

int main() {
	//In cout statement below substitute your name and lab number
	std::cout << "Sean DeBarr -- Lab 3" << std::endl << std::endl;

	//Variable declarations
	std::ifstream input;	// stores the file
	int numOfScores;		// stores the number of scores from first line in file
	float score;			// stores the score to be sent to score class
	bool validData;			// check for if non-numeric data is found in file 
	float average;			// stores the average
	Scores s;

	// Program logic

	// opens file user specifies
	openFile(input);
	// gets the number of score in file from first line
	validData = getLineFromFile(input, numOfScores);
	// if numOfScores is valid then start adding scores to array
	if(validData) {
		// adds the specified amount of scores to the array until complete or invalid score is detected
		for(size_t i = 1; (i < (numOfScores + 1)) & validData; ++i) {
			validData = getLineFromFile(input, score);
			if(validData) {
				validData = s.addScores(score);
			}
		}
		if(validData) {
			// sorts the array
			s.sort();
			// displays the array to console
			s.displayScores();
			// calculates average of scores and displays it
			average = s.calcAverage();
			std::cout << "The average of the scores is: " << average << std::endl;
			std::cout << std::endl;
		}
	}
	// closes the file
	input.close();

	//Closing program statements
	system("pause");
	return 0;
}

// Function definitions

// opens file
void openFile(std::ifstream &input) {

	std::string input_filename;	// string to store user defined file path

	// asks user for file path 
	while(true) {

		std::cout << "\nPlease input file location: ";
		getline(std::cin, input_filename);

		// open input file
		input.open(input_filename.c_str());

		// if file not found throw error and ask again
		if(!input) {
			std::cout << "\nInvaild filename or location...";
			std::cout << "Please try again...\n\n";
		}
		else {
			break;
		}
	}
}

// gets the scores from file
bool getLineFromFile(std::ifstream &input, float &value) {
	std::string temp;			// local string variable to temporarily store input
	bool valid = false;			// check for if input in numeric

	getline(input, temp);		// gets line from file

	// checks if data in file is valid
	if((temp.find_first_not_of(ALLOWED_CHARACTERS_F) != std::string::npos)) {
		std::cout << std::endl << "Invalid data detected in file: " << temp << std::endl;
		valid = false;
	}
	else {
		// converts string to float
		try {
			value = std::stof(temp);
			valid = true;
		}
		// catches if the input cannot convert to float
		catch(const std::out_of_range&) {
			std::cout << std::endl << "Score was to large. Please fix file and restart program." << temp << std::endl;
			valid = false;
		}
	}
	return valid;
}

// gets the number of scores in file
bool getLineFromFile(std::ifstream &input, int &value) {
	std::string temp;			// local string variable to temporarily store input
	bool valid = false;			// check for if input in numeric

	getline(input, temp);		// gets line from file

	// checks if data in file is valid
	if((temp.find_first_not_of(ALLOWED_CHARACTERS_I) != std::string::npos)) {
		std::cout << "Invalid data detected in file: " << temp << std::endl;
		std::cout << std::endl << "Exiting program ..." << std::endl;
		valid = false;
	}
	else {
		// converts string to int
		try {
			value = std::stoi(temp);
			if(value < 0) {
				throw "The number of scores in file cannot be negative.";
			}
			valid = true;
		}
		// catches if number of scores is negative
		catch(const char* errorMsg) {
			std::cout << std::endl << errorMsg << std::endl;
			std::cout << "Please fix file and restart program." << std::endl;
			std::cout << std::endl << "Exiting program ..." << std::endl;
			valid = false;
		}
		// catches if the input cannot convert to int
		catch(const std::out_of_range&) {
			std::cout << "Number of scores was to large. Please fix file and restart program." << temp << std::endl;
			valid = false;
		}
	}
	return valid;
}
