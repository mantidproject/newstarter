#include "Shape.h"
#include <iostream>

Shape::Shape(const int sides, const std::string& name)
	: m_sides(sides), m_name(name), m_area(0.0), m_perimeter(0.0) {}

const std::string& Shape::getName() const {
	return m_name;
}

int Shape::getSides() const {
	return m_sides;
}

double Shape::getArea() const {
	return m_area;
}

double Shape::getPerimeter() const {
	return m_perimeter;
}

void Shape::print() const {
	std::cout << m_name << std::endl
		<< "S: " << m_sides << std::endl
		<< "A: " << m_area << std::endl
		<< "P: " << m_perimeter << std::endl;
}