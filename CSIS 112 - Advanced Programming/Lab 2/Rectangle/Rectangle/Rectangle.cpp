#include "Rectangle.h"

// zero-argument constructor that initializes length and width to 0 
Rectangle::Rectangle() {
	length = 0;
	width = 0;
}

// computes the perimeter of the rectangle
float Rectangle::calcPerimeter(float l, float w) {
	return (2 * l) + (2 * w);
}

// computes the area of the rectangle
float Rectangle::calcArea(float l, float w) {
	return l * w;
}

// sets the rectangle length
void Rectangle::setLength(float l) {
	length = l;
}

// sets the rectangle width
void Rectangle::setWidth(float w) {
	width = w;
}

// returns the rectangle length
float Rectangle::getLength() const {
	return length;
}

// returns the rectangle width
float Rectangle::getWidth() const {
	return width;
}

// displays the length, width, perimeter, and area of the rectangle
void Rectangle::showData() {
	std::cout << "The Rectangle length is: " << Rectangle::getLength() << std::endl;
	std::cout << "The Rectangle width is: " << Rectangle::getWidth() << std::endl;
	std::cout << "The Rectangle perimeter is: " << Rectangle::calcPerimeter(Rectangle::getLength(), Rectangle::getWidth()) << std::endl;
	std::cout << "The Rectangle area is: " << Rectangle::calcArea(Rectangle::getLength(), Rectangle::getWidth()) << std::endl << std::endl;
}

