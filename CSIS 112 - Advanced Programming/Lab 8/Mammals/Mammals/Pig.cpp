#include "Pig.h"
// constructor 
Pig::Pig(int weight, std::string name):Mammal(weight, name) {
	std::cerr << "Invoking Pig constructor\n";
}
// default destructor
Pig::~Pig() {
	std::cerr << "Invoking Pig deconstructor\n";
}
// makes the animal speak
void Pig::Speak() {
	std::cout << "Oink\n";
}
