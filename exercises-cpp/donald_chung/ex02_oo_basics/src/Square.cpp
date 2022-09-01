#include <cmath>
#include <iostream>
#include "Square.h"


Square::Square(double side_i) : Shape("Square", 4), side{ side_i }
{
}

double Square::perimeter()
{
    double result{ 4 * side };
    return result;
}
double Square::area()
{
    double result{ std::pow(side, 2) };
    return result;
}

void Square::print()
{
	std::cout << "Type: " << this->get_type() <<
		"; Number of Sides: " << this->get_num_sides() <<
		"; Length: " << this->side <<
		"; Area: " << this->area() <<
		"; Perimeter: " << this->perimeter() <<
		"\n";
}
