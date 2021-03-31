// main.cpp -- this program calculates the number of potential team arrangements
// CSIS 111-001
// Public domain source code used with my instructor's permission

// Preprocessor instructions
#include <iostream>
#include <math.h>

using namespace std;

// Calculates the factorial of a given number
double factorial(int n) {
	if(n > 1)
		return n * factorial(n - 1);
	else
		return 1;
}

int main() {

	// Declare constant variables of students and team size
	const int NUM_STUDENTS = 18;
	const int SIZE_TEAM = 3;

	// Calculates the number of different teams possible using n!/(r!*(n - r)!)
	double numOfPerms = (factorial(NUM_STUDENTS) / (factorial(SIZE_TEAM) * (factorial(NUM_STUDENTS - SIZE_TEAM))));

	// Print out name in accordance with lab submission instructions
	cout << "Sean DeBarr -- Lab 2" << endl << endl;

	// Statements to satisfy programming assignment
	cout << "The number of different " << SIZE_TEAM << " person teams possible with " << NUM_STUDENTS << " students is " << numOfPerms << "." << endl << endl;

	// Closing program statements
	system("pause");
	return 0;
}