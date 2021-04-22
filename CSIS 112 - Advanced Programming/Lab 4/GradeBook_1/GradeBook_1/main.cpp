//main.cpp -- creates a gradebook and prompts user to either add to or list out gradebook contents
//CSIS 112-02
//<Sources if necessary>


//Include statements
#include <iostream>
#include <string>
#include <ctype.h>

#include "GradeBook.h"

//Global declarations: Constants and type definitions only -- NO variables

//Function prototypes

int main() {
	//In cout statement below substitute your name and lab number
	std::cout << "Sean DeBarr -- Lab 4" << std::endl << std::endl;

	//Variable declarations
	char choice;		// stores the users choice as a char
	std::string name;	// temporary storage of gradebook name

	//Program logic

	// prompts the user for a name to name the gradebook and then sets it
	std::cout << "Please enter the name of the gradebook: ";
	std::getline(std::cin, name, '\n');
	GradeBook g(name);

	// presents a menu to the user until they choose to quit
	do {
		std::cout << std::endl << std::endl << std::endl;
		std::cout << "Enter a selection:" << std::endl;
		std::cout << "A - Add student record" << std::endl;
		std::cout << "L - List all student records" << std::endl;
		std::cout << "Q - Quit" << std::endl << std::endl;

		std::cout << ">> ";
		std::cin >> choice;		// gets the choice from user
		std::cout << std::endl;

		switch(toupper(choice)) {
			case 'A':
			{
				// checks if more students can be added and then if able to adds a student to the gradebook
				if(g.getNumOfStudents() == 3) {
					std::cout << "Unable to add more students. Maximum of 3 reached." << std::endl;
				}
				else {
					std::string n;
					std::cout << "Please enter Student name: ";
					std::cin.ignore();
					std::getline(std::cin, n, '\n');
					std::cout << std::endl;
					g.addStudent(n);
				}
				break;
			}
			// checks if a student record exits and then if so displays all student records in the gradebook
			case 'L':
			{
				if(g.getNumOfStudents() == 0) {
					std::cout << "There are no Students on record." << std::endl;
					std::cout << "Please add Student records first." << std::endl;
				}
				else {
					g.displayGrades();
				}
				break;
			}
			// condition to exit the loop
			case 'Q':
			{
				std::cout << std::endl << std::endl << "Thank you for using this program." << std::endl << std::endl;
				break;
			}
			default:
				std::cout << "You have not entered a valid choice.  Please try again." << std::endl;
				break;
		}

	} while(toupper(choice) != 'Q');

	//Closing program statements
	system("pause");
	return 0;
}

//Function definitions
