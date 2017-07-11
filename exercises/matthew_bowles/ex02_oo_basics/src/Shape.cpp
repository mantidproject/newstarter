#include "Shape.h"

Shape::Shape()
{
}

Shape::Shape(std::string type, int sideCount)
	:type(type),
	sideCount(sideCount)
{
}

std::string Shape::getType() const
{
	return type;
}

int Shape::getSideCount() const
{
	return sideCount;
}

double Shape::calcArea() const
{
	return 0;
}

double Shape::calcPerimeter() const
{
	return 0;
}

void Shape::print() const
{
	std::cout << "Type: " << type << ", sides: " << sideCount;
}

Shape::~Shape()
{
}

