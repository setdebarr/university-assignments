#pragma once
#include <array>
#include <fstream>
#include <iostream>
#include <string>

class Scores {
public:
	Scores();						// initializes array to zeros
	Scores(float);					// initializes array with user specified values
	bool addScores(float);			// adds score to array
	void sort();					// sorts the array
	float calcAverage();			// returns the average of the scores
	void displayScores();			// displays score array to console

private:
	std::array<float, 100> scores;	// array for storing scores
	int numOfScores = 0;			// counter for number of scores entered
	bool validScore = true;			// check for if the score is non-negative
};