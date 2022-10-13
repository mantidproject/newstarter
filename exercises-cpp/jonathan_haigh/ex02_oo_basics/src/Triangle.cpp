#include "Triangle.h"
#include<cmath>

Triangle::Triangle(const double height, const double base) :
	Shape(3, "triangle"), m_height(height), m_base(base) {
	calcArea();
	calcPerimeter();
}

void Triangle::calcArea() {
	m_area = 0.5 * m_base * m_height;
}

void Triangle::calcPerimeter() {
	m_perimeter = m_base + 2 * sqrt(pow(m_height, 2) + (pow(m_base, 2) / 4));
}