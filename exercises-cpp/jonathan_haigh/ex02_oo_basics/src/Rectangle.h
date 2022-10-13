#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(const double side1, const double side2, const std::string& name = "rectangle");

private:
	void calcArea() override;
	void calcPerimeter() override;

	double m_side1;
	double m_side2;
};