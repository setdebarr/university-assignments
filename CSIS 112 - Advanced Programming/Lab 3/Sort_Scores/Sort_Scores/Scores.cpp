#include "Scores.h"

// initializes array to zeros 
Scores::Scores() {
	numOfScores = 0;
	for(size_t i = 0; i < scores.size(); i++) {
		scores[i] = 0;
	}
}

// initializes array with user specified values 
Scores::Scores(float n) {
	numOfScores = 0;
	for(size_t i = 0; i < scores.size(); i++) {
		scores[i] = n;
	}
}

// adds score to array
bool Scores::addScores(float n) {
	// checks if score is negative
	if(n < 0.0f) {
		validScore = false;
		std::cout << "\nInvalid score detected: " << n << std::endl;
		std::cout << "Please fix input and restart program." << std::endl << std::endl;
	}
	else {
		validScore = true;
		scores[numOfScores] = n;
		++numOfScores;
	}
	return validScore;
}

// sorts the array
void Scores::sort() {
	std::sort(scores.begin(), scores.begin() + numOfScores);
}

// returns the average of the scores
float Scores::calcAverage() {
	float total = 0;	// stores the sum of scores
	// adds up all scores in array
	for(size_t i = 0; i < numOfScores; ++i) {
		total += scores[i];
	}
	return (total / numOfScores);
}

// displays score array to console
void Scores::displayScores() {
	std::cout << "\nThe scores in the array are:" << std::endl;
	for(size_t i = 0; i < numOfScores; ++i) {
		std::cout << scores[i] << std::endl;
	}
	std::cout << std::endl;
}
