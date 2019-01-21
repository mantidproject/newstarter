# include "Shape.h"

void Shape::print_details(std::ostream & out)
{
	out << "Type: " << get_type() 
		<< "\t Sides: " << get_sides() 
		<< "\t Area: " << find_area() 
		<< "\t Perimeter: " << find_perimeter() 
		<< std::endl;
}
