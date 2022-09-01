#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double len_i, double wid_i) : Shape("Rectangle", 4), len{len_i}, wid{wid_i}
{
}
double Rectangle::area()
{
	return len * wid;
}

double Rectangle::perimeter() 
{
	return 2 * len + 2 * wid;
}

void Rectangle::print() 
{
	std::cout << "Type: " << this->get_type() << 
		"; Number of Sides: " << this->get_num_sides() << 
		"; Width: " << this->wid <<
		"; Length: " << this->len <<
		"; Area: " << this->area() << 
		"; Perimeter: " << this->perimeter() << 
		"\n";
}
