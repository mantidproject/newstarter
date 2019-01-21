# include "Shape.h"

//prints all the details of the shape
void Shape::print_details(std::ostream & out) const
{
	out << "Type: " << type() 
		<< "\t Sides: " << sides() 
		<< "\t Area: " << area() 
		<< "\t Perimeter: " << perimeter() 
		<< std::endl;
}
