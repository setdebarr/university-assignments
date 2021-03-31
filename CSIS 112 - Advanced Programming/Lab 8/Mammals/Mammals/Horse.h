#pragma once

#include "Mammal.h"

class Horse:public Mammal {
public:
	Horse(int weight, std::string name);	// constructor 
	~Horse();								// default destructor

	void Speak();							// makes the animal speak

private:

};