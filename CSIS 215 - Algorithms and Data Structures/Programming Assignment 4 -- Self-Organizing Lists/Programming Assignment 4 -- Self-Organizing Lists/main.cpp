#include <stdio.h>
#include <fstream>

#include "CountList.hpp"
#include "MoveToFrontList.hpp"
#include "TransposeList.hpp"
#include <string>

int main() {
	printf("Sean DeBarr - Programming Assignment 4 -- Self-Organizing Lists\n");

	char charIns[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	int charInsLength = sizeof(charIns) / sizeof(charIns[0]);

	char charFinds[] = {'F', 'D', 'F', 'G', 'E', 'G', 'F', 'A', 'D', 'F', 'G', 'E', 'H', 'I'};
	int charFindsLength = sizeof(charFinds) / sizeof(charFinds[0]);

	//#################################################################

	// Count heuristic
	printf("COUNT HEURISTIC: Chars\n");

	CountList<char> *countList = new CountList<char>();
	
	for(int i = 0; i < charInsLength; ++i) {
		countList->add(charIns[i]);
	}
	for(int i = 0; i < charFindsLength; ++i) {
		countList->find(charFinds[i]);
	}

	printf("Size of list: %d\n", countList->size());
	printf("Number of compares: %d\n", countList->getCompares());
	countList->printlist();
	printf("\n");

	// Move to Front heuristic
	printf("Move to Front HEURISTIC: Chars\n");

	MoveToFrontList<char> *moveToFrontList = new MoveToFrontList<char>();

	for(int i = 0; i < charInsLength; ++i) {
		moveToFrontList->add(charIns[i]);
	}
	for(int i = 0; i < charFindsLength; ++i) {
		moveToFrontList->find(charFinds[i]);
	}

	printf("Size of list: %d\n", moveToFrontList->size());
	printf("Number of compares: %d\n", moveToFrontList->getCompares());
	moveToFrontList->printlist();
	printf("\n");

	// Transpose heuristic
	printf("Transpose HEURISTIC: Chars\n");

	TransposeList<char> *transposeList = new TransposeList<char>();

	for(int i = 0; i < charInsLength; ++i) {
		transposeList->add(charIns[i]);
	}
	for(int i = 0; i < charFindsLength; ++i) {
		transposeList->find(charFinds[i]);
	}

	printf("Size of list: %d\n", transposeList->size());
	printf("Number of compares: %d\n", transposeList->getCompares());
	transposeList->printlist();
	printf("\n");

	//#################################################################

	std::fstream file;
	std::string w, filename;
	
	filename = "test.txt";

	// Count heuristic
	printf("COUNT HEURISTIC: Strings\n");

	CountList<std::string> *countListS = new CountList<std::string>();
	
	file.open(filename.c_str());
	while(file >> w) {
		countListS->find(w);
	}
	file.close();

	printf("Size of list: %d\n", countListS->size());
	printf("Number of compares: %d\n", countListS->getCompares());
	countListS->printlist(10);
	printf("\n");

	//// Move to Front heuristic
	//printf("Move to Front HEURISTIC: Strings\n");

	//MoveToFrontList<std::string> *moveToFrontListS = new MoveToFrontList<std::string>();
	//
	//file.open(filename.c_str());
	//while(file >> w) {
	//	moveToFrontListS->find(w);
	//}
	//file.close();

	//printf("Size of list: %d\n", moveToFrontListS->size());
	//printf("Number of compares: %d\n", moveToFrontListS->getCompares());
	//moveToFrontListS->printlist(10);
	//printf("\n");

	// Transpose heuristic
	printf("Transpose HEURISTIC: Strings\n");

	TransposeList<std::string> *transposeListS = new TransposeList<std::string>();

	file.open(filename.c_str());
	while(file >> w) {
		transposeListS->find(w);
	}
	file.close();

	printf("Size of list: %d\n", transposeListS->size());
	printf("Number of compares: %d\n", transposeListS->getCompares());
	transposeListS->printlist(10);
	printf("\n");


	printf("\nPress Enter to exit");
	getchar();
	return 0;
}