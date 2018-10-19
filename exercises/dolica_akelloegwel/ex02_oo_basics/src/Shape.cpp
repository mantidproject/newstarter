#include "Shape.h"

Shape::~Shape()
{
}
std::ostream & operator<<(std::ostream & os, const Shape & shape)
{
	// Retrieve the shape message and print
	os << shape.GetMessage();
	return os;
}
