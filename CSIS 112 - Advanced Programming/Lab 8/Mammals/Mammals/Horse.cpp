#include "Horse.h"
// constructor 
Horse::Horse(int weight, std::string name):Mammal(weight, name) {
	std::cerr << "Invoking Horse constructor\n";
}
// default destructor
Horse::~Horse() {
	std::cerr << "Invoking Horse deconstructor\n";
}
// makes the animal speak
void Horse::Speak() {
	std::cout << "I'm Mr. Ed\n";
}