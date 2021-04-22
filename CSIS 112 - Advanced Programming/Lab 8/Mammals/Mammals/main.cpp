//main.cpp -- stores user specified dynamically created mammal object in array and displays there contents to user
//CSIS 112-002
//<Sources if necessary>


//Include statements
#include <iostream>
#include <string>

#include "Mammal.h"
#include "Cat.h"
#include "Dog.h"
#include "Horse.h"
#include "Pig.h"

//Global declarations: Constants and type definitions only -- NO variables

//Function prototypes

int main() {
	//In cout statement below substitute your name and lab number
	std::cout << "Sean DeBarr -- Lab 8" << std::endl << std::endl;

	//Variable declarations
	std::string temp;	// stores the mammal name temporarily
	int counter{0};		// stores the current iteration of the loop
	int choice{0};		// stores user menu choice
	Mammal *m[5];		// stores pointers of user specified derived classes
	
	//Program logic

	// sets seed for random number generator
	srand(100);

	do {
		// displays menu
		std::cout << std::endl;
		std::cout << "Please select a mammal to add:\n";
		std::cout << "1 - Dog\n";
		std::cout << "2 - Cat\n";
		std::cout << "3 - Horse\n";
		std::cout << "4 - Pig\n";

		std::cout << "\n>> ";
		std::cin >> choice;
		std::cin.get();

		switch(choice) {
			// creates new Dog object and stores it in array
			case 1:
			{
				std::cout << "Please enter name of Dog: ";
				getline(std::cin, temp);
				std::cout << std::endl;
				m[counter] = new Dog((1 + rand() % 150), temp);
				break;
			}
			// creates new Cat object and stores it in array
			case 2:
			{
				std::cout << "Please enter name of Cat: ";
				getline(std::cin, temp);
				std::cout << std::endl;
				m[counter] = new Cat((1 + rand() % 150), temp);
				break;
			}
			// creates new Horse object and stores it in array
			case 3:
			{
				std::cout << "Please enter name of Horse: ";
				getline(std::cin, temp);
				std::cout << std::endl;
				m[counter] = new Horse((1 + rand() % 150), temp);
				break;
			}
			// creates new Pig object and stores it in array
			case 4:
			{
				std::cout << "Please enter name of Pig: ";
				getline(std::cin, temp);
				std::cout << std::endl;
				m[counter] = new Pig((1 + rand() % 150), temp);
				break;
			}
			// if invalid choice was detected restart loop
			default:
				std::cout << "You have not entered a valid choice.  Please try again." << std::endl;
				break;
		}
		// adds 1 to loop counter
		++counter;
	} while(counter < 5);

	// make each mammal speak and display name and weight
	for(size_t i = 0; i < (sizeof(m) / sizeof(m[1])); ++i) {
		std::cout << std::endl;
		m[i]->Speak();
		std::cout << "Name: " << m[i]->getName() << std::endl;
		std::cout << "Weight: " << m[i]->getWeight() << std::endl;
	}

	std::cout << std::endl;

	// cleanup the HEAP!
	for(size_t i = 0; i < (sizeof(m) / sizeof(m[1])); ++i) {
		delete m[i];
		m[i] = NULL;
	}

	//Closing program statements
	std::cout << std::endl;
	system("pause");
	return 0;
}

//Function definitions