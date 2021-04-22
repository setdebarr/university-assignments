#pragma once

#include "Mammal.h"

class Dog:public Mammal {
public:
	Dog(int weight, std::string name);	// constructor 
	~Dog();								// default destructor

	void Speak();						// makes the animal speak

private:

};