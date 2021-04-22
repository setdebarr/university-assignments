#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "StudentInfo.h"

class StudentGradeInfo: public StudentInfo {
public:
	friend std::ostream &operator<<(std::ostream &, StudentGradeInfo &);	// overloaded function to display all student info
	StudentGradeInfo(int);					// default constructor
	~StudentGradeInfo();					// default destructor
	void addGrade(double);					// add student grade to vector
	void displayGrades() const;				// display all grades in vector
	bool operator<(StudentGradeInfo &);		// overloaded function for sort function
	bool operator==(StudentGradeInfo &);	// overloaded function to compare to student objects by id

private:
	std::vector<double> grades;				// vector to store student grades
	double calcAverage() const;				// calculates grade average
};