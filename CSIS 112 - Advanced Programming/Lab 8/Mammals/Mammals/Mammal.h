#pragma once
#include <iostream>
#include <string>

class Mammal {
public:
	Mammal();					// default constructor 
	Mammal(int, std::string);	// constructor to set mammal weight and name
	virtual ~Mammal();			// default destructor

	void setName(std::string);	// sets the mammal name
	void setWeight(int);		// sets the mammal weight

	std::string getName();		// returns the mammal name
	int getWeight();			// returns the mammal weight

	virtual void Speak() = 0;	// purely virtual function

private:
	std::string name;			// stores mammal name
	int weight;					// stores mammal weight
};