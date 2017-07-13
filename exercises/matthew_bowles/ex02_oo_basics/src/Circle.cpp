#include "Circle.h"
#include <cmath>
#include <iostream>

Circle::Circle(double radius)
	:Shape("Circle", 1),
	m_radius(radius)
{
}

double Circle::calcArea() const
{
	return M_PI * m_radius * m_radius;
}

double Circle::calcPerimeter() const
{
	return M_PI * m_radius * 2;
}

void Circle::print() const
{
	Shape::print();
	std::cout << ", radius: " << m_radius << '\n';
}
