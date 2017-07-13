#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double side1, double side2)
	:Shape("Rectangle", 4),
	m_side1(side1),
	m_side2(side2)
{
}

double Rectangle::calcArea() const
{
	return m_side1*m_side2;
}

double Rectangle::calcPerimeter() const
{
	return m_side1 * 2 + m_side2 * 2;
}

void Rectangle::print() const
{
	Shape::print();
	std::cout << "Type: " << m_type << ", sides: " << m_sideCount << ", side 1: " << m_side1 << ", side 2: " << m_side2 << '\n';
}
