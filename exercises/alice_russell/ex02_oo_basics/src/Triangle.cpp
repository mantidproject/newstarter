#include "Triangle.h"

double Triangle::find_perimeter() const
{
	return base + 2.0 * sqrt(height*height + (base*base / 4.0));
}

double Triangle::find_area() const
{
	return 0.5 * base * height;
}

std::string Triangle::get_type() const
{
	return "Triangle";
}

unsigned int Triangle::get_sides() const
{
	return 3;
}
