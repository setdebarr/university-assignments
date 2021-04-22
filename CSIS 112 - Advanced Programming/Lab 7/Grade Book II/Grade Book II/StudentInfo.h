#pragma once

#include <iostream>
#include <string>

class StudentInfo {
public:
	StudentInfo(int);					// default constructor
	~StudentInfo();						// default destructor

	void setStudentName(std::string);	// sets the student name
	void setStudentID(int);				// sets the student id
	void setMajor(std::string);			// sets the student major

	std::string getStudentName() const;	// returns the student name
	int getStudentID() const;			// returns the student id
	std::string getMajor() const;		// returns the student major

private:
	std::string studentName;			// stores the student name
	int studentID;						// stores the studnent id
	std::string major;					// stores the student major
};