// Input_Grade_File.cpp -- this program reads a file to determine a students grade
// CSIS 111-001
// Public domain source code used with my instructor's permission

// include statement
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {

	// print out name in accordance with lab submission instructions
	cout << "Sean DeBarr -- Lab 3" << endl << endl;

	// declare local variables
	double studentScore, totalPoints, gradePercentage, finalScore;
	ifstream fileIn;
	string gradeFeedback;

	// open file
	fileIn.open("tempdata.dat");

	// read and store file contents
	while(fileIn >> studentScore >> totalPoints) {

		// round final student score using ceil
		finalScore = ceil(studentScore);

		// calculate grade percentage 
		gradePercentage = (finalScore / totalPoints) * 100;

		// determines what feedback to give to student
		if(gradePercentage > 90) {
			gradeFeedback = "Excellent";
		}
		else if(gradePercentage > 80) {
			gradeFeedback = "Well Done";
		}
		else if(gradePercentage > 70) {
			gradeFeedback = "Good";
		}
		else if(gradePercentage >= 60) {
			gradeFeedback = "Needs Improvement";
		}
		else {
			gradeFeedback = "Fail";
		}

		// display results with precision of 5 for gradePercentage
		cout << "With a score of " << studentScore << " points out of " << totalPoints << "." << endl;
		cout << "The student got a " << setprecision(5) << gradePercentage << "%." << endl;
		cout << gradeFeedback << endl << endl;
	}

	// pause system for user to see results
	system("pause");
	return 0;
}