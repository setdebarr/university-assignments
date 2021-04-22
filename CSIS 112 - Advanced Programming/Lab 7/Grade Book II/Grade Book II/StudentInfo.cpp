#include "StudentInfo.h"

// default constructor
StudentInfo::StudentInfo(int studentID) {
	this->setStudentID(studentID);
}

// default destructor
StudentInfo::~StudentInfo() {}

// sets the student name
void StudentInfo::setStudentName(std::string studentName) {
	this->studentName = studentName;
}

// sets the student id
void StudentInfo::setStudentID(int studentID) {
	this->studentID = studentID;
}

// sets the student major
void StudentInfo::setMajor(std::string major) {
	this->major = major;
}

// returns the student name
std::string StudentInfo::getStudentName()  const {
	return studentName;
}

// returns the student id
int StudentInfo::getStudentID()  const {
	return this->studentID;
}

// returns the student major
std::string StudentInfo::getMajor()  const {
	return this->major;
}