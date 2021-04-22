#include "Mammal.h"

// default constructor 
Mammal::Mammal() {
	setName("");
	setWeight(0);
	std::cerr << "Invoking Mammal default constructor\n";
}
// constructor to set mammal weight and name
Mammal::Mammal(int weight, std::string name) {
	setName(name);
	setWeight(weight);
	std::cerr << "Invoking Mammal client set constructor\n";
}
// default destructor
Mammal::~Mammal() {
	std::cerr << "Invoking Mammal deconstructor\n";
}
// sets the mammal name
void Mammal::setName(std::string name) {
	this->name = name;
}
// sets the mammal weight
void Mammal::setWeight(int weight) {
	this->weight = weight;
}
// returns the mammal name
std::string Mammal::getName() {
	return this->name;
}
// returns the mammal weight
int Mammal::getWeight() {
	return this->weight;
}
