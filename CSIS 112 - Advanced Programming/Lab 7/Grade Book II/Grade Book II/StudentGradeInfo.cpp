#include "StudentGradeInfo.h"

// default constructor
StudentGradeInfo::StudentGradeInfo(int studentID):StudentInfo(studentID) {}

// default destructor
StudentGradeInfo::~StudentGradeInfo() {}

// add student grade to vector
void StudentGradeInfo::addGrade(double g) {
	grades.push_back(g);
}

// display all grades in vector
void StudentGradeInfo::displayGrades() const {
	std::cout << "Grades: ";
	for(double e : grades) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

// calculates grade average
double StudentGradeInfo::calcAverage() const {
	double temp{0};
	for(double g : grades) {
		temp += g;
	}
	return temp / grades.size();
}

// overloaded function for sort function
bool StudentGradeInfo::operator<(StudentGradeInfo &s) {
	bool returnVal{false};
	if(this->getStudentID() < s.getStudentID()) {
		returnVal = true;
	}
	return returnVal;
}

// overloaded function to compare to student objects by id
bool StudentGradeInfo::operator==(StudentGradeInfo &s) {
	bool returnVal{false};
	if(this->getStudentID() == s.getStudentID()) {
		returnVal = true;
	}
	return returnVal;
}

// overloaded function to display all student info
std::ostream &operator<<(std::ostream &output, StudentGradeInfo &s) {
	output << "Student ID: " << s.getStudentID() << std::endl;
	output << "Student Name: " << s.getStudentName() << std::endl;
	output << "Student Major: " << s.getMajor() << std::endl;
	s.displayGrades();
	output << "Student Grade Average: " << s.calcAverage() << std::endl << std::endl;
	return output;
}
