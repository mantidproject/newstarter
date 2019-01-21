#include "Circle.h"

static const double PI = 3.141592653589793238463;

double Circle::find_perimeter() const
{
	
	return PI * radius * 2;
}

double Circle::find_area() const
{
	return PI * radius * radius;
}

std::string Circle::get_type() const
{
	return "Circle";
}

unsigned int Circle::get_sides() const
{
	return 1;
}
