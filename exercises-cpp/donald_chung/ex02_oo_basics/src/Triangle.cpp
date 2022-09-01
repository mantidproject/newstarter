#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(double base_i, double height_i) : Shape("Triangle", 3), base{ base_i }, height{ height_i }
{
}
double Triangle::area()
{
	return base * height / 2;
}

double Triangle::perimeter()
{
	return base + std::sqrt(std::pow(base, 2) + (4 * std::pow(height, 2)));
}

void Triangle::print()
{
	std::cout << "Type: " << this->get_type() <<
		"; Number of Sides: " << this->get_num_sides() <<
		"; Base: " << this->base <<
		"; Height: " << this->height <<
		"; Area: " << this->area() <<
		"; Perimeter: " << this->perimeter() <<
		"\n";
}
