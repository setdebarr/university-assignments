#pragma once
#include <iostream>

class Rectangle {

public:
	Rectangle();						// zero-argument constructor that initializes length and width to 0
	float calcPerimeter(float, float);	// computes the perimeter of the rectangle
	float calcArea(float, float);		// computes the area of the rectangle
	void setLength(float);				// sets the rectangle length
	void setWidth(float);				// sets the rectangle width
	float getLength() const;			// returns the rectangle length
	float getWidth() const;				// returns the rectangle width
	void showData();					// displays the length, width, perimeter, and area of the rectangle

private:
	float length;						// stores the rectangle length
	float width;						// stores the rectangle width
};