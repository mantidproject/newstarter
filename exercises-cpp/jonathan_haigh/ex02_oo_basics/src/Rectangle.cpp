#include "Rectangle.h"

Rectangle::Rectangle(const double side1, const double side2, const std::string& name) :
	Shape(4, name), m_side1(side1), m_side2(side2) {
	calcArea();
	calcPerimeter();
}

void Rectangle::calcArea() {
	m_area = m_side1 * m_side2;
}

void Rectangle::calcPerimeter() {
	m_perimeter = 2 * m_side1 + 2 * m_side2;
}