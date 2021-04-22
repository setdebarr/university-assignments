//main.cpp -- This program prompts user for how many rooms and room dimensions then calculates how many tiles and boxes they will need
//CSIS 112-002
//<Sources if necessary>
// The use of an allowed character array mentioned by Nathaniel Hatfield

//Include statements
#include <iostream>
#include <string>

//Global declarations: Constants and type definitions only -- NO variables
const int BOX{20};										// stores how many tiles are in a box
const std::string ALLOWED_CHARACTERS = "0123456789";	// character array of allowed user input

//Function prototypes
void getData(int&, int&, int&, int&, int&, int&);
void getData(int&, int&, int&, int&);
void getInput(int&);
void getInput(int&, int&);
void convertData(int&, int&, int&, int&);
void calcTilesNeeded(int&, int&, int&, int&);
void reset(int&, int&, int&, int&);

int main() {
	//In cout statement below substitute your name and lab number
	std::cout << "Sean DeBarr -- Lab 1" << std::endl << std::endl;

	//Variable declarations
	int sizeOfTile{0};		// stores the user defined tile size
	int numOfRooms{0};		// stores the user defined number of rooms
	int roomLengthF{0};		// stores the user defined room length in feet
	int roomWidthF{0};		// stores the user defined room width in feet
	int roomLengthI{0};		// stores the user defined room lenght in inches
	int roomWidthI{0};		// stores the user defined room width in inches
	int totalTileCount{0};	// stores the total number of tiles
	int numOfBoxes{0};		// stores the number of boxes needed
	int tilesLeft{0};		// stores the ammount of leftover tile

	//Program logic
	getData(sizeOfTile, numOfRooms, roomLengthF, roomWidthF, roomLengthI, roomWidthI);
	convertData(roomLengthF, roomWidthF, roomLengthI, roomWidthI);
	calcTilesNeeded(sizeOfTile, roomLengthI, roomWidthI, totalTileCount);
	numOfRooms--;

	// if there is more than on room, gets data for remaining rooms
	while(numOfRooms != 0) {
		reset(roomLengthF, roomWidthF, roomLengthI, roomWidthI);
		getData(roomLengthF, roomWidthF, roomLengthI, roomWidthI);
		convertData(roomLengthF, roomWidthF, roomLengthI, roomWidthI);
		calcTilesNeeded(sizeOfTile, roomLengthI, roomWidthI, totalTileCount);
		numOfRooms--;
	}

	// calculates number of boxes needed and leftover tile amount
	numOfBoxes = ceil((float)totalTileCount / BOX);
	tilesLeft = BOX - (totalTileCount % BOX);


	// displays final tallys
	std::cout << "Total tiles required is " << totalTileCount << "." << std::endl;
	std::cout << "Number of boxes needed is " << numOfBoxes << "." << std::endl;
	std::cout << "There will be " << tilesLeft << " extra tiles." << std::endl;

	//Closing program statements
	std::cout << "\nPress enter to exit...";
	std::cin.ignore();
	std::cin.get();
	return 0;
}

//Function definitions

// gets initial data
void getData(int &sizeOfTile, int &numOfRooms, int &roomLengthF, int &roomWidthF, int &roomLengthI, int &roomWidthI) {
	std::cout << "Enter number of rooms: ";
	getInput(numOfRooms);

	std::cout << "Enter size of tile in inches: ";
	getInput(sizeOfTile);

	std::cout << "Enter room width (feet and inches, separated by a space): ";
	getInput(roomLengthF, roomLengthI);

	std::cout << "Enter room length (feet and inches, separated by a space): ";
	getInput(roomWidthF, roomWidthI);
}

// gets additional room data
void getData(int &roomLengthF, int &roomWidthF, int &roomLengthI, int &roomWidthI) {

	std::cout << "Enter room width (feet and inches, separated by a space): ";
	getInput(roomLengthF, roomLengthI);

	std::cout << "Enter room length (feet and inches, separated by a space): ";
	getInput(roomWidthF, roomWidthI);
}

// gets a single positive integer from user								
void getInput(int &value) {

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

// gets two positive integers from user
void getInput(int &value1, int &value2) {

	std::string temp1, temp2;	// local string variables to temporarily store user input
	bool valid = false;			// check for if user entered vaild input

	// gets input from user
	std::cin >> temp1;	// gets input from user
	std::cin >> temp2;	// gets input from user

	// checks if the user entered allowed characters
	while(!valid) {
		if(((temp1.find_first_not_of(ALLOWED_CHARACTERS) != std::string::npos) || (temp2.find_first_not_of(ALLOWED_CHARACTERS) != std::string::npos)) | (temp1 == "0" & temp2 == "0")) {
			std::cout << "You must enter two integers seperated by a space, and they must be non zero positive integers.  Please try again. " << std::endl;
			std::cout << ">> ";
			std::cin >> temp1;
			std::cin >> temp2;
		}
		else {
			// trys to convert to integer, if the integer is too big stoi throws std::out_of_range exception
			try {
				value1 = std::stoi(temp1);
				value2 = std::stoi(temp2);
				valid = true;
			}
			catch(const std::out_of_range&) {
				std::cout << "One of those integers was too big.  Please try again." << std::endl;
				std::cout << ">> ";
				std::cin >> temp1;
				std::cin >> temp2;
			}

		}
	}
}

// converts room dimensions to inches
void convertData(int &rLenghtF, int &rWidthF, int &rLenghtI, int &rWidthI) {
	rLenghtI = rLenghtI + (rLenghtF * 12);
	rWidthI = rWidthI + (rWidthF * 12);
}

// calculates number of tiles needed per room and updates total tile count
void calcTilesNeeded(int &tileS, int &rLenght, int &rWidth, int &tTile) {
	int numOfTile{0};		// stores the number of tiles needed for room

	numOfTile = ceil((float)rLenght / tileS) * ceil((float)rWidth / tileS);

	std::cout << "Room requires " << numOfTile << " tiles." << std::endl << std::endl;
	tTile += numOfTile;
}

// resets all dimensions back to 0
void reset(int &a, int &b, int &c, int &d) {
	a = 0;
	b = 0;
	c = 0;
	d = 0;
}
