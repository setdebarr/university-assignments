#pragma once

#include "Mammal.h"

class Cat:public Mammal {
public:
	Cat(int weight, std::string name);	// constructor 
	~Cat();								// default destructor

	void Speak();						// makes the animal speak

private:

};