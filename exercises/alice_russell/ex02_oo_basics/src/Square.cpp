#include "Square.h"

//calculates the perimeter of the square 
double Square::perimeter() const
{
	return side * 4;
}

//calculates the area of the square 
double Square::area() const
{
	return side * 2;
}

//returns the type square 
std::string Square::type() const
{
	return "Square";
}

//return the number of sides - 4 
unsigned int Square::sides() const
{
	return 4;
}
