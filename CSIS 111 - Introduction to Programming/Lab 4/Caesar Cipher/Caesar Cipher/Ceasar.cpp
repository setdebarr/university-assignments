// Ceasar.cpp -- this program takes in a file as input and outputs a rot13 translation of the file
// CSIS 111-001
// Public domain source code used with my instructor's permission

// include statements
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// function declarations
void Rot13 (char&);
void WriteTranslatedChar (char&, ofstream&);

// program starts here
int main () {

	// print out name in accordance with lab submission instructions
	cout << "Sean DeBarr -- Lab 4" << endl << endl;

	// display opening message
	cout << "************************************" << endl;
	cout << "      Welcome to Caesar cipher" << endl;
	cout << "************************************" << endl;

	// initializes variables
	char c;
	int charCount = 0;
	int lineCount = 0;
	ifstream input;
	ofstream output;

	string input_filename;
	string output_filename = "output.rot13";

	// asks user for file path 
	while (true) {

		cout << "\nPlease input file location: ";
		getline(cin, input_filename);

		// open input file
		input.open (input_filename.c_str());

		// if file not found throw error and ask again
		if (!input) {
			cout << "\nInvaild filename or location...";
			cout << "Please try again...\n\n";
		}
		else {
			break;
		}
	}
	// open output file
	output.open (output_filename.c_str ());
	
	// rot13's the file file
	while (1) {
		// gets a new character
		input.get (c);
		
		// counter for characters
		charCount += 1;

		// breaks from loop once end of file is reached
		if (input.eof ()) {
			break;
		}

		// counter for lines
		if (c == '\n') {
			lineCount += 1;
		}

		/*
		Passes the char to the Rot13 function then passes the encoded char to the 
		WriteTranslatedChar function for outputing to the output file
		*/
		Rot13 (c);
		WriteTranslatedChar (c, output);
	}

	// close input and output files
	input.close ();
	output.close ();

	// displays char count and line count
	cout << "\nEncoded " << charCount << " characters." << endl;
	cout << "On " << lineCount << " lines." << endl << endl;
	cout << "Outputted to " << output_filename << endl << endl;
	cout << "*** Thank you for using Caesar cipher ***" << endl << endl;

	// pause system for user to see results
	system ("pause");
	return 0;
}

// recieves a char input and returns a char rotated by 13 places
void Rot13 (char &ch) {
	//  [A:M] -> [N:Z]
	if ('A' <= ch && ch <= 'M') {
		ch = ch + 13;
	}
	//  [N:Z] -> [A:M]
	else if ('N' <= ch && ch <= 'Z') {
		ch = ch - 13;
	}
	//  [a:m] -> [n:z]
	else if ('a' <= ch && ch <= 'm') {
		ch = ch + 13;
	}
	//  [n:z] -> [a:m]
	else if ('n' <= ch && ch <= 'z') {
		ch = ch - 13;
	} else {
		ch = ch;
	}
}

// writes the translated char to the output file
void WriteTranslatedChar (char &c , ofstream &output) {
	output.put (c);
}