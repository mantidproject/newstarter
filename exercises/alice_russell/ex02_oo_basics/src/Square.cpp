#include "Square.h"

double Square::find_perimeter() const
{
	return side * 4;
}

double Square::find_area() const
{
	return side * 2;
}

std::string Square::get_type() const
{
	return "Square";
}

unsigned int Square::get_sides() const
{
	return 4;
}
