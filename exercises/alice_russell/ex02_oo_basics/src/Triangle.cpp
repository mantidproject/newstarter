#include "Triangle.h"

//calculates the perimeter of the triangle 
double Triangle::perimeter() const
{
	return base + 2.0 * sqrt(height*height + (base*base / 4.0));
}

//calculates the area of the triangle 
double Triangle::area() const
{
	return 0.5 * base * height;
}

//retruns the type triangle 
std::string Triangle::type() const
{
	return "Triangle";
}

//returns the number of sides - 3
unsigned int Triangle::sides() const
{
	return 3;
}
