#include "Cat.h"
// constructor 
Cat::Cat(int weight, std::string name):Mammal(weight, name) {
	std::cerr << "Invoking Cat constructor\n";
}
// default destructor
Cat::~Cat() {
	std::cerr << "Invoking Cat deconstructor\n";
}
// makes the animal speak
void Cat::Speak() {
	std::cout << "Meow\n";
}
