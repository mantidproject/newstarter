#include "Shape.h"
#include <iostream>

Shape::Shape(std::string type, int sideCount)
	:m_type(type),
	m_sideCount(sideCount)
{
}

std::string Shape::getType() const
{
	return m_type;
}

int Shape::getSideCount() const
{
	return m_sideCount;
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
	std::cout << "Type: " << m_type << ", sides: " << m_sideCount;
}

Shape::~Shape()
{
}

