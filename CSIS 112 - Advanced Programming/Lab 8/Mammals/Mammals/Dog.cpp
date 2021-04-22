#include "Dog.h"
// constructor 
Dog::Dog(int weight, std::string name):Mammal(weight, name) {
	std::cerr << "Invoking Dog constructor\n";
}
// default destructor
Dog::~Dog() {
	std::cerr << "Invoking Dog deconstructor\n";
}
// makes the animal speak
void Dog::Speak() {
	std::cout << "Woof\n";
}
