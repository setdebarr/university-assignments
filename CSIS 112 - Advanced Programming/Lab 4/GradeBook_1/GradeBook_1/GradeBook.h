#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

class GradeBook {
public:
	GradeBook(std::string);					// constructor to creating a new gradebook
	void addStudent(std::string);			// adds a student to the student vector
	void displayGrades();					// displays the grades for each student in the student vector
	void setGradebookName(std::string);		// sets the gradebook name
	std::string getGradebookName() const;	// returns the gradebook name
	int getNumOfStudents() const;			// returns amount of students in student vector
private:
	std::string gradebookName;				// stores the gradebook name
	std::vector<Student> students;			// stores up to 3 student objects
};
