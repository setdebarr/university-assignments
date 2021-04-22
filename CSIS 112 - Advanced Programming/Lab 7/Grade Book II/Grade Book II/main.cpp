//main.cpp -- creates a gradebook and prompts user to either add to or list out gradebook contents
//CSIS 112-02
//<Sources if necessary>

/*
	Just want to appologize in advance for this somewhat convoluted code
*/

//Include statements
#include <iostream>
#include <string>
#include <ctype.h>

#include "GradeBook.h"

//Global declarations: Constants and type definitions only -- NO variables

//Function prototypes

int main() {
	//In cout statement below substitute your name and lab number
	std::cout << "Sean DeBarr -- Lab 7" << std::endl << std::endl;

	//Variable declarations
	char choice;		// stores the users choice as a char

	//Program logic

	GradeBook g;		// create new gradebook object to store student records

	//presents a menu to the user until they choose to quit
	do {
		std::cout << std::endl;
		std::cout << "Enter a selection:" << std::endl;
		std::cout << "A - Add student record" << std::endl;
		std::cout << "L - List all student records" << std::endl;
		std::cout << "Q - Quit" << std::endl << std::endl;

		std::cout << ">> ";
		std::cin >> choice;		// gets the choice from user
		std::cout << std::endl;
		std::cin.ignore();

		switch(toupper(choice)) {
			case 'A':
			{
				// trys to create student, if unable display why
				try {
					g.addStudent();
				}
				catch(const char *msg) {
					std::cout << msg << std::endl;
				}
				catch(const std::exception & e) {
					std::cout << e.what() << std::endl;
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
					g.printGradeBook();
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
