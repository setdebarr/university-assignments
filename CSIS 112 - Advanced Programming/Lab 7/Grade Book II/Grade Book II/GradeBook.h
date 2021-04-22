#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "StudentGradeInfo.h"

class GradeBook {
public:
	GradeBook();								// constructor to creating a new gradebook
	~GradeBook();								// default destructor
	void addStudent();							// adds a student to the student vector
	void printGradeBook();						// displays all info for each student in the student vector
	void sortRecords();							// sorts students by ID number
	int getNumOfStudents() const;				// returns the number of students in students vector

	std::string getSInput(std::string prompt);	// gets sentence from user
	int getIInput(std::string, int);			// gets a single positive integer from user	
	double getDInput(std::string, double);		// gets positive double value from user

private:
	std::vector<StudentGradeInfo> students;		// stores up to 3 student objects
	const std::string POS_INT = "0123456789";	// array of allowed charaters for integers
	const std::string DOUBLE = ".0123456789";	// array of allowed charaters for doubles
};