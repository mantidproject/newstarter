#include "Circle.h"

//calculates the perimeter of the circle
double Circle::perimeter() const
{
	
	return M_PI * radius * 2;
}

//calculates the area of the circle
double Circle::area() const
{
	return M_PI * radius * radius;
}

//return the type circle
std::string Circle::type() const
{
	return "Circle";
}

//returns the number of sides - 1
unsigned int Circle::sides() const
{
	return 1;
}
