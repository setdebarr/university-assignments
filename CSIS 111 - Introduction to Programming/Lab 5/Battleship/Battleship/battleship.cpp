// battleship.cpp -- a simple console battleship game. 
// CSIS 111-001
// Public domain source code used with my instructor's permission

// include statements
#include "resource.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Mmdeviceapi.h>
#include <time.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

// constant variables
const int BOARD_WIDTH = 25;
const int BOARD_HEIGHT = 25;
const char sound[] = {IDR_WAVE1, IDR_WAVE2, IDR_WAVE3, IDR_WAVE4, IDR_WAVE5, IDR_WAVE6, IDR_WAVE7};
/*
IDR_WAVE1
License Personal Use Only
https://soundbible.com/174-Torpedo-Launching-Sub.html
*/

/*
IDR_WAVE2
torpedo explosion
*/

/*
IDR_WAVE3
Britney Spears - ...Baby One More Time
short clip
*/


/*
IDR_WAVE4
Attribution 3.0 Unported (CC BY 3.0)
https://freesound.org/people/LittleRobotSoundFactory/sounds/270402/
*/

/*
IDR_WAVE5
This track is licensed under a ‘Creative Commons Attribution 4.0 International License’.
Ross Bugden
https://youtu.be/Bln0BEv5AJ0
*/

/*
IDR_WAVE6
blank track
*/

/*
IDR_WAVE7
"Makai Symphony - Dragon Castle" is under a Creative Commons license (CC BY-SA 3.0).
Music promoted by BreakingCopyright: https://youtu.be/9gBTKiVqprE
*/

// playing map
char playMap[BOARD_WIDTH][BOARD_HEIGHT];

// function prototypes
void initGame();
int offset(int);
void loadGameMap(char ocean[BOARD_WIDTH][BOARD_HEIGHT], int &);
int *getCords();
bool FleetSunk(int);
int getInput(string);
string Fire(int, int, int &, char ocean[BOARD_WIDTH][BOARD_HEIGHT]);
void updateGameBoard();

// program starts here
int main() {

	// print out name in accordance with lab submission instructions
	cout << "Sean DeBarr -- Lab 5" << endl << endl;

	// print start promt
	initGame();

	// Initialize game board array and ship counter
	char ocean[BOARD_WIDTH][BOARD_HEIGHT];
	int ships = 0;
	bool won = false;

	// initialize playboard with #'s
	for(int i = 0; i < BOARD_WIDTH; i++)
		for(int j = 0; j < BOARD_HEIGHT; j++) { playMap[i][j] = '~'; }

	// loads game map
	loadGameMap(ocean, ships);
	updateGameBoard();

	// main game loop
	do {

		// stores fire coordinates
		int *cords = getCords();

		// play torpedo launch sound if miss
		PlaySound((char *)sound[0], NULL, SND_RESOURCE | SND_ASYNC);

		// checks fire coordinates for hits
		string result = Fire(cords[1], cords[2], ships, ocean);

		// refreshes game board
		updateGameBoard();

		// displays fire results
		cout << result << endl;

		// checks if all ships are sunk
		won = FleetSunk(ships);
	} while(!won);

	// pause system for user to see results
	cout << "\nPress enter to exit...";
	cin.get();
	return 0;
}

