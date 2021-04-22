//main.cpp -- splices two integer arrays together, and then copys the elements of both arrays into a new array 
//CSIS 112-<Section Number>
//<Sources if necessary>


//Include statements
#include <iostream>
#include <string>

//Global declarations: Constants and type definitions only -- NO variables

//Function prototypes
int *splice(int[], int, int[], int, int);
void getPosInt(int&);
void fillArrayWithRandInt(int[], int, bool = true);
void displayArray(int[], int);

int main() {
	//In cout statement below substitute your name and lab number
	std::cout << "Sean DeBarr -- Lab 6" << std::endl << std::endl;

	//Variable declarations
	int array1Len;		// store user defined lenght for array1
	int array2Len;		// store user defined lenght for array2
	int splicePosition;	// store user defined splice position

	//Program logic

	// get size of integer arrays from user
	std::cout << "Please enter size of first array: ";
	getPosInt(array1Len);
	std::cout << "Please enter size of second array: ";
	getPosInt(array2Len);

	// declare the two arrays on heap with user defined size
	int *array1{new int[array1Len]};
	int *array2{new int[array2Len]};

	// ask user for position to splice array1
	std::cout << "How many elements from Array 1 would you like to splice before Array 2: ";
	getPosInt(splicePosition);

	// initialize random number generator with seed 100
	srand(100);

	// fill array1 with random numbers between positive 1-100
	fillArrayWithRandInt(array1, array1Len);

	// fill array2 with random numbers between negative 1-100 
	// went with negative numbers to distinguish between the two arrays
	fillArrayWithRandInt(array2, array2Len, false);

	// displays the contents of array1
	std::cout << std::endl << std::endl;
	std::cout << "Array 1:";
	displayArray(array1, array1Len);

	// displays the contents of array2
	std::cout << std::endl << std::endl;
	std::cout << "Array 2:";
	displayArray(array2, array2Len);

	// splice the arrays together
	int *splicedArray = splice(array1, array1Len, array2, array2Len, splicePosition);

	// display the contents of final spliced array
	std::cout << std::endl << std::endl;
	std::cout << "Spliced Array:";
	displayArray(splicedArray, array1Len + array2Len);

	// clean up the heap
	delete[] array1;
	delete[] array2;
	delete[] splicedArray;

	//Closing program statements
	std::cout << std::endl << std::endl;
	system("pause");
	return 0;
}

//Function definitions

// splices an array inbetween another at specified position 
int *splice(int array1[], int array1Len, int array2[], int array2Len, int splicePosition) {
	int *combinedArray{new int[array1Len + array2Len]};	// create new array big enough to hold all elements from both input arrays
	int array1Position{0};								// keeps track of current position in first array
	int arrayPosition{0};								// keeps track of current position in combinedArray

	// adds each element of first array into combinedArray up to splice position
	for(size_t i = 0; i < splicePosition; ++i) {
		combinedArray[i] = array1[i];
		array1Position += 1;
	}

	// sets current combinedArray positon to last postion in array1 
	arrayPosition = array1Position;

	// adds the entire array2 to combinedArray
	for(size_t i = 0; i < array2Len; ++i) {
		combinedArray[arrayPosition] = array2[i];
		arrayPosition += 1;
	}
	// adds the remaining elements of array1 to combinedArray 
	for(size_t i = array1Position; i < array1Len; ++i) {
		combinedArray[arrayPosition] = array1[i];
		arrayPosition += 1;
	}

	// returns the spliced array
	return combinedArray;
}

// gets positive integer from user
void getPosInt(int &value) {
	const std::string ALLOWED_CHARACTERS = "0123456789";	// character array of allowed user input

	std::string temp;				// local string variable to temporarily store user input
	bool valid = false;				// check for if user entered vaild input

	getline(std::cin, temp);		// gets input from user

	// checks if the user entered allowed characters
	while(!valid) {
		if((temp.find_first_not_of(ALLOWED_CHARACTERS) != std::string::npos) | temp == "0") {
			std::cout << "You must enter an integer, and that integer must be positive and not 0.  Please try again. " << std::endl;
			std::cout << ">> ";
			getline(std::cin, temp);
		}
		else {
			// trys to convert to integer, if the integer is too big stoi throws std::out_of_range exception
			try {
				value = std::stoi(temp);
				valid = true;
			}
			catch(const std::out_of_range&) {
				std::cout << "That integer was too big.  Please try again." << std::endl;
				std::cout << ">> ";
				getline(std::cin, temp);
			}

		}
	}
}

// fill array with random numbers between positive or negative 1-100 
void fillArrayWithRandInt(int array[], int arrayLen, bool postitive) {
	if(postitive) {
		for(size_t i = 0; i < arrayLen; ++i) {
			array[i] = (1 + rand() % 100);
		}
	}
	else {
		for(size_t i = 0; i < arrayLen; ++i) {
			array[i] = -(1 + rand() % 100);
		}
	}
}

// displays the contents of array
void displayArray(int array[], int arrayLen) {
	for(size_t i = 0; i < arrayLen; ++i) {
		// this makes sure only 10 elements are displayed per row
		if((i % 10) == 0) {
			std::cout << std::endl << array[i] << " ";
		}
		else {
			std::cout << array[i] << " ";
		}
	}
}
