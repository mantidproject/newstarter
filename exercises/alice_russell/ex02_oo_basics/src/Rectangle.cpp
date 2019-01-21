#include "Rectangle.h"

//calculates the perimeter of the rectangle 
double Rectangle::perimeter() const
{
	return side1 * 2 + side2 * 2;
}

//calculates the area of the rectangle 
double Rectangle::area() const
{
	return side1 * side2;
}

//returns the type rectangle 
std::string Rectangle::type() const
{
	return "Rectangle";
}

//returns the number of sides - 4 
unsigned int Rectangle::sides() const
{
	return 4;
}
