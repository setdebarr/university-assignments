#pragma once

#include <iostream>
#include <string>
#include <vector>

class Student {
public:
	Student(std::string);			// constructor to creating a student record
	void addGrades();				// adds up to 5 grades for student
	void displayStudentGrades();	// displays all grades of student
	void setName(std::string);		// sets the name of the student
	std::string getName() const;	// returns the name of the student
private:
	std::string name;				// stores the name of the student
	std::vector<double> grades;		// stores up to 5 grades for student
};