// display welcome message
void initGame() {
	string a;
	//initialize the random seeds
	srand(time(NULL));

	cout << R"(
		 _           _   _   _           _     _        
		| |         | | | | | |         | |   (_)       
		| |__   __ _| |_| |_| | ___  ___| |__  _ _ __   
		| '_ \ / _` | __| __| |/ _ \/ __| '_ \| | '_ \  
		| |_) | (_| | |_| |_| |  __/\__ \ | | | | |_) | 
		|_.__/ \__,_|\__|\__|_|\___||___/_| |_|_| .__/  
		                                        | |     
		                                        |_|	 
)";

	cout << R"(		                     |__
                                     |\/
                                     ---
                                     / | [
                              !      | |||
                            _/|     _/|-++'
                        +  +--|    |--|--|_ |-
                     { /|__|  |/\__|  |--- |||__/
                    +---------------___[}-_===_.'____                 /\
                ____`-' ||___-{]_| _[}-  |     |_[___\==--            \/   _
 __..._____--==/___]_|__|_____________________________[___\==--____,------' .7
|                                                                     BB-61/
 \_________________________________________________________________________|
  Matthew Bace
	)" << '\n';
	/*
	This ASCII pic can be found at
	https://asciiart.website/index.php?art=transportation/nautical
	*/


	//generates a random number between 0 and 1
	int randNum = rand() % 2;
	if(randNum == 1) {
		PlaySound((char *)sound[6], NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
		/*
		"Makai Symphony - Dragon Castle" is under a Creative Commons license (CC BY-SA 3.0).
		Music promoted by BreakingCopyright: https://youtu.be/9gBTKiVqprE
		*/
	}
	else {
		PlaySound((char *)sound[4], NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
		/*
		This track is licensed under a ‘Creative Commons Attribution 4.0 International License’.
		Ross Bugden
		https://youtu.be/Bln0BEv5AJ0
		*/
	}

	cout << "\nPress enter to continue.";
	getline(cin, a);
	PlaySound((char *)sound[5], NULL, SND_RESOURCE | SND_ASYNC);
}

// loads game map into ocean array
void loadGameMap(char ocean[BOARD_WIDTH][BOARD_HEIGHT], int &hulls) {
	string fileName = "map1.level";
	ifstream map(fileName.c_str());
	bool error = false;

	// checks if file exists
	if(!map) {
		cout << "Error, " << fileName << " couldn't be opened" << endl;
		cout << "\nFATAL ERROR. Press enter to exit.";
		cin.get();
		exit(1);
	}

	// loops through each row and column of map file
	for(int row = 0; row < BOARD_WIDTH; row++) {
		for(int column = 0; column < BOARD_HEIGHT; column++) {
			map >> ocean[row][column];

			// stores how many ship hulls on game map
			if(ocean[row][column] == '#') {
				hulls++;
			}

			// error handling
			if((ocean[row][column] != '~') && (ocean[row][column] != '#')) {
				cout << "Error reading file for element " << row + 1 << "," << column + 1 << endl;
				error = true;
			}
		}
	}

	// if there is an error in file exit program
	if(error) {
		cout << "\nFATAL ERROR. Press enter to exit.";
		cin.get();
		exit(1);
	}
	map.close();
}

// offsets coordinates by -1 so game board starts at (1,1) instead of (0,0)
int offset(int n) {
	return n - 1;
}

// gets the fire coordinates from the user
int *getCords() {
	static int Cords[2];
	string xPromt = "Please enter x-cordinate: ";
	string yPromt = "Please enter y-cordinate: ";

	cout << xPromt;
	Cords[1] = getInput(xPromt);
	cout << endl;

	cout << yPromt;
	Cords[2] = getInput(yPromt);
	cout << endl;

	updateGameBoard();

	return &Cords[0];
}

// check if all ships have been sunk
bool FleetSunk(int n) {
	if(n == 0) {

		// play win sound
		PlaySound((char *)sound[3], NULL, SND_RESOURCE | SND_ASYNC);
		/*
		Attribution 3.0 Unported (CC BY 3.0)
		https://freesound.org/people/LittleRobotSoundFactory/sounds/270402/
		*/

		// print out win message
		cout << "\nThe fleet was destroyed!" << endl;
		return true;

	}
	else {
		return false;
	}
}

// gets a positive numerical value from user
int getInput(string promt) {

	// declare local variables
	string userInput;
	int number;
	bool valid = false;

	// asks user for input and continues to ask till valid
	while(!valid) {

		// asks user for an integer
		getline(cin, userInput);

		// sanitizes user input
		try {
			number = stoi(userInput);
			if((number >= 1) & (number <= BOARD_WIDTH) & (number <= BOARD_HEIGHT)) {
				valid = true;
			}
			else {
				cout << "\nCordinates must be between 1-25. Try again.\n\n";
				cout << promt;
				valid = false;
			}
		}
		catch(const std::exception &) {
			cout << "\nInvalid input detected.\n\n";
			updateGameBoard();
			cout << promt;
		}

	}

	// returns the integer
	return number;
}

// determines if user hits a ship, updates the array if so and return result message
string Fire(int x, int y, int &n, char ocean[BOARD_WIDTH][BOARD_HEIGHT]) {
	if(playMap[offset(x)][offset(y)] == 'H') {
		PlaySound((char *)sound[2], NULL, SND_RESOURCE | SND_ASYNC);
		return "HIT AGAIN";
	}
	else if(ocean[offset(x)][offset(y)] == '#') {
		PlaySound((char *)sound[1], NULL, SND_RESOURCE | SND_ASYNC);
		playMap[offset(x)][offset(y)] = 'H';
		n--;
		return "HIT";
	}
	else {
		playMap[offset(x)][offset(y)] = 'M';
		return "MISS";
	}
}

// refreshes the console
void updateGameBoard() {
	system("cls");

	int counter = 0;
	int horzNumber = BOARD_WIDTH;
	int vertNumber = BOARD_HEIGHT;

	cout << "\n";

	// prints out board with row numbering
	for(int y = BOARD_HEIGHT - 1; y >= 0; y--) {
		for(int x = 0; x < BOARD_WIDTH; x++) {
			if(counter == 0 && vertNumber < 10) {
				cout << " " << vertNumber;
			}
			else if(counter == 0 && vertNumber >= 10) {
				cout << vertNumber;
			}
			cout << "  " << playMap[x][y];
			counter++;
		}
		cout << endl;
		counter = 0;
		vertNumber--;
	}

	// prints out column numbering
	cout << "    ";
	for(int n = 1; n < BOARD_WIDTH + 1; n++) {
		if(n < 9) {
			cout << n << "  ";
		}
		else {
			cout << n << " ";
		}
	}
	cout << "\n\n";
}
