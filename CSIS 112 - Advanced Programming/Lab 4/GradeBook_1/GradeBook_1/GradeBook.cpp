#include "GradeBook.h"

// constructor to creating a new gradebook
GradeBook::GradeBook(std::string n) {
	setGradebookName(n);
}
// adds a student to the student vector
void GradeBook::addStudent(std::string n) {
	// check if more than 3 student exist before adding another student
	if(students.size() < 3) {
		Student s(n);
		s.addGrades();
		students.push_back(s);
	}
	else {
		std::cout << "Unable to add more students. Maximum of 3 reached." << std::endl;
	}
}
// displays the grades for each student in the student vector
void GradeBook::displayGrades() {
	std::cout << getGradebookName() << ":" << std::endl;
	// loops through student vector and displays the grades for each
	for(Student s : students) {
		s.displayStudentGrades();
	}
}
// sets the gradebook name
void GradeBook::setGradebookName(std::string s) {
	gradebookName = s;
}
// returns the gradebook name
std::string GradeBook::getGradebookName() const {
	return gradebookName;
}
// returns amount of students in student vector
int GradeBook::getNumOfStudents() const {
	return students.size();
}
