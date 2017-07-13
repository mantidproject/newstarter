#include "Square.h"
#include <iostream>

Square::Square(double side)
	:Shape("Square", 4),
	m_side(side)
{
}

double Square::calcArea() const
{
	return m_side*m_side;
}

double Square::calcPerimeter() const
{
	return m_side * 4;
}

void Square::print() const
{
	std::cout << "Type: " << m_type << ", sides: " << m_sideCount << ", side: " << m_side << '\n';
}
