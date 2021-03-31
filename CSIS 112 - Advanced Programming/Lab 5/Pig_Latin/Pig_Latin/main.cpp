//main.cpp -- this program promts user for a sentence then translates that sentence into pig latin with pointer arithmetic
//CSIS 112-<Section Number>
//<Sources if necessary>

//Include statements
#include <iostream>

//Global declarations: Constants and type definitions only -- NO variables
const char ENDING[3] = {"ay"};		// characters to add at the end of translated word
const int SIZE_OF_ARRAY = {200};	// max size of user entered char array

//Function prototypes
void printLatinWord(char*);
void getInput(char[], int);

int main() {
	//In cout statement below substitute your name and lab number
	std::cout << "Sean DeBarr -- Lab 5" << std::endl << std::endl;

	//Variable declarations
	char input[200];		// array to store user entered sentence
	char *tPtr = NULL;		// pointer to hold token
	char *n_tPtr = NULL;	// pointer to hold next token
	bool done = false;		// check value for if user is done with program
	char choice = 'Y';		// stores whether the user want to continue program


	//Program logic

	while(!done) {
		if(toupper(choice) == 'Y') {
			// gets sentence to be translated from user 
			getInput(input, SIZE_OF_ARRAY);
			// gets the first token from the user entered char array
			tPtr = strtok_s(input, " ", &n_tPtr);
			// loops though char array until there are no more tokens left
			while(tPtr != NULL) {
				// translates word then gets the next token
				if(tPtr != NULL) {
					printLatinWord(tPtr);
					tPtr = strtok_s(NULL, " ", &n_tPtr);
				}
			}
		}
		// asks user if they want to run program again
		std::cout << std::endl << std::endl;
		std::cout << "Would you like to enter another sentence? (y/n)" << std::endl;
		std::cout << ">> ";
		std::cin.get(choice);
		std::cout << std::endl << std::endl;
		// makes sure user enters valid choice
		switch(toupper(choice)) {
			case 'Y':
			{
				std::cin.ignore();
				break;
			}
			case 'N':
			{
				done = true;
				break;
			}
			default:
			{
				std::cout << "Invalid choice. Please try again." << std::endl;
				std::cout << std::endl << std::endl;
				break;
			}

		}
	}
	//Closing program statements
	std::cout << "Thank you for using this program" << std::endl;
	std::cout << std::endl << std::endl;

	system("pause");
	return 0;
}

//Function definitions

// translates word into pig latin
void printLatinWord(char *tok) {
	// copy first character in token into temp char
	char first = *tok;
	// print out word by going to second element in pointer and adding the stored first character and "ay" to the end
	std::cout << ++tok << first << ENDING << " ";
}

// gets sentence to be translated from user
void getInput(char c[], int l) {
	std::cout << "Please enter sentence to translate: " << std::endl;
	std::cout << ">> ";
	std::cin.getline(c, l);
}