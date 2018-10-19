#include "Shape.h"

Shape::~Shape()
{
}
std::string Shape::CreateBaseMessage() const
{
	// Create a basic message without subclass info to act as a template when overloading <<
	return "\n  Perimeter: " + std::to_string(GetPerimeter()) + "\n  Area: " + std::to_string(GetArea()) + "\n";
}
std::ostream & operator<<(std::ostream & os, const Shape & shape)
{
	// Retrieve the shape message and print
	os << shape.GetMessage();
	return os;
}
