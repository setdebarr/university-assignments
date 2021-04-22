#pragma once

#include"Mammal.h"

class Pig:public Mammal {
public:
	Pig(int weight, std::string name);	// constructor 
	~Pig();								// default destructor

	void Speak();						// makes the animal speak

private:

};