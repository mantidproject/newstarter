#include "Triangle.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(double base, double height)
	:Shape("Triangle", 3),
	m_base(base),
	m_height(height)
{
}

double Triangle::calcArea() const
{
	return m_height * m_base / 2;
}

double Triangle::calcPerimeter() const
{ 
	return m_base + 2*(sqrt(m_height * m_height + (m_base * m_base / 4)));
}

void Triangle::print() const
{
	Shape::print();
	std::cout << ", base: " << m_base << ", height: " << m_height << '\n';
}

