#include "GradeBook.h"

// constructor to creating a new gradebook
GradeBook::GradeBook() {}

// default destructor
GradeBook::~GradeBook() {}

// adds a student to the student vector
void GradeBook::addStudent() {
	int temp;
	bool validID{false};
	// check if more than 3 student exist before adding another student
	if(students.size() < 3) {
		// creates new StudentGradeInfo object
		StudentGradeInfo s(getIInput("Please enter student ID", INT_MAX));
		std::cout << std::endl;

		// if this is not the only student object, check to make sure the passed in ID does not already exist
		if(getNumOfStudents() >= 1) {
			while(!validID) {
				for(StudentGradeInfo x : students) {
					if(s == x) {
						std::cout << "ID already exists. Please enter a new one.\n";
						s.setStudentID(getIInput("Please enter student ID", INT_MAX));
						std::cout << std::endl;
					}
					else {
						validID = true;
					}
				}
			}
		}

		// sets student name
		s.setStudentName(getSInput("Please enter Student name:"));
		std::cout << std::endl;

		// sets student major
		s.setMajor(getSInput("Please enter Student major:"));
		std::cout << std::endl;

		// promts user for number of grades to enter up to 5
		temp = getIInput("How many grades would you like to enter?", 5);
		for(int i = 0; i < temp; ++i) {
			std::string y = "Please enter Grade ";
			y.append(std::to_string(i + 1));
			s.addGrade(getDInput(y, 100));
		}

		std::cout << std::endl;

		// adds StudentGradeInfo object to vector
		students.push_back(s);
	}
	else {
		throw "Unable to add more students. Maximum of 3 reached.";
	}
}

// displays all info for each student in the student vector
void GradeBook::printGradeBook() {
	// sorts students by id
	sortRecords();
	// loops through student vector and displays all info for each
	for(StudentGradeInfo s : students) {
		std::cout << s;
	}
}

// sorts the student objects in vector by id
void GradeBook::sortRecords() {
	std::sort(students.begin(), students.end());
}

// returns the number of students in students vector
int GradeBook::getNumOfStudents() const {
	return students.size();
}

// gets sentence from user
std::string GradeBook::getSInput(std::string prompt) {
	std::string temp;
	std::cout << prompt << std::endl;
	std::cout << ">> ";
	std::getline(std::cin, temp);
	return temp;
}

// gets a single positive integer from user								
int GradeBook::getIInput(std::string prompt, int maxVal) {

	std::string temp;					// local string variable to temporarily store user input
	bool valid = false;					// check for if user entered vaild input
	int value;

	std::cout << prompt << std::endl;	// displays the passed in prompt
	std::cout << ">> ";

	getline(std::cin, temp);			// gets input from user

	// checks if the user entered allowed characters
	while(!valid) {
		if((temp.find_first_not_of(POS_INT) != std::string::npos)) {
			std::cout << "You must enter an integer, and that integer must be positive.  Please try again. " << std::endl;
			std::cout << ">> ";
			getline(std::cin, temp);
		}
		else {
			// trys to convert to integer, if error occurs it throws an exception
			try {
				value = std::stoi(temp);
				if(value > maxVal || value < 0) {
					throw "Integer must not be greater than ";
				}
				else {
					valid = true;
				}
			}
			catch(const char *msg) {
				std::cout << msg << maxVal << std::endl;
				std::cout << "Please try again." << std::endl;
				std::cout << ">> ";
				getline(std::cin, temp);
			}
			catch(const std::exception & e) {
				std::cout << e.what() << std::endl;
				std::cout << "Please try again." << std::endl;
				std::cout << ">> ";
				getline(std::cin, temp);
			}
		}
	}
	return value;
}

// gets positive double value from user
double GradeBook::getDInput(std::string prompt, double maxVal) {
	std::string temp;					// local string variable to temporarily store user input
	bool valid = false;					// check for if user entered vaild input
	double value;

	std::cout << prompt << std::endl;	// displays the passed in prompt
	std::cout << ">> ";

	getline(std::cin, temp);			// gets input from user

	// checks if the user entered allowed characters
	while(!valid) {
		if((temp.find_first_not_of(DOUBLE) != std::string::npos)) {
			std::cout << "You must enter an double, and that double must be positive.  Please try again. " << std::endl;
			std::cout << ">> ";
			getline(std::cin, temp);
		}
		else {
			// trys to convert to integer, if error occurs it throws an exception
			try {
				value = std::stod(temp);
				if(value > maxVal || value < 0) {
					throw "double must not be greater than ";
				}
				else {
					valid = true;
				}
			}
			catch(const char *msg) {
				std::cout << msg << maxVal << std::endl;
				std::cout << "Please try again." << std::endl;
				std::cout << ">> ";
				getline(std::cin, temp);
			}
			catch(const std::exception & e) {
				std::cout << e.what() << std::endl;
				std::cout << "Please try again." << std::endl;
				std::cout << ">> ";
				getline(std::cin, temp);
			}
		}
	}
	return value;
}