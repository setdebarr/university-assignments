#include "Student.h"

// constructor to creating a student record
Student::Student(std::string s) {
	setName(s);
}
// adds up to 5 grades for student
void Student::addGrades() {
	int n;
	double temp;
	std::cout << "How may grades would you like to enter (up to 5): ";
	std::cin >> n;
	// makes sure user enters a number between 1-5
	while((n > 5) | (n <= 0)) {
		std::cout << "Number of grades must be between 1-5. Please try again." << std::endl;
		std::cout << "How may grades would you like to enter (up to 5): ";
		std::cin >> n;
	}
	std::cout << "Please enter the " << n << " grades separated by a space: ";
	// adds grades to vector
	for(size_t i = 0; i < n; ++i) {
		std::cin >> temp;
		grades.push_back(temp);
	}
}
// displays all grades of student
void Student::displayStudentGrades() {
	std::cout << getName() << "'s grades are: ";
	for(double e : grades) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
}
// sets the name of the student
void Student::setName(std::string s) {
	name = s;
}
// returns the name of the student
std::string Student::getName() const {
	return name;
}
