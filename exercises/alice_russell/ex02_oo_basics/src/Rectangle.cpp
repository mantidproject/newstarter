#include "Rectangle.h"

double Rectangle::find_perimeter() const
{
	return side1 * 2 + side2 * 2;
}

double Rectangle::find_area() const
{
	return side1 * side2;
}

std::string Rectangle::get_type() const
{
	return "Rectangle";
}

unsigned int Rectangle::get_sides() const
{
	return 4;
}
