
#include <cmath>
#include <iostream>
#include "Circle.h"


Circle::Circle(double radius_i) : Shape("Circle", 1), radius{ radius_i }
{
}

const double pi = 3.14159265358979323846;

double Circle::perimeter()
{
	double result{ 2 * pi * radius };
	return result;
}
double Circle::area()
{

	double result{ pi * (std::pow(radius, 2)) };
	return result;
}

void Circle::print()
{
	std::cout << "Type: " << this->get_type() <<
		"; Number of Sides: " << this->get_num_sides() <<
		"; Radius: " << this->radius <<
		"; Area: " << this->area() <<
		"; Perimeter: " << this->perimeter() <<
		"\n";
}