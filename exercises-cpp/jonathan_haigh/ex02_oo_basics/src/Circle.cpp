#include "Circle.h"
#include<cmath>

Circle::Circle(const double radius) :
	Shape(1, "circle"), m_radius(radius) {
	calcArea();
	calcPerimeter();
}

void Circle::calcArea() {
	m_area = M_PI * pow(m_radius, 2);
}

void Circle::calcPerimeter() {
	m_perimeter = M_PI * 2 * m_radius;
}